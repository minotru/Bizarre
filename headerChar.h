#ifndef _CHARACTER_H
#define _CHARACTER_H
#include "items.h"

struct Character{
	char name[20];
	int stren = 0;
	int agil = 0;
	int intel = 0;
	char race[8];
	Weapon weapon;
	Shield shield;
	Legs pants;
	Chest Body;
	int pointsOfSkills;
	Artefact artefact;
	Backpack backpack;

};

void createChar( Character& pers );

void selectRace( Character& pers );

void upgradeCharacteristicsWithPoints( Character& pers );

void saveCharacterInfo( Character& pers );

#endif