#ifndef ANIMALS_H
#define ANIMALS_H

#include <Colonies.h>


class Bagoly : public Colonies
{
    public:
        Bagoly(const std:: string &nev, const char &faj, int Population);
        bool canReproduce (int korszam) override;
        void Reproduce() override;
        virtual ~Bagoly();
    protected:

    private:
};

class Farkas : public Colonies
{
  public:
        Farkas(const std:: string &nev, const char &faj, int Population);
        bool canReproduce (int korszam) override;
        void Reproduce() override;
        virtual ~Farkas();
    protected:

    private:
};


class Roka : public Colonies
{
    public:
        Roka(const std:: string &nev, const char &faj, int Population);
        bool canReproduce (int korszam) override;
        void Reproduce() override;
        virtual ~Roka();
    protected:

    private:
};

///////////////////////Zsakmanyok/////////////////

class Lemming : public Colonies
{
    public:
        Lemming(const std:: string &nev, const char &faj, int Population);
        virtual ~Lemming();
        bool canReproduce (int korszam) override;
        void Reproduce() override;
        bool PopulationNumEdit(int AttackVal, int &dmgvalue) override;
    protected:

    private:
};

class Urge : public Colonies
{
    public:
        Urge(const std:: string &nev, const char &faj, int Population);
        virtual ~Urge();
        bool canReproduce (int korszam) override;
        void Reproduce() override;
        bool PopulationNumEdit(int AttackVal, int &dmgvalue) override;
    protected:

    private:
};

class Nyul : public Colonies
{
    public:
        Nyul(const std:: string &nev, const char &faj, int Population);
        virtual ~Nyul();
        bool canReproduce (int korszam) override;
        void Reproduce() override;
        bool PopulationNumEdit(int AttackVal, int &dmgvalue) override;
    protected:

    private:
};



#endif // ANIMALS_H
