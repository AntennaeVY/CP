#include<stdio.h>
#include<stdlib.h>

int main() {
  float num1, num2, aux;
  int opcion = 0, seguir = 0;
  system("cls");

  printf("Bienvenido al programa de intercambio de variables\n");

  while(1) {

  printf("Por favor introduzca una de las siguientes opciones\n\n");

  printf("(1) CONTINUAR\n");
  printf("(2) SALIR\n\n");

  printf("Opcion: ");
  scanf("%d", &seguir);

  while(seguir < 1 || seguir > 2) {
    system("cls");

    printf("Opcion invalida!\n");
    printf("Por favor introduzca una de las siguientes opciones\n\n");

    printf("(1) CONTINUAR\n");
    printf("(2) SALIR\n\n");

    printf("Opcion: ");
    scanf("%d", &seguir);
  }

  if (seguir == 2) {
    break;
  }

  system("cls");

  while(1) {
    printf("Por favor introduzca el valor de NUM1: ");
    scanf("%f", &num1);

    printf("Por favor introduzca el valor de NUM2: ");
    scanf("%f", &num2);

    system("cls");

    printf("NUM1: %.2f\n", num1);
    printf("NUM2: %.2f\n", num2);

    printf("\nDesea realizar el cambio de variables?\n\n");

    printf("(1) CONTINUAR\n");
    printf("(2) MODIFICAR VALORES\n\n");

    printf("Opcion: ");
    scanf("%d", &opcion);

    while(opcion < 1 || opcion > 2) {
      system("cls");

      printf("Por favor introduzca una opcion valida!\n\n");
  
      printf("NUM1: %.2f\n", num1);
      printf("NUM2: %.2f\n", num2);

      printf("\nDesea realizar el cambio de variables?\n\n");

      printf("(1) CONTINUAR\n");
      printf("(2) MODIFICAR VALORES\n\n");
  
     printf("Opcion: ");
     scanf("%d", &opcion);
    }

    if (opcion == 1) {
      break;
    }
    
    system("cls");
  }

  aux = num1;
  num1 = num2;
  num2 = aux;

  system("cls");
  printf("Valores intercambiados con exito!\n\n");

  printf("NUM1: %.2f\n", num1);
  printf("NUM2: %.2f\n\n", num2);

  }
}

