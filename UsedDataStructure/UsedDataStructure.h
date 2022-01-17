#pragma once
#ifndef _USEDDATASTRUCTURE_
#define _USEDDATASTRUCTURE_

#pragma region Stack
typedef struct StackNodeType StackNode;
typedef struct StackType Stack;
struct StackNodeType {
	int data;
	StackNode* pLink;
};
struct StackType {
	int currentLength;
	StackNode* pTop;
};
Stack* createLNKStack();
int Push(Stack* pStack, StackNode node);
StackNode* Pop(Stack* pStack);
StackNode PeekStack(Stack* pStack);
void deleteLNKStack(Stack* pStack);
int IsStackEmpty(Stack* pStack);

#pragma endregion
#pragma region Queue
typedef struct QueueNodeType QueueNode;
typedef struct QueueType Queue;

struct QueueNodeType {
	char data;
	QueueNode* pLink;
};
struct QueueType {
	int currentLength;
	QueueNode Head;
	QueueNode* pFront;
	QueueNode* pRear;
};

Queue* CreateQueue();
int Enqueue(Queue* pQueue, QueueNode element);
QueueNode* Dequeue(Queue* pQueue);
QueueNode* PeekQueue(Queue* pQueue);
void DeleteQueue(Queue* pQueue);
//int isFull(Queue* pQueue);
int isEmpty(Queue* pQueue);
#pragma endregion

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif // _COMMON_LIST_DEF_!