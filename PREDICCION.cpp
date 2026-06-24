
#include <iostream>

#include "VARIABLES_GLOBALES.h"
#include "PREDICCION.h"

using namespace std;


//==================== INDICE OFENSIVO ====================

float calcularIndiceOfensivo(int codigoEquipo)
{
    float indice;
    indice = equipos[codigoEquipo].nivel;
    indice = indice + equipos[codigoEquipo].golesFavor*0.1;
    return indice;
}


//==================== INDICE DEFENSIVO ====================

float calcularIndiceDefensivo(int codigoEquipo)
{
    float indice;
    indice = equipos[codigoEquipo].nivel;
    indice = indice - equipos[codigoEquipo].golesContra*0.05;
    return indice;
}


//==================== PROBABILIDAD LOCAL ====================

float calcularProbabilidadLocal(int codigoLocal, int codigoVisitante)
{
    float local;
    float visitante;
    local = calcularIndiceOfensivo(codigoLocal);
    visitante = calcularIndiceOfensivo(codigoVisitante);
    return local/(local+visitante)*100;
}


//==================== PROBABILIDAD EMPATE ====================

float calcularProbabilidadEmpate(int codigoLocal,int codigoVisitante)
{
    return 20;
}


//==================== PROBABILIDAD VISITANTE ====================

float calcularProbabilidadVisitante(int codigoLocal,int codigoVisitante)
{
    float local;

    local = calcularProbabilidadLocal(codigoLocal,
                                      codigoVisitante);

    return 100-local-20;
}


//==================== MOSTRAR PREDICCION ====================

void mostrarPrediccion()
{
    int codigoLocal;
    int codigoVisitante;

    cout<<"Codigo local: ";
    cin>>codigoLocal;

    cout<<"Codigo visitante: ";

    cin>>codigoVisitante;

    cout<<endl;

    cout<<equipos[codigoLocal].nombre;

    cout<<" gana: ";
    cout<<calcularProbabilidadLocal(codigoLocal,   codigoVisitante);
    cout<<" %"<<endl;
    cout<<"Empate: ";
    cout<<calcularProbabilidadEmpate(codigoLocal, codigoVisitante);
    cout<<" %"<<endl;
    cout<<equipos[codigoVisitante].nombre;
    cout<<" gana: ";
    cout<<calcularProbabilidadVisitante(codigoLocal,codigoVisitante);
    cout<<" %"<<endl;
}

