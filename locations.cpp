#include "locations.h"

//=============================================================================
//LocationEmpty
//=============================================================================
void LocationEmpty::read(istream& file)
{
    //empty location, nothing to read 
}

void LocationEmpty::write(ostream& file) const
{
    file << "empty\n";
}

ActionResult LocationEmpty::action(Character& character) 
{
    //empty location, nothing to do
    return AR_NO;
}

//=============================================================================
//LocationHome
//=============================================================================
void LocationHome::read(istream& file)
{
    file >> race;
}

void LocationHome::write(ostream& file) const
{
    file << "home\n" << race << '\n';
}

ActionResult LocationHome::action(Character& character)
{
    
    return AR_NO;
}

//=============================================================================
//LocationShop
//=============================================================================
void LocationShop::read(istream& file)
{
  
}

void LocationShop::write(ostream& file) const
{
    file << "shop\n";
}

ActionResult LocationShop::action(Character& character)
{
    return AR_NO;
}

//=============================================================================
//LocationBattle
//=============================================================================
void LocationBattle::read(istream& file)
{
   
}

void LocationBattle::write(ostream& file) const
{
    file << "battle\n";
}

ActionResult LocationBattle::action(Character& character)
{
    return AR_NO;
}





