#ifndef NODE_HPP
#define NODE_HPP
#include<vector>
#include<iostream>
using namespace std;

/*  Node class containg the following fields
    int id: Facebook id of a person
    bool isVisited: To check whether the node has been visited or not
    vector<int> friends: Contains friend id's corresponding to the Node
    vector<int> edges: Contains edge weights at indices corresponding to the indices of nodes in friends
    Node* prev: Pointer to the previous node
    int degree: Node's initial degree in graph
    int initial_degree: Node's degree after any changes have been made to graph structure
*/
class Node{
    protected:
        int id;
        bool isVisited;
        vector<int> friends;
        vector<float> edges;
        Node* prev;
        int degree;
        int initial_degree;

    public:
        Node(int id); // Constructor
        ~Node(void); // Destructor

        //Getters and setters
        int getId();
        bool getIsVisisted();
        void setVisited(bool isVisited);
        vector<int>* getFriends();
        void addFriend(int n);
        vector<float>* getEdges();
        void addEdge(float e);
        Node* getPrev();
        void setPrev(Node* n);
        void incrementDegree();
        void decrementDegree();
        int getDegree();
        void setDegree(int d);
        void increment_initialDegree();
        int get_initialDegree();

        //Overload < operator for use in priority queue comparisons
        bool operator<(const Node& other);
};


#endif