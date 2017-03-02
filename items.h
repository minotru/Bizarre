#ifndef _ITEMS_H
#define _ITEMS_H

struct Buff{
    int HP;
    int MP;
    int HPReg;
    int MPReg;
    int armor;
    int magicArmor;
    int evasion;
    int damage;

    Buff(){
        HP = MP = HPReg = MPReg = armor = magicArmor = evasion = damage = 0;
    }
};

struct Item{
    char name[20];
    int slot;
    int space;

    Item(){
        slot = 1;
    }
};

struct WearableItem : Item
{
    int basicDamage;
    int durability;
};

struct Weapon : Item
{
    int basicDamage;
};

struct Artefact : Item
{
    Buff buff;
};

struct Backpack{
    int capacity;
};

#endif