/*Disjoint set hpp*/
#ifndef DISJOINTSET_HPP
#define DISJOINTSET_HPP
#include <vector>

using namespace std;

/**
 * Disjoint set class containing the following fields:
 * vector<int> items: vector of nodes, where each node is represented by an index
 * vector<int> sizes: size of subset of sentinel nodes. ONLY indices corresponding
 *                    to sentinel nodes are guaranteed to contain correct subset sizes.
 */
class DisjointSet{
protected:
    vector<int> items, sizes;

public:
    DisjointSet(int numItems);
    ~DisjointSet();
    //Finds item in the disjoint set. Utilizes path compression.
    //Returns index of sentinel node for subset that item is in.
    int ds_find(int item);
    //Combines to subsets. Utilizes union by size.
    //Returns true if union was successful.
    bool ds_union(int item1, int item2);    
};
#endif