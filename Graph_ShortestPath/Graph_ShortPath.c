#include<stdio.h>
#include<stdlib.h>
#include"LnkGraph.h"
#include"UsedDataStructure.h"
#include"Graph_ShortPath.h"

Queue* Dajkstra(Graph* pGraph, int StartVert, int EndVert) {
	Queue* ret = CreateQueue();



	return ret;
}

void PrintPath(Queue* pPath) {
	if (pPath != NULL) {
		printf("Path : ");
		while (IsQueueEmpty(pPath) == FALSE) {
			printf("%d    ", Dequeue(pPath)->data);
		}
		printf("\n");
	}
}