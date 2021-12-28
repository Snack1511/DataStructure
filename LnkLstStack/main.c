#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LnkLstStack.h"



int main() {
	LNKStack* pStack;
	LNKStackNode Node;
	LNKStackNode* pNode;

	pStack = createLNKStack();
	Node.data = 1;
	pushLS(pStack, Node);
	Node.data = 2;
	pushLS(pStack, Node);
	Node.data = 3;
	pushLS(pStack, Node);

	pNode = popLS(pStack);
	printf("Pop %d\n", pNode->data);
	printf("Stack Length : %d\n", pStack->currentLength);

	Node = peekLS(pStack);
	printf("Peek %d\n", Node.data);
	printf("Stack Length : %d\n", pStack->currentLength);

	deleteLNKStack(pStack);
	return 0;
}