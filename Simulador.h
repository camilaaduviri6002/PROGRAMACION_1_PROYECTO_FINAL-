#ifndef SIMULADOR_H_INCLUDED
#define SIMULADOR_H_INCLUDED

int calcularEventoAleatorio(int limiteInferior,int limiteSuperior);
bool imprimirMarcador(int minuto,int golesL,int golesV,int indiceLocal,int indiceVisitante);
bool simularPartidoVivo(int indiceLocal,int indiceVisitante);

#endif


