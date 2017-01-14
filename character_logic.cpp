#include "character.h"

Character::Character(int _stren, int _agil, int _intel)
{
    stren = _stren;
    agil = _agil;
    intel = _intel;
}

int Character::HP()
{
    int HP = stren * 20;
    if (artefact.buff.HP)
        HP += artefact.buff.HP;
    return HP;
}

int Character::HPRegen()
{
    int reg = stren;
    if (artefact.buff.HPReg)
        reg += artefact.buff.HPReg;
    return reg;
}

int Character::MP()
{
    int MP = stren * 10;
    if (artefact.buff.MP)
        MP += artefact.buff.MP;
    return MP;
}

int Character::MPRegen()
{
    int reg = intel;
    if (artefact.buff.MPReg)
        reg += artefact.buff.MPReg;
    return reg;
}

int Character::armor()
{
    int armor = 0.4*agil + 0.7*stren;
    armor /= 5;
    if (artefact.buff.armor)
        armor += artefact.buff.armor;
    return armor;
}

int Character::magicArmor()
{
    int armor = intel;
    armor /= 5;
    if (artefact.buff.magicArmor)
        armor += artefact.buff.magicArmor;
    return armor;
}

int Character::evasion()
{
    int evas = 0.8*agil + 0.2*intel;
    evas /= 5;
    if (artefact.buff.evasion)
        evas += artefact.buff.evasion;
    evas /= 5;
    return evas;
}