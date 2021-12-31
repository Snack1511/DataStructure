#ifndef _MAP_DEF_
#define _MAP_DEF_

#define WIDTH 8
#define HEIGHT 8

#define NUM_DIRECTION 4
typedef struct MapPositionType MapPosition;
//offset : x, y
static int DIRECTION_OFFSETS[NUM_DIRECTION][2] = {
	{0, -1},	//위쪽으로 이동
	{1, 0},		//오른쪽으로 이동
	{0, 1},		//아래쪽으로 이동
	{-1, 0}		//왼쪽으로 이동
};
/*
	이동가능 방향을 표현하는 배열변수 DIRECTION_OFFSET[]을 static으로 선언한 이유는
	프로그램 상에서 유일하게 1개의 인스턴스를 가지도록 하기 위해서이다.
*/
enum PosStatus {NOT_VISIT = 0, VISIT = 1, WALL = 2};
struct MapPositionType {
	int x;
	int y;
	int direction;
};
#endif