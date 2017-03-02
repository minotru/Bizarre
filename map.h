#ifndef _MAP_H
#define _MAP_H 

#include "common.h"
#include "locations.h"

//TODO, Simon, 02.03.17:add access to nodes from map.

class Map : ISerializable
{   
public:   
    struct Node
    {
        ILocation *location;
        vector<int> edges;
        Node() : location(NULL) {}
        ~Node() {delete location;}
    };

    Map();
    ~Map();
    void read(istream& is);
    void write(ostream& os) const;
    bool areConnected(int l1, int l2) const;
    //Node& getNode(int id);
private:   
    //key - id of the location
    map <int, Node> locations;
};

#endif // _MAP_H