
#ifndef SIMULADOR_H_INCLUDED
#define SIMULADOR_H_INCLUDED


//==================== EVENTOS ====================

int calcularEventoAleatorio(int limiteInferior,
                            int limiteSuperior);


//==================== MARCADOR ====================

bool imprimirMarcador(int minuto,
                      int golesL,
                      int golesV,
                      int indiceLocal,
                      int indiceVisitante);


//==================== MATRICES ====================

void mostrarMatrizGoles();

void mostrarMatrizVictorias();


//==================== ESTADISTICAS ====================

void mostrarEstadisticasEquipos();


//==================== SIMULACION ====================

bool simularPartidoVivo(int indiceLocal,
                        int indiceVisitante);


#endif

