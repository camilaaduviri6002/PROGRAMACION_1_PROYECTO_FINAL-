
#include <iostream>
#include <cstdlib>
#include <iomanip>

#include "VARIABLES_GLOBALES.h"
#include "BASE_DE_DATOS.h"
#include "Simulador.h"

#include "MOTOR_APUESTAS.h"
#include "USUARIO.h"

using namespace std;


//==================== EVENTO ALEATORIO ====================

int calcularEventoAleatorio(int limiteInferior,
                            int limiteSuperior)
{
    return limiteInferior +
           rand()%(limiteSuperior-limiteInferior+1);
}


//==================== MARCADOR ====================

bool imprimirMarcador(int minuto,
                      int golesL,
                      int golesV,
                      int indiceLocal,
                      int indiceVisitante)
{
    cout<<endl;

    cout<<"Minuto "<<minuto<<endl;

    cout<<equipos[indiceLocal].nombre
        <<" "
        <<golesL
        <<" - "
        <<golesV
        <<" "
        <<equipos[indiceVisitante].nombre
        <<endl;

    return true;
}


//==================== MATRIZ DE GOLES ====================

void mostrarMatrizGoles()
{
    cout<<"\n========== MATRIZ DE GOLES ==========\n\n";

    cout<<setw(15)<<" ";

    for(int j=0;j<nEquipos;j++)
    {
        cout<<setw(4)<<j;
    }

    cout<<endl;

    for(int i=0;i<nEquipos;i++)
    {
        cout<<setw(15)<<equipos[i].nombre;

        for(int j=0;j<nEquipos;j++)
        {
            cout<<setw(4)<<matrizGoles[i][j];
        }

        cout<<endl;
    }
}


//==================== MATRIZ DE VICTORIAS ====================

void mostrarMatrizVictorias()
{
    cout<<"\n========== MATRIZ DE VICTORIAS ==========\n\n";

    cout<<setw(15)<<" ";

    for(int j=0;j<nEquipos;j++)
    {
        cout<<setw(4)<<j;
    }

    cout<<endl;

    for(int i=0;i<nEquipos;i++)
    {
        cout<<setw(15)<<equipos[i].nombre;

        for(int j=0;j<nEquipos;j++)
        {
            cout<<setw(4)<<matrizVictorias[i][j];
        }

        cout<<endl;
    }
}


//==================== ESTADISTICAS ====================

void mostrarEstadisticasEquipos()
{
    cout<<"\n=============== ESTADISTICAS DE EQUIPOS ===============\n\n";

    cout
    <<left
    <<setw(5)<<"Cod"
    <<setw(20)<<"Equipo"
    <<setw(7)<<"Nivel"
    <<setw(5)<<"PJ"
    <<setw(5)<<"GF"
    <<setw(5)<<"GC"
    <<setw(5)<<"V"
    <<setw(5)<<"E"
    <<setw(5)<<"D"
    <<setw(5)<<"DG"
    <<endl;

    for(int i=0;i<nEquipos;i++)
    {
        int diferenciaGoles;

        diferenciaGoles =
        equipos[i].golesFavor -
        equipos[i].golesContra;

        cout
        <<left
        <<setw(5)<<equipos[i].codigo
        <<setw(20)<<equipos[i].nombre
        <<setw(7)<<equipos[i].nivel
        <<setw(5)<<equipos[i].partidosJugados
        <<setw(5)<<equipos[i].golesFavor
        <<setw(5)<<equipos[i].golesContra
        <<setw(5)<<equipos[i].victorias
        <<setw(5)<<equipos[i].empates
        <<setw(5)<<equipos[i].derrotas
        <<setw(5)<<diferenciaGoles
        <<endl;
    }
}


//==================== SIMULAR PARTIDO ====================

bool simularPartidoVivo(int indiceLocal,
                        int indiceVisitante)
{
    int golesL=0;

    int golesV=0;

    int evento;


    cout<<endl;

    cout<<"========== PARTIDO EN VIVO =========="<<endl<<endl;

    cout<<equipos[indiceLocal].nombre
        <<" vs "
        <<equipos[indiceVisitante].nombre
        <<endl;


    //==================== DESARROLLO DEL PARTIDO ====================

    for(int minuto=0;minuto<=90;minuto+=5)
    {
        evento=calcularEventoAleatorio(1,100);

        if(evento<=5)
        {
            golesL++;

            cout<<endl;

            cout<<"GOOOOL DE "
                <<equipos[indiceLocal].nombre
                <<endl;
        }

        else if(evento>=96)
        {
            golesV++;

            cout<<endl;

            cout<<"GOOOOL DE "
                <<equipos[indiceVisitante].nombre
                <<endl;
        }

        imprimirMarcador(minuto,
                         golesL,
                         golesV,
                         indiceLocal,
                         indiceVisitante);
    }


    //==================== RESULTADO FINAL ====================

    cout<<endl;

    cout<<"========== RESULTADO FINAL =========="<<endl<<endl;

    cout<<equipos[indiceLocal].nombre
        <<" "
        <<golesL
        <<" - "
        <<golesV
        <<" "
        <<equipos[indiceVisitante].nombre
        <<endl;



    //==================== MATRIZ GOLES ====================

    matrizGoles[indiceLocal][indiceVisitante]+=golesL;

    matrizGoles[indiceVisitante][indiceLocal]+=golesV;



    //==================== PARTIDOS JUGADOS ====================

    equipos[indiceLocal].partidosJugados++;

    equipos[indiceVisitante].partidosJugados++;



    //==================== GOLES FAVOR Y CONTRA ====================

    equipos[indiceLocal].golesFavor+=golesL;

    equipos[indiceLocal].golesContra+=golesV;

    equipos[indiceVisitante].golesFavor+=golesV;

    equipos[indiceVisitante].golesContra+=golesL;



    //==================== VICTORIAS, EMPATES Y DERROTAS ====================

    if(golesL>golesV)
    {
        matrizVictorias[indiceLocal][indiceVisitante]++;

        equipos[indiceLocal].victorias++;

        equipos[indiceVisitante].derrotas++;
    }

    else if(golesV>golesL)
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

    //==================== RESOLVER APUESTAS ====================

int resultado;

if(golesL>golesV)
{
    resultado=1;
}
else if(golesL==golesV)
{
    resultado=2;
}
else
{
    resultado=3;
}

for(int i=0;i<nApuestas;i++)
{
    if(apuestas[i].resuelta==false)
    {
        if(apuestas[i].codigoLocal==indiceLocal &&
           apuestas[i].codigoVisitante==indiceVisitante)
        {
            if(apuestas[i].opcion==resultado)
            {
                int posUsuario;

                posUsuario=buscarUsuario(apuestas[i].username);

                if(posUsuario!=-1)
                {
                    apuestas[i].ganancia=
                    apuestas[i].monto*
                    apuestas[i].cuota;

                    depositarSaldo(posUsuario,
                                   apuestas[i].ganancia);

                    cout<<endl;

                    cout<<"APUESTA GANADORA"<<endl;

                    cout<<"Usuario: "
                        <<apuestas[i].username
                        <<endl;

                    cout<<"Ganancia: "
                        <<apuestas[i].ganancia
                        <<" Bs"
                        <<endl;
                }
            }

            apuestas[i].resuelta=true;
        }
    }
}

    //==================== GUARDAR ====================

    guardarEquipos();

    guardarMatrizGoles();

    guardarMatrizVictorias();

    guardarUsuarios();

guardarApuestas();



    //==================== MOSTRAR ESTADISTICAS ====================

    cout<<endl;

    mostrarMatrizGoles();

    cout<<endl;

    mostrarMatrizVictorias();

    cout<<endl;

    mostrarEstadisticasEquipos();

    cout<<endl;

    system("pause");

    return true;
}




