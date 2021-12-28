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
	���������� ���� ������ ����ü�� ����ϴ� ����
	1. ���� �߻� �ڷ����� ���Ǹ� �״�� �̿��ϱ� ���ؼ�
	2. �迭�� ������ ������ ���뼺�� ���̱� ���ؼ�
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