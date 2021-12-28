#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ArrayStack.h"

int main() {
	ArrayStack* pStack = NULL;
	ASNode SNode;
	ASNode* pSNode = NULL;

	pStack = createArrayStack(32);

	SNode.data = 1;
	pushAS(pStack, SNode);

	SNode.data = 2;
	pushAS(pStack, SNode);

	SNode.data = 3;
	pushAS(pStack, SNode);
	pSNode = popAS(pStack);
	printf("Top is %d(using Pop)\n", pSNode->data);
	free(pSNode);
	printf("Stack Length : %d\n", pStack->currentElements);

	pSNode = popAS(pStack);
	printf("Top is %d(using Pop)\n", pSNode->data);
	free(pSNode);
	printf("Stack Length : %d\n", pStack->currentElements);

	printf("Top is %d(using Peek)\n", peekAS(pStack).data);
	printf("Stack Length : %d\n", pStack->currentElements);

	deleteArrayStack(pStack);
	return 0;
}