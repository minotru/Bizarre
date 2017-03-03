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
    virtual ActionResult action(Character& character) = 0;
    virtual ~ILocation() {}
};

class LocationEmpty : public ILocation
{
public:    
    void read(istream& is);
    void write(ostream& os) const;
    ActionResult action(Character& character);
};

class LocationHome : public ILocation
{
public:    
    void read(istream& is);
    void write(ostream& os) const;
    ActionResult action(Character& character);
private:
    string race;
};

class LocationShop : public ILocation
{
public:    
    void read(istream& is);
    void write(ostream& os) const;
    ActionResult action(Character& character);
};

class LocationBattle : public ILocation
{
public:    
    void read(istream& is);
    void write(ostream& os) const;
    ActionResult action(Character& character);
};

#endif // _LOCATIONS_H
