
#include <iostream>

#include "VARIABLES_GLOBALES.h"
#include "PREDICCION.h"

using namespace std;


//==================== INDICE OFENSIVO ====================

float calcularIndiceOfensivo(int codigoEquipo)
{
    float indice;

    indice = equipos[codigoEquipo].nivel;

    indice = indice
            + equipos[codigoEquipo].golesFavor*0.1;

    return indice;
}


//==================== INDICE DEFENSIVO ====================

float calcularIndiceDefensivo(int codigoEquipo)
{
    float indice;

    indice = equipos[codigoEquipo].nivel;

    indice = indice
            - equipos[codigoEquipo].golesContra*0.05;

    return indice;
}


//==================== PROBABILIDAD LOCAL ====================

float calcularProbabilidadLocal(int codigoLocal,
                                int codigoVisitante)
{
    float fuerzaLocal;

    float fuerzaVisitante;


    fuerzaLocal =
            calcularIndiceOfensivo(codigoLocal)
            +
            calcularIndiceDefensivo(codigoLocal)
            +
            matrizVictorias[codigoLocal][codigoVisitante]*2
            +
            matrizGoles[codigoLocal][codigoVisitante]*0.2;


    fuerzaVisitante =
            calcularIndiceOfensivo(codigoVisitante)
            +
            calcularIndiceDefensivo(codigoVisitante)
            +
            matrizVictorias[codigoVisitante][codigoLocal]*2
            +
            matrizGoles[codigoVisitante][codigoLocal]*0.2;


    return fuerzaLocal/(fuerzaLocal+fuerzaVisitante)*80;
}


//==================== PROBABILIDAD EMPATE ====================

float calcularProbabilidadEmpate(int codigoLocal,
                                 int codigoVisitante)
{
    float probLocal;

    probLocal =
    calcularProbabilidadLocal(codigoLocal,
                              codigoVisitante);

    if(probLocal>45 && probLocal<55)
    {
        return 25;
    }

    return 20;
}


//==================== PROBABILIDAD VISITANTE ====================

float calcularProbabilidadVisitante(int codigoLocal,
                                    int codigoVisitante)
{
    float probLocal;

    float probEmpate;


    probLocal =
    calcularProbabilidadLocal(codigoLocal,
                              codigoVisitante);

    probEmpate =
    calcularProbabilidadEmpate(codigoLocal,
                               codigoVisitante);


    return 100-probLocal-probEmpate;
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

    cout<<"========== PREDICCION =========="<<endl;

    cout<<endl;


    cout<<equipos[codigoLocal].nombre
        <<" vs "
        <<equipos[codigoVisitante].nombre
        <<endl;

    cout<<endl;


    cout<<equipos[codigoLocal].nombre
        <<" gana: "
        <<calcularProbabilidadLocal(codigoLocal,
                                    codigoVisitante)
        <<" %"<<endl;


    cout<<"Empate: "
        <<calcularProbabilidadEmpate(codigoLocal,
                                     codigoVisitante)
        <<" %"<<endl;


    cout<<equipos[codigoVisitante].nombre
        <<" gana: "
        <<calcularProbabilidadVisitante(codigoLocal,
                                        codigoVisitante)
        <<" %"<<endl;


    cout<<endl;

    cout<<"========== HISTORIAL =========="<<endl;

    cout<<endl;


    cout<<"Victorias de "
        <<equipos[codigoLocal].nombre
        <<": "
        <<matrizVictorias[codigoLocal][codigoVisitante]
        <<endl;


    cout<<"Victorias de "
        <<equipos[codigoVisitante].nombre
        <<": "
        <<matrizVictorias[codigoVisitante][codigoLocal]
        <<endl;


    cout<<endl;


    cout<<"Goles de "
        <<equipos[codigoLocal].nombre
        <<": "
        <<matrizGoles[codigoLocal][codigoVisitante]
        <<endl;


    cout<<"Goles de "
        <<equipos[codigoVisitante].nombre
        <<": "
        <<matrizGoles[codigoVisitante][codigoLocal]
        <<endl;


    cout<<endl;


    if(calcularProbabilidadLocal(codigoLocal,codigoVisitante)
       >
       calcularProbabilidadVisitante(codigoLocal,codigoVisitante))
    {
        cout<<"Favorito: "
            <<equipos[codigoLocal].nombre
            <<endl;
    }
    else
    {
        cout<<"Favorito: "
            <<equipos[codigoVisitante].nombre
            <<endl;
    }
}

