#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"MyCircularlist_headernode.h"


CircleList* createCList() {
	CircleList* pReturn;
	pReturn = (CircleList*)malloc(sizeof(CircleList));
	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(pReturn));
		pReturn->Header.pLink = &(pReturn->Header);
	}
	return pReturn;
}
int addCLElements(CircleList* pList, int position, CircleNode Value) {
	int ret = FALSE;
	CircleNode* pPrev;
	CircleNode* pValue;
	pValue = (CircleNode*)malloc(sizeof(CircleNode));
	if (pValue == NULL) {
		printf("메모리 할당 오류 addCLElements()\n");
		return ret;
	}
	*pValue = Value;
	pValue->pLink = NULL;
	if (pList != NULL) {
		if (position >= 0 && position <= pList->currentElementLength) {
			pPrev =&( pList->Header);
			for (int i = 0; i < position; i++) {
				pPrev = pPrev->pLink;
			}
			pValue->pLink = pPrev->pLink;
			pPrev->pLink = pValue;
			pList->currentElementLength++;
			ret = TRUE;
		}
	}
	return ret;
}
int removeCLElements(CircleList* pList, int position) {
	int rt = FALSE;
	CircleNode* pTarget, *pPrev, *pLastNode;
	if (pList != NULL) {
		if (position >= 0 && position < pList->currentElementLength) {
			pPrev = &(pList->Header);
			for (int i = 0; i < position; i++) {
				pPrev = pPrev->pLink;
			}
			pTarget = pPrev->pLink;
			pPrev->pLink = pTarget->pLink;
			pTarget = NULL;
			free(pTarget);
			pList->currentElementLength--;
			rt = TRUE;
		}
	}
	return rt;
}
CircleNode* getCLNode(CircleList* pList, int position) {
	CircleNode* pTarget = NULL;
	if (pList != NULL) {
		if (position >= 0&&pList->currentElementLength > 0) {
			if (position > pList->currentElementLength) {
				position %= pList->currentElementLength;
			}
			pTarget = pList->Header.pLink;
			for (int i = 0; i < position; i++) {
				pTarget = pTarget->pLink;
			}
		}
	}
	return pTarget;
	
}
void deleteCList(CircleList* pList) {
	clearCList(pList);
	pList = NULL;
	free(pList);
}
void clearCList(CircleList* pList) {
	CircleNode* pTarget;
	if (pList != NULL) {
		pTarget = &(pList->Header);
		for (int i = 0; i < pList->currentElementLength; i++) {
			if (pTarget->pLink != NULL) {
				CircleNode* pDelete;
				pDelete = pTarget;
				pTarget = pTarget->pLink;
				free(pDelete);
			}
		}
		pList->Header.pLink = NULL;
		pList->currentElementLength = 0;
	}
}
int getCListLength(CircleList* pList) {
	int length = 0;
	if (pList != NULL) {
		length = pList->currentElementLength;
	}
	return length;
}
void displayCircularList(CircleList* pList) {
	if (pList != NULL) {
		for (int i = 0; i < pList->currentElementLength; i++) {
			printf("[%d] %d    ", i, getCLNode(pList, i)->Data);
		}
		printf("\n");
	}
}