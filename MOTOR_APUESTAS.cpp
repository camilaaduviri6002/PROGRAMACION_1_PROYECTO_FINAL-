#include <iostream>
#include <cstring>

#include "VARIABLES_GLOBALES.h"
#include "BASE_DE_DATOS.h"
#include "USUARIOS.h"

using namespace std;


//==================== REGISTRAR APUESTA ====================

void registrarApuesta()
{
    char username[30];

    cout<<"Username: ";
    cin>>username;

    int posUsuario;

    posUsuario = buscarUsuario(username);

    if(posUsuario==-1)
    {
        cout<<"Usuario inexistente."<<endl;

        return;
    }

    int codigoLocal;
    int codigoVisitante;

    cout<<"Codigo local: ";
    cin>>codigoLocal;

    cout<<"Codigo visitante: ";
    cin>>codigoVisitante;

    int opcion;

    cout<<"1. Local"<<endl;
    cout<<"2. Empate"<<endl;
    cout<<"3. Visitante"<<endl;

    cin>>opcion;

    float monto;

    cout<<"Monto: ";

    cin>>monto;

    if(usuarios[posUsuario].saldo<monto)
    {
        cout<<"Saldo insuficiente."<<endl;

        return;
    }

    retirarSaldo(posUsuario,monto);

    strcpy(apuestas[nApuestas].username,username);

    apuestas[nApuestas].codigoLocal =codigoLocal;

    apuestas[nApuestas].codigoVisitante =codigoVisitante;

    apuestas[nApuestas].opcion =opcion;

    apuestas[nApuestas].monto =monto;

    apuestas[nApuestas].cuota =1.5;

    apuestas[nApuestas].resuelta =false;

    apuestas[nApuestas].ganancia =0;

    nApuestas++;

    guardarApuestas();

    cout<<"Apuesta registrada."<<endl;
}


//==================== MOSTRAR APUESTAS ====================

void mostrarApuestas()
{
    for(int i=0;i<nApuestas;i++)
    {
        cout<<apuestas[i].username
            <<endl;

        cout<<equipos[apuestas[i].codigoLocal].nombre

            <<" vs "

            <<equipos[apuestas[i].codigoVisitante].nombre

            <<endl;

        cout<<"Monto: "

            <<apuestas[i].monto

            <<endl;

        cout<<"Cuota: "

            <<apuestas[i].cuota

            <<endl<<endl;
    }
}


//==================== BUSCAR APUESTA ====================

int buscarApuesta(int codigoLocal,
                  int codigoVisitante)
{
    for(int i=0;i<nApuestas;i++)
    {
        if(apuestas[i].codigoLocal==codigoLocal &&apuestas[i].codigoVisitante==codigoVisitante)
        {
            return i;
        }
    }

    return -1;
}


//==================== TOTAL APOSTADO ====================

float totalApostadoUsuario(char username[])
{
    float suma=0;

    for(int i=0;i<nApuestas;i++)
    {
        if(strcmp(username,apuestas[i].username)==0)
        {
            suma=suma+apuestas[i].monto;
        }
    }

    return suma;
}


//==================== HISTORIAL ====================

void mostrarHistorialUsuario(char username[])
{
    for(int i=0;i<nApuestas;i++)
    {
        if(strcmp(username,
                  apuestas[i].username)==0)
        {
            cout
            <<equipos[apuestas[i].codigoLocal].nombre

            <<" vs "

            <<equipos[apuestas[i].codigoVisitante].nombre

            <<endl;

            cout<<"Monto: "

                <<apuestas[i].monto

                <<endl;

            cout<<"Ganancia: "

                <<apuestas[i].ganancia

                <<endl<<endl;
        }
    }
}
