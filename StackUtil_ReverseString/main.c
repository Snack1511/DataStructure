#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LnkLstStack.h"
#include"StackUtil.h"

int main() {
	char* str = "Hello ma F'rend";
	printf("%s", str);
	str = reverseString(str);
	printf("%s", str);
	return 0;
}
