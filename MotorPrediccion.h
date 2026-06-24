#ifndef MOTORPREDICCION_H_INCLUDED
#define MOTORPREDICCION_H_INCLUDED

#include <iostream>
#include <string>
#include <cmath>

#include "MotorApuestas.h"

using namespace std;

const int MAX_PARTIDOS = 200;

struct Equipo
{
    int id;
    string nombre;
    int ranking;
    int golesFavor;
    int golesContra;
};

extern Partido partidos[MAX_PARTIDOS];
extern int nPartidos;

int BuscarPartidoJugado(int equipoFila, int equipoCol, int pos)
{
    if(pos == nPartidos)
        return -1;

    if(partidos[pos].jugado &&
       ((partidos[pos].codigoLocal == equipoFila &&
         partidos[pos].codigoVisitante == equipoCol) ||
        (partidos[pos].codigoLocal == equipoCol &&
         partidos[pos].codigoVisitante == equipoFila)))
        return pos;

    return BuscarPartidoJugado(equipoFila, equipoCol, pos + 1);
}


int SumarGFRec(int fila, int col, int n)
{
    if(col == n)
        return 0;

    int aporte = 0;
    if(BuscarPartidoJugado(fila, col, 0) != -1)
        aporte = matrizGoles[fila][col];

    return aporte + SumarGFRec(fila, col + 1, n);
}


int SumarGCRec(int fila, int col, int n)
{
    if(col == n)
        return 0;

    int aporte = 0;
    if(BuscarPartidoJugado(fila, col, 0) != -1)
        aporte = matrizGoles[col][fila];

    return aporte + SumarGCRec(fila, col + 1, n);
}

float FuerzaOfensiva(Equipo e)
{
    if(nEquipos == 0)
        return 0;

    int totalGF = SumarGFRec(e.id, 0, nEquipos);
    return (float)totalGF / nEquipos;
}

float FuerzaDefensiva(Equipo e)
{
    if(nEquipos == 0)
        return 0;

    int totalGC = SumarGCRec(e.id, 0, nEquipos);
    return (float)totalGC / nEquipos;
}


float ProbLocal(Equipo a, Equipo b)
{
    float ataqueA = FuerzaOfensiva(a);
    float defensaB = FuerzaDefensiva(b);

    float valor = ataqueA - defensaB + 50;

    if(valor < 5)
        valor = 5;
    if(valor > 90)
        valor = 90;

    return valor;
}

float ProbEmpate(float local, float visitante)
{
    float dif = fabs(local - visitante);

    if(dif < 10)
        return 35;
    if(dif < 20)
        return 25;

    return 15;
}

float ProbVisitante(float local, float empate)
{
    return 100 - local - empate;
}

float Cuota(float prob)
{
    if(prob <= 0)
        return 0;

    return 100 / prob;
}

void MostrarPrediccion(Equipo a, Equipo b)
{
    float local = ProbLocal(a, b);
    float empate = ProbEmpate(local, 100 - local);
    float visitante = ProbVisitante(local, empate);

    cout << "\n==============================";
    cout << "\nPARTIDO: " << a.nombre << " VS " << b.nombre;
    cout << "\n\nPROBABILIDADES:";
    cout << "\nLocal: " << local << "%";
    cout << "\nEmpate: " << empate << "%";
    cout << "\nVisitante: " << visitante << "%";
    cout << "\n\nCUOTAS:";
    cout << "\nLocal: " << Cuota(local);
    cout << "\nEmpate: " << Cuota(empate);
    cout << "\nVisitante: " << Cuota(visitante);
    cout << "\n==============================\n";
}

#endif