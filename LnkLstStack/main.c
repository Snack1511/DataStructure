#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LnkLstStack.h"



int main() {
	Stack* pStack;
	StackNode Node;
	StackNode* pNode;

	pStack = createLNKStack();
	Node.data = 1;
	Push(pStack, Node);
	Node.data = 2;
	Push(pStack, Node);
	Node.data = 3;
	Push(pStack, Node);

	pNode = Pop(pStack);
	printf("Pop %d\n", pNode->data);
	printf("Stack Length : %d\n", pStack->currentLength);

	Node = Peek(pStack);
	printf("Peek %d\n", Node.data);
	printf("Stack Length : %d\n", pStack->currentLength);

	deleteLNKStack(pStack);
	return 0;
}