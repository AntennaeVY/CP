/*
    Programa desarrollado por Jose R. Oses y Ludwuing Contreras
    para la catedra de Programacion 2 - Prof. Carlos Ferrer
    USM 2021-22

    Simulacion y Control: Sistema de Craqueo Catalítico de la Refinería Amuay - Punto Fijo, Venezuela
*/

#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
using namespace std;

// Definir la estructura de PLC que manejara todas las variables
struct PLC {
    int temperatura = 40;
    int perturbacion_temperatura = 0;
    int presion_catalizador = 20;
    int presion_crudo = 30;
    string switch_temperatura = "ON";
    string switch_presion_diferencial;
    string valvula_catalizador;
    string bomba_catalizador = "ON";
    string bomba_crudo = "ON";
    bool condiciones_normales = true;
    bool emergencia = false;

    // Funcion que prende o apaga una determinada bomba
    void cambiar_estado_bomba(string bomba, string estado) {
        if (estado == "OFF" || estado == "ON") {
            if (bomba == "CATALIZADOR") {
                bomba_catalizador = estado;
            } else if (bomba == "CRUDO") {
                bomba_crudo = estado;
            }
        }
    }

    // Funcion para mostrar todos los datos en pantalla
    void imprimir() {
        cout << "TEMPERATURA: " << temperatura << endl;
        cout << "PERTURBACION DE TEMPERATURA: " << perturbacion_temperatura << endl;
        cout << "PRESION DEL CATALIZADOR: " << presion_catalizador << endl;
        cout << "PRESION DEL CRUDO: " << presion_crudo << endl;
        cout << "SWITCH DE TEMPERATURA: " << switch_temperatura;

        if (switch_temperatura == "ON") {
            cout << " (NORMAL)" << endl;
        } else {
            cout << " (ALARMA)" << endl;
        }

        cout << "SWITCH DE PRESION DIFERENCIAL: " << switch_presion_diferencial;
        
        if (switch_presion_diferencial == "ON") {
            cout << " (NORMAL)" << endl;
        } else {
            cout << " (ALARMA)" << endl;
        }

        cout << "VALVULA DEL CATALIZADOR: " << valvula_catalizador << endl;
        cout << "BOMBA DEL CATALIZADOR: " << bomba_catalizador << endl;
        cout << "BOMBA DEL CRUDO: " << bomba_crudo << endl; 
    }
};

int main() {
    struct PLC plc;

    // Ciclo que simulara el paso del tiempo
    while(true) {    
        // Se leen los datos desde el archivo externo
        ifstream fin("C:\\torre.txt");
        fin >> plc.perturbacion_temperatura;
        fin >> plc.switch_presion_diferencial;
        fin >> plc.valvula_catalizador;

        // Se imprime la informacion por pantalla
        plc.imprimir();

        // Verifica que estemos en condiciones normales
        if (
            plc.temperatura <= 100 && 
            plc.switch_presion_diferencial == "ON" &&
            plc.switch_temperatura == "ON"
        ) {
            plc.condiciones_normales = true;
        } else {
            plc.condiciones_normales = false;
        }

        // Verifica alguna de las condiciones de emergencia
        if ( 
            plc.switch_presion_diferencial == "OFF" ||  
            plc.switch_temperatura == "OFF"
        ) {
            plc.emergencia = true;
        } else {
            plc.emergencia = false;
        }

        // Si ambas estan encendidas
        if (plc.bomba_catalizador == "ON" &&  plc.bomba_crudo == "ON") {
            // Y la temperatura es menor que valor de estabilizacion
            if (plc.temperatura < 80 + plc.perturbacion_temperatura) {
                // La temperatura aumenta
                plc.temperatura++;
            } else if (plc.condiciones_normales == true && plc.temperatura > 80) {
                // Si estamos en condiciones normales, se estabiliza en 80
                plc.temperatura--;
            }

            // Si la perturbacion de la temperatura es negativa
            if (
                plc.perturbacion_temperatura < 0 && 
                plc.temperatura > 80 + plc.perturbacion_temperatura
                ) {
                // La temperatura desciende
                plc.temperatura--;
            }
        // Si ambas estan apagadas o una de ellas lo esta
        } else if (
            (plc.bomba_catalizador == "OFF" && plc.bomba_crudo == "OFF") || 
            (plc.bomba_catalizador != plc.bomba_crudo)
        ) {
            // La temperatura desciende
            if (plc.temperatura > 40 + plc.perturbacion_temperatura) {
                plc.temperatura--;
            }
        }

        // Si la temperatura alcanza un valor critico
        if (plc.temperatura > 100) {
            // Y el switch de temperatura esta en normal
            if (plc.switch_temperatura == "ON") {
                // Ponlo en alerta
                plc.switch_temperatura = "OFF";
            }
        // Si la temperatura esta en valores normales
        } else if (plc.temperatura < 95) {
            // Y el switch de temperatura esta en alerta
            if (plc.switch_temperatura == "OFF") {
                // Ponlo en normal
                plc.switch_temperatura = "ON";
            }
        }

        // Si la bomba de crudo esta encendida
        if (plc.bomba_crudo == "ON") {
            // Aumenta la presion a la descarga de la bomba de crudo y se estabiliza en condiciones normales
            if (plc.condiciones_normales) {
                if (plc.presion_crudo < 70) {
                    plc.presion_crudo++;
                } else if (plc.presion_crudo > 70) {
                    plc.presion_crudo--;
                }
            }

            // Si esta por encima del valor critico, se apaga
            if (plc.presion_crudo >= 90 || plc.emergencia) {
                plc.cambiar_estado_bomba("CRUDO", "OFF");
            }
            // Si esta apagada
        } else {
            // Desciende la presion a la descarga de la bomba de crudo
            if (plc.presion_crudo > 0) {
                plc.presion_crudo--;
            }
            // Si la presion es menor que el valor critico
            if (plc.presion_crudo < 50 && !plc.emergencia) {
                // Se enciende
                plc.cambiar_estado_bomba("CRUDO", "ON");
            }
            
        }

        // Si la bomba del catalizador esta encendida
        if (plc.bomba_catalizador == "ON") {

            // Si la valvula manual esta abierta         
            if (plc.valvula_catalizador == "ABIERTA") {
                // La presion a la descarga de la bomba de catalizador aumenta un poco (se asume que la bomba envia mas cantidad de la que sale por la valvula)
                if (plc.condiciones_normales) {
                    if (plc.presion_catalizador < 55) {
                        plc.presion_catalizador++; 
                    } else if (plc.presion_catalizador > 55) {
                        plc.presion_catalizador--;
                    }
                }

            // Si no, y la valvula esta cerrada
            } else if (plc.valvula_catalizador == "CERRADA") {
                // La presion a la descarga de la bomba de catalizador aumenta mucho mas
                plc.presion_catalizador += 2;
            }

            // Si la presion es muy alta, se apaga
            if (plc.presion_catalizador >= 70 || plc.emergencia) {
                plc.cambiar_estado_bomba("CATALIZADOR", "OFF");
            }

        // Si la bomba del catalizador esta apagada
        } else {   
            // Si la valvula del catalizador esta abierta
            if (plc.valvula_catalizador == "ABIERTA") {
                // La presion a la descarga de la bomba de catalizador desciende
                if (plc.presion_catalizador > 0) {
                    plc.presion_catalizador--;
                }
            } 

            // Si esta por debajo de los valores minimos
            if (plc.presion_catalizador < 40 && !plc.emergencia) {
                plc.cambiar_estado_bomba("CATALIZADOR", "ON");
            }      
        }

        Sleep(1000);
        system("cls");
    }
}