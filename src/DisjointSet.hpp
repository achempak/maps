#ifndef DISJOINTSET_HPP
#define DISJOINTSET_HPP
#include <vector>

using namespace std;

class DisjointSet{
protected:
    vector<int> items, sizes;

public:
    DisjointSet(int numItems);
    ~DisjointSet();
    int ds_find(int item);
    bool ds_union(int item1, int item2);    
};
#endif