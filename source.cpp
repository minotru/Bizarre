#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include "headerChar.h"
#include "items.h"
#include <cstdlib>

using namespace std;

int main()
{
	Character MainOne;
	createChar( MainOne );
	saveCharacterInfo( MainOne );


	system( "pause" );
	return 0;
}
