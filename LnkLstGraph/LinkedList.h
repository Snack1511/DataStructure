#ifndef _LINKEDLIST_
#define _LINKEDLIST_
typedef struct GraphVertexType Vertex;
typedef struct LinkedNodeInfo LinkedNode;
typedef struct LinkedListInfo LinkedList;

struct GraphVertexType {
	int vertID;
	int weight;
};
typedef struct LinkedNodeInfo {
	Vertex data;
	LinkedNode* pNextNode;
};

typedef struct LinkedListInfo {
	int currentElementCount;
	LinkedNode headerNode;
};
LinkedList* createList();
int addLLElement(LinkedList* pList, int position, LinkedNode Node);
int removeLLElement(LinkedList* pList, int position);
LinkedNode* getLLElement(LinkedList* pList, int position);
void displayLinkedList(LinkedList* pList);

void deleteLinkedList(LinkedList* pList);
void clearLinkedList(LinkedList* pList);

int GetPosition(LinkedList* pList, LinkedNode Node);

#endif


#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif // _COMMON_LIST_DEF_!
/*

*/