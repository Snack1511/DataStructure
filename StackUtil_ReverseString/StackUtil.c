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
	return reString;
}