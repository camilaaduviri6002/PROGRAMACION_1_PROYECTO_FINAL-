#ifndef MOTOR_APUESTAS_H_INCLUDED
#define MOTOR_APUESTAS_H_INCLUDED


void registrarApuesta();
void mostrarApuestas();
int buscarApuesta(int codigoLocal,int codigoVisitante);
float totalApostadoUsuario(char username[]);
void mostrarHistorialUsuario(char username[]);


#endif
