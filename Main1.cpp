#include <iostream>
#include "INICIAR_SISTEMA.h"
#include "Menus.h"

using namespace std;

int main()
{
    cout<<"========================================"<<endl;

    cout<<" SISTEMA DE PREDICCION DE FUTBOL "<<endl;

    cout<<"========================================"<<endl;

    cout<<endl;

    inicializarSistema();

    menuPrincipal();

    cout<<endl;

    cout<<"Gracias por utilizar el sistema."<<endl;

    return 0;
}
