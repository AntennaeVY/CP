#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DIGITO 1
#define STRING 2
#define ALFABETO 3

long long int multiplicar(int a, int b) {
	return (long long int) a * b;
}

int validar(char buff[], int limite, int tipo) {
	int indice = 0;
	
	for(indice = 0; indice <= limite - 1; indice++) {
		char ch = buff[indice];
		
		switch(tipo) {
			case DIGITO: 
				if (!isdigit(ch) && !(indice == 0 && ch == '-')) return 0;
				break;
			case STRING:
				if (!isascii(ch)) return 0;
				break;
			case ALFABETO:
				if (!isalpha(ch)) return 0;
				break;
			default:
				return 0;
		}
	}
	
	return 1;
}


int main() {
	char num1[8], num2[8]; 
	int longitud_num1, longitud_num2, numero1, numero2;
	
	printf("Introduzca el primer numero: ");
	fgets(num1, 8, stdin);
	fflush(stdin);
	
	longitud_num1 = strlen(num1);
	
	if (num1[longitud_num1 - 1] == '\n') {
		num1[longitud_num1--] = '\0';
	}
	
	while(validar(num1, longitud_num1, DIGITO) == 0 ||( longitud_num1 > 6 && num1[0] == '-') || (longitud_num1 > 5 && num1[0] != '-') || longitud_num1 <= 0) {
		printf("Por favor introduzca un numero entero valido no mayor a 5 digitos\n");
		printf("Introduzca el primer numero: ");
		
		fgets(num1, 8, stdin);
		fflush(stdin);
		
		longitud_num1 = strlen(num1);
	
		if (num1[longitud_num1 - 1] == '\n') {
			num1[longitud_num1--] = '\0';
		}
	}
	
	printf("Introduzca el segundo numero: ");
	fgets(num2, 8, stdin);
	fflush(stdin);
	
	longitud_num2 = strlen(num2);
	
	if (num2[longitud_num2 - 1] == '\n') {
		num2[longitud_num2--] = '\0';
	}
	
	while(validar(num2, longitud_num2, DIGITO) == 0 ||( longitud_num2> 6 && num2[0] == '-') || (longitud_num2 > 5 && num2[0] != '-') || longitud_num2 <= 0) {
		printf("Por favor introduzca un numero entero valido no mayor a 5 digitos\n");
		printf("Introduzca el segundo numero: ");
		
		fgets(num2, 8, stdin);
		fflush(stdin);
		
		longitud_num2 = strlen(num2);
	
		if (num2[longitud_num2 - 1] == '\n') {
			num2[longitud_num2--] = '\0';
		}
	}
	
	numero1 = atoi(num1);
	numero2 = atoi(num2);
	
	system("cls");
	
	printf("La multiplicacion de %d y %d es: %lld\n", numero1, numero2, multiplicar(numero1, numero2));
	
	return 0;
}

