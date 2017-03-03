#include "character.h"

int Creature::HP ()
{
    int HP = stren * 20;
    return HP;
}

int Creature::HPRegen ()
{
    int reg = stren;
    return reg;
}
int Creature::MP ()
{
    int MP = stren * 10;
    return MP;
}

int Creature::MPRegen ()
{
    int reg = intel;
    return reg;
}

int Creature::armor ()
{
    int armor = 0.4*agil + 0.7*stren;
    armor /= 5;
    return armor;
}

int Creature::magicArmor ()
{
    int armor = intel;
    armor /= 5;
    return armor;
}

int Creature::evasion ()
{
    int evas = 0.8*agil + 0.2*intel;
    evas /= 5;
    evas /= 5;
    return evas;
}