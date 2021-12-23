/*
	81,7,4,2,6.5,8.2,7,10,5,2.5,7,7,2,3,2.3

	4*4¹è¿­
	
*/

#include<stdio.h>

int main() {
	float arr[4][4] = {
		8.1,7,4,2,6.5,8.2,7,10,5,2.5,7,7,2,3,2.3
	};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%f    ", arr[j][i]);
		}
		printf("\n");
	}

	return 0;
}