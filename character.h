#ifndef _CHARACTER_H
#define _CHARACTER_H
#include "items.h"

struct Character{
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
};

void createCharacter( Character& pers );

void selectRace( Character& pers );

void upgradeCharacteristicsWithPoints( Character& pers );

void saveCharacterInfo(const Character& pers );

#endif
