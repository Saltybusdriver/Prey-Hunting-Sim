#include "Animals.h"
#include "iostream"
//Bagoly
Bagoly::Bagoly(const std:: string &nev, const char &faj, int Population):Colonies::Colonies(nev,faj,Population){};

bool Bagoly::canReproduce(int korszam)
{
    return korszam % 8 == 0;
}
void Bagoly::Reproduce()
{
    _Population *= 1.25;
}
Bagoly::~Bagoly()
{
    //dtor
}

//Farkas
Farkas::Farkas(const std:: string &nev, const char &faj, int Population):Colonies::Colonies(nev,faj,Population){};

bool Farkas::canReproduce(int korszam)
{
    return korszam % 8 == 0;
}
void Farkas::Reproduce()
{
    _Population *= 1.5;
}
Farkas::~Farkas()
{
    //dtor
}

//Roka
Roka::Roka(const std:: string &nev, const char &faj, int Population):Colonies::Colonies(nev,faj,Population){};

bool Roka::canReproduce(int korszam)
{
    return korszam % 8 == 0;
}
void Roka::Reproduce()
{
    _Population *= 1.75;
}
Roka::~Roka()
{
    //dtor
}

//////////////////////////////////////////Zsakmanyok///////////////////////

Lemming::Lemming(const std:: string &nev, const char &faj, int Population):Colonies::Colonies(nev,faj,Population){};
bool Lemming::canReproduce(int korszam)
{
    return korszam % 2 == 0;
}
void Lemming::Reproduce()
{
    _Population *= 2;
    if (_Population > 200) _Population = 30;
}
bool Lemming::PopulationNumEdit(int AttackVal, int &dmgvalue)
{

        _Population -= (AttackVal * 4);
       dmgvalue=AttackVal*4;
        if (_Population <= 0)
        {
            _Population = 0;

            return true;
        }

        return false;
}
Lemming::~Lemming()
{
    //dtor
}

//Urge

Urge::Urge(const std:: string &nev, const char &faj, int Population):Colonies::Colonies(nev,faj,Population){};
bool Urge::canReproduce(int korszam)
{
    return korszam % 4 == 0;
}
void Urge::Reproduce()
{
    _Population *= 2;
    if (_Population > 200) _Population = 30;
}
bool Urge::PopulationNumEdit(int AttackVal, int &dmgvalue)
{

        _Population -= (AttackVal * 2);
    dmgvalue=AttackVal*2;
        if (_Population <= 0)
        {
            _Population = 0;

            return true;
        }

        return false;
}
Urge::~Urge()
{
    //dtor
}

//Nyul
Nyul::Nyul(const std:: string &nev, const char &faj, int Population):Colonies::Colonies(nev,faj,Population){};
bool Nyul::canReproduce(int korszam)
{
    return korszam % 2 == 0;
}
void Nyul::Reproduce()
{
    _Population *= 1.5;
    if (_Population > 100) _Population = 20;
}
bool Nyul::PopulationNumEdit(int AttackVal, int &dmgvalue)
{

        _Population -= (AttackVal * 2);
        dmgvalue=AttackVal*2;
        if (_Population <= 0)
        {
            _Population = 0;

            return true;
        }
        return false;
}
Nyul::~Nyul()
{
    //dtor
}



