#include "Graph.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>

class NodePtrComp {
public:
    bool operator()(Node*& lhs, Node*& rhs) const {
        return *lhs < *rhs;
    }
};

/*Constructor to create an object in the heap that accessed through a pointer*/
Graph::Graph(void) { 
  graph = new unordered_map<int, Node*>;
  sum_edges = 0;
}

/*Destructor*/
Graph::~Graph(void) {
  for (auto iter = graph->begin(); iter!=graph->end(); ++iter)
   delete iter->second;
  delete graph;
}
/* Reinitializes prev to nullptr and isVisited to false.
  Called whenever shortestPath is called.
*/
void Graph::reinitialize()
{
  for(auto iter = (*graph).begin(); iter!= (*graph).end(); iter++)
  {
    iter->second->setVisited(false); // to reinitialize Visited flag to not visited
    iter->second->setPrev((Node*)0); // to reinitialize so that the node has no previous
    iter->second->setDegree(iter->second->get_initialDegree());
  }
}

float Graph::getSum_edges(){
  return sum_edges;
}


/*Adds node_data to the hash map  
    node_data is a vector containing node ids and the edge weight between those nodes
    node_data[0]: id1
    node_data[1]: id2
    node_data[1]: edge weight
    */
 void Graph::addNode(vector<string> node_data){
   int id_1 = stoi(node_data[0]); // stores the first element of the vector by converting the string into an int
   int id_2 = stoi(node_data[1]); 
   float edge = stof(node_data[2]); // converts edge string to edge float

   if(graph->find(id_1)==graph->end())
   {
     graph->insert({id_1, new Node(id_1)}); 
   }

   if(graph->find(id_2)==graph->end()) 
   {
     graph->insert({id_2, new Node(id_2)}); 
   }

   (*graph)[id_1]->addFriend(id_2);
   (*graph)[id_1]->incrementDegree();
   (*graph)[id_1]->increment_initialDegree();
   (*graph)[id_1]->addEdge(edge);
   (*graph)[id_2]->addFriend(id_1);
   (*graph)[id_2]->incrementDegree();
   (*graph)[id_2]->increment_initialDegree();
   (*graph)[id_2]->addEdge(edge); 
   sum_edges += edge;
 }
 
/* Read in relationships from an input file to create a graph */
bool Graph::loadFromFile(const char* in_filename) {
  ifstream infile(in_filename);

  while (infile) {
    string s;
    if (!getline(infile, s)) break;

    istringstream ss(s);
    vector<string> record;

    while (ss) {
      string s;
      if (!getline(ss, s, ' ')) break;
      record.push_back(s);
    }

    if (record.size() != 3) {
      continue;
    }
    Graph::addNode(record); //Add node to hashmap with friend data and edge data
  } 

  if (!infile.eof()) {
    cerr << "Failed to read " << in_filename << "!\n";
    return false;
  }
  infile.close();
  return true;
}

/* Reads file of nodes of which to compute the shortest path */
bool Graph::shortestPathHelper(const char* in_filename, const char* out_filename) {
  ifstream infile(in_filename);
  ofstream outfile(out_filename);

  while (infile) {
    string s;
    if (!getline(infile, s)) break;

    istringstream ss(s);
    vector<string> record;

    while (ss) {
      string s;
      if (!getline(ss, s, ' ')) break;
      record.push_back(s);
    }

    if (record.size() != 2) {
      continue;
    }

   int id_1 = stoi(record[0]);
   int id_2 = stoi(record[1]);

   Graph::shortestPath(id_1, id_2, outfile);      
  }
  if (!infile.eof()) {
    cerr << "Failed to read " << in_filename << "!\n";
    return false;
  }
  infile.close();
  outfile.close();
  return true;
}

/*Find whether a path between two nodes exists or not*/
bool Graph::pathfinder(int from, int to){
  reinitialize();
  // Implementing DFS as it will be faster in case of path finder
  stack<Node*> s;

  /*Return false if the either of the ids are not there in the graph*/
  if((*graph).find(from) ==  (*graph).end() || (*graph).find(to) == (*graph).end()) return false;

  s.push((*graph)[from]);
  Node* curr = s.top();

  while(!s.empty() && curr!=(*graph)[to]) //Loop until stack is empty or desired node is reached
  {
    curr = s.top();
    curr->setVisited(true);
    s.pop();
    //Iterate over friends of the current node to find those nodes that are just one step away from the current node
    for(auto it = curr->getFriends()->begin(); it!=curr->getFriends()->end(); ++it)
    {
      if(!(*graph)[*it]->getIsVisisted())
      {
        s.push((*graph)[*it]);
        (*graph)[*it]->setVisited(true);
      }
    }
  }
  if(curr==(*graph)[to]) return true;
  return false;
}

/*
  Find the shortest path using BFS algorithm
  Print the shortest path in the outfile if the shortest path is found. Otherwise print a newline
*/
void Graph::shortestPath(int from, int to, ofstream& outfile){
  reinitialize();

  if((*graph).find(from) ==  (*graph).end() || (*graph).find(to) == (*graph).end())
  {
    outfile<<endl;
    return;
  }
  queue<Node*> q; // Initialize a queue to store the pointers 

  q.push((*graph)[from]);
  Node* curr = q.front();
  curr->setVisited(true);
  while(!q.empty() && curr!=(*graph)[to]) //Loop until stack is empty or desired node is reached
  {
    //Iterate over friends of the current node to find those nodes that are just one step away from the current node
    for(auto it = curr->getFriends()->begin(); it!=curr->getFriends()->end(); ++it){
      if(!(*graph)[*it]->getIsVisisted()){
        q.push((*graph)[*it]);
        (*graph)[*it]->setVisited(true); 
        (*graph)[*it]->setPrev(curr);
      }
    }
    q.pop();
    curr=q.front();
  }

  //Now we are at the node for which we have to find the shortest path.
  //We just need to traverse back with the help of prev pointer to retrace the path
  if(curr==(*graph)[to]){
    stack<Node*> toReturn; // Creating a stack to reverse the path traversed
    Node* current = curr;
    while(current!=nullptr){
      toReturn.push(current);
      current = current->getPrev();
    }
    
    //Print the ids to the file
    while(toReturn.size()>1){
      outfile<<toReturn.top()->getId()<<" ";
      toReturn.pop();
    }
    outfile<<toReturn.top()->getId()<<endl;;
    toReturn.empty();
  }
  else{
    outfile<<endl;
  }
}

void Graph::socialgathering(int k, ofstream& out_file){
  reinitialize();

  priority_queue<Node*, vector<Node*>, NodePtrComp> pq;
  int maxDeg = 0;
  for (auto iter = graph->begin(); iter!=graph->end(); ++iter){
    pq.push(iter->second);
    if(iter->second->getDegree()>maxDeg) maxDeg = iter->second->getDegree(); //Added this line to check if k is greater than max degree in graph
  }
  if(maxDeg<k) return; //return if max degree is less than k
  
  Node* curr = pq.top();
  while(curr->getDegree() < k){
    if(!curr->getIsVisisted()){
      curr->setVisited(true);
      for(auto it = curr->getFriends()->begin(); it!=curr->getFriends()->end(); ++it){
        Node* frnd = (*graph)[*it];
        frnd->decrementDegree();
        pq.push(frnd);
      }
    }
    curr->setDegree(0);
    pq.pop();
    curr = pq.top();
  }

  priority_queue<int, vector<int>, std::greater<int>> first;
  while(!pq.empty()){
    Node* temp = pq.top();
    pq.pop();
    if(!temp->getIsVisisted()){
      first.push(temp->getId());
      temp->setVisited(true);
    }
  }
  while(!first.empty()){
    out_file<<first.top()<<endl;
    first.pop();
  }
}

void Graph::printGraph(){
  cout<<"Number of buckets of hashmap is: "<<graph->bucket_count()<<endl;
  cout<<"Number of elements in hashmap is: "<<graph->size()<<endl;
  cout<<"Load factor is: "<<graph->load_factor()<<endl;
  for(unsigned i=0; i<graph->bucket_count(); ++i){
    cout<<"Bucket #"<<i<<" contains: ";
    for(auto local_it = graph->begin(i); local_it!=graph->end(i); ++local_it){
      cout<<local_it->second->getId()<<"(Degree: "<<local_it->second->getDegree()<<"). "<<"(Friends: ";
      for(auto iter = local_it->second->getFriends()->begin(); iter!=local_it->second->getFriends()->end(); ++iter){
        cout<<*iter<<",";
      }
      cout<<"), ";
      cout<<"(Edges: ";
      for(auto iter = local_it->second->getEdges()->begin(); iter!=local_it->second->getEdges()->end(); ++iter){
        cout<<*iter<<",";
      }
      cout<<") ";
    }
    cout<<endl;
  }
}
