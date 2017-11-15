/*
 * Graphs.hpp
 *
 *  Created on: Nov 15, 2017
 *      Author: logsn
 */

#ifndef GRAPHS_HPP_
#define GRAPHS_HPP_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// a structure to represent a weighted edge in graph
struct Edge {
	int src, dest, weight;
};

// a structure to represent a connected, undirected
// and weighted graph
struct Graph {
	// V-> Number of vertices, E-> Number of edges
	int V, E;

	// graph is represented as an array of edges.
	// Since the graph is undirected, the edge
	// from src to dest is also edge from dest
	// to src. Both are counted as 1 edge here.
	struct Edge* edge;
};


// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
	Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;

	graph->edge = new Edge[E];

	return graph;
}

// A structure to represent a subset for union-find
struct subset {
	int parent;
	int rank;
};


int find(struct subset subsets[], int i);
void Union(struct subset subsets[], int x, int y);
int myComp(const void* a, const void* b);




#endif /* GRAPHS_HPP_ */
