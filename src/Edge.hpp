#ifndef EDGE_HPP
#define EDGE_HPP

using namespace std;

class Edge{
protected:
    int id;
    float weight;
    int node1;
    int node2;

public:
    Edge(int id, float weight, int node1, int node2);
    ~Edge();
    bool operator<(const Edge& other);
};
#endif