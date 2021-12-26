#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"MyDLList.h"

DoubleLinkedList* createDLList() {
	DoubleLinkedList* pReturn;
	pReturn = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(DoubleLinkedList));
		pReturn->Header.pLLink = &(pReturn->Header);
		pReturn->Header.pRLink = &(pReturn->Header);
		printf("메모리 할당 및 초기화 완료!\n");
	}
	else {
		printf("메모리 할당 오류!\n");
	}
	return pReturn;
}
void deleteDLList(DoubleLinkedList* pList) {
	if (pList != NULL) {
		clearDLList(pList);
		free(pList);
		printf("리스트 제거 완료!\n");
	}
	else {
		printf("pList가 NULL입니다!\n");
	}
}
void clearDLList(DoubleLinkedList* pList) {
	DLNode *pDeleteNode, *pNextNode;
	if (pList != NULL) {
		pDeleteNode = &(pList->Header);
		for (int i = 0; i < pList->currentElementLength; i++) {
			if (pDeleteNode != NULL) {
				pNextNode = pDeleteNode->pRLink;
				pDeleteNode->pLLink = NULL;
				pDeleteNode->pRLink = NULL;
				pDeleteNode = pNextNode;
			}
		}
		printf("리스트 초기화 완료!\n");
	}
	else {
		printf("pList가 NULL입니다!\n");
	}
}
int addDLElements(DoubleLinkedList* pList, int position, DLNode Value) {
	int ret = FALSE;
	DLNode *pNewNode, *pPrevNode;
	

	if (pList != NULL) {
		if (position >= 0 && position <= pList->currentElementLength) {
			pNewNode = (DLNode*)malloc(sizeof(DLNode));
			if (pNewNode == NULL) {
				printf("메모리할당오류\n");
				return ret;
			}
			*pNewNode = Value;
			pNewNode->pLLink = NULL;
			pNewNode->pRLink = NULL;

			pPrevNode = &(pList->Header);
			for (int i = 0; i < position; i++) {
				pPrevNode = pPrevNode->pRLink;
			}
			pNewNode->pLLink = pPrevNode;
			pNewNode->pRLink = pPrevNode->pRLink;
			pPrevNode->pRLink = pNewNode;
			pNewNode->pRLink->pLLink = pNewNode;
			pList->currentElementLength++;
			ret = TRUE;
		}
		else{
			printf("[%d]은(는) 위치 인덱스를 벗어 났습니다.\n", position);
		}
	}
	else {
		printf("pList가 NULL입니다!\n");
	}
	return ret;
}
int removeDLElements(DoubleLinkedList* pList, int position) {
	int ret = 0;
	DLNode* pPrevNode, * pDeleteNode;
	if (pList != NULL) {
		if (position >= 0 && position <= pList->currentElementLength) {
			pPrevNode = &(pList->Header);
			for (int i = 0; i < position; i++) {
				pPrevNode = pPrevNode->pRLink;
			}
			pDeleteNode = pPrevNode->pRLink;
			pPrevNode->pRLink = pDeleteNode->pRLink;
			pPrevNode->pRLink->pLLink = pPrevNode;
			free(pDeleteNode);
			pList->currentElementLength--;
			ret = TRUE;
		}
		else {
			printf("[%d]은(는) 위치 인덱스를 벗어 났습니다.\n", position);
		}
	}
	else {
		printf("pList가 NULL입니다!\n");
	}
	return ret;
}
int getDLListLength(DoubleLinkedList* pList) {
	int length = pList->currentElementLength;
	return length;
}
DLNode getDLNode(DoubleLinkedList* pList, int position) {
	DLNode* pIter;
	DLNode Target;
	if (pList != NULL) {
		if (position >= 0 && position <= pList->currentElementLength) {
			pIter = pList->Header.pRLink;
			for (int i = 0; i < position; i++) {
				pIter = pIter->pRLink;
			}
			Target = *(pIter);
		}
	}
	return Target;
}
void displayDLList(DoubleLinkedList* pList) {
	for (int i = 0; i < pList->currentElementLength; i++) {
		printf("[%d] %d    ", i, getDLNode(pList, i).Data);
	}
	printf("\n");
}