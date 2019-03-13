#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "MST.hpp"
#include "Node.hpp"
#include "Edge.hpp"
#include "Graph.hpp"
#include "DisjointSet.hpp"
using namespace std;

void usage(char* program_name) {
  cerr << program_name << " called with incorrect arguments." << endl;
  cerr << "Usage: " << program_name
       << " roadmap_file mst_output_file"
       << endl;
  exit(-1);
}

int main(int argc, char* argv[]) {
  
  if (argc != 3) {
    usage(argv[0]);
  }
  

  char* roadmap_filename = argv[1];
  char* mst_output_filename = argv[2];
  //char* output_filename = argv[3];

  //TODO   
 /* You can call the pathfinder function from here */
 
  MST* a = new MST();
  ofstream outfile(mst_output_filename);
  a->loadFromFile(roadmap_filename);
  a->mstbuild(outfile);
  outfile.close();
  delete a;


 //Graph* a = new Graph();
 //a->loadFromFile(graph_filename);

 /*To print the graph, uncomment the below line and see the magic*/
 //a->printGraph();

 //a->shortestPathHelper(pairs_filename, output_filename);
 //delete a;
}  