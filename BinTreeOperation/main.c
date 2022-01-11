#include<stdio.h>
#include<stdlib.h>

#include"BinTree.h"
#include"BinTreeOp.h"


Tree* CreateExampleTree() {
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
		printf("����Ʈ�� �����Ϸ�\n");
	}
	return pTree;
}

int main() {
	int CompareResult = FALSE;
	int Count = 0;
	Tree* pTree = NULL, * pCopyTree = NULL;

	pTree = CreateExampleTree();
	printf("����Ʈ�� ����\n");
	DisplayTree(pTree);

	pCopyTree = CopyBinTree(pTree);
	printf("����Ʈ�� ���纻\n");
	DisplayTree(pCopyTree);

	CompareResult = EqualBinTree(pTree, pCopyTree);
	printf("\n����Ʈ�� �񱳰�� : (%d)\n", CompareResult);

	Count = GetNodeCountTree(pTree);
	printf("\n����Ʈ�� ��尳�� : %d\n", Count);
	
	Count = GetLeafNodeCountTree(pTree);
	printf("\n����Ʈ�� �ܸ����� : %d\n", Count);

	Count = GetHeightTree(pTree);
	printf("\n����Ʈ�� ���� : %d\n", Count);
	return 0;
}