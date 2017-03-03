#ifndef _ITEMS_H
#define _ITEMS_H
#include "common.h"

class Item
{
public:
    string name;
	int space;

	Item()
	{
        name.assign ( "" );
        space = 0;
	}

	Item( string _name, int _space )
	{
        name.assign ( _name );
		space = _space;
	}

    virtual void showStats ()
    {
        cout << "Name: " << name << endl << "Space required: " << space << endl;
    }
};

class WearableItem : public Item
{
public:
    char type;              //type: a || w || i
    int durability;
    bool slot;
    int maxDurability;
   
    void showStats ()
    {
        cout << "Name: " << name << endl << "Type: " << type << endl << "Space required: " << space << endl 
            << "Max. Durability: " << maxDurability << endl << "Durability: " << durability << endl;
    }
};

class Armor : public WearableItem
{
public:
	int basicArmor;
    Armor ( string _name , int bA , int _space , int dur , int maxDur , char _type )
    {
        name.assign ( _name );
        space = _space;
        type = _type;
        basicArmor = bA;
        durability = dur;
        maxDurability = maxDur;
    }
    void showStats ()
    {
        cout << "Name: " << name << endl << "Type: " << type << endl  << "Armor: " << basicArmor << endl << "Space required: " << space << endl
            << "Max. Durability: " << maxDurability << endl << "Durability: " << durability << endl;
    }
};

class Weapon : public WearableItem
{
public:
    int basicDamage;
    Weapon ( string _name , int bD , int _space , int dur , int maxDur )
    {
        name.assign ( _name );
        space = _space;
        basicDamage = bD;
        durability = dur;
        maxDurability = maxDur;
    }
    void showStats ()
    {
        cout << "Name: " << name << endl << "Type: " << type << endl << "Damage: " << basicDamage << endl << "Space required: " << space << endl
            << "Max. Durability: " << maxDurability << endl << "Durability: " << durability << endl;
    }
};

class Backpack : public Item
{
public:
    
};




#endif