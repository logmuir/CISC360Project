/*
 * Prim.hpp
 *
 *  Created on: Nov 15, 2017
 *      Author: logsn
 */

#ifndef PRIM_HPP_
#define PRIM_HPP_

#include "Graphs.hpp"

void primMST(Graph* g);
int printPrimMST(int parent[], int n, Graph* g);
int Prim_main(Graph* graph);

#endif /* PRIM_HPP_ */
