#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int Fib_ReCursion(int n) {
	int ret = 0;
	if (n == 0) {
		ret = 0;
	}
	else if(n == 1){
		ret = 1;
	}
	else {
		ret = Fib_ReCursion(n - 1) + Fib_ReCursion(n - 2);
	}
	return ret;
}

int Fib_iter(int n) {
	int Result = 0, PrevResult = 0;
	int temp = 0;
	if (n > 0) {
		Result = 1;
		if (n > 1) {
			for (int i = 2; i <= n; i++) {
				temp = Result + PrevResult;
				PrevResult = Result;
				Result = temp;
			}

		}
	}
	return Result;
}
int main() {
	int m = Fib_ReCursion(6);
	int n = Fib_iter(6);
	printf("Fib_ReCursion 6 : %d\n", m);
	printf("FIb_Iter 6 : %d\n", n);
	printf("---------------------------\n");
	double resultTime_Recursion = 0;
	double resultTime_Iteration = 0;
	int count = 42;
	clock_t t = clock();
	m = Fib_ReCursion(count);
	resultTime_Recursion = (clock() - t)/CLOCKS_PER_SEC;
	t = clock();
	n = Fib_iter(count);
	resultTime_Iteration = (clock() - t) / CLOCKS_PER_SEC;
	printf("Fib_ReCursion %d : %d     Duration : %lf\n", count, m, resultTime_Recursion);
	printf("FIb_Iter %d : %d     Duration : %lf\n", count, n, resultTime_Iteration);
}