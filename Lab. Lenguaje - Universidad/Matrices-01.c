#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX 100
#define MAX2 20
#define MAX_DIG 3
#define MAX_DIG_ART 4
#define DIGITO 1
#define STRING 2
#define ALFABETO 3
#define PALABRA 4

int validar(char buff[], int limite, int tipo);
int leer_input(char buff[], int longitud);

int main() {
	char vendedores[MAX][MAX2+1], vendedor[MAX2+2], n_str[MAX_DIG+2], articulo[MAX_DIG_ART+2];
	int articulos[MAX][3], suma[MAX], min_sum=2e9, min_i, max_sum=0, max_i, articulo_len, vendedor_len, n_str_len, n, i, j;
	
	printf("Introduzca la cantidad de vendedores: ");
	n_str_len = leer_input(n_str, MAX_DIG+2);
	
	while(validar(n_str, n_str_len, DIGITO) == 0 || n_str_len >= 4 || atoi(n_str) > 100) {
		printf("Introduzca un entero positivo valido, no mayor a 100: ");
		n_str_len = leer_input(n_str, MAX_DIG+2);
	}
	
	n = atoi(n_str);
	
	system("cls");
	
	for(i=0; i < n; i++) {
		printf("VENDEDOR ACTUAL: %d\nVENDEDORES RESTANTES: %d\n\n", i+1, n-i-1);
		
		printf("Nombre del Vendedor %d: ", i+1);
		vendedor_len = leer_input(vendedor, MAX2+2);
		
		while(validar(vendedor, vendedor_len, PALABRA) == 0 || vendedor_len > 20) {
			printf("Por favor introducir un nombre valido, no mayor a 20 caracteres\n");
			printf("Nombre del Vendedor %d: ", i+1);
			
			vendedor_len = leer_input(vendedor, MAX2+2);
		}
		
		strcpy(vendedores[i], vendedor);
		
		system("cls");
	}
	
	for(i=0; i < n; i++) {
		int sum = 0;
		
		for(j=0; j < 3; j++) {
			printf("Introduzca la cantidad de ART%d vendidos por %s: ", j+1, vendedores[i]);
			articulo_len = leer_input(articulo, MAX_DIG_ART+2);
			
			
			while(validar(articulo, articulo_len, DIGITO) == 0 || atoi(articulo) > 9999) {
				printf("Por favor introduzca una cantidad valida, no mayor a %d digitos\n", MAX_DIG_ART);
				printf("Introduzca la cantidad de ART%d vendidos por %s: ", i+1, vendedores[i]);
				
				articulo_len = leer_input(articulo, MAX_DIG_ART+2);
			}
			
			articulos[i][j] = atoi(articulo);
			sum += atoi(articulo);
			
			system("cls");
		}
		
		suma[i] = sum;
		
		if (sum < min_sum){
			min_sum = sum;
			min_i = i;	
		} 
		
		if (sum > max_sum) {
			max_sum = sum;
			max_i = i;		
		} 
	}
	
	printf("VENDEDOR CON MAS VENTAS: %s (%d VENTAS)\n", vendedores[max_i], max_sum);
	printf("VENDEDOR CON MENOS VENTAS: %s (%d VENTAS)\n\n", vendedores[min_i], min_sum);
	
	printf("VENDEDOR\t\t\tART1\t\t\tART2\t\t\tART3");
	
	for(i=0; i < n; i++) {
		printf("\n%s\t\t\t", vendedores[i]);
		for(j=0; j < 3; j++) {
			printf("%d\t\t\t", articulos[i][j]);
		}
	}

}

int validar(char buff[], int limite, int tipo) {
	int i = 0, espacio = 0;
	
	for(; i < limite; i++) {
		char ch = buff[i];
		
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
			case PALABRA:
				if (!isalpha(ch) && ch != 0x20 || buff[0] == 0x20) return 0;
				
				if (ch == 0x20 && espacio) {
					return 0;
				} else if (ch == 0x20 && !espacio) {
					espacio = 1;
				} else {
					espacio = 0;
				}
				
				break;
		}
		
	}
}

int leer_input(char buff[], int longitud) {
	fgets(buff, longitud, stdin);
	fflush(stdin);
	
	int str_len = strlen(buff);
	
	if (buff[str_len - 1] == '\n' || buff[str_len - 1] == 0x20) {
		buff[--str_len] = '\0';
	}
	
	return str_len;
}