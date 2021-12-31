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
		//입구 위치를 스택에 푸시
		while (isEmpty == FALSE && isFound == FALSE) {
			//움직일 다른 곳이 있고, 아직 출구를 못찾았다면 경로를 계속 찾는다.
			pNode = popLS(pStack);
			//스택에서 위치 정보 및 방향정보 팝

			if (pNode != NULL) {
				int x = pNode->data.x;
				int y = pNode->data.y;

				int direction = pNode->data.direction;
				
				while (isFound == FALSE && direction < NUM_DIRECTION) {
					//현 위치에서 아직 가보지 못한 방향이 있는가?

					int newX = x + DIRECTION_OFFSETS[direction][0];
					int newY = y + DIRECTION_OFFSETS[direction][1];

					if (newX >= 0 && newX < WIDTH &&			//newX가 범위 내 일때
						newY >= 0 && newY < HEIGHT &&			//newY가 범위 내 일때
						mazeArray[newY][newX] == NOT_VISIT &&	//미로배열의 해당인덱스가 방문상태가 아닐 떼
						markArray[newY][newX] == NOT_VISIT)		//마킹배열의 해당인덱스가 방문상태가 아닐 때
					{
						MapPosition newPosition;
						newPosition.x = x;
						newPosition.y = y;
						newPosition.direction = direction + 1;
						pushLSMapPosition(pStack, newPosition);
						markArray[y][x] = VISIT;
						//이동 가능하다면 현재의 위치 정보 및 방향 정보를 스택에 푸시

						x = newX;
						y = newY;
						direction = 0;
						//새위치로 이동, 단 이때 방향정보는 초기화

						if (newX == endPos.x && newY == endPos.y) {
							isFound = TRUE;
							newPosition.x = newX;
							newPosition.y = newY;
							newPosition.direction = 0;
							pushLSMapPosition(pStack, newPosition);
							markArray[newY][newX] = VISIT;
							//출구를 찾은 경우 마지막 출구 위치를 스택에 푸시
						}
					
					}
					else {
						direction++;
					}
					//기존의 방향에 의한 새로운 위치로 이동할 수 없다면 다른 방향으로 시도
				}//end of while
				free(pNode);
			}//end of if
			isEmpty = isStackEmpty(pStack);
			//더이상 움직일 위치가 있는 지 점검
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