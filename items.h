#ifndef _ITEMS_H
#define _ITEMS_H
#include "common.h"
enum typeOfItem { armor , weapon , item };
static int ID = 0;

class Item
{
public:
    string name;
	int space;
    typeOfItem type;

	Item():name(""),space(0){}
	Item( string _name, int _space,typeOfItem _type ):name(_name),space(_space),type(_type){}

    virtual void showStats ()
    {
        cout << "Name: " << name << endl << "Space required: " << space << endl;
    }
    virtual ~Item ();
    //virtual bool isBroken ();
};

class WearableItem : public Item
{
protected:
    int durability;
    int maxDurability;

    WearableItem ( string _name , int _space , typeOfItem _type , int _durability, int _maxDurability ) 
        :Item(_name,_space,_type),durability(_durability),maxDurability(_maxDurability) {}
public:
    void showStats ()
    {
        cout << "Name: " << name << endl << "Type: " << type << endl << "Space required: " << space << endl 
            << "Max. Durability: " << maxDurability << endl << "Durability: " << durability << endl;
    }
    virtual bool isBroken ()
    {
        if ( durability <= 0 ) return true;
        else return false;
    }
    
};

class Armor : public WearableItem
{
protected:
    int basicArmor;
public:

    Armor ( string _name , int _space , typeOfItem _type , int _durability , int _maxDurability , int bA ) 
        :WearableItem ( _name , _space , _type , _durability , _maxDurability ) , basicArmor ( bA ) {}


    void showStats ()
    {
        cout << "Name: " << name << endl << "Type: " << type << endl << "Armor: " << basicArmor << endl << "Space required: " << space << endl
            << "Max. Durability: " << maxDurability << endl << "Durability: " << durability << endl;
    }
    virtual bool isBroken ()
    {
        if ( durability <= 0 ) return true;
        else return false;
    }
};

class Weapon : public WearableItem
{
protected:
    int basicDamage;
public:
    Weapon ( string _name , int _space , typeOfItem _type , int _durability , int _maxDurability , int bD ) 
        :WearableItem ( _name , _space , _type , _durability , _maxDurability ) , basicDamage ( bD ) {}

    void showStats ()
    {
        cout << "Name: " << name << endl << "Type: " << type << endl << "Damage: " << basicDamage << endl << "Space required: " << space << endl
            << "Max. Durability: " << maxDurability << endl << "Durability: " << durability << endl;
    }

    virtual bool isBroken ()
    {
        if ( durability <= 0 ) return true;
        else return false;
    }
};

class field
{
    Item* value;
    static int ID;
public:

    field ()
    {
        value = nullptr;
        ID++;
    }

    ~field ()
    {
        delete value;
    }

    void setValue ( Item _item )
    {
        value = new Item( _item );
    }
    void setValue ( Weapon _item )
    {
        value = new Weapon( _item );
    }
    void setValue ( Armor _item )
    {
        value = new Armor( _item );
    }

    Item* getValue ()
    {
        
    }
};

class Bag : public Item
{
public:
    
};




#endif