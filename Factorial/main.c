#include<stdio.h>
int Factorial(int n) {
	int ret = 0;
	if (n <= 1) {
		ret = 1;
	}
	else {
		ret = n * Factorial(n - 1);
	}
	return ret;
}
int main() {
	int n = 3;
	int result = Factorial(n);
	printf("Factorial %d : %d", n, result);
	return 0;
}