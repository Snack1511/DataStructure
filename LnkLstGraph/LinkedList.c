#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkedList.h"
LinkedList* createList() {
	LinkedList* pReturn = (LinkedList*)malloc(sizeof(LinkedList));
	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(LinkedList));
	}
	return pReturn;
}
int addLLElement(LinkedList* pList, int position, LinkedNode Node) {
	LinkedNode* next = NULL;
	LinkedNode* prev = NULL;
	if (pList != NULL) {
		if (position >= 0 && position <= pList->currentElementCount) {
			next = (LinkedNode*)malloc(sizeof(LinkedNode));
			if (next != NULL) {
				*next = Node;
				next->pNextNode = NULL;

				prev = &(pList->headerNode);
				for (int i = 0; i < position; i++) {
					prev = prev->pNextNode;
				}
				next->pNextNode = prev->pNextNode;
				prev->pNextNode = next;

				pList->currentElementCount++;
			}
			
		}
	}

}
int removeLLElement(LinkedList* pList, int position) {
	LinkedNode* prev = NULL;
	LinkedNode* target = NULL;
	if (pList != NULL) {
		if (position >= 0 && position < pList->currentElementCount) {
			prev = &(pList->headerNode);
			for (int i = 0; i < position; i++) {
				prev = prev->pNextNode;
			}
			target = prev->pNextNode;
			prev->pNextNode = target->pNextNode;

			free(target);
			pList->currentElementCount--;
		}
	}
}

LinkedNode* getLLElement(LinkedList* pList, int position) {
	LinkedNode* pReturn = NULL;
	if (pList != NULL) {
		if (position >= 0 && position <= pList->currentElementCount) {
			pReturn = &(pList->headerNode);
			for (int i = 0; i < position; i++) {
				pReturn = pReturn->pNextNode;
			}
		}
	}
	return pReturn;
}
void displayLinkedList(LinkedList* pList) {
	LinkedNode* target = NULL;
	if (pList != NULL) {
		target = &(pList->headerNode);
		for (int i = 0; i < pList->currentElementCount; i++) {
			target = target->pNextNode;
			printf("%d\t", target->data);
		}
		printf("\n");
	}
}

void deleteLinkedList(LinkedList* pList) {
	if (pList != NULL) {
		clearLinkedList(pList);
	}
	free(pList);
	printf("deleteLinkedList\n");
}
void clearLinkedList(LinkedList* pList){
	LinkedNode* prev = NULL;
	LinkedNode* target = NULL;

	if (pList != NULL) {
		prev = pList->headerNode.pNextNode;
		for (int i = 1; i < pList->currentElementCount; i++) {
			target = prev;
			prev = prev->pNextNode;
			free(target);
		}
		pList->currentElementCount = 0;
	}
	printf("clearLinkedList\n");
}

int GetPosition(LinkedList* pList, LinkedNode Node) {
	int ret = 0;
	if (pList != NULL) {
		LinkedNode* pPrev = NULL;
		pPrev = pList->headerNode.pNextNode;

		while (pPrev->data.vertID != Node.data.vertID) {
			pPrev = pPrev->pNextNode;
			ret++;
		}
	}
	return ret;
}