/*Edge hpp*/
#ifndef EDGE_HPP
#define EDGE_HPP

#include <vector>
using namespace std;

/*  Edge class containg the following fields
    int id: edge id
    float weight: edge weight
    int node1: node at one side of the edge
    int node2: node at other side of the edge
*/
class Edge{
protected:
    int id;
    float weight;
    int node1;
    int node2;

public:
    Edge(int id, int node1, int node2, float weight);
    ~Edge();

    //Getters and setters
    vector<int> getNode_pair();
    int getid();
    float getWeight();
    //Overloading less than operator for use in priority queue
    bool operator<(const Edge& other);
};
#endif