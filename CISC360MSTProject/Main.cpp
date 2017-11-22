/*
 * Main.cpp
 *
 *  Created on: Nov 15, 2017
 *      Author: Chris
 */

#include "Boruvka.hpp"
#include "Kruskal.hpp"
#include "Prim.hpp"

int main() {

	Graph* graph = createGraph(4, 5);
	Boruvka_main(graph);
	Kruskal_main(graph);
}

