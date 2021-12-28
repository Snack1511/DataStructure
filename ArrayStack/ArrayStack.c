#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "ArrayStack.h"


ArrayStack* createArrayStack(int length) {
	ArrayStack* pReturn = NULL;
	if (length > 0) {
		pReturn = (ArrayStack*)malloc(sizeof(ArrayStack));
		if (pReturn != NULL) {
			memset(pReturn, 0, sizeof(ArrayStack));
			pReturn->maxElements = length;
			
		}
		else {
			printf("createArrayStack 메모리 할당 오류1 \n");
			return NULL;
		}
		pReturn->pElements = (ASNode*)malloc(sizeof(ASNode) * length);
		if (pReturn->pElements != NULL) {
			memset(pReturn->pElements, 0, sizeof(ASNode) * length);
		}
		else {
			printf("createArrayStack 메모리 할당 오류2 \n");
			free(pReturn);
			return NULL;
		}
	}
	else {
		printf("최대길이 오류 : %d\n", length);
	}
	return pReturn;
}
/*
	구조체 소스변화에 독립된 구현을 위해 함수memset을 사용
	--> 소스를 유지/보수하는 비용을 감소시키는 장점이 존재
*/
int pushAS(ArrayStack* pStack, ASNode node) {
	int ret = FALSE;
	if (pStack != NULL) {
		if (isFullAS(pStack) == FALSE) {
			pStack->pElements[pStack->currentElements] = node;
			pStack->currentElements++;
			ret = TRUE;
		}
		else {
			printf("pushAS 오버플로우 오류\n");
		}
	}
	else {
		printf("pushAS 메모리 오류\n");
	}
	return ret;
}
ASNode* popAS(ArrayStack* pStack) {
	ASNode* pNodeReturn = NULL;
	if (pStack != NULL) {
		if (isEmptyAS(pStack) == FALSE) {
			pNodeReturn = (ASNode*)malloc(sizeof(ASNode));
			if (pNodeReturn != NULL) {
				*pNodeReturn = pStack->pElements[pStack->currentElements-1];
				memset(&(pStack->pElements[pStack->currentElements-1]), 0, sizeof(ASNode));
				pStack->currentElements--;
			}
			else {
				printf("popAS 메모리오류2\n");
			}
		}
		else {
			printf("popAS 언더플로우 오류\n");
		}
	}
	else {
		printf("popAS 메모리오류\n");
	}
	return pNodeReturn;
}
ASNode peekAS(ArrayStack* pStack) {
	ASNode ReturnNode = {0, };
	if (pStack != NULL) {
		ReturnNode = pStack->pElements[pStack->currentElements - 1];
	}
	return ReturnNode;
}
void deleteArrayStack(ArrayStack* pStack) {
	if (pStack != NULL) {
		if (pStack->pElements != NULL) {
			free(pStack->pElements);
		}
		free(pStack);
		printf("스택 삭제 완료\n");
	}
}
int isFullAS(ArrayStack* pStack) {
	int ret = FALSE;
	if (pStack != NULL) {
		if (pStack->currentElements >= pStack->maxElements) {
			ret = TRUE;
		}
	}
	else {
		printf("isFullAS 메모리 오류\n");
		ret = TRUE;
	}
	return ret;
}
int isEmptyAS(ArrayStack* pStack) {
	int ret = FALSE;
	if (pStack != NULL) {
		if (pStack->currentElements - 1 < 0) {
			ret = TRUE;
		}
	}
	else {
		printf("isEmptyAS 메모리 오류\n");
		ret = TRUE;
	}
	return ret;
}