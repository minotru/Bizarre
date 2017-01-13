#include "stdinclude.h"
#include "headerChar.h"
#include "items.h"

using namespace std;

void createChar( Character& pers )
{
		int k;
		cout << "Hi \nPress 1. to start a new game \nPress 2. to load saved options\n";
		cin >> k;
		while ( k<1 || k>2 )
		{
			cout << "Incorrect enter, try again" << endl;
			cin >> k;
		}
		if ( k == 1 )
		{
			cout << "Enter your character's name" << endl;
			cin.ignore();
			cin.getline(pers.name , 20);
			pers.pointsOfSkills = 20;
			selectRace(pers);
			cout << "Now you need to upgrade characteristics\n";
			upgradeCharacteristicsWithPoints( pers );
		}
		else if ( k == 2 )
		{
			char nameOfFile[20];
			cout << "Enter the name of the file\n";
			cin.ignore();
			cin.getline( nameOfFile , 20 );
			ifstream in( nameOfFile );
			in >> pers.name >> pers.race >> pers.stren >> pers.agil >> pers.intel >> pers.pointsOfSkills;
		}

}

void selectRace( Character& pers )
{
		cout << "Select your race \n 1.Human (+Intelligence) \n 2.Orc (+Strength) \n 3.Elf (+Agility)\n";
		int l;
		cin >> l;
		while ( l<1 || l>3 )
		{
			cout << "Incorrect enter, try again" << endl;
			cin >> l;
		}
		if ( l == 1 )
		{
			strcpy( pers.race , "Human" );
			pers.intel += 10;
		}
		if ( l == 2 )
		{
			strcpy( pers.race , "Orc" );
			pers.stren += 10;
		}
		if ( l == 3 )
		{
			strcpy( pers.race , "Elf" );
			pers.agil += 10;
		}
}


void upgradeCharacteristicsWithPoints( Character& pers )
{
	while ( true )
	{
		if ( pers.pointsOfSkills )
		{
			int k;
			cout << "You have " << pers.pointsOfSkills << " points of skills.\n";
			cout << "What characteristic do you want to up?\n 1.Strength \n 2.Agility \n 3.Intelligence\n 0.Exit\n";
			cin >> k;
			if ( k == 1 || k == 2 || k == 3 )
			{
				int p;
				cout << "How many points?\n";
				cin >> p;
				if ( p >= pers.pointsOfSkills )
                    cout << "Not enough points!\n";
				else
				{
					if ( k == 1 )
					{
						pers.stren += p;
						pers.pointsOfSkills -= p;
					}
					else if ( k == 2 )
					{
						pers.agil += p;
						pers.pointsOfSkills -= p;
					}
					else if ( k == 3 )
					{
						pers.intel += p;
						pers.pointsOfSkills -= p;
					}
                    cout << "Done.\n";
                    // << pers.pointsOfSkills << " points left\n";
				}

			}
			else if ( k == 0 )
			{
				cout << "Returning back to the menu\n";
				break;
			}
			else
			{
				cout << "Wrong, try again\n";
				continue;
			}
		}
		else
		{
			cout << "You have no points, returning back to the menu\n";
			break;
		}
	}
}


void saveCharacterInfo( Character& pers )
{
	ofstream out( "Character.txt" );
	out << pers.name << ' ' << pers.race << ' ' << pers.stren << ' '
	<< pers.agil << ' ' << pers.intel << ' ' << pers.pointsOfSkills;
	out.close();
}

//_________________________________________________________________________________________________________________________________________________________

int HP( Character pers )
{
	int HP = pers.stren * 20;
	if ( pers.artefact.buff.HP )
		HP += pers.artefact.buff.HP;
	return HP;
}

int HPRegen(const Character& pers )
{
	int reg = pers.stren;
	if ( pers.artefact.buff.HPReg )
		reg += pers.artefact.buff.HPReg;
	return reg;
}

int MP(const Character& pers )
{
	int MP = pers.stren * 10;
	if ( pers.artefact.buff.MP )
		MP += pers.artefact.buff.MP;
	return MP;
}

int MPRegen(const Character& pers )
{
	int reg = pers.intel;
	if ( pers.artefact.buff.MPReg )
		reg += pers.artefact.buff.MPReg;
	return reg;
}
