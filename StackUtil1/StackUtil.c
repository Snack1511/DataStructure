#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"StackUtil.h"
char* reverseString(char* pSource) {
	int strlength = 0;
	char* reString = NULL;
	int index = 0;
	LNKStack* pStack = NULL;
	LNKStackNode Node;
	pStack = createLNKStack();
	if (pSource != NULL) {
		strlength = strlen(pSource);
		for (int i = 0; i < strlength; i++) {
			Node.data = (int)pSource[i];
			pushLS(pStack, Node);
		}

		reString = (char*)malloc(sizeof(char) * (strlength+1));
		// 원본 문자열의 길이보다 1이 크도록 미리 문자열을 생성해야 한다. --> 복사된 문자열의 제일 뒤에는 '\0'을 덧붙여야 한다.
		if (reString != NULL) {
			for (int i = 0; i < strlength; i++) {
				*(reString + i) = (char)popLS(pStack)->data;
			}
			*(reString + strlength) = '\0';
		}
		
	}
	deleteLNKStack(pStack);
	return reString;
}
/*
	strlen = 입력파라미터가 NULL값이 되어서는 안된다.
	strcpy = 원본 문자열의 길이보다 1이 크도록 미리 문자열을 생성해야 한다.
			
*/

int checkBlanketMatching(char* pSource) {
	int ret = TRUE;
	int strLength = 0;
	LNKStack* pStack = NULL;
	LNKStackNode Node;
	pStack = createLNKStack();
	strLength = strlen(pSource);
	if (pSource != NULL) {
		for (int i = 0; i < strLength; i++) {
			if (pSource[i] == '(') {
				Node.data = (int)')';
				pushLS(pStack, Node);
			}
			else if (pSource[i] == '{') {
				Node.data = (int)'}';
				pushLS(pStack, Node);
			}
			else if(pSource[i] == '['){
				Node.data = (int)']';
				pushLS(pStack, Node);
			}
			else {
				if (pSource[i] == ')' || pSource[i] == '}' || pSource[i] == ']') {
					if (isStackEmpty(pStack) == FALSE) {
						if (pSource[i] != (char)popLS(pStack)->data) {
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
	if (isStackEmpty(pStack) == FALSE) {
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