#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
using namespace std;

int main() {
    int temperatura = 40;
    int perturbacion_temp = 0;
    int perturbacion_pres = 0;
    int presion_bomba = 0;
    int presion_vl = 0;
    int nivel = 0;
    string bomba = "ENCENDIDA";
    string v3 = "ABIERTA";
    string v2 = "ABIERTA";
    string v1 = "CERRADA";
    bool alerta = false;

    while(true) {
        ifstream tanque("C:\\Tanque.txt");
        tanque >> perturbacion_temp;
        tanque >> perturbacion_pres;
        tanque >> v2;
        tanque >> v3;

        cout << "TEMPERATURA: " << temperatura << endl;
        cout << "PERTURBACION TEMPERATURA: " << perturbacion_temp << endl;
        cout << "PRESION VAPOR DE LECHE: " << presion_vl << endl;
        cout << "PERTURBACION PRESION DE VAPOR DE LECHE: " << perturbacion_pres << endl;
        cout << "NIVEL DEL TANQUE: " << nivel << endl;
        cout << "BOMBA: " << bomba << endl;
        cout << "PRESION BOMBA: " << presion_bomba << endl;
        cout << "V1: " << v1 << endl;
        cout << "V2: " << v2 << endl;
        cout << "V3: " << v3 << endl;

        if (alerta) {
            cout << endl << "TANQUES DE ALMACENAMIENTO CONTAMINADOS!!! " << endl;
        }

        if (nivel < 95 && presion_bomba < 60) {
            bomba = "ENCENDIDA";
        } else if (nivel >= 95 || presion_bomba >= 60) {
            bomba = "APAGADA";
        }

        if (nivel > 90  && temperatura < 95 && presion_vl < 95) {
            v1 = "ABIERTA";
        } else if (nivel < 90 || temperatura > 100 || presion_vl > 100) {
            v1 = "CERRADA";
        }


        if (bomba == "ENCENDIDA") {
            if (v2 == "ABIERTA") {
                if (nivel < 95) {
                    nivel++;
                }

                if (presion_bomba < 40) {
                    presion_bomba++;
                } else if (presion_bomba > 40) {
                    presion_bomba--;
                }
            } else if (v2 == "CERRADA") {
                presion_bomba++;
            }
            
        } else if (bomba == "APAGADA") {
            if (presion_bomba > 0) {
                presion_bomba--;
            }
        }

        if (v3 == "ABIERTA") {
            if (nivel > 0) {
                nivel--;
            }
        }

        if (v1 == "ABIERTA") {
            if (temperatura < 95 + perturbacion_temp) {
                temperatura++;
            } else if (temperatura > 95 + perturbacion_temp) {
                temperatura--;
            }

            if (presion_vl < 95 + perturbacion_pres) {
                presion_vl++;
            } else if (presion_vl > 95 + perturbacion_pres) {
                presion_vl--;
            }
        } else if (v1 == "CERRADA") {
            if (temperatura > 40 + perturbacion_temp) {
                temperatura--;
            } else if (temperatura < 40 + perturbacion_temp) {
                temperatura++;
            }

            if (presion_vl > 0 + perturbacion_pres) {
                presion_vl--;
            }
        }

        if (v2 == "ABIERTA" && v3 == "ABIERTA") {
            alerta = true;
        }

        Sleep(1000);
        system("cls");
    }
}