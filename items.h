#ifndef _ITEMS_H
#define _ITEMS_H

struct buff{
	int HP = 0;
	int MP = 0;
	int HPreg = 0;
	int MPreg = 0;
	int armor = 0;		//%
	int magicArmor = 0;	//%
	int evasion = 0;	//%
	int damage = 0;
};

struct weapon{
	char name[20];
	int basicDamage;
	int durability;
	int slot = 1;
	int space;
};

struct chest{
	char name[20];
	int basicArmor;
	int durability;
	int slot = 1;
	int space;
};

struct legs{
	char name[20];
	int basicArmor;
	int durability;
	int slot = 1;
	int space;
};

struct head{
	char name[20];
	int basicArmor;
	int durability;
	int slot = 1;
	int space;
};

struct shield{
	char name[20];
	int basicArmor;
	int durability;
	int slot = 1;
	int space;
};

struct artefact{
	char name[20];
	buff Buff;
	int slot = 1;
	int space;
};

struct backpack{
	char name[20];
	int slot = 1;
	int capacity;
	int space;
};



#endif