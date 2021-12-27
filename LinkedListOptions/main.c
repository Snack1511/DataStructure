#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.h"
#include"LinkedListOpt.h"

int main() {
	int i = 0;
	int arrayCount = 0;
	LinkedList* pList = NULL;
	LinkedList* pListB = NULL;
	LinkedNode* pNode = NULL;
	LinkedNode node;

	pList = createList();
	pListB = createList();
	if (pList != NULL && pListB != NULL) {
		node.data = 1;
		addLLElement(pList, 0, node);
		node.data = 3;
		addLLElement(pList, 1, node);
		node.data = 5;
		addLLElement(pList, 2, node);
		node.data = 7;
		addLLElement(pList, 3, node);
		iterateLinkedList(pList);


		node.data = 2;
		addLLElement(pListB, 0, node);
		node.data = 4;
		addLLElement(pListB, 1, node);
		node.data = 6;
		addLLElement(pListB, 2, node);
		node.data = 8;
		addLLElement(pListB, 3, node);
		iterateLinkedList(pListB);
		

		concatLinkedList(pList, pListB);
		iterateLinkedList(pList);
		
		reverseLinkedList(pList);
		iterateLinkedList(pList);


		removeLLElement(pList, 1);
		displayLinkedList(pList);

		removeLLElement(pList, 1);
		displayLinkedList(pList);

		


		displayLinkedList(pList);
		deleteLinkedList(pList);
	}
	return 0;
}