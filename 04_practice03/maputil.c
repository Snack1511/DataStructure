#include<stdio.h>
#include<stdlib.h>
#include"mapdef.h"
#include"maplinkedstack.h"
#include"maputil.h"

int pushLSMapPosition(LNKStack* pStack, MapPosition data) {
	LNKStackNode node = { 0, };
	node.data = data;
	return pushLS(pStack, node);
}
void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LNKStack* pStack) {
	LNKStackNode* pNode = NULL;
	int isEmpty = FALSE, isFound = FALSE, i = 0;
	int markArray[HEIGHT][WIDTH] = {0, };

	if (pStack != NULL) {
		MapPosition newPosition = startPos;
		newPosition.direction = 0;
		pushLSMapPosition(pStack, newPosition);
		//�Ա� ��ġ�� ���ÿ� Ǫ��
		while (isEmpty == FALSE && isFound == FALSE) {
			//������ �ٸ� ���� �ְ�, ���� �ⱸ�� ��ã�Ҵٸ� ��θ� ��� ã�´�.
			pNode = popLS(pStack);
			//���ÿ��� ��ġ ���� �� �������� ��

			if (pNode != NULL) {
				int x = pNode->data.x;
				int y = pNode->data.y;

				int direction = pNode->data.direction;
				
				while (isFound == FALSE && direction < NUM_DIRECTION) {
					//�� ��ġ���� ���� ������ ���� ������ �ִ°�?

					int newX = x + DIRECTION_OFFSETS[direction][0];
					int newY = y + DIRECTION_OFFSETS[direction][1];

					if (newX >= 0 && newX < WIDTH &&			//newX�� ���� �� �϶�
						newY >= 0 && newY < HEIGHT &&			//newY�� ���� �� �϶�
						mazeArray[newY][newX] == NOT_VISIT &&	//�̷ι迭�� �ش��ε����� �湮���°� �ƴ� ��
						markArray[newY][newX] == NOT_VISIT)		//��ŷ�迭�� �ش��ε����� �湮���°� �ƴ� ��
					{
						MapPosition newPosition;
						newPosition.x = x;
						newPosition.y = y;
						newPosition.direction = direction + 1;
						pushLSMapPosition(pStack, newPosition);
						markArray[y][x] = VISIT;
						//�̵� �����ϴٸ� ������ ��ġ ���� �� ���� ������ ���ÿ� Ǫ��

						x = newX;
						y = newY;
						direction = 0;
						//����ġ�� �̵�, �� �̶� ���������� �ʱ�ȭ

						if (newX == endPos.x && newY == endPos.y) {
							isFound = TRUE;
							newPosition.x = newX;
							newPosition.y = newY;
							newPosition.direction = 0;
							pushLSMapPosition(pStack, newPosition);
							markArray[newY][newX] = VISIT;
							//�ⱸ�� ã�� ��� ������ �ⱸ ��ġ�� ���ÿ� Ǫ��
						}
					
					}
					else {
						direction++;
					}
					//������ ���⿡ ���� ���ο� ��ġ�� �̵��� �� ���ٸ� �ٸ� �������� �õ�
				}//end of while
				free(pNode);
			}//end of if
			isEmpty = isStackEmpty(pStack);
			//���̻� ������ ��ġ�� �ִ� �� ����
		}//end of while
	}


}
void showPath(LNKStack* pStack, int mazeArray[HEIGHT][WIDTH]) {
	LNKStackNode* pNode = NULL;
	int resultArray[HEIGHT][WIDTH] = { 0, };
	int isEmpty = FALSE;

	int i, j;
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			resultArray[i][j] = mazeArray[i][j];
		}
	}

	if (pStack != NULL) {
		i = 0;
		while (isEmpty == FALSE) {
			pNode = popLS(pStack);
			if (pNode != NULL) {
				int x = pNode->data.x;
				int y = pNode->data.y;

				resultArray[y][x] = VISIT;

				if (i > 0) {
					printf(" <-- ");
				}
				printf("<%d, %d>", x, y);

				i++;
				free(pNode);
			}
			isEmpty = isStackEmpty(pStack);
		}
		printf("\n");
		printMaze(resultArray);
	}
}
void printMaze(int mazeArray[HEIGHT][WIDTH]) {
	int i, j;
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			if (mazeArray[i][j] == WALL) {
				printf("*");
			}
			else if (mazeArray[i][j] == VISIT) {
				printf(".");
			}
			else {
				printf(" ");
			}

		}
		printf("\n");
	}
}