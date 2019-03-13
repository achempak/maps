#include "Node.hpp"
#include <vector>
#include <iostream>

Node::Node(int id) : id(id), isVisited(0), prev(0), degree(0), initial_degree(0){
    friends = vector<int>(0);
    edges = vector<float>(0);
}

Node::~Node(void){}

int Node::getId(){
    return id;
}

bool Node::getIsVisisted(){
    return isVisited;
}

void Node::setVisited(bool v){
    isVisited = v;
}

vector<int>* Node::getFriends(){
    return &friends;
}

void Node::addFriend(int n){
    friends.push_back(n);
}

void Node::addEdge(float e){
    edges.push_back(e);
}

vector<float>* Node::getEdges(){
    return &edges;
}

Node* Node::getPrev(){
    return prev;
}

void Node::setPrev(Node* n){
    prev = n;
}

void Node::incrementDegree(){
    degree++;
}

void Node::decrementDegree(){
    degree--;
}

int Node :: getDegree(){
    return degree;
}

void Node::setDegree(int d){
    degree = d;
}

void Node::increment_initialDegree(){
    initial_degree++;
}

int Node::get_initialDegree(){
    return initial_degree;
}


bool Node::operator<(const Node& other) {
    if(this->degree != other.degree) return this->degree>other.degree;
    return this->id>other.id;
}