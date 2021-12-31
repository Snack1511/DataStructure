#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"normalLinkedListStack.h"

LinkedList* createList() {
	LinkedList* pReturn = NULL;
	pReturn = (LinkedList*)malloc(sizeof(LinkedList));
	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(LinkedList));
	}
	return pReturn;
}
int addListElement(LinkedList* pList, int position, LinkedListNode node) {
	LinkedListNode* pNewnode = NULL, *pPrevnode = NULL;
	int ret = FALSE;
	if (pList != NULL) {
		if (position >= 0 && position <= pList->currentLength) {
			pNewnode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
			if (pNewnode != NULL) {
				*pNewnode = node;
				pNewnode->pLink = NULL;
				pPrevnode = &(pList->phead);
				for (int i = 0; i < position; i++) {
					pPrevnode = pPrevnode->pLink;
				}
				pNewnode->pLink = pPrevnode->pLink;
				pPrevnode->pLink = pNewnode;
				pList->currentLength++;
				ret = TRUE;
			}
			
		}

	}
	return ret;
}
int removeElement(LinkedList* pList, int position) {
	LinkedListNode * pPrevnode = NULL, *pDelnode=NULL;
	int ret = FALSE;
	if (pList != NULL) {
		if (position >= 0 && position <= pList->currentLength) {
			pPrevnode = &(pList->phead);
			for (int i = 0; i < position-1; i++) {
				pPrevnode = pPrevnode->pLink;
			}
			pDelnode = pPrevnode->pLink;
			pPrevnode->pLink = pDelnode->pLink;
			pDelnode = NULL;
			free(pDelnode);
			pList->currentLength--;
			ret = TRUE;
		}
		

	}
	return ret;
}
LinkedListNode* GetElement(LinkedList* pList, int position) {
	LinkedListNode* pNode = NULL;
	if (pList != NULL) {
		if (position >= 0 && position <= pList->currentLength) {
			pNode = pList->phead.pLink;
			for (int i = 0; i < position-1; i++) {
				pNode = pNode->pLink;
			}

		}
	}
	return pNode;
}
LinkedListNode* GetLastElement(LinkedList* pList) {
	LinkedListNode* pNode = NULL;
	if (pList != NULL) {
		pNode = GetElement(pList, pList->currentLength);
	}
	return pNode;
}
//------- 리스트구현 -------------

int PushStack(LinkedList* pList, LinkedListNode node) {
	if (pList != NULL) {
		addListElement(pList, pList->currentLength, node);
	}
}
LinkedListNode* PopStack(LinkedList* pList) {
	LinkedListNode pReturnNode = *GetLastElement(pList);
	if (pList != NULL) {
		removeElement(pList, pList->currentLength);
	}
	return &pReturnNode;
}

//------ 스택구현 ---------------