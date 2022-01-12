#ifndef _ARRAYHEAP_
#define _ARRAYHEAP_
typedef struct ArrayHeapNodeType HeapNode;
typedef struct ArrayHeapType Heap;
struct ArrayHeapNodeType {
	int key;
	char data;
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
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif // _COMMON_LIST_DEF_! 