#ifndef MST_HPP
#define MST_HPP

#include "Edge.hpp"
#include "DisjointSet.hpp"

#include <iostream>
#include <queue>

using namespace std;


class EdgePtrComp {
public:
    bool operator()(Edge*& lhs, Edge*& rhs) const {
        return *lhs < *rhs;
    }
};

class MST{
protected:
int numnodes;
priority_queue<Edge*, vector<Edge*>, EdgePtrComp>* pq;
public:
MST(void);
~MST(void);
bool loadFromFile(const char* in_filename);
void addEdge(vector<string> edgeinfo);
void mstbuild(ofstream& out_file);
void setNumnodes(int n);
int getNumnodes();
bool printToFile(const char* out_filename);
};
#endif