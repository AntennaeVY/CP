#include<stdio.h>
#include<stdlib.h>

void imprimir_mensaje(char str[]) {
	printf("%s", str);
}

int main() {
	char str[] = "Hola! Mi nombre es Jose!\n";
	
	imprimir_mensaje(str);	
}
