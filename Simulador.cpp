#include <iostream>
#include <cstdlib>

#include "VARIABLES_GLOBALES.h"
#include "BASE_DE_DATOS.h"
#include "Simulador.h"

using namespace std;


//==================== EVENTO ALEATORIO ====================

int calcularEventoAleatorio(int limiteInferior,
                            int limiteSuperior)
{
    return limiteInferior +
           rand() % (limiteSuperior - limiteInferior + 1);
}


//==================== IMPRIMIR MARCADOR ====================

bool imprimirMarcador(int minuto,
                      int golesL,
                      int golesV,
                      int indiceLocal,
                      int indiceVisitante)
{
    cout << "Minuto " << minuto << endl;

    cout << equipos[indiceLocal].nombre
         << " "
         << golesL
         << " - "
         << golesV
         << " "
         << equipos[indiceVisitante].nombre
         << endl
         << endl;

    return true;
}


//==================== SIMULAR PARTIDO ====================

bool simularPartidoVivo(int indiceLocal,
                        int indiceVisitante)
{
    int golesL = 0;

    int golesV = 0;

    int evento;


    cout << endl;

    cout << "===== PARTIDO EN VIVO =====" << endl;

    cout << equipos[indiceLocal].nombre
         << " vs "
         << equipos[indiceVisitante].nombre
         << endl
         << endl;


    for(int minuto = 0; minuto <= 90; minuto += 5)
    {
        evento = calcularEventoAleatorio(1,100);

        if(evento <= 5)
        {
            golesL++;

            cout << "GOOOOL DE "
                 << equipos[indiceLocal].nombre
                 << endl;
        }

        else if(evento >= 96)
        {
            golesV++;

            cout << "GOOOOL DE "
                 << equipos[indiceVisitante].nombre
                 << endl;
        }

        imprimirMarcador(minuto,golesL, golesV,indiceLocal,indiceVisitante);
    }


    //==================== RESULTADO FINAL ====================

    cout << "===== RESULTADO FINAL =====" << endl
         << endl;

    cout << equipos[indiceLocal].nombre
         << " "
         << golesL
         << " - "
         << golesV
         << " "
         << equipos[indiceVisitante].nombre
         << endl
         << endl;


    //==================== MATRIZ DE GOLES ====================

    matrizGoles[indiceLocal][indiceVisitante] += golesL;

    matrizGoles[indiceVisitante][indiceLocal] += golesV;


    //==================== PARTIDOS JUGADOS ====================

    equipos[indiceLocal].partidosJugados++;

    equipos[indiceVisitante].partidosJugados++;


    //==================== GOLES A FAVOR Y EN CONTRA ====================

    equipos[indiceLocal].golesFavor += golesL;

    equipos[indiceLocal].golesContra += golesV;

    equipos[indiceVisitante].golesFavor += golesV;

    equipos[indiceVisitante].golesContra += golesL;


    //==================== VICTORIAS, DERROTAS Y EMPATES ====================

    if(golesL > golesV)
    {
        matrizVictorias[indiceLocal][indiceVisitante]++;

        equipos[indiceLocal].victorias++;

        equipos[indiceVisitante].derrotas++;
    }

    else if(golesV > golesL)
    {
        matrizVictorias[indiceVisitante][indiceLocal]++;

        equipos[indiceVisitante].victorias++;

        equipos[indiceLocal].derrotas++;
    }

    else
    {
        equipos[indiceLocal].empates++;

        equipos[indiceVisitante].empates++;
    }


    //==================== GUARDAR CAMBIOS ====================

    guardarEquipos();

    guardarMatrizGoles();

    guardarMatrizVictorias();


    cout << endl;

    cout << "Estadisticas actualizadas correctamente." << endl;

    return true;
}
