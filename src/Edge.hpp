#ifndef EDGE_HPP
#define EDGE_HPP

#include <vector>
using namespace std;

class Edge{
protected:
    int id;
    float weight;
    int node1;
    int node2;

public:
    Edge(int id, int node1, int node2, float weight);
    ~Edge();
    vector<int> getNode_pair();
    int getid();
    float getWeight();
    bool operator<(const Edge& other);
};
#endif