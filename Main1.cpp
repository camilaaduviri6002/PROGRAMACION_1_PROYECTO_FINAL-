#include <iostream>

#include "VARIABLES GLOBALES.h"
#include "INICIAR SISTEMA.h"

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

    return 0;
}
