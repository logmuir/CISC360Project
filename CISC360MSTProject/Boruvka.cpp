/*
 * Boruvka.cpp
 *
 *  Created on: Nov 15, 2017
 *      Author: Chris
 */

// Boruvka's algorithm to find Minimum Spanning
// Tree of a given connected, undirected and
// weighted graph

#include "Boruvka.hpp"

// The main function for MST using Boruvka's algorithm
void boruvkaMST(Graph* graph)
{
    // Get data of given graph
    int V = graph->V, E = graph->E;
    Edge *edge = graph->edge;

    // Allocate memory for creating V subsets.
    subset *subsets = new subset[V];

    // An array to store index of the cheapest edge of
    // subset.  The stored index for indexing array 'edge[]'
    int *cheapest = new int[V];

    // Create V subsets with single elements
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Initially there are V different trees.
    // Finally there will be one tree that will be MST
    int numTrees = V;
    int MSTweight = 0;

    // Keep combining components (or sets) until all
    // compnentes are not combined into single MST.
    while (numTrees > 1)
    {
    	for (int v = 0; v < V; ++v) {
    		cheapest[v] = -1;
    	}
        // Traverse through all edges and update
        // cheapest of every component
        for (int i=0; i<E; i++)
        {
            // Find components (or sets) of two corners
            // of current edge
            int set1 = find(subsets, edge[i].src);
            int set2 = find(subsets, edge[i].dest);

            // If two corners of current edge belong to
            // same set, ignore current edge
            if (set1 == set2)
                continue;

            // Else check if current edge is closer to previous
            // cheapest edges of set1 and set2
            else
            {
               if (cheapest[set1] == -1 ||
                   edge[cheapest[set1]].weight > edge[i].weight)
                 cheapest[set1] = i;

               if (cheapest[set2] == -1 ||
                   edge[cheapest[set2]].weight > edge[i].weight)
                 cheapest[set2] = i;
            }
        }

        // Consider the above picked cheapest edges and add them
        // to MST
        for (int i=0; i<V; i++)
        {
            // Check if cheapest for current set exists
            if (cheapest[i] != -1)
            {
                int set1 = find(subsets, edge[cheapest[i]].src);
                int set2 = find(subsets, edge[cheapest[i]].dest);

                if (set1 == set2)
                    continue;
                MSTweight += edge[cheapest[i]].weight;
            //    printf("Edge %d-%d included in MST\n",
            //           edge[cheapest[i]].src, edge[cheapest[i]].dest);

                // Do a union of set1 and set2 and decrease number
                // of trees
                Union(subsets, set1, set2);
                numTrees--;
            }
        }
    }

   // printf("Weight of MST is %d\n", MSTweight);
    return;
}

// Driver program to test above functions
int Boruvka_main(Graph* graph1) {
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

/*
	    // add edge 0-1
	    graph1->edge[0].src = 0;
	    graph1->edge[0].dest = 1;
	    graph1->edge[0].weight = 10;

	    // add edge 0-2
	    graph1->edge[1].src = 0;
	    graph1->edge[1].dest = 2;
	    graph1->edge[1].weight = 6;

	    // add edge 0-3
	    graph1->edge[2].src = 0;
	    graph1->edge[2].dest = 3;
	    graph1->edge[2].weight = 5;

	    // add edge 1-3
	    graph1->edge[3].src = 1;
	    graph1->edge[3].dest = 3;
	    graph1->edge[3].weight = 15;

	    // add edge 2-3
	    graph1->edge[4].src = 2;
	    graph1->edge[4].dest = 3;
	    graph1->edge[4].weight = 4;
*/
	    boruvkaMST(graph1);

	    return (0);
}

