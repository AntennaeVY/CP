#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define ARR_SIZE 10
#define STR_SIZE 20

#define DIGIT 1
#define ALPHABET 2
#define STRING 3
#define WORD 4

int binSearchInt(int arr[], int element, int left, int right);
int binSearchStr(char arr[ARR_SIZE][STR_SIZE+1], char element[], int left, int right);
int validate(char str[], int size, int type);
int getInput(char buff[], int size);

int main() {
	char arr[ARR_SIZE][STR_SIZE+1];
	
	int i, j;
	
	for(i=0; i < ARR_SIZE; i++) {
		char str[STR_SIZE+2];
		
		printf("Introduzca una palabra (%d/%d): ", i+1, ARR_SIZE);
		int len = getInput(str, STR_SIZE+2);
		
		while(validate(str, len, ALPHABET) == 0 || len > STR_SIZE || len <= 0) {
			printf("Por favor introduzca una palabra valida hasta 20 caracteres: ");
			
			len = getInput(str, STR_SIZE+2);
		}
		
		strcpy(arr[i], str);
	}
	
	for(i=0; i < ARR_SIZE-1; i++) {
		for(j=i+1; j < ARR_SIZE; j++) {
			if (strcmp(arr[i], arr[j]) > 0) {
				char tmp[STR_SIZE];
				
				strcpy(tmp, arr[i]);
				strcpy(arr[i], arr[j]);
				strcpy(arr[j], tmp);
			}
		}
	}
	
	system("cls");
	
	printf("Introduzca la palabra a buscar en el arreglo: ");
	
	char find[STR_SIZE+2];
	int find_len = getInput(find, STR_SIZE+2);
	
	while(validate(find, find_len, ALPHABET) == 0 || find_len > STR_SIZE || find_len <= 0) {
		printf("Por favor introduzca una palabra valida hasta 20 caracteres: ");
	
		find_len = getInput(find, STR_SIZE+2);
	}
	
	int indice = binSearchStr(arr, find, 0, ARR_SIZE-1);
	
	printf("La palabra %s se encuentra en el lugar %d\n\n", arr[indice], indice+1);
	
	for(i=0; i < ARR_SIZE; i++) {
		printf("%d.- %s\n", i+1, arr[i]);
		
	}
		
}

int binSearchInt(int arr[], int element, int left, int right) {
	if (right < left) return -1;
	
	int mid = (left+right)/2;
	
	if (arr[mid] == element) return mid;
	else if (arr[mid] > element) return binSearchInt(arr, element, left, mid-1);
	else return binSearchInt(arr, element, mid+1, right);
}

int binSearchStr(char arr[ARR_SIZE][STR_SIZE+1], char element[], int left, int right) {
	if (right < left) return -1;
	
	int mid = (left+right)/2;
	
	if(strcmp(arr[mid], element) == 0) return mid;
	else if(strcmp(arr[mid], element) > 0) return binSearchStr(arr, element, left, mid-1);
	else return binSearchStr(arr, element, mid+1, right);
}

int validate(char str[], int size, int type) {
	int i;
	
	for (i=0; i < size; i++) {
		int ch = str[i];
	
		switch(type) {
			case ALPHABET: if(!isalpha(ch)) return 0;
						   break;
		}	
	}
	
	return 1;
}

int getInput(char buff[], int size) {
	fgets(buff, size, stdin);
	fflush(stdin);
	
	int len = strlen(buff);
	
	if (buff[len-1] == '\n') {
		buff[len-1] = 0x00;
		len--;
	}
	
	return len;
}

