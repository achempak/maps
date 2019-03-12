// Header file for node class
#ifndef NODE_HPP
#define NODE_HPP
#include<vector>
#include<iostream>
using namespace std;

/*  Node class containg the following fields
    int id : Facebook id of a person
    bool isVisited : To check whether the node has been visited or not
    vector<int> friends : Contains friend id's corresponding to the Node
    Node* prev : Pointer to the previous node
*/
class Node{
    protected:
        int id;
        bool isVisited;
        vector<int> friends;
        Node* prev;
        int degree;
        int initial_degree;

    public:
        Node(int id); // Constructor
        ~Node(void); // Destructor

        int getId();
        bool getIsVisisted();
        void setVisited(bool isVisited);
        vector<int>* getFriends();
        void addFriend(int n);
        void removeFriend(Node n);
        Node* getPrev();
        void setPrev(Node* n);
        void incrementDegree();
        void decrementDegree();
        int getDegree();
        void setDegree(int d);
        void increment_initialDegree();
        int get_initialDegree();

        bool operator<(const Node& other);
};


#endif