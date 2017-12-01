/*
 * GraphGen.cpp
 *
 *  Created on: Nov 30, 2017
 *      Author: Chris
 */

#include "Graphs.hpp"

Graph generateRandGraphs(int NOE, int NOV){
	int max = 100;
	int i = 0;
	int edges[NOE][2];
	Edge **allEdges = new Edge*[NOE];

	while(i < NOE){
		edges[i][0] = rand()%NOV+1;
		edges[i][1] = rand()%NOV+1;
		if(edges[i][0] == edges[i][1])
			continue;
		else{
			for(int j = 0; j < i; j++){
				if((edges[i][0] == edges[j][0] && edges[i][1] == edges[j][1])||
						(edges[i][0] == edges[j][1] && edges[i][1] == edges[j][0]))
					i--;
			}
		}
		i++;
	}
	for(int i = 0; i < NOE; i++){
		Edge *e = createEdge(edges[i][0], edges[i][1], rand()%(max));
		allEdges[i] = e;
	}
	Graph* g = createGraph(NOV, NOE, *allEdges);
	return (*g);
}


