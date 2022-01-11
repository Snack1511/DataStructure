#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"StackUtil.h"
char* reverseString(char* pSource) {
	int strlength = 0;
	char* reString = NULL;
	int index = 0;
	Stack* pStack = NULL;
	StackNode Node;
	pStack = createLNKStack();
	if (pSource != NULL) {
		strlength = strlen(pSource);
		for (int i = 0; i < strlength; i++) {
			Node.data = (int)pSource[i];
			Push(pStack, Node);
		}

		reString = (char*)malloc(sizeof(char) * (strlength+1));
		// ���� ���ڿ��� ���̺��� 1�� ũ���� �̸� ���ڿ��� �����ؾ� �Ѵ�. -->  ����� ���ڿ��� ���� �ڿ��� '\0'�� ���ٿ��� �Ѵ�.
		if (reString != NULL) {
			for (int i = 0; i < strlength; i++) {
				*(reString + i) = (char)Pop(pStack)->data;
			}
			*(reString + strlength) = '\0';
		}
		
	}
	deleteLNKStack(pStack);
	return reString;
}
/*
	strlen = �Է��Ķ���Ͱ� NULL���� �Ǿ�� �ȵȴ�.
	strcpy = ���� ���ڿ��� ���̺��� 1�� ũ���� �̸� ���ڿ��� �����ؾ� �Ѵ�.
			
*/

int checkBlanketMatching(char* pSource) {
	int ret = TRUE;
	int strLength = 0;
	Stack* pStack = NULL;
	StackNode Node;
	pStack = createLNKStack();
	strLength = strlen(pSource);
	if (pSource != NULL) {
		for (int i = 0; i < strLength; i++) {
			if (pSource[i] == '(') {
				Node.data = (int)')';
				Push(pStack, Node);
			}
			else if (pSource[i] == '{') {
				Node.data = (int)'}';
				Push(pStack, Node);
			}
			else if(pSource[i] == '['){
				Node.data = (int)']';
				Push(pStack, Node);
			}
			else {
				if (pSource[i] == ')' || pSource[i] == '}' || pSource[i] == ']') {
					if (IsStackEmpty(pStack) == FALSE) {
						if (pSource[i] != (char)Pop(pStack)->data) {
							printf("Wrong Match!!\n");
							ret = FALSE;
						}
					}
					else {
						printf("Much Blanket Count Error!!!\n");
						ret = FALSE;
					}
				}
			}
		}
	}
	if (IsStackEmpty(pStack) == FALSE) {
		printf("Less Blanket Count Error!!!\n");
		ret = FALSE;
	}
	else {
		if (ret == TRUE) {
			printf("Correct!\n");
		}
	}
	return ret;
}