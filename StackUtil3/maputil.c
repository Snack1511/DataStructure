#include<stdio.h>
#include<stdlib.h>
#include"mapdef.h"
#include"maplinkedstack.h"
#include"maputil.h"

int pushLSMapPosition(Stack* pStack, MapPosition data) {
	StackNode node = { 0, };
	node.data = data;
	return Push(pStack, node);
}
/*
	findPath
	mazeArray : 지도를 표현하는 2차원 배열
	start/endPos : 출발/도착 위치
	pStack : 실제 앍리즘에 의해 탐색된 경로 
		--> findPath를 호출하는 외부에서 미리 메모리를 할당하고 그 포인터를 전달해줘야 함
		--> 즉, findPath함수는 입력과 출려그이 역할을 모두 수행하는 일종의 In-Out파라미터
*/
void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, Stack* pStack) {
	StackNode* pNode = NULL;
	int isEmpty = FALSE, isFound = FALSE, i = 0;
	int markArray[HEIGHT][WIDTH] = {0, }; // 함수 내부의 미로의 위치별 방문여부

	if (pStack != NULL) {
		MapPosition newPosition = startPos;
		newPosition.direction = 0;
		pushLSMapPosition(pStack, newPosition);
		//입구 위치를 스택에 푸시
		while (isEmpty == FALSE && isFound == FALSE) {
			//움직일 다른 곳이 있고, 아직 출구를 못찾았다면 경로를 계속 찾는다.
			pNode = Pop(pStack);
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
			isEmpty = IsStackEmpty(pStack);
			//더이상 움직일 위치가 있는 지 점검
		}//end of while
	}


}
void showPath(Stack* pStack, int mazeArray[HEIGHT][WIDTH]) {
	StackNode* pNode = NULL;
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
			pNode = Pop(pStack);
			if (pNode != NULL) {
				int x = pNode->data.x;
				int y = pNode->data.y;

				resultArray[y][x] = VISIT;

				if (i > 0) {
					printf(" <- ");
				}
				printf("<%d, %d>", x, y);

				i++;
				free(pNode);
			}
			isEmpty = IsStackEmpty(pStack);
		}
		printf("\n");
		printf("--------------ResultArray\n");
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