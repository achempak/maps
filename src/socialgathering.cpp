#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Graph.hpp"
#include "Node.hpp"

using namespace std;

void usage(char* program_name) {
  cerr << program_name << " called with incorrect arguments." << endl;
  cerr << "Usage: " << program_name
       << " friendship_pairs_file k_value output_file"
       << endl;
  exit(-1);
}

int main(int argc, char* argv[]) {
  if (argc != 4) {
    usage(argv[0]);
  }
  char* graph_filename = argv[1];
  char* output_filename = argv[3];
  //istringstream ss(argv[2]);
  //char c[sizeof(argv[2])] = argv[2];
  //char c[] = (*argv)[2];
  string s = argv[2];
  int k = stoi(s);
  

 //TODO
 /* You can call the social gathering function from here */
  Graph* a = new Graph();
  ofstream outfile(output_filename);
  a->loadFromFile(graph_filename);
  a->socialgathering(k, outfile);
  outfile.close();
  delete a;
}