#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "headerChar.h"
#include "items.h"

using namespace std;

int main()
{
	Character MainOne;
	createChar( MainOne );
	saveCharacterInfo( MainOne );


	system( "pause" );
	return 0;
}