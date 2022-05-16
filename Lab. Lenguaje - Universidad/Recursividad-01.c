#include<stdio.h>
#include<string.h>
#include<stdlib.h>

long long fib(int n) {
	if (n <= 1) return n==1;
	
	return fib(n-1) + fib(n-2);
}

long long fibIt(int n) {
	long long next = 1, prev = 0, temp = 0;
	
	while(--n) {
		temp = next;
		next = next + prev;
		prev = temp;
	}
	
	return next;
}

long long FIB[1001];

int fibOp(unsigned int n) {
	if(FIB[n] != -1) return FIB[n];
	
	return fibOp(n-1) + fibOp(n-2);
}

int main() {
	memset(FIB, -1, sizeof(FIB));
	FIB[0] = 0;
	FIB[1] = 1;
	
	unsigned int n;
	
	do {
		printf("Ingrese un entero positivo valido (0-1000): ");
		fflush(stdin);
	} while(scanf("%d", &n) != 1 || n < 0 || n > 1000); 
	
	printf("%lli\n", fibOp(n));
	printf("%lli\n", fib(n));
	printf("%lli\n", fibIt(n));
}
