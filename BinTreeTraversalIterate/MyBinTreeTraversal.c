#include<stdio.h>
#include<stdlib.h>
#include"BinTree.h"
#include"BinTreeStack.h"
#include"BinTreeQueue.h"
#include"MyBinTreeTraversal.h"

void MyPreorderTraversalIterateTree(Tree* pTree) {
	if (pTree != NULL) {
		PreorderTraversalIterateTreeNode(pTree->pRootNode);
	}
	else {
		printf("전위순회를 실행할 수 없습니다.\n");
	}
	printf("------- 전위순회 종료 --------\n");
}
void PreorderTraversalIterateTreeNode(TreeNode* pTreeNode) {
	Stack* pCheckNodeStack = CreateStack();
	StackNode CheckNode = { 0, };
	TreeNode* pNextNode = pTreeNode;
	

	while (pNextNode->Visit == FALSE || IsStackEmpty(pCheckNodeStack) == FALSE) {
		if (pNextNode->Visit == FALSE) {
			printf("현재노드 %c\n", pNextNode->data);
			pNextNode->Visit = TRUE;
			CheckNode.data = pNextNode;
			Push(pCheckNodeStack, CheckNode);
		}
		else {
			Pop(pCheckNodeStack);
		}//방문및 스택에서 방문노드제거

		if (pNextNode->pLeftChild != NULL && pNextNode->pLeftChild->Visit == FALSE) {
			pNextNode = pNextNode->pLeftChild;
		}//좌측탐색
		else if (pNextNode->pRightChild != NULL && pNextNode->pRightChild->Visit == FALSE) {
			pNextNode = pNextNode->pRightChild;
		}//우측탐색
		else {
			if (IsStackEmpty(pCheckNodeStack) == FALSE) {
				pNextNode = PeekStack(pCheckNodeStack).data;
			}
		}//이전노드 귀환

	}
	DeleteStack(pCheckNodeStack);
}

void MyInorderTraversalIterateTree(Tree* pTree) {
	if (pTree != NULL) {
		InorderTraversalIterateTreeNode(pTree->pRootNode);
	}
	else {
		printf("중위순회를 실행할 수 없습니다.\n");
	}
	printf("------- 중위순회 종료 --------\n");
}
void InorderTraversalIterateTreeNode(TreeNode* pTreeNode) {
	Stack* pCheckNodeStack = CreateStack();
	StackNode CheckNode = { 0, };
	TreeNode* pNextNode = pTreeNode;

	while (pNextNode->Visit == FALSE || IsStackEmpty(pCheckNodeStack) == FALSE) {//좌측탐색
		if (pNextNode->pLeftChild != NULL && pNextNode->pLeftChild->Visit == FALSE) {
			CheckNode.data = pNextNode;
			Push(pCheckNodeStack, CheckNode);
			pNextNode = pNextNode->pLeftChild;
		}
		else {
			if (pNextNode->Visit == FALSE) {
				printf("현재노드 %c\n", pNextNode->data);
				pNextNode->Visit = TRUE;
				//현재노드 출력
				if (pNextNode->pRightChild != NULL && pNextNode->pRightChild->Visit == FALSE) {
					pNextNode = pNextNode->pRightChild;
				}//우측노드 탐색
			}
			else {
				if (IsStackEmpty(pCheckNodeStack) == FALSE) {
					pNextNode = Pop(pCheckNodeStack)->data;
				}
			}//단말 노드이거나 방문한 노드들일 경우

		}

	}
	DeleteStack(pCheckNodeStack);

	
}

void MyPostorderTraversalIterateTree(Tree* pTree) {
	if (pTree != NULL) {
		PostorderTraversalIterateTreeNode(pTree->pRootNode);
	}
	else {
		printf("후위순회를 실행할 수 없습니다.\n");
	}
	printf("------- 후위순회 종료 --------\n");
}
void PostorderTraversalIterateTreeNode(TreeNode* pTreeNode) {
	Stack* pCheckNodeStack = CreateStack();
	StackNode CheckNode = { 0, };
	TreeNode* pNextNode = pTreeNode;

	while (pNextNode->Visit == FALSE || IsStackEmpty(pCheckNodeStack) == FALSE) {
		if (pNextNode->pLeftChild != NULL && pNextNode->pLeftChild->Visit == FALSE) {
			CheckNode.data = pNextNode;
			Push(pCheckNodeStack, CheckNode);
			pNextNode = pNextNode->pLeftChild;
		}//좌측
		else {
			if (pNextNode->pRightChild != NULL && pNextNode->pRightChild->Visit == FALSE) {
				CheckNode.data = pNextNode;
				Push(pCheckNodeStack, CheckNode);
				pNextNode = pNextNode->pRightChild;
			}//우측
			else {
				printf("현재노드 %c\n", pNextNode->data);
				pNextNode->Visit = TRUE;
				if (IsStackEmpty(pCheckNodeStack) == FALSE) {
					pNextNode = Pop(pCheckNodeStack)->data;
				}
			}//현재
		}
	}
	DeleteStack(pCheckNodeStack);
}



void MyLevelTraversalIterateTree(Tree* pTree) {
	if (pTree != NULL) {
		LevelTraversalIterateTreeNode(pTree->pRootNode);
	}
	else {
		printf("레벨순회를 실행할 수 없습니다.\n");
	}
	printf("------- 레벨순회 종료 --------\n");
}
void LevelTraversalIterateTreeNode(TreeNode* pTreeNode) {
	Queue* pCheckQueue = CreateQueue();
	QueueNode CheckNode = { 0, };
	TreeNode* pNextNode = pTreeNode;

	CheckNode.data = pNextNode;
	Enqueue(pCheckQueue, CheckNode);

	while (isEmpty(pCheckQueue) == FALSE) {
		pNextNode = Dequeue(pCheckQueue)->data;
		if (pNextNode->pLeftChild != NULL) {
			CheckNode.data = pNextNode->pLeftChild;
			Enqueue(pCheckQueue, CheckNode);
		}
		if (pNextNode->pRightChild != NULL) {
			CheckNode.data = pNextNode->pRightChild;
			Enqueue(pCheckQueue, CheckNode);
		}
		printf("현재노드 %c\n", pNextNode->data);
	}
	DeleteQueue(pCheckQueue);
}

void ResetVisitInformation(Tree* pTree) {
	Stack* pCheckNodeStack = CreateStack();
	StackNode CheckNode = { 0, };
	TreeNode* pNextNode = pTree->pRootNode;

	while (pNextNode->Visit == TRUE || IsStackEmpty(pCheckNodeStack) == FALSE) {//좌측탐색
		if (pNextNode->pLeftChild != NULL && pNextNode->pLeftChild->Visit == TRUE) {
			CheckNode.data = pNextNode;
			Push(pCheckNodeStack, CheckNode);
			pNextNode = pNextNode->pLeftChild;
		}
		else {
			if (pNextNode->Visit == TRUE) {
				pNextNode->Visit = FALSE;
				//현재노드 출력
				if (pNextNode->pRightChild != NULL && pNextNode->pRightChild->Visit == TRUE) {
					pNextNode = pNextNode->pRightChild;
				}//우측노드 탐색
			}
			else {
				if (IsStackEmpty(pCheckNodeStack) == FALSE) {
					pNextNode = Pop(pCheckNodeStack)->data;
				}
			}//단말 노드이거나 방문한 노드들일 경우

		}

	}
}