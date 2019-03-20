# maps
This is a mapping algorithm that can be used to find the minimum spanning tree (MST) of any set of coordinates, provided that edges
are calculated beforehand. The folder contains a Disjoint Set class that can be used to produce a disjoint set of any set of integers.
There are also methods to print out the MST in the form of an adjacency list (implemented as an Unordered Set) as well as to find and
display the path between two points according the MST.

Possible Future Improvements:
1. Make the Disjoint Set class a template class that works with any object
2. Add additional map-related algorithms
3. Calculate edge lengths from a list of node pairs, so that (undirected) edges don't need to  be directly supplied to the algorithm
