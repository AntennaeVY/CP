#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<windows.h>
#include<time.h>

#define DIGITO 	 1
#define STRING 	 2
#define ALFABETO 3
#define PALABRA	 4
#define DECIMAL  5

int validar(char[], int, int);
int leer_input(char[], int);
void guardar_archivo(long long, long long, long long);
void leer_archivo(void);

void banner(void);
void menu(void);

void jugar(void);
void reglas(void);
void resumen_diario(void);

void gameloop(unsigned int, double*);
void botones(void);
void tragamonedas(char*, char*, char*);

int main() {
	while (1) {
		char opcion_str[3];
		unsigned int opcion, opcion_size;
		
		do {
			banner();
			menu();
	
			printf("\n\tSeleccione una opcion: ");
			opcion_size = leer_input(opcion_str, 3);
			opcion = atoi(opcion_str);

		} while(validar(opcion_str, opcion_size, DIGITO) == 0 || opcion_size > 1 || opcion_size <= 0 || opcion > 4 || opcion <= 0);
	
		
		switch(opcion) {
			case 1:
				jugar();
				break;
			case 2: 
				reglas();
				break;
			case 3:
				resumen_diario();
				break;
			case 4:
				return 0;
		}
	}
}


void banner() {
	system("cls");
	printf("\n\t\t***- MAQUINA TRAGAMONEDAS -***\n");
}

void menu() {
	printf("\n\t1) Jugar\n");
	printf("\n\t2) Reglas\n");
	printf("\n\t3) Resumen Diario\n");
	printf("\n\t4) Salir\n");
}

void reglas() {
	system("cls");
	
	printf("\n\t\tEl juego consiste en que, al ser accionada la palanca, las ruedas comienzan a girar,\n");
	printf("\t\tpudiendose observar el desplazamiento de las figuras a traves de la ventana; si al momento de\n");
	printf("\t\tdetenerse las tres ruedas, quedan en la ventana tres figuras iguales, el jugador gana el triple\n"); 
	printf("\t\tde lo que aposto. Si solo dos figuras son iguales, el jugador gana el doble de lo que aposto y\n");
	printf("\t\tsi las tres figuras son diferentes el jugador pierde.\n\n");
	printf("\t\tEl jugador siempre apuesta la mitad de lo que tiene, termina de jugar cuando se queda sin dinero\n");
	printf("\t\to al haberse agotado el numero de veces que quiere jugar.\n\n\n");
	
	printf("\t\t");
	system("pause");
}

void botones() {
	printf("\n\n\t[1] Accionar palanca");
	printf("\n\t[2] Salir");
}

void resumen_diario() {
	system("cls");
	printf("\n");
	leer_archivo();
	printf("\n\t\t");
	system("pause");
}

void tragamonedas(char *slot1, char *slot2, char *slot3) {
	printf("\n\n\t\t");
	printf(" ==============================");
	printf("\n\t\t");
	printf("/                              \\");
	printf("\n\t\t");
	printf("|                              |");
	printf("\n\t\t");
	printf("|     -----   -----   -----    |");
	printf("\n\t\t");
	printf("|     | %s |   | %s |   | %s |    |", slot1, slot2, slot3);
	printf("\n\t\t");
	printf("|     -----   -----   -----    |");
	printf("\n\t\t");
	printf("|                              |");
	printf("\n\t\t");
	printf("|                              |");
	printf("\n\t\t");
	printf("|                              |");
	printf("\n\t\t");
	printf("................................");
	printf("\n");

}



void jugar () {
	char intentos_str[5], dinero_str[10];
	unsigned int intentos, intentos_size, dinero_size;
	double dinero;
	
	do {
		system("cls");
		printf("\n\tIntroduce la cantidad de veces que quieres jugar (MAX 100): ");
		
		intentos_size = leer_input(intentos_str, 5);
		intentos = atoi(intentos_str);
	} while (validar(intentos_str, intentos_size, DIGITO) == 0 || intentos_size > 3 || intentos_size <= 0 || intentos > 100 || intentos <= 0);

	do {	
		system("cls");
		printf("\n\tIntroduce la cantidad inicial de dinero con la que quieres empezar (MAX 1M): ");
		
		dinero_size = leer_input(dinero_str, 10);
		dinero = atof(dinero_str);
	} while(validar(dinero_str, dinero_size, DECIMAL) == 0 || dinero_size > 11 || dinero_size <= 0 || dinero > 1000000 || dinero <= 0);
	
	gameloop(intentos, &dinero);
}

void gameloop(unsigned int intentos, double* dinero) {
	char accion_str[3];
	char *slot1[] = {"A", "B", "C", "S", "7", "Z", "X", "L", "O"};
	char *slot2[] = {"A", "B", "C", "S", "7", "Z", "X", "L", "O"};
	char *slot3[] = {"A", "B", "C", "S", "7", "Z", "X", "L", "O"};
	int accion, accion_size, apuesta = 0;
	int index1 = 4, index2 = 4, index3 = 4;
	
	char* error = "";
	
	while(intentos--) {
		do {
			banner();
			
			printf("\n\t[!] Intentos restantes: %d", intentos+1);
			printf("\n\t[$] Dinero disponible: %.2f", *dinero);
			
			botones();
			
			tragamonedas(slot1[index1], slot2[index2], slot3[index3]);
			
			printf(error);
			
			printf("\n\n\tSeleccione una opcion: ");
			
			accion_size = leer_input(accion_str, 3);
			accion = atoi(accion_str);
		} while(validar(accion_str, accion_size, DIGITO) == 0 || accion_size > 1 || accion_size <= 0 || accion > 2 || accion <= 0);
		
		if (accion == 2) return;
		
		if (*dinero < 1) {
			system("cls");
			printf("\n\tLamentablemente la cantidad de dinero con la que dispone no es suficiente para seguir jugando!\n\n\t");
			system("pause");
			return;			
		}
		
		srand(time(NULL));
		
		if (accion == 1) {
			int contador = 0;
			apuesta = (*dinero)/2;
			*dinero = (*dinero)/2;
			
			while(contador != 10) {
				index1 = rand() % sizeof(slot1)/sizeof(slot1[0]);
				index2 = rand() % sizeof(slot2)/sizeof(slot2[0]);
				index3 = rand() % sizeof(slot3)/sizeof(slot3[0]);
				
				system("cls");
				
				printf("\n\t[!] Intentos restantes: %d", intentos);
				printf("\n\t[$] Dinero disponible: %.2f", *dinero);
			
				botones();
			
				tragamonedas(slot1[index1], slot2[index2], slot3[index3]);
				
				Sleep(200);
				contador++;
			}
			
			if (slot1[index1] == slot2[index2] && slot2[index2] == slot3[index3]) {
				error = "\n\tUsted ha ganado el triple!\n";
				*dinero += 3*apuesta;
				guardar_archivo(0, 2*apuesta, 1);
			} else if (slot1[index1] == slot2[index2] || slot2[index2] == slot3[index3]) {
				error = "\n\tUsted ha ganado el doble!\n";
				*dinero += 2*apuesta;
				guardar_archivo(0, apuesta, 1);
			} else {
				error = "\n\tSiga intentando!\n";	
				guardar_archivo(apuesta, 0, 1);
			}
			
		}
		
		if (intentos == 0) {
			printf("%s\n", error);
			system("pause");
		}
	}
	
	system("cls");
	printf("\n\tIntentos agotados!\n\n\t");
	system("pause");
}

void guardar_archivo(long long recibido, long long entregado, long long jugadas) {
	time_t t = time(NULL);
	struct tm fecha = *localtime(&t);
	
	// 2022_12_31.txt = 15 + 1
	char* filename = (char*)malloc(16 * sizeof(char));
	
	// move C:\Windows\Temp\tgmtemp.txt ./2022_12_31.txt > NUL 2>&1
	char* comando = (char*)malloc((60) * sizeof(char));
	
	//	printf("now: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	snprintf(filename, 16, "%d_%02d_%02d.txt", fecha.tm_year + 1900, fecha.tm_mon + 1, fecha.tm_mday);
	snprintf(comando, 60, "move C:\\Windows\\Temp\\tgmtemp.txt ./%s 2> nul", filename);

	FILE* archivo, *archivo2;
	
	char tmp[1024], mensajes[3][1024];
	long long total_dinero_recibido = 0, total_dinero_entregado = 0, total_jugadas = 0;
	long long *arr[] = {&total_dinero_recibido, &total_dinero_entregado, &total_jugadas};
	long long arr2[] = {recibido, entregado, jugadas};
	
	if (archivo = fopen(filename, "rb")) { 
		archivo2 = fopen("C:\\Windows\\Temp\\tgmtemp.txt", "w");
		
		// Leer total, guardar en variable
		fseek(archivo, 0, SEEK_SET);
		
		int i;
		for(i = 0; i < 3; i++) {
			fgets(tmp, 1024, archivo);	
			
			sscanf(tmp, "%[^0123456789] %lld", mensajes[i], arr[i]);

			fprintf(archivo2, "%s%lld\n", mensajes[i],  *arr[i] + arr2[i]);
		}
		
		while(fgets(tmp, 1024, archivo) != NULL) {
				while(tmp[strlen(tmp) - 1] == '\n' || tmp[strlen(tmp) - 1] == '\r' ) {
					tmp[strlen(tmp) - 1] = '\0';
				}
				
				fprintf(archivo2, "%s\n", tmp);
		}
	
	} else {
		archivo2 = fopen("C:\\Windows\\Temp\\tgmtemp.txt", "w");
		
		fprintf(archivo2, "TOTAL RECIBIDO: %lld\n", recibido);
		fprintf(archivo2, "TOTAL ENTREGADO: %lld\n", entregado);
		fprintf(archivo2, "TOTAL JUGADAS: %lld\n\n", jugadas);
		
	}

				
	// Modificar total, escribir jugadas y sobreescribir total
	fprintf(archivo2, "[%02d:%02d:%02d]: Recibido = %lld, Entregado = %lld\n", fecha.tm_hour, fecha.tm_min, fecha.tm_sec, recibido, entregado);	
		
	fclose(archivo2);
	fclose(archivo);
	
	system(comando);	
}

void leer_archivo() {
	time_t t = time(NULL);
	struct tm fecha = *localtime(&t);
	char* filename = (char*)malloc(16 * sizeof(char));
	
	snprintf(filename, 16, "%d_%02d_%02d.txt", fecha.tm_year + 1900, fecha.tm_mon + 1, fecha.tm_mday);

	FILE* archivo;
	archivo = fopen(filename, "rb");
	
	if (!archivo) {
		printf("\t\tEl archivo de registro aun no existe o esta corrupto\n\n");
		fclose(archivo);
		free(filename);
		return;
	}
	
	char tmp[1024];
	
	while(fgets(tmp, 1024, archivo) != NULL) {
		while(tmp[strlen(tmp) - 1] == '\n' || tmp[strlen(tmp) - 1] == '\r' ) {
			tmp[strlen(tmp) - 1] = '\0';
		}
		
		printf("\t\t%s\n", tmp);
	}
	
	fclose(archivo);
	free(filename);
}

int validar(char buff[], int limite, int tipo) {
	int i = 0, espacio = 0, punto = 0;
	
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
			case DECIMAL:
				if (!isdigit(ch) && ch != '.' || buff[0] == '.' || punto > 1) return 0;
				else if (ch == '.') punto++;
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
