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
#include <iomanip>
#include <chrono>
#include <ctime>
#include <thread>
#include <fstream>>
using namespace std;

int main() {

	srand(time(NULL));
	int numVerts = 100;
	//int numEdges = (((numVerts - 1) * (numVerts - 2))/2) + 1;
	int  numEdges = 300;
	Graph* graph = generateRandGraphs(numVerts, numEdges);
	ofstream myFileStream;
	myFileStream.open("chris.txt", ios::app);
	myFileStream << graph->V << "," << graph->E;
	/*
	for (int x = 0; x < numEdges; x++){
		Edge e = graph->edge[x];
		myFileStream << e.src << " " << e.dest << " " << e.weight << ",";
	}
	*/


	clock_t startTime = clock();
	Boruvka_main(graph);
	clock_t endTime = clock();
	clock_t clockTicksTaken = endTime - startTime;
	double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
	cout << "Boruvka's CPU Time (seconds): "<< timeInSeconds <<endl;
	myFileStream << "," << timeInSeconds;

	startTime = clock();
	Kruskal_main(graph);
	endTime = clock();
	clockTicksTaken = endTime - startTime;
	timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
	cout<< "Kruskal's CPU Time (seconds): "<< timeInSeconds <<endl;
	myFileStream << "," << timeInSeconds << "\n";

	//	Kruskal_main(graph);
	// Prim_main(graph);
	myFileStream.close();
}

