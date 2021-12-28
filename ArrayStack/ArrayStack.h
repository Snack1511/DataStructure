#pragma once
#ifndef _ARRAYSTACK_
#define _ARRAYSTACK_
typedef struct ArrayStackNodeType ASNode;
typedef struct ArrayStackType ArrayStack;
struct ArrayStackNodeType {
	int data;
};
struct ArrayStackType {
	int currentElements;
	int maxElements;
	ASNode* pElements;
};
/*
	원소저장을 위해 별도의 구조체를 사용하는 이유
	1. 스택 추상 자료형의 정의를 그대로 이용하기 위해서
	2. 배열로 구현한 스택의 범용성을 높이기 위해서
*/
ArrayStack* createArrayStack(int length);
int pushAS(ArrayStack* pStack, ASNode node);
ASNode* popAS(ArrayStack* pStack);
ASNode peekAS(ArrayStack* pStack);
void deleteArrayStack(ArrayStack* pStack);
int isFullAS(ArrayStack* pStack);
int isEmptyAS(ArrayStack* pStack);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif // _COMMON_LIST_DEF_!