/*
 * Graphs.cpp
 *
 *  Created on: Nov 15, 2017
 *      Author: logsn
 */


#include "Graphs.hpp"


// Creates a graph with V vertices and E edges
Graph* createGraph(int V, int E, Edge* edges) {
	Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;

	graph->edge = edges;

	return (graph);
}

Graph* createGraph(int V, int E) {
	Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;

	return (graph);
}

Edge* createEdge(int src, int dest, int weight) {
	Edge* edge = new Edge;
	edge->src = src;
	edge->dest = dest;
	edge->weight = weight;

	return (edge);
}

// A utility function to find set of an element i
// (uses path compression technique)
int find(subset subsets[], int i) {
	// find root and make root as parent of i
	// (path compression)
	if (subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);

	return (subsets[i].parent);
}

// A function that does union of two sets of x and y
// (uses union by rank)
void Union(subset subsets[], int x, int y) {
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);

	// Attach smaller rank tree under root of high
	// rank tree (Union by Rank)
	if (subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if (subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;

	// If ranks are same, then make one as root and
	// increment its rank by one
	else {
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}

// Compare two edges according to their weights.
// Used in qsort() for sorting an array of edges
int myComp(const void* a, const void* b) {
	Edge* a1 = (Edge*) a;
	Edge* b1 = (Edge*) b;
	return (a1->weight > b1->weight);
}


