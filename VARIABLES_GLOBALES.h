#ifndef VARIABLES_GLOBALES_H_INCLUDED
#define VARIABLES_GLOBALES_H_INCLUDED

#include "ESTRUCTURAS.h"

const int MAX_USUARIOS = 100;
const int MAX_EQUIPOS = 50;
const int MAX_APUESTAS = 1000;

extern Usuario usuarios[MAX_USUARIOS];

extern Equipo equipos[MAX_EQUIPOS];

extern Apuesta apuestas[MAX_APUESTAS];

extern int matrizGoles[MAX_EQUIPOS][MAX_EQUIPOS];

extern int matrizVictorias[MAX_EQUIPOS][MAX_EQUIPOS];

extern int nUsuarios;
extern int nEquipos;
extern int nApuestas;

#endif
