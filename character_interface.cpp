#include "stdinclude.h"
#include "character.h"
#include "items.h"

void createCharacter( Character& pers )
{
    int k;
    cout << "Hi \nPress 1. to start a new game \nPress 2. to load saved parametres\n";
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
        cin.getline( pers.name , 20 );
        pers.pointsOfSkills = 20;
        selectRace( pers );
        cout << "Now you need to upgrade characteristics\n";
        upgradeCharacteristicsWithPoints( pers );
    }
    else if ( k == 2 )
    {
        bool wellRead = false;
        char nameOfFile[20];
        int time = 0;
        do
        {
            cout << "Enter your character's name\n";
            if (time == 0)
                cin.ignore();
            cin.getline( nameOfFile , 20 );
            //cout << nameOfFile << '#' << endl;
            strcat(nameOfFile, ".txt");
            ifstream in( nameOfFile );
            if (in.is_open()) //file exists
            {    
                in >> pers.name >> pers.race >> pers.stren >> pers.agil 
                   >> pers.intel >> pers.pointsOfSkills;
                wellRead = true;
            }
            else
                cout << "Error, no such saved name. Try again.\n";
            time++;
        } while (!wellRead);
        cout << "Loaded.\n";
    }
}

void selectRace( Character& pers )
{
    cout << "Select your race\n"
        "1.Human (+Intelligence)\n2.Orc (+Strength)\n3.Elf (+Agility)\n";
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
    int k=1;
    while (pers.pointsOfSkills>0 && k!=0)
    {
        cout << "You have " << pers.pointsOfSkills << " points of skills.\n";
        cout << "What characteristic do you want to up?\n"
                "1.Strength \n2.Agility \n3.Intelligence\n0.Exit\n";
        cin >> k;
        if ( k >= 1 && k <= 3 )
        {
            int p;
            cout << "How many points?\n";
            cin >> p;
            if ( p > pers.pointsOfSkills )
                cout << "Not enough points!\n";
            else
            {
                switch (k)
                {
                case 1:
                    pers.stren += p;
                    break;
                case 2:
                    pers.agil += p;
                    break;
                case 3:
                    pers.intel += p;
                    break;
                default:
                    break;
                }
                pers.pointsOfSkills -= p;
                cout << "Done.\n";
                // << pers.pointsOfSkills << " points left\n";
            }

        }
        else
            switch (k)
            {
            case 0:
                cout << "Returning back to the menu\n";
                break;
            default:
                cout << "Wrong, try again\n";
                break;
            }
    }
    if (!pers.pointsOfSkills)
    {
        cout << "You have no points, returning back to the menu\n";
    }
}

void saveCharacterInfo(const Character& pers )
{
    char fileName[80];
    strcpy(fileName, pers.name);
    strcat(fileName, ".txt");
    ofstream out(fileName);
    out << pers.name << ' ' << pers.race << ' ' << pers.stren << ' '
        << pers.agil << ' ' << pers.intel << ' ' << pers.pointsOfSkills;
    out.close();
}
