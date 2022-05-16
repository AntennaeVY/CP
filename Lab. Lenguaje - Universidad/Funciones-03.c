#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX					2048
#define MAX_DIG_FILAS		2
#define	MAX_DIG_COLUMNAS	2
#define DIGITO				1
#define	STRING				2				
#define	ALFABETO			3

void imprimir_con_borde(char* mensaje, int longitud, int f, int c); 

int validar(char buff[], int limite, int tipo);

int main() {
	char str[MAX+2], filas_str[MAX_DIG_FILAS+2], columnas_str[MAX_DIG_COLUMNAS+2];
	int longitud_cadena, longitud_filas, longitud_columnas;
	int filas, columnas;
	
	system("cls");
	
	printf("Ingrese el numero de filas del recuadro: ");
	fgets(filas_str, MAX_DIG_FILAS + 2, stdin);
	fflush(stdin);
	
	longitud_filas = strlen(filas_str);
	
	if (filas_str[longitud_filas - 1] == '\n') { 
		filas_str[longitud_filas - 1] = '\0';
		longitud_filas--;
	}
	
	while(validar(filas_str, longitud_filas, DIGITO) == 0 || longitud_filas > MAX_DIG_FILAS || (filas_str[0] < '5' && filas_str[1] == '\0') ) {
		printf("Por favor ingrese un numero valido de %d digitos mayor o igual a 5\n", MAX_DIG_FILAS);
		printf("Ingrese el numero de filas del recuadro: ");
		fgets(filas_str, MAX_DIG_FILAS + 2, stdin);
		fflush(stdin);
		
		longitud_filas = strlen(filas_str);
	
		if (filas_str[longitud_filas - 1] == '\n') { 
			filas_str[longitud_filas - 1] = '\0';
			longitud_filas--;
		}
		
	}
	
	filas = atoi(filas_str);
	
	printf("Ingrese el numero de columnas del recuadro: ");
	fgets(columnas_str, MAX_DIG_COLUMNAS + 2, stdin);
	fflush(stdin);
	
	longitud_columnas = strlen(columnas_str);
	
	if (columnas_str[longitud_columnas - 1] == '\n') { 
		columnas_str[longitud_columnas - 1] = '\0';
		longitud_columnas--;
	}
	
	while(validar(columnas_str, longitud_columnas, DIGITO) == 0 || longitud_columnas > MAX_DIG_COLUMNAS || (columnas_str[0] < '5' && columnas_str[1] == '\0')) {
		printf("Por favor ingrese un numero valido de %d digitos mayor o igual a 5\n", MAX_DIG_COLUMNAS);
		printf("Ingrese el numero de columnas del recuadro: ");
		fgets(columnas_str, MAX_DIG_COLUMNAS + 2, stdin);
		fflush(stdin);
		
		longitud_columnas = strlen(columnas_str);
	
		if (columnas_str[longitud_columnas - 1] == '\n') { 
			columnas_str[longitud_columnas - 1] = '\0';
			longitud_columnas--;
		}
		
	}
	
	columnas = atoi(columnas_str);
	
	printf("Ingrese la cadena a imprimir: ");	
	
	fgets(str, MAX+2, stdin);
	fflush(stdin);
	
	longitud_cadena = strlen(str);
	
	if (str[longitud_cadena - 1] == '\n') {
		str[longitud_cadena - 1] = '\0';
		longitud_cadena--;
	}
	
	while (validar(str, longitud_cadena, STRING) == 0 || longitud_cadena > MAX) {
		printf("Por favor solo caracteres ASCII validos hasta 2048 caracteres\n");
		printf("Ingrese la cadena a imprimir: ");	
	
		fgets(str, MAX+2, stdin);
		fflush(stdin);
		
		longitud_cadena = strlen(str);
	
		if (str[longitud_cadena - 1] == '\n') {
			str[longitud_cadena - 1] = '\0';
			longitud_cadena--;
		}
	}
	
	system("cls");	
	imprimir_con_borde(str, longitud_cadena, filas, columnas);
}

void imprimir_con_borde(char* mensaje, int longitud, int f, int c) {
	int filas = f, columnas = c, posicion = 0;
	
	int i, j;
	
	for(i=0; i < columnas; i++) {		
		printf("*");
	}										
	
	printf("\n");
	
	for(i=0; i < (longitud/(columnas-4)) + (longitud%columnas != 0); i++) {
		printf("* ");
		
		for(j=0; j < columnas - 4; j++) {
			
			if (posicion > (columnas - 4) * (i+1)) {
				break;
			}
			
			if (posicion < longitud) {
				if (isprint(mensaje[posicion])) {
					printf("%c", mensaje[posicion]);
				}
				posicion++;
			} else {
				printf(" ");
			}
		}
		
		printf(" *\n");
	}
	
	for(i=0; i < columnas; i++) {
		printf("*");
	}
	
	printf("\n");
}

int validar(char buff[], int limite, int tipo) {
	int indice = 0;
	
	while(indice <= limite - 1) {
		char ch = buff[indice];
		
		switch(tipo) {
			case DIGITO: 
				if (!isdigit(ch)) return 0;
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
		
		indice++;
	}
	
	return 1;
}

