#include "MST.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

MST::MST():numnodes(0){
    pq = new priority_queue<Edge*, vector<Edge*>, EdgePtrComp>;
}

MST::~MST(){}

void MST::setNumnodes(int n){
    numnodes = n;
}

int MST::getNumnodes(){
    return numnodes;
}

bool MST::loadFromFile(const char* in_filename){
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

    if (record.size() != 4) {
      continue;
    }

    //TODO - YOU HAVE THE PAIR OF IDS OF 2 FRIENDS IN 'RECORD'. WHAT DO NEED TO DO NOW? 
    MST::addEdge(record);    // Add id pairs into hashmap
  } 

  if (!infile.eof()) {
    cerr << "Failed to read " << in_filename << "!\n";
    return false;
  }
  infile.close();
  return true;
}

void MST::addEdge(vector<string> edgeinfo){
    int id = stoi(edgeinfo[0]);
    int node1 = stoi(edgeinfo[1]);
    int node2 = stoi(edgeinfo[2]);
    float weight = stof(edgeinfo[3]);
    if(getNumnodes() < node1) setNumnodes(node1);
    if(getNumnodes() < node2) setNumnodes(node2);
    pq->push(new Edge(id, node1, node2, weight));
}

void MST::mstbuild(ofstream& out_file){
    DisjointSet ds(getNumnodes());
    

}