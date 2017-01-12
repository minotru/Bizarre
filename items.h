#ifndef _ITEMS_H
#define _ITEMS_H

struct buff{
	int HP = 0;
	int MP = 0;
	int HPReg = 0;
	int MPReg = 0;
	int armor = 0;		//%
	int magicArmor = 0;	//%
	int evasion = 0;	//%
	int damage = 0;
};

struct Weapon{
	char name[20];
	int basicDamage;
	int durability;
	int slot = 1;
	int space;
};

struct Chest{
	char name[20];
	int basicArmor;
	int durability;
	int slot = 1;
	int space;
};

struct Legs{
	char name[20];
	int basicArmor;
	int durability;
	int slot = 1;
	int space;
};

struct Head{
	char name[20];
	int basicArmor;
	int durability;
	int slot = 1;
	int space;
};

struct Shield{
	char name[20];
	int basicArmor;
	int durability;
	int slot = 1;
	int space;
};

struct Artefact{
	char name[20];
	buff Buff;
	int slot = 1;
	int space;
};

struct Backpack{
	char name[20];
	int slot = 1;
	int capacity;
	int space;
};



#endif