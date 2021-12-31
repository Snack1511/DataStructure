#ifndef _MAP_UTIL_
#define _MAP_UTIL_

void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LNKStack *pStack);//미로의 경로 탐색
int pushLSMapPosition(LNKStack* pStack, MapPosition data);												//Push확장
void showPath(LNKStack* pStack, int mazeArray[HEIGHT][WIDTH]);											// 찾은경로 표시
void printMaze(int mazeArray[HEIGHT][WIDTH]);															//미로 전체 표시

#endif