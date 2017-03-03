#ifndef  _LOCATIONS_H
#define  _LOCATIONS_H

#include "common.h"
#include "character.h"

enum ActionResult 
{
    AR_NO,
    AR_CHARACTER_KILLED, 
    AR_MOBS_KILLED,
};

class ILocation : public ISerializable
{
public:
    virtual ActionResult action(Hero& character) = 0;
    virtual ~ILocation() {}
};

class LocationEmpty : public ILocation
{
public:    
    void read(istream& is);
    void write(ostream& os) const;
    ActionResult action(Hero& character);
};

class LocationHome : public ILocation
{
public:    
    void read(istream& is);
    void write(ostream& os) const;
    ActionResult action(Hero& character);
private:
    string race;
};

class LocationShop : public ILocation
{
public:    
    void read(istream& is);
    void write(ostream& os) const;
    ActionResult action(Hero& character);
};

class LocationBattle : public ILocation
{
public:    
    void read(istream& is);
    void write(ostream& os) const;
    ActionResult action(Hero& character);
};

#endif // _LOCATIONS_H
