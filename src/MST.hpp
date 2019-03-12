#ifndef MST_HPP
#define MST_HPP

#include "Edge.hpp"
#include "DisjointSet.hpp"
#include "Node.hpp"

#include <iostream>
#include <queue>

using namespace std;

class MST{
public:
bool loadFromFile(const char* in_filename);
bool printToFile(const char* out_filename);
};
#endif