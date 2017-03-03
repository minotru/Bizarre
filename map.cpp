#include "map.h"
//#include "stdinclude.h"

Map::Map()
{
    
}

/*
Map file format is the following:
<locationsNumber>
<locationId> <edgesNumber>
<edgeToVertex> <edgeToVertex>...
<locationType>
<locationInfo>
.
.
.
*/
void Map::read(istream& file)
{ 
    int locationsNumber;
    file >> locationsNumber;
    for (int i = 0; i < locationsNumber; i++)
    {
        string type;
        int id, edgesNumber;
        file >> id >> edgesNumber;
        for (int i = 0; i < edgesNumber; i++)
        {
            int v;
            file >> v;
            locations[id].edges.push_back(v);
        }
        file >> type;
        if (type == "home")
            locations[id].location = new LocationHome;
        else if (type =="shop")
            locations[id].location = new LocationShop;
        else if (type == "battle")  
            locations[id].location  = new LocationBattle;
        else if (type == "empty")
            locations[id].location = new LocationEmpty;
        else
            throw std::exception("Map::read. Unknow type of the location.");
        locations[id].location->read(file);
    }
}

void Map::write(ostream& file) const
{
    file << locations.size() << endl;
    for (auto it = locations.begin(); it != locations.end(); it++)
    { 
        file << it->first << ' ' << it->second.edges.size() << endl;
        for (int i = 0; i < it->second.edges.size(); i++)
            file << it->second.edges[i] << ' ';
        file << endl;
        it->second.location->write(file);
    }
}

bool Map::areConnected(int l1, int l2) const
{
    //try
    //{
        const vector<int>& edges = locations.at(l1).edges;
    //}
    //catch (std::exception& e)
    //{
      //  throw std::exception("Map::areConnected. Not existing id.");
    //}
    return find(edges.begin(), edges.end(), l2) != edges.end();
}

Map::~Map()
{
    
}