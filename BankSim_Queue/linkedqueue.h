#ifndef _LINKEDQUEUE_
#define _LINKEDQUEUE_
#include"SimDef.h"

typedef struct BinTreeQueueNodeType QueueNode;
typedef struct BinTreeQueueType Queue;

struct BinTreeQueueNodeType {
	NodeData data;
	QueueNode* pLink;
};
struct BinTreeQueueType {
	int currentLength;
	QueueNode Head;
	QueueNode* pFront;
	QueueNode* pRear;
};

Queue* CreateQueue();
int Enqueue(Queue* pQueue, QueueNode element);
QueueNode* Dequeue(Queue* pQueue);
QueueNode* Peek(Queue* pQueue);
void DeleteQueue(Queue* pQueue);
//int isFull(Queue* pQueue);
int IsQueueEmpty(Queue* pQueue);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif // _COMMON_LIST_DEF_! 