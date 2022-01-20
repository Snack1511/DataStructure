#ifndef _LINKEDDEQUE_
#define _LINKEDDEQUE_

typedef struct DequeNodeType DequeNode;
typedef struct DequeType Deque;

struct DequeNodeType {
	char data;
	DequeNode* pLLink;
	DequeNode* pRLink;

};
struct DequeType {
	int currentLength;
	DequeNode* pFront;
	DequeNode* pRear;
};

Deque* CreateDeque();
int InsertFront(Deque* pDeque, DequeNode element);
int InsertRear(Deque* pDeque, DequeNode element);
DequeNode* DeleteFront(Deque* pDeque);
DequeNode* DeleteRear(Deque* pDeque);
DequeNode* PeekFront(Deque* pDeque);
DequeNode* PeekRear(Deque* pDeque);
void DeleteDeque(Deque* pDeque);
int IsQueueEmpty(Deque* pDeque);


#endif
#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif // _COMMON_LIST_DEF_! 