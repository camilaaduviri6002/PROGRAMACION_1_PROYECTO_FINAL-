#ifndef VARIABLES_GLOBALES_H_INCLUDED
#define VARIABLES_GLOBALES_H_INCLUDED

#include "ESTRUCTURAS.h"

const int MAX_USUARIOS=100;
const int MAX_EQUIPOS=50;
const int MAX_APUESTAS=1000;

Usuario usuarios[MAX_USUARIOS];

Equipo equipos[MAX_EQUIPOS];

Apuesta apuestas[MAX_APUESTAS];

int matrizGoles[MAX_EQUIPOS][MAX_EQUIPOS];

int matrizVictorias[MAX_EQUIPOS][MAX_EQUIPOS];

int nUsuarios=0;
int nEquipos=0;
int nApuestas=0;

#endif
