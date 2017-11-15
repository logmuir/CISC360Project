/*
 * Boruvka.cpp
 *
 *  Created on: Nov 15, 2017
 *      Author: Chris
 */

// Boruvka's algorithm to Boruvka_find Minimum Spanning
// Tree of a given connected, undirected and
// weighted graph
#include <stdio.h>

// a structure to represent a weighted Boruvka_Edge in graph
struct Boruvka_Edge {
	int src, dest, weight;
};

// a structure to represent a connected, undirected
// and weighted graph as a collection of Boruvka_Edges.
struct Boruvka_Graph {
	// V-> Number of vertices, E-> Number of Boruvka_Edges
	int V, E;

	// graph is represented as an array of Boruvka_Edges.
	// Since the graph is undirected, the Boruvka_Edge
	// from src to dest is also Boruvka_Edge from dest
	// to src. Both are counted as 1 Boruvka_Edge here.
	Boruvka_Edge* Boruvka_Edge;
};

// A structure to represent a Boruvka_subset for union-Boruvka_find
struct Boruvka_subset {
	int parent;
	int rank;
};

// Function prototypes for union-Boruvka_find (These functions are defined
// after boruvkaMST() )
int Boruvka_find(struct Boruvka_subset Boruvka_subsets[], int i);
void Boruvka_Union(struct Boruvka_subset Boruvka_subsets[], int x, int y);

// The main function for MST using Boruvka's algorithm
void boruvkaMST(struct Boruvka_Graph* Boruvka_graph) {
	// Get data of given graph
	int V = Boruvka_graph->V, E = Boruvka_graph->E;
	Boruvka_Edge *Boruvka_Edge = Boruvka_graph->Boruvka_Edge;

	// Allocate memory for creating V Boruvka_subsets.
	struct Boruvka_subset *Boruvka_subsets = new Boruvka_subset[V];

	// An array to store index of the cheapest Boruvka_Edge of
	// Boruvka_subset.  The stored index for indexing array 'Boruvka_Edge[]'
	int *cheapest = new int[V];

	// Create V Boruvka_subsets with single elements
	for (int v = 0; v < V; ++v) {
		Boruvka_subsets[v].parent = v;
		Boruvka_subsets[v].rank = 0;
		cheapest[v] = -1;
	}

	// Initially there are V different trees.
	// Finally there will be one tree that will be MST
	int numTrees = V;
	int MSTweight = 0;

	// Keep combining components (or sets) until all
	// compnentes are not combined into single MST.
	while (numTrees > 1) {
		// Traverse through all Boruvka_Edges and update
		// cheapest of every component
		for (int i = 0; i < E; i++) {
			// Find components (or sets) of two corners
			// of current Boruvka_Edge
			int set1 = Boruvka_find(Boruvka_subsets, Boruvka_Edge[i].src);
			int set2 = Boruvka_find(Boruvka_subsets, Boruvka_Edge[i].dest);

			// If two corners of current Boruvka_Edge belong to
			// same set, ignore current Boruvka_Edge
			if (set1 == set2)
				continue;

			// Else check if current Boruvka_Edge is closer to previous
			// cheapest Boruvka_Edges of set1 and set2
			else {
				if (cheapest[set1] == -1
						|| Boruvka_Edge[cheapest[set1]].weight
								> Boruvka_Edge[i].weight)
					cheapest[set1] = i;

				if (cheapest[set1] == -1
						|| Boruvka_Edge[cheapest[set2]].weight
								> Boruvka_Edge[i].weight)
					cheapest[set2] = i;
			}
		}

		// Consider the above picked cheapest Boruvka_Edges and add them
		// to MST
		for (int i = 0; i < V; i++) {
			// Check if cheapest for current set exists
			if (cheapest[i] != -1) {
				int set1 = Boruvka_find(Boruvka_subsets,
						Boruvka_Edge[cheapest[i]].src);
				int set2 = Boruvka_find(Boruvka_subsets,
						Boruvka_Edge[cheapest[i]].dest);

				if (set1 == set2)
					continue;
				MSTweight += Boruvka_Edge[cheapest[i]].weight;
				printf("Boruvka_Edge %d-%d included in MST\n",
						Boruvka_Edge[cheapest[i]].src,
						Boruvka_Edge[cheapest[i]].dest);
				//Boruvka_Edge[cheapest[i]].weight);

				// Do a union of set1 and set2 and decrease number
				// of trees
				Boruvka_Union(Boruvka_subsets, set1, set2);
				numTrees--;
			}
		}
	}

	printf("Weight of MST is %d\n", MSTweight);
	return;
}

// Creates a graph with V vertices and E Boruvka_Edges
struct Boruvka_Graph* Boruvka_createGraph(int V, int E) {
	Boruvka_Graph* graph = new Boruvka_Graph;
	graph->V = V;
	graph->E = E;
	graph->Boruvka_Edge = new Boruvka_Edge[E];
	return graph;
}

// A utility function to Boruvka_find set of an element i
// (uses path compression technique)
int Boruvka_find(struct Boruvka_subset Boruvka_subsets[], int i) {
	// Boruvka_find root and make root as parent of i
	// (path compression)
	if (Boruvka_subsets[i].parent != i)
		Boruvka_subsets[i].parent = Boruvka_find(Boruvka_subsets,
				Boruvka_subsets[i].parent);

	return Boruvka_subsets[i].parent;
}

// A function that does union of two sets of x and y
// (uses union by rank)
void Boruvka_Union(struct Boruvka_subset Boruvka_subsets[], int x, int y) {
	int xroot = Boruvka_find(Boruvka_subsets, x);
	int yroot = Boruvka_find(Boruvka_subsets, y);

	// Attach smaller rank tree under root of high
	// rank tree (Boruvka_Union by Rank)
	if (Boruvka_subsets[xroot].rank < Boruvka_subsets[yroot].rank)
		Boruvka_subsets[xroot].parent = yroot;
	else if (Boruvka_subsets[xroot].rank > Boruvka_subsets[yroot].rank)
		Boruvka_subsets[yroot].parent = xroot;

	// If ranks are same, then make one as root and
	// increment its rank by one
	else {
		Boruvka_subsets[yroot].parent = xroot;
		Boruvka_subsets[xroot].rank++;
	}
}

// Driver program to test above functions
int Boruvka_main() {
	/* Let us create following weighted graph
	 10
	 0--------1
	 |  \     |
	 6|   5\   |15
	 |      \ |
	 2--------3
	 4       */
	int V = 4;  // Number of vertices in graph
	int E = 5;  // Number of Boruvka_Edges in graph
	struct Boruvka_Graph* graph = Boruvka_createGraph(V, E);

	// add Boruvka_Edge 0-1
	graph->Boruvka_Edge[0].src = 0;
	graph->Boruvka_Edge[0].dest = 1;
	graph->Boruvka_Edge[0].weight = 10;

	// add Boruvka_Edge 0-2
	graph->Boruvka_Edge[1].src = 0;
	graph->Boruvka_Edge[1].dest = 2;
	graph->Boruvka_Edge[1].weight = 6;

	// add Boruvka_Edge 0-3
	graph->Boruvka_Edge[2].src = 0;
	graph->Boruvka_Edge[2].dest = 3;
	graph->Boruvka_Edge[2].weight = 5;

	// add Boruvka_Edge 1-3
	graph->Boruvka_Edge[3].src = 1;
	graph->Boruvka_Edge[3].dest = 3;
	graph->Boruvka_Edge[3].weight = 15;

	// add Boruvka_Edge 2-3
	graph->Boruvka_Edge[4].src = 2;
	graph->Boruvka_Edge[4].dest = 3;
	graph->Boruvka_Edge[4].weight = 4;

	boruvkaMST(graph);

	return 0;
}

