/*Disjoint set cpp*/
#include "DisjointSet.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

/**Items and sizes are initialized to number of nodes plus one.
 * Each index is initially set to -1 (sentinel). This disjoint set is NOT applicable
 * for general use. It is assumed that all of indices of the vector 
 * correspond to and actual node in the dataset. Even if the node isn't
 * in the dataset, this won't matter with respect to building the mst since
 * union will never be called on nodes that don't exist in the dataset.
 * For general use, this class can be somewhat easily modified.
 */
DisjointSet::DisjointSet(int numItems){
    items = vector<int>(numItems+1, -1);
    sizes = vector<int>(numItems+1, 1);
}

DisjointSet::~DisjointSet(){}

int DisjointSet::ds_find(int item){
    if(item>items.size()) return -2; //item doesn't exist in set
    if(items[item]==-1) return item; //item is a sentinel node
    vector <int> v;
    int temp = item;
    //Keeps track of which nodes are children of a specific sentinel
    while(items[temp] != -1){
        v.push_back(temp);
        temp = items[temp];
    }
    //Implements path compression using the data from the previous loop
    for(unsigned i=0; i<v.size()-1; i++){
        items[v[i]] = temp;
    }
    return temp;
}

bool DisjointSet::ds_union(int item1, int item2){
    int sentinel1 = DisjointSet::ds_find(item1); 
    int sentinel2 = DisjointSet::ds_find(item2);
    //Returns false if either of the items are not in the disjoint set or if they share the
    //same sentinel node
    if(sentinel1==sentinel2 || sentinel1==-2 || sentinel2==-2) return false;
    int size1 = sizes[sentinel1]; //Size of item1's subset
    int size2 = sizes[sentinel2]; //Size of item2's ubset
    //Union by size
    if(size1<size2){
        items[sentinel1] = sentinel2;
        sizes[sentinel1] = size2+size1;
    } 
    else{
        items[sentinel2] = sentinel1;
        sizes[sentinel2] = size1+size2;
    }
    return true;
}