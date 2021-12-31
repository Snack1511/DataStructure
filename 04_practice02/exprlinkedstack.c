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
		printf("�޸� �Ҵ� �� �ʱ�ȭ �Ϸ�!\n");
	}
	else {
		printf("createLNKStack �޸� �Ҵ� ����\n");
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
			printf("Push ����!\n");
		}
		else {
			printf("pushLS ��� �޸� ����\n");
		}

	}
	else {
		printf("pushLS ���� �޸� ����\n");
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
			printf("popLS ����÷ο� ����\n");
		}
	}
	else {
		printf("popLS ���� �޸� ����\n");
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
			printf("peekLS ����÷ο� ����\n");
		}
	}
	else {
		printf("peekLs ���� �޸� ����\n");
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
		//	���� ����ü ��ü�� ���� �޸� ���� ������ 
		//		����� ���鿡 ���ؼ� ���� �޸� ������ �ǽ�
		printf("����� �޸� ���� �Ϸ�\n");
		free(pStack);
		printf("���� �޸� ���� �Ϸ�\n");
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
		printf("isStackEmpty ���� �޸� ����\n");
	}
	return ret;
}