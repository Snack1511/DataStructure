#include<stdio.h>


/*
1 : 1. C

2 : 1. B -> C
2 : 2. C

3 : 1. C -> B -> A -> C
3 : 2. B -> C
3 : 3. C

4 : 1. B -> C -> A -> B -> C -> A -> B -> C
4 : 2. C -> B -> A- > C
4 : 3. B -> C
4 : 4. C

5 : 1. C -> B -> A -> C -> B -> A -> C -> B -> A -> C -> B -> A -> C -> B -> A -> C
5 : 2. B -> C -> A -> B -> C -> A -> B -> C
5 : 3. C -> B -> A- > C
5 : 4. B -> C
5 : 5. C

6 : 1. B -> C -> A -> B -> C -> A -> B -> C -> A -> B -> C -> A -> B -> C -> A -> B -> C -> A -> B -> C -> A -> B -> C -> A -> B -> C
6 : 2. C -> B -> A -> C -> B -> A -> C -> B -> A -> C -> B -> A -> C -> B -> A -> C
6 : 3. B -> C -> A -> B -> C -> A -> B -> C
6 : 4. C -> B -> A- > C
6 : 5. B -> C
6 : 6. C

*/
void Hanoi(int n, char Base, char Tmp, char Goal) {
	if (n == 1) {
		printf("%d : %c %c\n", n, Base ,Goal);
	}
	else {
		Hanoi(n - 1, Base, Tmp, Goal);
		printf("%d : %c %c\n", n, Base ,Goal);
		Hanoi(n - 1, Tmp, Base, Goal);

	}
}//시작과 임시가 달라지는 것을 알고리즘의 기준으로 삼음

int main() {
	int Count = 3;
	Hanoi(4, 'A', 'B', 'C');
	return 0;
}