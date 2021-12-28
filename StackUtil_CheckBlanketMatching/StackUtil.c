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