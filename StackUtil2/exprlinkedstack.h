#pragma once
#ifndef _LNKLSTSTACK_
#define _LNKLSTSTACK_
typedef struct BinTreeStackNodeType StackNode;
typedef struct BinTreeStackType Stack;

struct BinTreeStackNodeType {
	ExprToken data;
	StackNode* pLink;
};
struct BinTreeStackType {
	int currentLength;
	StackNode* pTop;
};
Stack* createLNKStack();
int Push(Stack* pStack, StackNode node);
StackNode* Pop(Stack* pStack);
StackNode Peek(Stack* pStack);
void deleteLNKStack(Stack* pStack);
int IsStackEmpty(Stack* pStack);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif // _COMMON_LIST_DEF_!