#include "character.h"
#include "map.h"
#include "items.h"
#include "stdinclude.h"

using namespace std;

int main()
{
    Map map;
    map.read(ifstream("map_in.txt"));
   // Character MainOne;
    //createCharacter( MainOne );
    //saveCharacterInfo( MainOne );
    map.write(ofstream("map_out.txt"));
    system( "pause" );
    return 0;
}