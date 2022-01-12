#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BinTree.h"
#include"BinTreeStack.h"

Stack* CreateStack() {
	Stack* pReturn = NULL;
	pReturn = (Stack*)malloc(sizeof(Stack));
	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(Stack));
	}
	else {
		printf("createStack �޸� �Ҵ� ����\n");
	}
	return pReturn;
}
int Push(Stack* pStack, StackNode node) {
	int ret = FALSE;
	StackNode* pNewNode;
	if (pStack != NULL) {
		pNewNode = (StackNode*)malloc(sizeof(StackNode));
		if (pNewNode != NULL) {
			*pNewNode = node;
			pNewNode->pLink = pStack->pTop;
			pStack->pTop = pNewNode;
			pStack->currentLength++;
			ret = TRUE;
		}
		else {
			printf("pushLS ��� �޸� ����\n");
		}
		
	}
	else {
		printf("pushLS ���� �޸� ����\n");
	}
}
StackNode* Pop(Stack* pStack) {
	StackNode* pReturnNode = NULL;
	if (pStack != NULL) {
		if (IsStackEmpty(pStack) == FALSE) {
			pReturnNode = (StackNode*)malloc(sizeof(StackNode));
			pReturnNode = pStack->pTop;
			pStack->pTop = pReturnNode->pLink;
			pReturnNode->pLink = NULL;
			pStack->currentLength--;
		}
		else {
			printf("popLS ����÷ο� ����\n");
		}
	}
	else {
		printf("popLS ���� �޸� ����\n");
	}
	return pReturnNode;
}
StackNode PeekStack(Stack* pStack) {
	StackNode ReturnNode = { 0, };
	if (pStack != NULL) {
		if (IsStackEmpty(pStack) == FALSE) {
			ReturnNode = *(pStack->pTop);
		}
		else {
			printf("peekLS ����÷ο� ����\n");
		}
	}
	else {
		printf("peekLs ���� �޸� ����\n");
	}
	return ReturnNode;
}
void DeleteStack(Stack* pStack) {
	StackNode* pNode = NULL;
	StackNode* pDelNode = NULL;

	if (pStack != NULL) {
		pNode = pStack->pTop;
		while (pNode != NULL) {
			pDelNode = pNode;
			pNode = pNode->pLink;
			free(pDelNode);
		}
		//	���� ����ü ��ü�� ���� �޸� ���� ������ 
		//		����� ���鿡 ���ؼ� ���� �޸� ������ �ǽ�
		free(pStack);
	}
}
int IsStackEmpty(Stack* pStack) {
	int ret = FALSE;
	if (pStack != NULL) {
		if (pStack->currentLength <= 0) {
			ret = TRUE;
		}
	}
	else {
		printf("isStackEmpty ���� �޸� ����\n");
	}
	return ret;
}