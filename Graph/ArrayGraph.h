#ifndef _ARRAYGRAPH_
#define _ARRAYGRAPH_

typedef struct GraphType Graph;

struct GraphType
{
	int maxVertexCnt;
	int curVertexCnt;
	int GraphType;
	int **ppAdjEdge;		//간선정보 저장용 2차배열
	int *pVertex;			//노드저장용 1차배열
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
#endif // !_COMMONDEF_
