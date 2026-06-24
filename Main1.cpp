#include <iostream>
#include <iomanip>

#include "VARIABLES_GLOBALES.h"
#include "INICIAR_SISTEMA.h"
#include "USUARIO.h"

using namespace std;

int main()
{
    inicializarSistema();

    cout<<"Numero de equipos: "<<nEquipos<<endl;

    cout<<endl;

    for(int i=0;i<nEquipos;i++)
    {
        cout<<equipos[i].codigo<<" ";

        cout<<equipos[i].nombre<<" ";

        cout<<"Nivel: "<<equipos[i].nivel<<endl;
    }
        cout << setw(15) << "";

for(int j=0; j<nEquipos; j++)
{
    cout << setw(5) << j;
}

cout << endl;

for(int i=0; i<nEquipos; i++)
{
    cout << setw(15) << equipos[i].nombre;

    for(int j=0; j<nEquipos; j++)
    {
        cout << setw(5) << matrizGoles[i][j];
    }

    cout << endl;
}

cout << "\nMatriz de victorias:\n\n";

for(int i=0;i<5;i++)
{
    for(int j=0;j<5;j++)
    {
        cout << matrizVictorias[i][j] << "\t";
    }

    cout << endl;
}





    inicializarSistema();

    registrarUsuario();

    cout<<endl;

    mostrarUsuarios();

    cout<<endl;

    int posicion;

    posicion=buscarUsuario("Alejandro");

    if(posicion!=-1)
    {
        cout<<"Alejandro encontrado en la posicion "<<posicion<<endl;

        depositarSaldo(posicion,200);

        retirarSaldo(posicion,50);

        mostrarSaldo(posicion);
    }
    else
    {
        cout<<"Alejandro no existe"<<endl;
    }

    return 0;
}
