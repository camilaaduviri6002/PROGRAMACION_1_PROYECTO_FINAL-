#include <iostream>
#include <cstdlib>
#include <windows.h> 
#include "VARIABLES_GLOBALES.h"
#include "BASE_DE_DATOS.h"
#include "SIMULADOR.h"

using namespace std;

int calcularEventoAleatorio(int limiteInferior, int limiteSuperior) {
    return limiteInferior + rand() % (limiteSuperior - limiteInferior + 1);
}

bool imprimirMarcador(int minuto, int golesL, int golesV, int indiceLocal, int indiceVisitante) {
    cout << "=========================================" << endl;
    cout << "           PARTIDO EN VIVO               " << endl;
    cout << "=========================================" << endl;
    
    if (minuto <= 90) {
        cout << " Minuto: " << minuto << "'" << endl;
    } else {
        cout << " RESULTADO FINAL" << endl;
    }
    
    cout << "-----------------------------------------" << endl;
    cout << " " << equipos[indiceLocal].nombre << " [" << golesL << "] - [" << golesV << "] " << equipos[indiceVisitante].nombre << endl;
    cout << "=========================================\n" << endl;
    
    return true;
}

bool simularPartidoVivo(int indiceLocal, int indiceVisitante) {
    int minuto = 1;
    int golesL = 0;
    int golesV = 0;
    int probabilidadEvento;
    bool partidoEnCurso = true;

    system("cls");
    cout << "\nLos equipos salen a la cancha..." << endl;
    Sleep(2000);

    while (partidoEnCurso) {
        system("cls");
        imprimirMarcador(minuto, golesL, golesV, indiceLocal, indiceVisitante);

        probabilidadEvento = calcularEventoAleatorio(1, 100);

        if (probabilidadEvento >= 1 && probabilidadEvento <= 3) {
            golesL++;
            cout << "¡GOOOOOOOOOOOOOOOL DE " << equipos[indiceLocal].nombre << "!" << endl;
            Sleep(2000);
        } else if (probabilidadEvento >= 4 && probabilidadEvento <= 6) {
            golesV++;
            cout << "¡GOOOOOOOOOOOOOOOL DE " << equipos[indiceVisitante].nombre << "!" << endl;
            Sleep(2000);
        } else if (probabilidadEvento == 50) {
            cout << "¡Falta peligrosa! Tarjeta Amarilla." << endl;
            Sleep(1500);
        }

        minuto++;

        if (minuto > 90) {
            partidoEnCurso = false;
        } else {
            Sleep(200); 
        }
    }

    system("cls");
    imprimirMarcador(90, golesL, golesV, indiceLocal, indiceVisitante);
    matrizGoles[indiceLocal][indiceVisitante] += golesL;
    matrizGoles[indiceVisitante][indiceLocal] += golesV;
    
    if (golesL > golesV) {
        matrizVictorias[indiceLocal][indiceVisitante] += 1;
        cout << "\n¡Victoria para " << equipos[indiceLocal].nombre << "!" << endl;
    } else if (golesV > golesL) {
        matrizVictorias[indiceVisitante][indiceLocal] += 1;
        cout << "\n¡Victoria para " << equipos[indiceVisitante].nombre << "!" << endl;
    } else {
        cout << "\n¡El partido termina en Empate!" << endl;
    }
    guardarMatrizGoles();
    guardarMatrizVictorias();
    
    system("pause");
    return true;
}
