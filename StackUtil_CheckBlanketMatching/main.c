#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LnkLstStack.h"
#include"StackUtil.h"

int main() {
	char* str = "Hello ma F'rend";
	printf("%s\n", str);
	str = reverseString(str);
	printf("%s", str);
	printf("\n------------------\n");
	printf("\n");

	char* strExpression1 = "((A+B+C)*D)";
	printf("%s\n", strExpression1);
	if (checkBlanketMatching(strExpression1) == TRUE) {
		printf("%s is TRUE\n", strExpression1);
		
	}
	else {
		printf("%s is FALSE\n", strExpression1);
	}
	printf("\n");

	char* strExpression2 = "((A+B)+C)*D)";
	printf("%s\n", strExpression2);
	if (checkBlanketMatching(strExpression2) == TRUE) {
		printf("%s is TRUE\n", strExpression2);

	}
	else {
		printf("%s is FALSE\n", strExpression2);
	}
	printf("\n");

	char* strExpression3 = "((A+B+C*D)";
	printf("%s\n", strExpression3);
	if (checkBlanketMatching(strExpression3) == TRUE) {
		printf("%s is TRUE\n", strExpression3);

	}
	else {
		printf("%s is FALSE\n", strExpression3);
	}
	printf("\n");

	char* strExpression4 = "({A+B+C)*D)";
	printf("%s\n", strExpression4);
	if (checkBlanketMatching(strExpression4) == TRUE) {
		printf("%s is TRUE\n", strExpression4);

	}
	else {
		printf("%s is FALSE\n", strExpression4);
	}
	printf("\n");

	char* strExpression5 = "({A+B)+C)*D)";
	printf("%s\n", strExpression5);
	if (checkBlanketMatching(strExpression5) == TRUE) {
		printf("%s is TRUE\n", strExpression5);

	}
	else {
		printf("%s is FALSE\n", strExpression5);
	}

	return 0;
}
