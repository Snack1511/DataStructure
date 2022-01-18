#ifndef _LNKGRAPH_
#define _LNKGRAPH_

#include"LinkedList.h"

typedef struct GraphType Graph;
struct GraphType {
	int curLength;
	int maxLength;
	int DirectMode;
	LinkedList** ppAdjacentList;
	int* pVertex;
};

Graph* CreateGraph(int MaxVertCount);
Graph* CreateDirectGraph(int MaxVertCount);
void DeleteGraph(Graph* pGraph);

int AddVertex(Graph* pGraph, int Vert);
int AddEdge(Graph* pGraph, int EnterVert, int OutVert);
int AddEdgeWeigt(Graph* pGraph, int InVert, int OutVert, int weight);

int RemoveVertex(Graph* pGraph, int Vert);
int RemoveEdge(Graph* pGraph, int EnterVert, int OutVert);

void displayGraph(Graph* pGraph);
void DisplayLastVertex(Graph* pGraph);
void DisplayEdge(Graph* pGraph);
#endif

#ifndef _COMMONDEF_
#define _COMMONDEF_

#define USED 1
#define NOTUSED 0

#define SUCCESS 1
#define FAILED 0

#define TRUE 1
#define FALSE 0

#define UNDIRECT 1
#define DIRECT 0

#define VISIT 1
#define NOTVISIT 0
#endif // !_COMMONDEF_

