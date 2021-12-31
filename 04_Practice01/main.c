#include<stdio.h>
#include<stdlib.h>
#include"normalLinkedListStack.h"

int main() {
	LinkedList* pList = NULL;
	pList = createList();
	LinkedListNode node;
	LinkedListNode* pNode = NULL;
	node.data = 1;
	PushStack(pList, node);
	node.data = 2;
	PushStack(pList, node);
	node.data = 3;
	PushStack(pList, node);
	pNode = PopStack(pList);
	printf("%d\n", pNode->data);
	pNode = PopStack(pList);
	printf("%d\n", pNode->data);
	pNode = PopStack(pList);
	printf("%d\n", pNode->data);
	return 0;
}