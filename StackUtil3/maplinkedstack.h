#pragma once
#ifndef _LNKLSTSTACK_
#define _LNKLSTSTACK_
typedef struct LinkedListStackNodeType LNKStackNode;
typedef struct LinkedListStackType LNKStack;

struct LinkedListStackNodeType {
	MapPosition data;
	LNKStackNode* pLink;
};
struct LinkedListStackType {
	int currentLength;
	LNKStackNode* pTop;
};
LNKStack* createLNKStack();
int pushLS(LNKStack* pStack, LNKStackNode node);
LNKStackNode* popLS(LNKStack* pStack);
LNKStackNode peekLS(LNKStack* pStack);
void deleteLNKStack(LNKStack* pStack);
int isStackEmpty(LNKStack* pStack);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif // _COMMON_LIST_DEF_!