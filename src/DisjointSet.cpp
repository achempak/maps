#include "DisjointSet.hpp"
#include <queue>

DisjointSet::DisjointSet(int numItems){
    items = vector<int>(numItems, -1);
    sizes = vector<int>(numItems, 1);
}

DisjointSet::~DisjointSet(){}

int DisjointSet::ds_find(int item){
    if(items[item]==-1) return item;
    vector <int> v;
    int temp = item;
    while(items[temp] != -1){
        v.push_back(temp);
        temp = items[temp];
    }

    for(int i=0; i<v.size()-1; i++){
        items[v[i]] = temp;
    }
    return temp;
}

void DisjointSet::ds_union(int item1, int item2){
    int sentinel1 = DisjointSet::ds_find(item1);
    int sentinel2 = DisjointSet::ds_find(item2);
    if(sentinel1 == sentinel2) return;
    int size1 = sizes[sentinel1];
    int size2 = sizes[sentinel2];
    if(size1<size2){
        items[sentinel1] = sentinel2;
        sizes[sentinel1] = size2+size1;
    } 
    else{
        items[sentinel2] = sentinel1;
        sizes[sentinel2] = size1+size2;
    }
}