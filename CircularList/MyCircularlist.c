#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"MyCircularlist.h"


CircleList* createCList() {
	CircleList* pReturn;
	pReturn = (CircleList*)malloc(sizeof(CircleList));
	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(pReturn));
	}
	return pReturn;
}
int addCLElements(CircleList* pList, int position, CircleNode Value) {
	int ret = FALSE;
	CircleNode* pPrev;
	CircleNode* pValue;
	if (pList != NULL) {
		if (position >= 0) {
			pValue = (CircleNode*)malloc(sizeof(CircleNode));
			if (pValue == NULL) {
				printf("메모리 할당 오류 addCLElements()\n");
				return ret;
			}
			*pValue = Value;
			pValue->pLink = NULL;
			if (pList->currentElementLength == 0) {
				pList->pHeader = pValue;
				pValue->pLink = pList->pHeader;
				pList->currentElementLength++;
			}
			else {
				if (position <= pList->currentElementLength) {
					pPrev = pList->pHeader;
					for (int i = 0; i < position-1; i++) {
						pPrev = pPrev->pLink;
					}
					pValue -> pLink = pPrev -> pLink;
					pPrev->pLink = pValue;
					pList->currentElementLength++;
				}
				else {
					ret = FALSE;
				}
			}
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
			if (position == 0) {
				pTarget = pList->pHeader;
				if (pList->currentElementLength == 1) {
					free(pTarget);
					pList->pHeader = NULL;
				}
				else {
					pLastNode = pList->pHeader;
					while (pLastNode->pLink != pList->pHeader) {
						pLastNode = pLastNode->pLink;
					}
					pLastNode->pLink = pTarget->pLink;
					pList->pHeader = pTarget->pLink;
					free(pTarget);
				}
			}
			else {
				pPrev = pList->pHeader;
				for (int i = 0; i < position - 1; i++) {
					pPrev = pPrev->pLink;
				}
				pTarget = pPrev->pLink;
				pPrev->pLink = pTarget->pLink;
				free(pTarget);
			}
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
			pTarget = pList->pHeader;
			for (int i = 0; i < position; i++) {
				pTarget = pTarget->pLink;
			}
		}
	}
	return pTarget;
	
}
void deleteCList(CircleList* pList) {
	if (pList != NULL) {
		clearCList(pList);
		free(pList);
	}
}
void clearCList(CircleList* pList) {
	CircleNode* pTarget;
	if (pList != NULL) {
		pTarget = pList->pHeader;
		for (int i = 0; i < pList->currentElementLength; i++) {
			if (pTarget->pLink != NULL) {
				CircleNode* pDelete;
				pDelete = pTarget;
				pTarget = pTarget->pLink;
				free(pDelete);
			}
		}
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