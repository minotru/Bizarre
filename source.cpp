#include "character.h"
#include "items.h"
#include "stdinclude.h"

using namespace std;

int main()
{
	Character MainOne;
	createCharacter( MainOne );
	saveCharacterInfo( MainOne );

	system( "pause" );
	return 0;
}
