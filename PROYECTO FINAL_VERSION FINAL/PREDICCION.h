#ifndef PREDICCION_H_INCLUDED
#define PREDICCION_H_INCLUDED



float calcularIndiceOfensivo(int codigoEquipo);

float calcularIndiceDefensivo(int codigoEquipo);

float calcularProbabilidadLocal(int codigoLocal, int codigoVisitante);

float calcularProbabilidadEmpate(int codigoLocal,int codigoVisitante);

float calcularProbabilidadVisitante(int codigoLocal,int codigoVisitante);

void mostrarPrediccion();


#endif 
