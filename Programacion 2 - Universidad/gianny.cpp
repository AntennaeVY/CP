#include<iostream>
#include<fstream>
#include<windows.h>
#include<string>
using namespace std;

int main() {
    int temperatura = 40;
    int presion_leche = 0;
    int nivel_tanque = 0;
    int presion_bomba = 0;
    string bomba = "ON";
    string v1 = "OFF";
    string v2 = "ON";
    string v3 = "OFF";
    int perturbacion_temp = 0;
    int perturbacion_pres = 0;
    bool contaminados = false;

    inicio:
        ifstream fin("C:\\tanque.txt");
        fin >> perturbacion_temp >> perturbacion_pres >> v2 >> v3;

        if (v2 == "ON" && v3 == "ON") {
            contaminados = true;
        }

        if (contaminados) {
            cout << "ALERTA: TANQUES DE ALMACENAMIENTO CONTAMINADOS!!!" << endl << endl;
        }

        cout << "Temperatura = " << temperatura << "C" << endl;
        cout << "Perturbacion de la temperatura = " << perturbacion_temp << "C" << endl;
        cout << "Presion del vapor de leche = " << presion_leche << "psi" << endl;
        cout << "Perturbacion de la presion del vapor de leche = " << perturbacion_pres << "psi" << endl;
        cout << "Nivel del tanque = " << nivel_tanque << "%" << endl;
        cout << "Estado de la bomba = " << bomba << endl;
        cout << "Presion de la bomba = " << presion_bomba << "psi" << endl;
        cout << "Valvula de vapor de agua = " << v1 << endl;
        cout << "Valvula de entrada = " << v2 << endl;
        cout << "Valvula de salida = " << v3 << endl << endl;

        if (v1 == "ON") {
            if (temperatura < 95 + perturbacion_temp) {
                temperatura += 1;
            } else if (temperatura > 95 + perturbacion_temp) {
                temperatura -= 1;
            }
        } else if (v1 == "OFF") {
            if (temperatura > 40 + perturbacion_temp) {
                temperatura -= 1;
            } else if (temperatura < 40 + perturbacion_temp){
                temperatura += 1;
            }
        }

        if (v1 == "ON" || temperatura >= 95) {
            if (presion_leche < 95 + perturbacion_pres) {
                presion_leche += 1;
            } else if (presion_leche > 95 + perturbacion_pres) {
                presion_leche -= 1;
            }
        } else if (v1 == "OFF" && temperatura < 95){
            if (presion_leche > 0 + perturbacion_pres) {
                presion_leche -= 1;
            } else if (presion_leche < 0 + perturbacion_pres) {
                presion_leche += 1;
            }
        }

        if (bomba == "ON" && v2 == "ON" && v3 == "ON") {
            nivel_tanque = nivel_tanque;
        } else if (bomba == "OFF" && v2 == "ON" && v3 == "ON") {
            if (nivel_tanque > 0) {
                nivel_tanque -= 1;
            }

        } else if (bomba == "ON" && v2 == "OFF" && v3 == "ON") {
            if (nivel_tanque > 0) {
                nivel_tanque -= 1;
            }
        } else if (bomba == "OFF" && v2 == "OFF" && v3 == "ON") {
            if (nivel_tanque > 0) {
                nivel_tanque -= 1;
            }
        } else if (bomba == "ON" && v2 == "ON" && v3 == "OFF") {
            if (nivel_tanque < 100) {
                nivel_tanque += 1;
            }
        }

        if (bomba == "OFF" && presion_bomba < 20 && nivel_tanque < 90) {
            bomba = "ON";
        } else if (bomba == "OFF" && presion_bomba >= 20 && presion_bomba <= 60 && nivel_tanque < 90) {
            bomba = "ON";
        } else if (bomba == "ON" && presion_bomba > 60 && nivel_tanque < 90) {
            bomba = "OFF";
        } else if (bomba == "OFF" && presion_bomba < 20 && nivel_tanque >= 90 && nivel_tanque < 95) {
            bomba = "ON";
        } else if (bomba == "ON" && presion_bomba > 60 && nivel_tanque >= 90 && nivel_tanque < 95) {
            bomba = "OFF";
        } else if (bomba == "ON" && presion_bomba < 20 && nivel_tanque >= 95) {
            bomba = "OFF";
        } else if (bomba == "ON" && presion_bomba >= 20 && presion_bomba <= 60 && nivel_tanque >= 95) {
            bomba = "OFF";
        } else if (bomba == "ON" && presion_bomba > 60 && nivel_tanque >= 95) {
            bomba = "OFF";
        }

        if (v1 == "OFF" && temperatura < 95 && presion_leche < 90 && nivel_tanque >= 90) {
            v1 = "ON";
        } else if (v1 == "OFF" && temperatura < 95 && presion_leche < 90 && nivel_tanque >= 90) {
            v1 = "ON";
        } else if (v1 == "ON" && (temperatura > 100 || presion_leche > 100 || nivel_tanque < 90)) {
            v1 = "OFF";
        }

        if(bomba == "ON" && v2 == "ON") {
            if (presion_bomba < 40) {
                presion_bomba += 1;
            } else if (presion_bomba > 40) {
                presion_bomba -= 1;
            }
        } else if (bomba == "OFF" && v2 == "ON") {
            if (presion_bomba > 0) {
                presion_bomba -= 1;
            }
        } else if (bomba == "ON" && v2 == "OFF") {
            presion_bomba += 2;
        } else if (bomba == "OFF" && v2 == "OFF") {
        
        }

        Sleep(1000);
        system("cls");
        goto inicio;
}