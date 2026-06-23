#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED


struct Usuario
{
    char username[30];
    char password[30];
    float saldo;
    bool administrador;
};

struct Equipo
{
    int codigo;
    char nombre[30];

    int nivel;

    int partidosJugados;

    int golesFavor;
    int golesContra;

    int victorias;
    int empates;
    int derrotas;

    char racha[6];
};

struct Partido
{
    int codigoLocal;
    int codigoVisitante;

    int golesLocal;
    int golesVisitante;

    bool jugado;
};

struct Apuesta
{
    char username[30];

    int codigoLocal;
    int codigoVisitante;

    int opcion;

    float monto;
    float cuota;

    bool resuelta;

    float ganancia;
};

struct Evento
{
    int minuto;
    int tipoEvento;
    char descripcion[50];
};

#endif
