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
	Buff buff;
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
