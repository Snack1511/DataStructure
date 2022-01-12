#ifndef _LSTMAXHEAP_
#define _LSTMAXHEAP_

typedef struct HeapNodeType Node;
typedef struct HeapType Heap;


struct HeapNodeType {
	int key;
	char data;
	Node* pLink;
};
struct HeapType {
	int currentLength;
	Node* Root;
};

Heap* CreateHeap();
void InsertHeapNode(Heap* pHeap, Node node);
Node* DeleteHeapNode(Heap* pHeap);
void DeleteHeap(Heap* pHeap);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif // _COMMON_LIST_DEF_! 