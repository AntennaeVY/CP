#include<stdio.h>
#include<stdlib.h>

int main() {
  int clave = 1234, input_clave = 0, opcion = 0, opcion_retiro = 0, opcion_deposito = 0;
  float saldo = 520, monto_retiro = 0, monto_deposito = 0;

    printf("BIENVENIDO AL CAJERO AUTOMATICO\n\n");
    printf("A continuacion por favor introduzca su clave.\n");
    printf("Clave: ");

    scanf("%d", &input_clave);
    
    while (clave != input_clave) {
      printf("Clave incorrecta!\n");
      printf("Clave: ");
      scanf("%d", &input_clave);
    }

    system("cls");

  while(1) { 
    printf("(1) CONSULTA SALDO\n");
    printf("(2) RETIRAR\n");
    printf("(3) DEPOSITAR\n");
    printf("(4) SALIR\n");

    printf("\nOpcion: ");
    scanf("%d", &opcion);

    while(opcion < 1 || opcion > 4) {
      system("cls");
      printf("Opcion invalida, por favor introduzca una opcion valida\n\n");

      printf("(1) CONSULTA SALDO\n");
      printf("(2) RETIRAR\n");
      printf("(3) DEPOSITAR\n");
      printf("(4) SALIR\n");

      printf("\nOpcion: ");
      scanf("%d", &opcion);
    }

    system("cls");

    if (opcion == 1) {
      printf("SU SALDO ES: %.2f\n\n", saldo);
    } else if (opcion == 2) {
      while(1) {

      printf("RETIRAR\n\n");
      printf("Por favor ingrese el monto a retirar\n");
      printf("Monto a retirar: ");

      scanf("%f", &monto_retiro);

      system("cls");
      printf("Por favor, confirme el monto a retirar\n\n");

      printf("MONTO A RETIRAR: %.2f\n\n", monto_retiro);

      printf("(1) CONFIRMAR\n");
      printf("(2) RECHAZAR\n");

      printf("\nOpcion: ");
      scanf("%d", &opcion_retiro);
      
      while(opcion_retiro < 1 || opcion_retiro > 2) {
        system("cls");

        printf("Por favor introduzca una opcion valida\n\n");

        printf("MONTO A RETIRAR: %.2f\n\n", monto_retiro);

        printf("(1) CONFIRMAR\n");
        printf("(2) RECHAZAR\n");

        printf("\nOpcion: ");
        scanf("%d", &opcion_retiro);
      }

      if (opcion_retiro == 1) {

        if (monto_retiro > saldo) {
          system("cls");
          printf("Lo sentimos, usted no dispone de esa cantidad en su cuenta!\n\n");
        } else {
          saldo -= monto_retiro; 
          system("cls");
          printf("Retiro realizado con exito!\n\n");
        }
        break;
      }

      system("cls");
    }


    } else if (opcion == 3) {
      while(1) {
        printf("DEPOSITAR\n\n");
        printf("Por favor ingrese el monto a depositar\n");
        printf("Monto a depositar: ");

        scanf("%f", &monto_deposito);

        system("cls");
        printf("Por favor, confirme el monto a depositar\n\n");

        printf("MONTO A DEPOSITAR: %.2f\n\n", monto_deposito);
        printf("(1) CONFIRMAR\n");
        printf("(2) RECHAZAR\n");

        printf("\nOpcion: ");
        scanf("%d", &opcion_deposito);
      
        while(opcion_deposito < 1 || opcion_deposito > 2) {
          system("cls");

          printf("Por favor introduzca una opcion valida\n\n");

          printf("MONTO A DEPOSITAR: %.2f\n\n", monto_deposito);

          printf("(1) CONFIRMAR\n");
          printf("(2) RECHAZAR\n");

          printf("\nOpcion: ");
          scanf("%d", &opcion_deposito);
        }

        if (opcion_deposito == 1) {
          saldo += monto_deposito;

          system("cls");
          printf("Deposito realizado con exito!\n\n");
          break;
        }

        system("cls");
      }
    } else if (opcion == 4) {
      system("cls");
      printf("Gracias, vuelva pronto..\n");

      break;
    }
  }
}

