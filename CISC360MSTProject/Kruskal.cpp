/*
 * Kruskal.cpp
 *
 *  Created on: Nov 15, 2017
 *      Author: Chris
 */

// C++ program for Kruskal's algorithm to find Minimum Spanning Tree
// of a given connected, undirected and weighted graph

#include "Kruskal.hpp"

// The main function to construct MST using Kruskal's algorithm
void KruskalMST(Graph* graph)
{
	int V = graph->V, E = graph->E;
	Edge* result = graph->edge;  // This will store the resultant MST
	int e = 0;  // An index variable, used for result[]
	int i = 0;  // An index variable, used for sorted edges

	// Step 1:  Sort all the edges in non-decreasing
	// order of their weight. If we are not allowed to
	// change the given graph, we can create a copy of
	// array of edges

	//print statements to check sorting
	/*
	cout << "BEFORE QSORT" << endl;
	for (int i = 0; i < E; i++){
		cout << result[i].src << " " << result[i].dest << " " << result[i].weight << endl;
	}
	*/
	//qsort(result, E, sizeof(result[0]), myComp);
	result = Kruskal_sort(result, E);
	/*
	cout << "AFTER QSORT" << endl;
	for (int i = 0; i < E; i++){
			cout << result[i].src << " " << result[i].dest << " " << result[i].weight << endl;
	}
	*/

	// Allocate memory for creating V subsets
	subset *subsets =
			(subset*) malloc( V * sizeof(subset) );

	// Create V subsets with single elements
	for (int v = 0; v < V; ++v)
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	int numTrees = V;
	// Number of edges to be taken is equal to V-1
	//while (e < E)
	for (i = 0; i < E;)
	{
		// Step 2: Pick the smallest edge. And increment
		// the index for next iteration
		Edge next_edge = graph->edge[i++];

		int x = find(subsets, next_edge.src);
		int y = find(subsets, next_edge.dest);

		// If including this edge does't cause cycle,
		// include it in result and increment the index
		// of result for next edge
		if (x != y)
		{
			result[e++] = next_edge;
			Union(subsets, x, y);
			numTrees --;
		}
		// Else discard the next_edge
	}
	if (numTrees>1) {
		cout << "DISJOINT" << endl;
		cout << "NO MST" << endl;
		return;
	}

	// print the contents of result[] to display the
	// built MST
	int MSTweight = 0;
	printf("Following are the edges in the constructed MST\n");
	for (i = 0; i < e; ++i){
				printf("%d -- %d == %d\n", result[i].src, result[i].dest,
						result[i].weight);
				MSTweight += result[i].weight;
	};
	cout << "MST weight: " << MSTweight << endl;

	return;
}

Edge* Kruskal_sort(Edge* edges, int num_edges){
	Edge tmp;
	for (int i=0; i<num_edges; i++){
		for (int j=i+1; j<num_edges; j++){
			if (edges[i].weight > edges[j].weight){
				tmp = edges[i];
				edges[i] = edges[j];
				edges[j] = tmp;
			}
		}
	}
	return (edges);
}

// Driver program to test above functions

int Kruskal_main(Graph* graph2) {

	/* Let us create following weighted graph
	 10
	 0--------1
	 |  \     |
	6|   5\   |15
	 |      \ |
	 2--------3
	 4       */
	//int V = 4;  // Number of vertices in graph
	//int E = 5;  // Number of edges in graph
	//Graph* graph2 = createGraph(V, E);
	/*
	// add edge 0-1
	graph2->edge[0].src = 0;
	graph2->edge[0].dest = 1;
	graph2->edge[0].weight = 10;

	// add edge 0-2
	graph2->edge[1].src = 0;
	graph2->edge[1].dest = 2;
	graph2->edge[1].weight = 6;

	// add edge 0-3
	graph2->edge[2].src = 0;
	graph2->edge[2].dest = 3;
	graph2->edge[2].weight = 5;

	// add edge 1-3
	graph2->edge[3].src = 1;
	graph2->edge[3].dest = 3;
	graph2->edge[3].weight = 15;

	// add edge 2-3
	graph2->edge[4].src = 2;
	graph2->edge[4].dest = 3;
	graph2->edge[4].weight = 4;
	 */
	KruskalMST(graph2);

	return (0);
}

