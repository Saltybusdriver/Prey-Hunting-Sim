#ifndef COLONIES_H
#define COLONIES_H
#include <string>
#include <ostream>


class Colonies
{
    private:
        static bool _randomized_;
    protected:
        std:: string _Name;
        char _Specie;
        int _Population;
        int _szumrag=0;


    public:

        Colonies(const std::string &nev, const char &faj, int Population);
        std::string nev() const{ return _Name;}
        int Population()
        {
            return _Population;
        }
        void set_Population(int pop)
        {
            _Population=pop;
        }
        int szumrag()
        {
            return _szumrag;
        }

        std::string get_Name()
        {
            return _Name;
        }
        char get_Specie()
        {
            return _Specie;
        }

        void set_szumrag(int r);
        bool isAlive();
        virtual bool PopulationNumEdit(int modosulat, int &dmgvalue);
        virtual bool canReproduce (int korszam);
        virtual void Reproduce();
        bool PopulationNumEdit();
        friend std::ostream &operator<<(std::ostream &os,const Colonies &c)
        {
            os<<c._Name << " " << c._Specie << " ("<<c._Population<<")";
            return os;
        }
        virtual ~Colonies();
};



#endif // Colonies_H
