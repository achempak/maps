/*MST hpp*/
#ifndef MST_HPP
#define MST_HPP

#include "Edge.hpp"
#include "DisjointSet.hpp"
#include <iostream>
#include <queue>

using namespace std;

/*  
    Class used to define operator for use in priority queue edge comparisons
*/
class EdgePtrComp {
public:
    bool operator()(Edge*& lhs, Edge*& rhs) const {
        return *lhs < *rhs;
    }
};

/*
    MST class with two fields.
    int numnodes: number of nodes in MST
    priority_queue<Edge*, vector<Edge*>, EdgePtrComp>* pq: priority queue of edges in MST
*/
class MST{
protected:
int numnodes;
priority_queue<Edge*, vector<Edge*>, EdgePtrComp>* pq;

public:
MST(void);
~MST(void);
//loads data from file into priority queue
bool loadFromFile(const char* in_filename);
//adds edge to priority queue
void addEdge(vector<string> edgeinfo);
//builds mst using disjoint set of nodes and pq
void mstbuild(ofstream& out_file);
//getter and setter to modify numnodes field
void setNumnodes(int n);
int getNumnodes();
//prints final mst to out_filename
bool printToFile(const char* out_filename);
};
#endif