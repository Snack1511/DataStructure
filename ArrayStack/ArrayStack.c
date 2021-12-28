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
			printf("createArrayStack �޸� �Ҵ� ����1 \n");
			return NULL;
		}
		pReturn->pElements = (ASNode*)malloc(sizeof(ASNode) * length);
		if (pReturn->pElements != NULL) {
			memset(pReturn->pElements, 0, sizeof(ASNode) * length);
		}
		else {
			printf("createArrayStack �޸� �Ҵ� ����2 \n");
			free(pReturn);
			return NULL;
		}
	}
	else {
		printf("�ִ���� ���� : %d\n", length);
	}
	return pReturn;
}
/*
	����ü �ҽ���ȭ�� ������ ������ ���� �Լ�memset�� ���
	--> �ҽ��� ����/�����ϴ� ����� ���ҽ�Ű�� ������ ����
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
			printf("pushAS �����÷ο� ����\n");
		}
	}
	else {
		printf("pushAS �޸� ����\n");
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
				printf("popAS �޸𸮿���2\n");
			}
		}
		else {
			printf("popAS ����÷ο� ����\n");
		}
	}
	else {
		printf("popAS �޸𸮿���\n");
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
		printf("���� ���� �Ϸ�\n");
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
		printf("isFullAS �޸� ����\n");
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
		printf("isEmptyAS �޸� ����\n");
		ret = TRUE;
	}
	return ret;
}