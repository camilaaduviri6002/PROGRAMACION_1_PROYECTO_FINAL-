#include <iostream>
#include <cstdlib>

#include "INICIAR_SISTEMA.h"
#include "MENUS.h"

using namespace std;

int main() {
    bool sistemaIniciado;

    cout << "==================================================" << endl;
    cout << "   INICIANDO SISTEMA DE PREDICCION DE FUTBOL...   " << endl;
    cout << "==================================================" << endl;
    inicializarSistema();
    cout << "\nPresione ENTER para ir al Menu Principal..." << endl;
    system("pause > nul"); 
    sistemaIniciado = menuPrincipal();
    if (sistemaIniciado) {
        cout << "\nApagando el sistema de forma segura. ¡Hasta pronto!" << endl;
    }

    return 0;
}
