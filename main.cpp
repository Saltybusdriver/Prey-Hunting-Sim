#include <iostream>
#include <istream>
#include <time.h>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "Colonies.h"
#include "Animals.h"
#include <map>
using namespace std;

#define NORMAL_MODE
#ifdef NORMAL_MODE

void create (const string &fileName, vector<Colonies*> &Prey, vector<Colonies*> &Predator, bool &GoodIN,map<char,int> &freq){
    ifstream f(fileName);
    if(f.fail())
    {
        cout << "The file that you have entered is not found!\n";
        GoodIN=false;
        return;
    }
    //get amount of predators/preys then resize vector
    int r, zs;

    if(f >> zs >> r)
    Prey.resize(zs);
    Predator.resize(r);

    for( unsigned int i = 0; i < zs; ++i )
    {
        char ch;
        string nev;
        int Population;
        f >> nev >> ch >> Population;
        if (Population>0)
        {
            switch(ch)
            {
                case 'l' :
                    Prey[i] = new Lemming(nev,ch,Population); //2,2
                    break;
                case 'n' :
                    Prey[i] = new Nyul(nev,ch,Population); //2,1.5
                    break;
                case 'u' :
                    Prey[i] = new Urge(nev,ch,Population); //4,2
                    break;
            }
        }
    }

    for( unsigned int i = 0; i < r; ++i )
    {
        char ch;
        string nev;
        int Population;
        f >> nev >> ch >> Population;
        if (Population>0)
        {
            switch(ch)
            {
                case 'h' :
                    Predator[i] = new Bagoly(nev,ch,Population);
                    break;
                case 's' :
                    Predator[i] = new Roka(nev,ch,Population);
                    break;
                case 'f' :
                    Predator[i] = new Farkas(nev,ch,Population);
                    break;
            }
            Predator[i]-> set_szumrag(Population);
        }

    }
}

void print (const vector<Colonies*> &vec)
{
    for (auto & val: vec)
    {
        cout << *val<< endl;
    }
}
void Reproduce(vector<Colonies*> colony,const int &RoundNum)
{
    for (Colonies* K : colony)
    {
        if (K->isAlive() && K->canReproduce(RoundNum))
        {
            K->Reproduce();
            cout<<*K<<" has reproduced"<<endl;
        }
    }
    cout<<endl;
}
void vadaszat(vector<Colonies*> &Prey,vector<Colonies*> &Predator,vector<Colonies*> &ExtinctAn)
{
    int dmg=0;
    for (unsigned int i = 0; i < Predator.size(); i++){

        int r=0;
        if(Prey.size()>0)
        {
            r = rand() % Prey.size();
        }
        if (Prey[r]->PopulationNumEdit(Predator[i]->Population(),dmg))
        {

            ExtinctAn.push_back(Prey[r]);
            if(Prey.empty())
            {
            }
            else Prey.erase(Prey.begin()+r);
            if (Predator[i]->PopulationNumEdit())
            {
                ExtinctAn.push_back(Predator[i]);
                Predator.erase(Predator.begin()+i);
            }
        }
        cout << i+1<<". Predator has attacked " << r+1 <<". Prey! Dealing: "<<dmg<<" Damage"<<endl;
    }


}
bool round(int RoundNum,vector<Colonies*> &Prey,vector<Colonies*> &Predator, string &eredmeny, vector<Colonies*> &ExtinctAn)
{

        int szum = 0;
        bool ue = true;
        int szum2=0;
        int seged=0;
        for(int i=0;i<Prey.size();++i)
        {
            if(Prey[i]->Population()==0){}
            else seged++;
            if(seged==0) exit(1);
        }
        Reproduce(Predator,RoundNum);
        Reproduce(Prey, RoundNum);
        if (Prey.size() == 0)
        {
            cout<<"All preys have gone extinct. Predators will slowly die off"<<endl<<endl;
            for (unsigned int i = 0; i < Predator.size(); i++)
            {
                Predator[i]->PopulationNumEdit();
            }
        }
        else vadaszat(Prey,Predator,ExtinctAn);
        cout << "/////////////////////////" ;
        cout << "\n Extinc Species:\n\n";
        print(ExtinctAn);
        cout << "/////////////////////////" <<endl;

        cout << "\n Preys:\n\n";
        print(Prey);
        cout << "/////////////////////////" << endl;

        cout << "\n Ragadozok:\n\n";
        print(Predator);
        cout << "/////////////////////////" << endl;

        for (unsigned int i = 0; i < Predator.size(); i++)
        {

            szum += Predator[i]->Population();
            szum2+=Predator[i]->szumrag();

        }
         if (szum<4) ue = false;
        if (!ue)
        {

            eredmeny = "\n Number of predators have fallen below 4!\n";
            cout<<"current all pred pop: "<<szum<<" "<<"Original pred pop: "<<szum2<<endl;;
            return true;
        }




        for(int i=0;i<Predator.size();++i)
        {
            if(Predator[0]->get_Specie()==Predator[0]->get_Specie())
            if (szum > 2 * szum2)
            {
                eredmeny = "\
                cout<<szum<<" "<<szum2;nNumber of Predators has doubled, exiting program\n";
                return true;
            }
        }
        return false;

}
bool szimulacio(vector<Colonies*> &Prey,vector<Colonies*> &Predator, string &eredmeny,vector<Colonies*>ExtincAn)
{
    try
    {
        int RoundNum = 0;
        do{
            cout << endl;
            cout << "|-----------------------|" << endl;
            cout << "|    \tROUND: "<< RoundNum+1 <<".\t|" << endl;
            cout << "|-----------------------|" << endl;
            RoundNum++;
        }
        while (!round(RoundNum,Prey, Predator, eredmeny,ExtincAn));
    }
    catch(const exception &e)
    {
        cout << e.what() << endl;
    }
    return false;
}


bool Colonies::_randomized_ = true;


int main()
{
    srand(time(NULL));
            map<char,int> freq;

    vector<Colonies*> Prey;
    vector<Colonies*> Predator;
    vector<Colonies*> ExtincAn;


    string lmao;
    bool GoodIN=false;
    do{
        cout<<"Enter Filename that is to be read: (input.txt)/(input1.txt): ";
        GoodIN=true;
        cin>>lmao;
        create(lmao, Prey, Predator,GoodIN,freq);
    }
    while(GoodIN==false);

    cout << "Preys:\n";
    print(Prey);
    cout <<endl<< "Predators:\n";
    print(Predator);
    cout << "\n--- Game start ---\n\n";
    string eredmeny = "If you see this message then i don't know whats wrong";
    szimulacio(Prey, Predator, eredmeny,ExtincAn);
    cout << eredmeny;

    return 0;
}










///////////////////////////TESTCASE////////////////////////////

#else

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <istream>
#include <time.h>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "Colonies.h"
#include "Animals.h"
#include <map>



void create (const string &fileName, vector<Colonies*> &Prey, vector<Colonies*> &Predator, bool &GoodIN,map<char,int> &freq){
    ifstream f(fileName);
    if(f.fail())
    {
       // cout << "The file that you have entered is not found!\n";
        GoodIN=false;
//        throw FILE_NOT_FOUND;
        return;
    }
    //get amount of predators/preys then resize vector
    int r, zs;

    if(f >> zs >> r)
    Prey.resize(zs);
    Predator.resize(r);

    for( unsigned int i = 0; i < zs; ++i )
    {
        char ch;
        string nev;
        int Population;
        f >> nev >> ch >> Population;
        if (Population>0)
        {
            switch(ch)
            {
                case 'l' :
                    Prey[i] = new Lemming(nev,ch,Population); //2,2
                    break;
                case 'n' :
                    Prey[i] = new Nyul(nev,ch,Population); //2,1.5
                    break;
                case 'u' :
                    Prey[i] = new Urge(nev,ch,Population); //4,2
                    break;
            }
        }
        //Predator[i]-> set_szumrag(Population);
    }

    for( unsigned int i = 0; i < r; ++i )
    {
        char ch;
        string nev;
        int Population;
        f >> nev >> ch >> Population;
        if (Population>0)
        {
            switch(ch)
            {
                case 'h' :
                    Predator[i] = new Bagoly(nev,ch,Population);
                    break;
                case 's' :
                    Predator[i] = new Roka(nev,ch,Population);
                    break;
                case 'f' :
                    Predator[i] = new Farkas(nev,ch,Population);
                    break;
            }
            Predator[i]-> set_szumrag(Population);
        }

    }
}

void Reproduce(vector<Colonies*> colony,const int &RoundNum, bool &canrepr)
{
    for (Colonies* K : colony)
    {
        if (K->isAlive() && K->canReproduce(RoundNum))
        {
            K->Reproduce();
            canrepr=true;

        }
    }
    //cout<<endl;
}
void vadaszat(vector<Colonies*> &Prey,vector<Colonies*> &Predator,vector<Colonies*> &ExtinctAn)
{
    int dmg=0;
    for (unsigned int i = 0; i < Predator.size(); i++){

        int r=0;
        if(Prey.size()>0)
        {
            r = rand() % Prey.size();
        }
        if (Prey[r]->PopulationNumEdit(Predator[i]->Population(),dmg))
        {

            ExtinctAn.push_back(Prey[r]);
            if(Prey.empty())
            {
            }
            else Prey.erase(Prey.begin()+r);
            if (Predator[i]->PopulationNumEdit())
            {
                ExtinctAn.push_back(Predator[i]);
                Predator.erase(Predator.begin()+i);
            }
        }
       // cout << i+1<<". Predator has attacked " << r+1 <<". Prey! Dealing: "<<dmg<<" Damage"<<endl;
    }


}
bool round(int RoundNum,vector<Colonies*> &Prey,vector<Colonies*> &Predator, string &eredmeny, vector<Colonies*> &ExtinctAn)
{

        int szum = 0;
        bool ue = true;
        int szum2=0;
        int seged=0;
        for(int i=0;i<Prey.size();++i)
        {
            if(Prey[i]->Population()==0){}
            else seged++;
            if(seged==0) exit(1);
        }
        //Reproduce(Predator,RoundNum);
       // Reproduce(Prey, RoundNum);
        if (Prey.size() == 0)
        {
          //  cout<<"All preys have gone extinct. Predators will slowly die off"<<endl<<endl;
            for (unsigned int i = 0; i < Predator.size(); i++)
            {
                Predator[i]->PopulationNumEdit();
            }
        }
        else vadaszat(Prey,Predator,ExtinctAn);
        for (unsigned int i = 0; i < Predator.size(); i++)
        {

            szum += Predator[i]->Population();
            szum2+=Predator[i]->szumrag();

        }
         if (szum<4) ue = false;
        if (!ue)
        {

            eredmeny = "\n Number of predators have fallen below 4!\n";
           // cout<<"current all pred pop: "<<szum<<" "<<"Original pred pop: "<<szum2<<endl;;
            return true;
        }




        for(int i=0;i<Predator.size();++i)
        {
            if(Predator[0]->get_Specie()==Predator[0]->get_Specie())
            if (szum > 2 * szum2)
            {
                eredmeny = "\
                cout<<szum<<" "<<szum2;nNumber of Predators has doubled, exiting program\n";
                return true;
            }
        }
        return false;

}
bool szimulacio(vector<Colonies*> &Prey,vector<Colonies*> &Predator, string &eredmeny,vector<Colonies*>ExtincAn,int &RoundNum)
{
    try
    {
        RoundNum = 0;
        do{
           /*/ cout << endl;
            cout << "|-----------------------|" << endl;
            cout << "|    \tROUND: "<< RoundNum+1 <<".\t|" << endl;
            cout << "|-----------------------|" << endl;/*/
            RoundNum++;
        }
        while (!round(RoundNum,Prey, Predator, eredmeny,ExtincAn)|| RoundNum!=2);
    }
    catch(const exception &e)
    {
        //cout << e.what() << endl;
    }
    return false;
}



TEST_CASE("isempty", "[ReadIN]") {

    vector<Colonies*> Prey;
    vector<Colonies*> Predator;
    vector<Colonies*> ExtincAn;
    map<char,int> freq;
    bool GoodIN=true;
    create("fas.txt", Prey, Predator,GoodIN,freq);
    REQUIRE(GoodIN==false);
}
TEST_CASE("existing", "[ReadIN]") {
    vector<Colonies*> Prey;
    vector<Colonies*> Predator;
    vector<Colonies*> ExtincAn;
    map<char,int> freq;
    bool GoodIN=true;
    create("input.txt", Prey, Predator,GoodIN,freq);
    REQUIRE(GoodIN==true);
}

TEST_CASE("is good data", "[ReadIN]") {
    vector<Colonies*> Prey;
    vector<Colonies*> Predator;
    vector<Colonies*> ExtincAn;
    map<char,int> freq;
    int roundnum=1;
    bool canreprod=false;
    bool GoodIN=true;
    create("input1.txt", Prey, Predator,GoodIN,freq);
    REQUIRE(GoodIN==true);
    string asdf;
    REQUIRE(Predator[0]->get_Specie()=='f');
    REQUIRE(Predator[0]->get_Name()=="gggggg");
    REQUIRE(Predator.size()==2);
    szimulacio(Prey, Predator, asdf,ExtincAn,roundnum);
    Reproduce(Prey, roundnum,canreprod);
    REQUIRE(roundnum==2);
    REQUIRE(canreprod==true);
}

#endif
//TODO: TEST CASE N ERROR HANDLING
