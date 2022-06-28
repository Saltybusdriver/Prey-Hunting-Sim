#include "Colonies.h"
#include "iostream"
Colonies::Colonies(const std:: string &nev, const char &faj, int Population):_Name(nev), _Specie(faj), _Population(Population) { };

void Colonies::set_szumrag(int r)
{
    _szumrag += r;
}
bool Colonies::PopulationNumEdit(int NumbAttack, int &dmgvalue)
{
    _Population -= NumbAttack;
}
bool Colonies::canReproduce (int korszam)
{
    return korszam % 2 == 0;
}
bool Colonies::isAlive()
{
    return _Population > 0;
}
void Colonies::Reproduce()
{
    _Population *= 1.5;
}
bool Colonies::PopulationNumEdit()
{
    _Population *= 0.75;
    if (_Population <= 0)
    {
        _Population = 0;
        return true;
    }
    return false;
}
Colonies::~Colonies()
{
    //dtor
}
