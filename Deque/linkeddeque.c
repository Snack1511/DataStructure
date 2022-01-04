#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include"linkeddeque.h"

Deque* CreateDeque() {
	Deque* pReturn = NULL;
	pReturn = (Deque*)malloc(sizeof(Deque));
	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(Deque));
	}
	else {
		printf("pReturn 메모리 할당 오류\n");
	}
	return pReturn;
}

int InsertFront(Deque* pDeque, DequeNode element) {
	int ret = FALSE;
	DequeNode *pNode = NULL;
	if (pDeque != NULL) {
		pNode = (DequeNode*)malloc(sizeof(DequeNode));
		if (pNode != NULL) {
			*pNode = element;
			pNode->pLLink = NULL;
			pNode->pRLink = NULL;
			if (isEmpty(pDeque) == TRUE) {
				pDeque->pFront = pNode;
				pDeque->pRear = pNode;
			}
			else {
				pDeque->pFront->pLLink = pNode;
				pNode->pRLink = pDeque->pFront;
				pDeque->pFront = pNode;
			}
			pDeque->currentLength++;
			ret = TRUE;
		}
	}
	else {
		printf("pDeque 메모리 할당 오류 : InsertFront\n");
	}
	return ret;
}
int InsertRear(Deque* pDeque, DequeNode element) {
	int ret = FALSE;
	DequeNode* pNode = NULL;
	if (pDeque != NULL) {
		pNode = (DequeNode*)malloc(sizeof(DequeNode));
		if (pNode != NULL) {
			*pNode = element;
			pNode->pLLink = NULL;
			pNode->pRLink = NULL;
			if (isEmpty(pDeque) == TRUE) {
				pDeque->pFront = pNode;
				pDeque->pRear = pNode;
			}
			else {
				pDeque->pRear->pRLink = pNode;
				pNode->pLLink = pDeque->pRear;
				pDeque->pRear = pNode;
			}
			pDeque->currentLength++;
			ret = TRUE;
		}
	}
	else {
		printf("pDeque 메모리 할당 오류 : InsertRear\n");
	}
	return ret;
}
DequeNode* DeleteFront(Deque* pDeque) {
	DequeNode* pReturn = NULL;
	if (pDeque != NULL) {
		if (isEmpty(pDeque) == FALSE) {
			pReturn = pDeque->pFront;
			if (pDeque->currentLength == 1) {
				pDeque->pFront = NULL;
				pDeque->pRear = NULL;
			}
			else {
				pDeque->pFront = pReturn->pRLink;
				pDeque->pFront->pLLink = NULL;
			}
			pReturn->pRLink = NULL;
			pDeque->currentLength--;
		}
		else {
			printf("언더플로우 오류 : DeleteFront \n");
		}
	}
	else {
		printf("pDeque 메모리 할당 오류 : DeleteFront\n");
	}
	return pReturn;
}
DequeNode* DeleteRear(Deque* pDeque) {
	DequeNode* pReturn = NULL;
	if (pDeque != NULL) {
		if (isEmpty(pDeque) == FALSE) {
			pReturn = pDeque->pRear;
			if (pDeque->currentLength == 1) {
				pDeque->pFront = NULL;
				pDeque->pRear = NULL;
			}
			else {
				pDeque->pRear = pReturn->pLLink;
				pDeque->pRear->pRLink = NULL;
			}
			pReturn->pLLink = NULL;
			pDeque->currentLength--;
		}
		else {
			printf("언더플로우 오류 : DeleteFront \n");
		}
	}
	else {
		printf("pDeque 메모리 할당 오류 : DeleteRear\n");
	}
	return pReturn;
	
}
DequeNode* PeekFront(Deque* pDeque) {
	DequeNode* pReturn = NULL;
	if (pDeque != NULL) {
		pReturn = pDeque->pFront;
	}
	else {
		printf("pDeque 메모리 할당 오류 : DeleteRear\n");
	}
	return pReturn;
}
DequeNode* PeekRear(Deque* pDeque) {

	DequeNode* pReturn = NULL;
	if (pDeque != NULL) {
		pReturn = pDeque->pRear;
	}
	else {
		printf("pDeque 메모리 할당 오류 : DeleteRear\n");
	}
	return pReturn;
	
}
void DeleteDeque(Deque* pDeque) {
	DequeNode* DelNode;
	if (pDeque != NULL) {
		if (isEmpty(pDeque) == FALSE) {
			while (isEmpty(pDeque) == FALSE) {
				DelNode = DeleteRear(pDeque);
				free(DelNode);
			}
		}
		free(pDeque);
	}
	printf("Complete DeleteDeque\n");
}
int isEmpty(Deque* pDeque) {
	if (pDeque->currentLength <= 0) {
		return TRUE;
	}
	else {
		return FALSE;
	}

}
