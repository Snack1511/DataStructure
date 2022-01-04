#ifndef _LINKEDQUEUE_
#define _LINKEDQUEUE_
typedef struct LinkedListQueueNodeType QueueNode;
typedef struct LinkedListQueueType Queue;

struct LinkedListQueueNodeType {
	char data;
	QueueNode* pLink;
};
struct LinkedListQueueType {
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
int isEmpty(Queue* pQueue);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif // _COMMON_LIST_DEF_! 