#ifndef _CHARACTER_H
#define _CHARACTER_H
#include "items.h"

struct Character{
	char name[20];
	int stren;
	int agil;
	int intel;
	char race[8];
	Weapon weapon;
	Shield shield;
	Legs pants;
	Chest Body;
	int pointsOfSkills;
	Artefact artefact;
	Backpack backpack;

    Character()
    {
        stren = 0;
        agil = 0;
        intel = 0;
    }
};

void createChar( Character& pers );

void selectRace( Character& pers );

void upgradeCharacteristicsWithPoints( Character& pers );

void saveCharacterInfo( Character& pers );

#endif
