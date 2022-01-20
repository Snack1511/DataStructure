#include<stdio.h>
#include<stdlib.h>
#include"LnkGraph.h"

#define MAXGRAPHSIZE 6

int main(int argc, char* argv[]) {
	Graph* pG = NULL;

	
	pG = CreateGraph(MAXGRAPHSIZE);

	if (pG != NULL) {
		for (int i = 0; i < 6; ++i) {
			AddVertex(pG, i);
		}

		AddEdgeWeigt(pG, 0, 1, 1);
		AddEdgeWeigt(pG, 0, 2, 4);
		AddEdgeWeigt(pG, 1, 2, 2);
		AddEdgeWeigt(pG, 2, 3, 1);
		AddEdgeWeigt(pG, 3, 4, 8);
		AddEdgeWeigt(pG, 3, 5, 3);
		AddEdgeWeigt(pG, 4, 5, 4);

		DisplayEdge(pG);
	}
}