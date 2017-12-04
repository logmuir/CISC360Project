/*
 * Kruskal.hpp
 *
 *  Created on: Nov 15, 2017
 *      Author: logsn
 */

#ifndef KRUSKAL_HPP_
#define KRUSKAL_HPP_

#include "Graphs.hpp"
#include<iostream>
using namespace std;

void KruskalMST(Graph* graph);
int Kruskal_main(Graph* graph);
Edge* Kruskal_sort(Edge* edges, int num_edges);



#endif /* KRUSKAL_HPP_ */
