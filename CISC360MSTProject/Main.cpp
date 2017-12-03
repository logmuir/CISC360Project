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
#include <ctime>

int main() {

	srand(time(NULL));
	Graph* graph = generateRandGraphs(4, 4);
	Boruvka_main(graph);
//	Kruskal_main(graph);
}

