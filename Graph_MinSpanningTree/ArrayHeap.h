#ifndef _ARRAYHEAP_
#define _ARRAYHEAP_
typedef struct EdgeDataType Data;
typedef struct ArrayHeapNodeType HeapNode;
typedef struct ArrayHeapType Heap;
struct EdgeDataType {
	int InVert;
	int OutVert;
};
struct ArrayHeapNodeType {
	int key;
	Data data;
};
struct ArrayHeapType {
	int maxLength;
	int currentLength;
	HeapNode* HeapArray;
};

Heap* CreateHeap(int MaxLength);
void DeleteHeapArray(Heap* pHeap);
void InsertHeapNode(Heap* pHeap, HeapNode node);
HeapNode* DeleteHeap(Heap* pHeap);
HeapNode CreateEdgeNodeData(int Invert, int Outvert, int weight);
void DisplayHeap(Heap* pHeap);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif // _COMMON_LIST_DEF_! 