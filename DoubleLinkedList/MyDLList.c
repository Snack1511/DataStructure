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
		printf("�޸� �Ҵ� �� �ʱ�ȭ �Ϸ�!\n");
	}
	else {
		printf("�޸� �Ҵ� ����!\n");
	}
	return pReturn;
}
void deleteDLList(DoubleLinkedList* pList) {
	if (pList != NULL) {
		clearDLList(pList);
		free(pList);
		printf("����Ʈ ���� �Ϸ�!\n");
	}
	else {
		printf("pList�� NULL�Դϴ�!\n");
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
		printf("����Ʈ �ʱ�ȭ �Ϸ�!\n");
	}
	else {
		printf("pList�� NULL�Դϴ�!\n");
	}
}
int addDLElements(DoubleLinkedList* pList, int position, DLNode Value) {
	int ret = FALSE;
	DLNode *pNewNode, *pPrevNode;
	

	if (pList != NULL) {
		if (position >= 0 && position <= pList->currentElementLength) {
			pNewNode = (DLNode*)malloc(sizeof(DLNode));
			if (pNewNode == NULL) {
				printf("�޸��Ҵ����\n");
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
			printf("[%d]��(��) ��ġ �ε����� ���� �����ϴ�.\n", position);
		}
	}
	else {
		printf("pList�� NULL�Դϴ�!\n");
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
			printf("[%d]��(��) ��ġ �ε����� ���� �����ϴ�.\n", position);
		}
	}
	else {
		printf("pList�� NULL�Դϴ�!\n");
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