#ifndef _CHARACTER_H
#define _CHARACTER_H
#include "common.h"
#include "items.h"

/*struct Character{
	char name[20];
	int stren;
	int agil;
	int intel;
	char race[8];
    int pointsOfSkills;
	Weapon weapon;
    WearableItem shield, pants, body;
	Artefact artefact;
	Backpack backpack;

    Character(int _stren = 5, int _agil = 5, int _intel = 5);

    int HP();
    int HPRegen();
    int MP();
    int MPRegen();
    int armor();
    int magicArmor();
    int evasion();
};*/

class Creature
{
public:
    string name;
    int stren;
    int agil;
    int intel;
    

    Creature ()
    {
        stren = 5;
        agil = 5;
        intel = 5;
    }

    Creature ( int _stren , int _agil , int _intel )
    {
        stren = _stren;
        agil = _agil;
        intel = _intel;
    }

    int HP ();
    int HPRegen ();
    int MP ();
    int MPRegen ();
    int armor ();
    int magicArmor ();
    int evasion ();
};

class Hero : public Creature
{
public:
    string race;
    int pointsOfSkills;

};

void createCharacter( Hero& pers );

void selectRace( Hero& pers );

void upgradeCharacteristicsWithPoints( Hero& pers );

void saveCharacterInfo(const Hero& pers );

#endif
