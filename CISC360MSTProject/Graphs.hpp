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
#include<iostream>
using namespace std;


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
	Edge* edge;
};


// A structure to represent a subset for union-find
struct subset {
	int parent;
	int rank;
};


int find(subset subsets[], int i);
void Union(subset subsets[], int x, int y);
int myComp(const void* a, const void* b);
Graph* createGraph(int V, int E);
Graph* createGraph(int V, int E, Edge* allEdges);
Edge* createEdge(int src, int dest, int weight);


#endif /* GRAPHS_HPP_ */
