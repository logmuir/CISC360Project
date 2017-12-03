/*
 * Main.cpp
 *
 *  Created on: Nov 15, 2017
 *      Author: Chris
 */

#include "Boruvka.hpp"
#include "Kruskal.hpp"
#include "Prim.hpp"
#include "GraphGen.hpp"

int main() {


	Graph* graph = generateRandGraphs(4, 5);
	Boruvka_main(graph);
//	Kruskal_main(graph);
}

