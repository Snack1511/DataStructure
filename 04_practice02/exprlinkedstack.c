#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"exprdef.h"
#include"exprlinkedstack.h"
LNKStack* createLNKStack() {
	LNKStack* pReturn = NULL;
	pReturn = (LNKStack*)malloc(sizeof(LNKStack));
	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(LNKStack));
		printf("메모리 할당 및 초기화 완료!\n");
	}
	else {
		printf("createLNKStack 메모리 할당 오류\n");
	}
	return pReturn;
}
int pushLS(LNKStack* pStack, LNKStackNode node) {
	int ret = FALSE;
	LNKStackNode* pNewNode;
	if (pStack != NULL) {
		pNewNode = (LNKStackNode*)malloc(sizeof(LNKStackNode));
		if (pNewNode != NULL) {
			*pNewNode = node;
			pNewNode->pLink = pStack->pTop;
			pStack->pTop = pNewNode;
			pStack->currentLength++;
			ret = TRUE;
			printf("Push 성공!\n");
		}
		else {
			printf("pushLS 노드 메모리 오류\n");
		}

	}
	else {
		printf("pushLS 스택 메모리 오류\n");
	}
}
LNKStackNode* popLS(LNKStack* pStack) {
	LNKStackNode* pReturnNode = NULL;
	if (pStack != NULL) {
		if (isStackEmpty(pStack) == FALSE) {
			pReturnNode = (LNKStackNode*)malloc(sizeof(LNKStackNode));
			pReturnNode = pStack->pTop;
			pStack->pTop = pReturnNode->pLink;
			pReturnNode->pLink = NULL;
			pStack->currentLength--;
		}
		else {
			printf("popLS 언더플로우 오류\n");
		}
	}
	else {
		printf("popLS 스택 메모리 오류\n");
	}
	return pReturnNode;
}
LNKStackNode peekLS(LNKStack* pStack) {
	LNKStackNode ReturnNode = { 0, };
	if (pStack != NULL) {
		if (isStackEmpty(pStack) == FALSE) {
			ReturnNode = *(pStack->pTop);
		}
		else {
			printf("peekLS 언더플로우 오류\n");
		}
	}
	else {
		printf("peekLs 스택 메모리 오류\n");
	}
	return ReturnNode;
}
void deleteLNKStack(LNKStack* pStack) {
	LNKStackNode* pNode = NULL;
	LNKStackNode* pDelNode = NULL;

	if (pStack != NULL) {
		pNode = pStack->pTop;
		while (pNode != NULL) {
			pDelNode = pNode;
			pNode = pNode->pLink;
			free(pDelNode);
		}
		//	스택 구조체 자체에 대한 메모리 해제 이전에 
		//		저장된 노드들에 대해서 먼저 메모리 해제를 실시
		printf("저장된 메모리 해제 완료\n");
		free(pStack);
		printf("스택 메모리 해제 완료\n");
	}
}
int isStackEmpty(LNKStack* pStack) {
	int ret = FALSE;
	if (pStack != NULL) {
		if (pStack->currentLength <= 0) {
			ret = TRUE;
		}
	}
	else {
		printf("isStackEmpty 스택 메모리 오류\n");
	}
	return ret;
}