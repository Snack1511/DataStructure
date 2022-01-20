#ifndef _MINSPANNINGTREEE_
#define _MINSPANNINGTREEE_
Graph* Kruskal(Graph *pGraph);
Graph* Prim(Graph* pGraph);
int AddEdgeWeightHeapNode(Graph* pGraph, HeapNode* pNode);
int FindCycleHeapNode(Graph* pGraph, HeapNode Node);
int FindCycle(Graph* pGraph, int Invert, int Outvert);
int IsAllVertexConnect(Graph *pGraph);
#endif