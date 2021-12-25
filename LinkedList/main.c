#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.h"

int main() {
	int i = 0;
	int arrayCount = 0;
	LinkedList* pList = NULL;
	LinkedNode* pNode = NULL;
	LinkedNode node;

	pList = createList();
	if (pList != NULL) {
		node.data = 1;
		addLLElement(pList, 0, node);
		node.data = 3;
		addLLElement(pList, 1, node);
		node.data = 5;
		addLLElement(pList, 2, node);
		node.data = 7;
		addLLElement(pList, 3, node);
		displayLinkedList(pList);

		removeLLElement(pList, 1);
		displayLinkedList(pList);

		removeLLElement(pList, 1);
		displayLinkedList(pList);

		

		node.data = 1;
		addLLElement(pList, 0, node);
		node.data = 2;
		addLLElement(pList, 1, node);
		node.data = 2;
		addLLElement(pList, 2, node);
		node.data = 9;
		addLLElement(pList, 3, node);
		displayLinkedList(pList);
		deleteLinkedList(pList);
	}
	return 0;
}