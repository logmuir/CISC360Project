/*
 * Prim.cpp
 *
 *  Created on: Nov 15, 2017
 *      Author: Chris
 */

// A C / C++ program for Prim's Minimum Spanning Tree (MST) algorithm.
// The program is for adjacency matrix representation of the graph
#include <stdio.h>
#include <limits.h>
#include "Prim.hpp"

// Number of vertices in the graph

// A utility function to find the vertex with minimum key value, from
// the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[],Graph* g) {
	//Number of vertices
	int V = g->V;

	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return (min_index);
}

// A utility function to print the constructed MST stored in parent[]
int printPrimMST(int parent[], int n, Graph* g) {
	int V = g->V;
	int graph[g->V][g->E];
	printf("Edge   Weight\n");
	for (int i = 1; i < V; i++)
		printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
	return (1);
}

// Function to construct and print MST for a graph represented using adjacency
// matrix representation
void primMST(Graph* g) {
	int V = g->V;
	int parent[V]; // Array to store constructed MST
	int key[V];   // Key values used to pick minimum weight edge in cut
	bool mstSet[V];  // To represent set of vertices not yet included in MST

	//2D graph representation
	int graph[g->V][g->E];

	// Initialize all keys as INFINITE
	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	// Always include first 1st vertex in MST.
	key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
	parent[0] = -1; // First node is always root of MST

	// The MST will have V vertices
	for (int count = 0; count < V - 1; count++) {
		// Pick the minimum key vertex from the set of vertices
		// not yet included in MST
		int u = minKey(key, mstSet, g);

		// Add the picked vertex to the MST Set
		mstSet[u] = true;

		// Update key value and parent index of the adjacent vertices of
		// the picked vertex. Consider only those vertices which are not yet
		// included in MST
		for (int v = 0; v < V; v++)

			// graph[u][v] is non zero only for adjacent vertices of m
			// mstSet[v] is false for vertices not yet included in MST
			// Update the key only if graph[u][v] is smaller than key[v]
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	// print the constructed MST
	printPrimMST(parent, V, g);
	return;
}

// driver program to test above function
int Prim_main(Graph* graph) {
	/* Let us create the following graph
	    2    3
	 (0)--(1)--(2)
	 |   / \   |
    6| 8/   \5 |7
	 | /     \ |
	 (3)-------(4)
	       9          */


	// Print the solution
	primMST(graph);

	return (0);
}

