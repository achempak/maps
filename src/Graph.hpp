#ifndef GRAPH_HPP
#define GRAPH_HPP
#include "Node.hpp"
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Graph {
 protected:
  /*Data Structure : Hash Map with Key as the "ids" and values as the pointer to the obeject (Node)*/
  unordered_map<int, Node*>* graph; // pointer to the hash map

 public:
  Graph(void); //Constructor

  ~Graph(void); // Destructor

  /* Read in relationships from an input file to create a graph */
  bool loadFromFile(const char* in_filename);

  /* Reinitializes prev to nullptr and isVisited to false.
  Called whenever shortestPath is called.
  */
  void reinitialize();

  /*Add friend-pair (id1 , id2) into the hashmap
    vector<string> idNumber: vector containing ids of friend Nodes
    idNumbers[0]=id1
    idNumbers[1]=id2
  */
  void addNode(vector<string> idNumbers); 

  /*Finds whether a path between two nodes exists or not
    Return true if a path does exist. Else, return false.
  */
  bool pathfinder(int from, int to);

  /* Reads file of nodes of which to compute the shortest path */
  bool shortestPathHelper(const char* in_filename, const char* out_filename);

  /*
    Find the shortest path using BFS algorithm
    Print the shortest path in the outfile if the shortest path is found. Otherwise print a newline
  */
  void shortestPath(int from, int to, ofstream& out_file);

  /*
    Function just to check whether the graph is printed as we thought
    Credits : Mr. Aditya  :)
  */
  void printGraph();
	
  

  void socialgathering(int k, ofstream& out_file);

  void socialgatheringHelper(const char* in_filename, const char* out_filename);
};

#endif  // GRAPH_HPP