
#include <iostream>
#include <cstring>

#include "VARIABLES_GLOBALES.h"
#include "BASE_DE_DATOS.h"
#include "USUARIO.h"
#include "PREDICCION.h"

using namespace std;


//==================== REGISTRAR APUESTA ====================

void registrarApuesta()
{
    char username[30];

    cout<<"Username: ";

    cin>>username;

    int posUsuario;

    posUsuario=buscarUsuario(username);

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


    if(codigoLocal==codigoVisitante)
    {
        cout<<"Un equipo no puede jugar contra si mismo."<<endl;

        return;
    }


    cout<<endl;

    mostrarPrediccion();

    cout<<endl;


    int opcion;

    cout<<"1. Gana local"<<endl;

    cout<<"2. Empate"<<endl;

    cout<<"3. Gana visitante"<<endl;

    cout<<"Opcion: ";

    cin>>opcion;


    float monto;

    cout<<"Monto a apostar: ";

    cin>>monto;


    if(monto<=0)
    {
        cout<<"Monto invalido."<<endl;

        return;
    }


    if(usuarios[posUsuario].saldo<monto)
    {
        cout<<"Saldo insuficiente."<<endl;

        return;
    }


    float cuota;


    if(opcion==1)
    {
        cuota=100/
        calcularProbabilidadLocal(codigoLocal,
                                  codigoVisitante);
    }

    else if(opcion==2)
    {
        cuota=100/
        calcularProbabilidadEmpate(codigoLocal,
                                   codigoVisitante);
    }

    else
    {
        cuota=100/
        calcularProbabilidadVisitante(codigoLocal,
                                      codigoVisitante);
    }


    retirarSaldo(posUsuario,monto);


    strcpy(apuestas[nApuestas].username,
           username);

    apuestas[nApuestas].codigoLocal=
    codigoLocal;

    apuestas[nApuestas].codigoVisitante=
    codigoVisitante;

    apuestas[nApuestas].opcion=
    opcion;

    apuestas[nApuestas].monto=
    monto;

    apuestas[nApuestas].cuota=
    cuota;

    apuestas[nApuestas].resuelta=
    false;

    apuestas[nApuestas].ganancia=
    0;


    nApuestas++;

    guardarApuestas();


    cout<<endl;

    cout<<"Apuesta registrada correctamente."<<endl;

    cout<<"Cuota asignada: "
        <<cuota
        <<endl;
}


//==================== MOSTRAR APUESTAS ====================

void mostrarApuestas()
{
    for(int i=0;i<nApuestas;i++)
    {
        cout<<"Usuario: "
            <<apuestas[i].username
            <<endl;

        cout
        <<equipos[apuestas[i].codigoLocal].nombre

        <<" vs "

        <<equipos[apuestas[i].codigoVisitante].nombre

        <<endl;

        cout<<"Monto: "
            <<apuestas[i].monto
            <<endl;

        cout<<"Cuota: "
            <<apuestas[i].cuota
            <<endl;

        if(apuestas[i].resuelta)
        {
            cout<<"Estado: Resuelta"<<endl;
        }

        else
        {
            cout<<"Estado: Pendiente"<<endl;
        }

        cout<<"Ganancia: "
            <<apuestas[i].ganancia
            <<endl;

        cout<<endl;
    }
}


//==================== BUSCAR APUESTA ====================

int buscarApuesta(int codigoLocal,
                  int codigoVisitante)
{
    for(int i=0;i<nApuestas;i++)
    {
        if(apuestas[i].codigoLocal==codigoLocal
           &&
           apuestas[i].codigoVisitante==codigoVisitante)
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
        if(strcmp(username,
                  apuestas[i].username)==0)
        {
            suma+=apuestas[i].monto;
        }
    }

    return suma;
}


//==================== HISTORIAL DE USUARIO ====================

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

            cout<<"Cuota: "
                <<apuestas[i].cuota
                <<endl;

            cout<<"Ganancia: "
                <<apuestas[i].ganancia
                <<endl;

            if(apuestas[i].resuelta)
            {
                cout<<"Estado: Resuelta"<<endl;
            }

            else
            {
                cout<<"Estado: Pendiente"<<endl;
            }

            cout<<endl;
        }
    }
}

