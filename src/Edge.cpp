#include "Edge.hpp"

Edge::Edge(int id, float weight, int node1, int node2) : id(id), weight(weight), node1(node1), node2(node2){}

Edge::~Edge(){}

vector<int> Edge::getNode_pair(){
    return vector<int>{node1, node2};
}

int Edge::getid(){
    return id;
}

float Edge::getWeight(){
    return weight;
}

bool Edge::operator<(const Edge& other) {
    if(this->weight != other.weight) return this->weight>other.weight;
    return this->id>other.id;
}