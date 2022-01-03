#ifndef _ARRAYQUEUE_
#define _ARRAYQUEUE_
typedef struct ArrayQueueNodeType QueueNode;
typedef struct ArrayQueueType Queue;

struct ArrayQueueNodeType {
	char data;
};
struct ArrayQueueType {
	int maxLength;				//최대 원소 개수
	int currentLength;			//현재 원소 개수
	int front;					//프론트의 위치 --> 프런트 노드의 이전 위치
	int rear;					//리어의 위치
	QueueNode* pElements;		//노드저장을 위한 1차원 배열 포인터
};


Queue* CreateQueue(int maxLength);
int Enqueue(Queue* pQueue, QueueNode element);
QueueNode* Dequeue(Queue* pQueue);
QueueNode* Peek(Queue* pQueue);
void DeleteQueue(Queue* pQueue);
int isFull(Queue* pQueue);
int isEmpty(Queue* pQueue);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif // _COMMON_LIST_DEF_! 