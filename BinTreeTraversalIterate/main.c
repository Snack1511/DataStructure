#include<stdio.h>
#include<stdlib.h>
#include"BinTree.h"
#include"BinTreeTraversal.h"
#include"MyBinTreeTraversal.h"


Tree* createExampleTree() {
	Tree* pTree = NULL;
	TreeNode* pNodeA = NULL, * pNodeB = NULL, * pNodeC = NULL,
		* pNodeD = NULL, * pNodeE = NULL, * pNodeF = NULL,
		* pNodeG = NULL, * pNodeH = NULL, * pNodeI = NULL,
		* pNodeJ = NULL, * pNodeK = NULL, * pNodeL = NULL, * pNodeM = NULL;
	TreeNode Node = { 0, };

	Node.data = 'A';
	pTree = MakeBinTree(Node);
	if (pTree != NULL) {
		pNodeA = GetRoot(pTree);

		Node.data = 'B';
		pNodeB = InsertLeftChild(pNodeA, Node);

		if (pNodeB != NULL) {
			Node.data = 'D';
			pNodeD = InsertLeftChild(pNodeB, Node);
			if (pNodeD != NULL) {
				Node.data = 'H';
				pNodeH = InsertLeftChild(pNodeD, Node);
				Node.data = 'I';
				pNodeI = InsertRightChild(pNodeD, Node);
			}

			Node.data = 'E';
			pNodeE = InsertRightChild(pNodeB, Node);
			if (pNodeE != NULL) {
				Node.data = 'J';
				pNodeJ = InsertLeftChild(pNodeE, Node);
			}
		}

		Node.data = 'C';
		pNodeC = InsertRightChild(pNodeA, Node);

		if (pNodeC != NULL) {
			Node.data = 'F';
			pNodeF = InsertLeftChild(pNodeC, Node);
			if (pNodeF != NULL) {
				Node.data = 'K';
				pNodeK = InsertRightChild(pNodeF, Node);
			}
			Node.data = 'G';
			pNodeG = InsertRightChild(pNodeC, Node);
			if (pNodeG != NULL) {
				Node.data = 'L';
				pNodeL = InsertLeftChild(pNodeG, Node);

				Node.data = 'M';
				pNodeM = InsertRightChild(pNodeG, Node);
			}
		}
		printf("예제트리 생성완료\n");
	}
	return pTree;
}

void Cut() {
	printf("\n\n");
}
int main() {
	Tree* pTree = NULL;
	pTree = createExampleTree();
	Cut();
	if (pTree != NULL) {
		printf("------- 전위순회 시작 -------\n");
		printf("--------- Book Logic --------\n");
		PreorderTraversalIterateTree(pTree);
		printf("--------- My Logic ----------\n");
		MyPreorderTraversalIterateTree(pTree);
		ResetVisitInformation(pTree);
		Cut();
		printf("------- 중위순회 시작------- \n");
		printf("--------- Book Logic --------\n");
		InorderTraversalIterateTree(pTree);
		printf("--------- My Logic ----------\n");
		MyInorderTraversalIterateTree(pTree);
		ResetVisitInformation(pTree);
		Cut();
		
		printf("------- 후위순회 시작------- \n");
		printf("--------- Book Logic --------\n");
		PostorderTraversalIterateTree(pTree);
		printf("--------- My Logic ----------\n");
		MyPostorderTraversalIterateTree(pTree);
		ResetVisitInformation(pTree);
		Cut();
		
		printf("------- 레벨순회 시작------- \n");
		printf("--------- Book Logic --------\n");
		LevelTraversalIterateTree(pTree);
		printf("--------- My Logic ----------\n");
		MyLevelTraversalIterateTree(pTree);
		ResetVisitInformation(pTree);
		Cut();

	}
	return 0;
}