#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

#define DIGITO 	 1
#define PALABRA  2
#define NEGATIVO 3

int validar(char[], int, int);
int leer_input(char[], int);

void banner(void);
void menu(void);

void encriptar(char*, int*);
void desencriptar(int*, int*);
void encriptar_y_desencriptar(void);

int matriz_encriptacion[3][3] = {{1, -2, 2}, {-1, 1, 3}, {1, -1, -4}};
int matriz_desencriptacion[3][3] = {{-1, -10, -8}, {-1, -6, -5}, {0, -1, -1}};


int main() {
	char opcion_str[3], mensaje[32], longitud_mensaje_encriptado_str[4], *error="", mensaje_encriptado_digito_str[6];
	int opcion, opcion_size, mensaje_size, mensaje_encriptado_size, longitud_mensaje_encriptado_size, longitud_mensaje_encriptado;
	int mensaje_encriptado[30], mensaje_encriptado_digito, mensaje_encriptado_digito_size, i;
	
	while(1) {
		error = "";
	
		do  {
			banner();
			menu();	
			
			printf("%s", error);
			printf("\t\tSeleccione una opcion: ");
		
			opcion_size = leer_input(opcion_str, 3);
		
			opcion = atoi(opcion_str);
		
			error = "\t\tPor favor introduzca una opcion valida!\n\n";
		} while (validar(opcion_str, opcion_size, DIGITO) == 0 || opcion_size > 1 || opcion <= 0 || opcion > 4 );

	
	
		switch(opcion) {
			case 1:
				error = "";
				
				do  {
					system("cls");
	
					printf("%s", error);
					printf("\t\tPor favor introduzca el mensaje a encriptar: "); 
					mensaje_size = leer_input(mensaje, 32);
	
					error = "\t\tSolo letras y espacios. Maximo 30 caracteres\n\n";
	
				} while (validar(mensaje, mensaje_size, PALABRA) == 0 || mensaje_size <= 0 || mensaje_size > 30);
				
				encriptar(mensaje, &mensaje_size);
				break;
			
			case 2:
				error = "";
				
				do  {
					system("cls");
	
					printf("%s", error);
					printf("\t\tPor favor introduzca la cantidad de numeros del mensaje a desencriptar: "); 
					longitud_mensaje_encriptado_size = leer_input(longitud_mensaje_encriptado_str, 4);
					longitud_mensaje_encriptado = atoi(longitud_mensaje_encriptado_str);
	
					error = "\t\tLongitud invalida, solo se aceptan numeros multiplos de 3. Maximo 30 de longitud\n\n";
	
				} while (
							validar(longitud_mensaje_encriptado_str, longitud_mensaje_encriptado_size, DIGITO) == 0 
							|| longitud_mensaje_encriptado_size <= 0 || longitud_mensaje_encriptado_size > 2 
							|| longitud_mensaje_encriptado <= 0 || longitud_mensaje_encriptado > 30
							|| longitud_mensaje_encriptado%3 != 0
				);
				
				for(i=0; i < longitud_mensaje_encriptado; i++) {
					error = "";
					
					do {
						printf("%s", error);
						
						printf("\t\tIntroduzca el numero (%d/%d): ", i+1, longitud_mensaje_encriptado);
						mensaje_encriptado_digito_size = leer_input(mensaje_encriptado_digito_str, 5);
						mensaje_encriptado_digito = atoi(mensaje_encriptado_digito_str);
						
						error = "\t\tNumero invalido!\n\n";
							
					} while (
							validar(mensaje_encriptado_digito_str, mensaje_encriptado_digito_size, NEGATIVO) == 0
							|| mensaje_encriptado_digito_size > 4 || mensaje_encriptado_digito_size <= 0
							|| mensaje_encriptado_digito > 130 || mensaje_encriptado_digito < -104
					);
					
					mensaje_encriptado[i] = mensaje_encriptado_digito;
				}
				
				desencriptar(mensaje_encriptado, &longitud_mensaje_encriptado);
				break;
			
			case 3:
				encriptar_y_desencriptar();
				break;
				
			case 4:
				return 0;
				break;	
		}	
	}
	

}

void banner() {
	system("cls");
	printf("\t\t***-ENCRIPTADOR Y DESENCRIPTADOR-***\n\n");
}

void menu() {
	printf("\t\t1) Encriptar un mensaje\n");
	printf("\t\t2) Desencriptar un mensaje\n");
	printf("\t\t3) Encriptar y desencriptar un mensaje\n");
	printf("\t\t4) Salir\n\n");

}

void encriptar(char* mensaje, int* mensaje_size) {
	system("cls");
	int i, j, k;

	for(i=0; i < (3-*(mensaje_size)%3)%3; i++) {
		mensaje[*(mensaje_size)+i] = ' ';
	}
	
	*(mensaje_size) += (3-*(mensaje_size)%3)%3;	
	mensaje[*mensaje_size] = '\0';

	
	int filas = (int)ceil((double)(*mensaje_size)/3.0);
	int* matriz = malloc(filas * 3 * sizeof(int));
	int* matriz_encriptada = malloc(filas * 3 * sizeof(int));
	
	memset(matriz_encriptada, 0, filas * 3 * sizeof(int));

	for(i=0; i < filas; i++) {
		for(j=0; j < 3; j++) {
			char ch = *(mensaje + i*3 + j);
			int num = 0;
			
			if (ch == ' ') 
				num = 0;
			else 
				num = (int)tolower(ch) - 96;
			
			*(matriz + i*3 + j) = num;
		}
	}

	// Multiplicacion de matrices
	
	for(i=0; i < filas; i++) {
		for(j=0; j < 3; j++) {
			for(k=0; k < 3; k++) {
				*(matriz_encriptada + i*3 + j) +=  *(matriz + i*3 + k) * matriz_encriptacion[k][j];
			}
		}
	}
	
	printf("\t\tEl mensaje encriptado es:\n\n\t\t");
	
	for(i=0; i < filas; i++) {
		for(j=0; j < 3; j++) {
			printf("%d ", 	*(matriz_encriptada + i*3 + j) );
		}
	}
	
	printf("\n\n\t\t");
	system("pause");
	free(matriz);	
	free(matriz_encriptada);
}

void desencriptar(int* mensaje, int* mensaje_size) {
	system("cls");
	
	int i,j, k;
	
	int* matriz_desencriptada = malloc(*mensaje_size * sizeof(int));
	memset(matriz_desencriptada, 0, *mensaje_size * sizeof(int));
	
	for(i=0; i < *mensaje_size/3; i++) {
		for(j=0; j < 3; j++) {
			for(k=0; k < 3; k++) {
				*(matriz_desencriptada + i*3 + j) +=  *(mensaje + i*3 + k) * matriz_desencriptacion[k][j];
			}
		}
	}
	
	char* mensaje_desencriptado = (char*)malloc(*mensaje_size * sizeof(char));
	
	for(i=0; i < *mensaje_size/3; i++) {
		for(j=0; j < 3; j++) {
			if (*(matriz_desencriptada + i*3 + j) != 0) {
				*(mensaje_desencriptado + i*3 + j) = (char)(*(matriz_desencriptada + i*3 + j) + 96);			
			} else {
				*(mensaje_desencriptado + i*3 + j) = ' ';
			}

		}
	}
	
	*(mensaje_desencriptado + *mensaje_size) = '\0';
	
	printf("\t\tEl mensaje desencriptado es:");
	printf("\n\n\t\t%s\n\n\t\t", mensaje_desencriptado);
	
	system("pause");
	free(matriz_desencriptada);
	free(mensaje_desencriptado);
}

void encriptar_y_desencriptar() {
	char mensaje[32], *error="";
	int mensaje_size, i, j, k;
	
	error = "";
	
	do  {
		system("cls");

		printf("%s", error);
		printf("\t\tPor favor introduzca el mensaje a encriptar: "); 
		mensaje_size = leer_input(mensaje, 32);

		error = "\t\tSolo letras y espacios. Maximo 30 caracteres\n\n";

	} while (validar(mensaje, (mensaje_size), PALABRA) == 0 || mensaje_size <= 0 || mensaje_size > 30);
	
	encriptar(mensaje, &mensaje_size);

	printf("\n\n\t\t");
	
	printf("El mensaje desencriptado es:\n\n\t\t%s\n\n\t\t", mensaje);
	
	system("pause");
}

int validar(char buff[], int limite, int tipo) {
	int i = 0, espacio = 0, punto = 0;
	
	for(; i < limite; i++) {
		char ch = buff[i];
		
		switch(tipo) {
			case DIGITO: 
				if (!isdigit(ch)) return 0;
				break;
			case PALABRA:
				if (!isalpha(ch) && ch != 0x20) return 0;
				break;
			case NEGATIVO:
				if (!isdigit(ch) && !(ch == '-' && i == 0)) return 0;
				break;
		}
		
	}
}

int leer_input(char buff[], int longitud) {
	fgets(buff, longitud, stdin);
	fflush(stdin);
	
	int str_len = strlen(buff);
	
	if (buff[str_len - 1] == '\n') {
		buff[--str_len] = '\0';
	}
	
	return str_len;
}
