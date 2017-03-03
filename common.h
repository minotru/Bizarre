#ifndef _COMMON_H
#define _COMMON_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stdexcept>

using namespace std;

class ISerializable
{
public:
    virtual void read(istream&) = 0;
    virtual void write(ostream& os) const = 0;
};

#endif //_COMMON_H
