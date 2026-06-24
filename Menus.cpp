#include <iostream>
#include <cstdlib>

#include "VARIABLES_GLOBALES.h"
#include "USUARIO.h"
#include "SIMULADOR.h"
// #include "MotorApuestas.h" // Descomentar cuando Camila corrija el struct
#include "MENUS.h"

using namespace std;

bool menuUsuarios() {
    int opcion;
    bool salirSubmenu = false;

    while (!salirSubmenu) {
        system("cls");
        cout << "=== MENU USUARIOS ===" << endl;
        cout << "1. Registrar usuario" << endl;
        cout << "2. Iniciar sesion" << endl;
        cout << "3. Mostrar todos los usuarios" << endl;
        cout << "4. Volver" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            registrarUsuario(); 
            system("pause");
        } else if (opcion == 2) {
            iniciarSesion();    
            system("pause");
        } else if (opcion == 3) {
            mostrarUsuarios(); 
            system("pause");
        } else if (opcion == 4) {
            salirSubmenu = true;
        } else {
            cout << "Opcion invalida." << endl;
            system("pause");
        }
    }
    return true;
}

bool menuSimulador() {
    int idLocal;
    int idVisitante;
    bool simulacionExitosa = false;

    system("cls");
    cout << "=== PREPARAR PARTIDO EN VIVO ===" << endl;
    cout << "Ingrese el CODIGO del equipo Local: ";
    cin >> idLocal;
    cout << "Ingrese el CODIGO del equipo Visitante: ";
    cin >> idVisitante;

    if (idLocal >= 0 && idLocal < nEquipos && idVisitante >= 0 && idVisitante < nEquipos) {
        simulacionExitosa = simularPartidoVivo(idLocal, idVisitante);
    } else {
        cout << "Error: Codigos de equipo no validos." << endl;
        system("pause");
    }

    return simulacionExitosa;
}

bool menuPrincipal() {
    int opcion;
    bool salirSistema = false;

    while (!salirSistema) {
        system("cls");
        cout << "====================================" << endl;
        cout << "  SISTEMA DE PREDICCION DE FUTBOL   " << endl;
        cout << "====================================" << endl;
        cout << "1. Usuarios" << endl;
        cout << "2. Equipos (En construccion)" << endl;
        cout << "3. Prediccion (En construccion)" << endl;
        cout << "4. Apuestas (En construccion)" << endl;
        cout << "5. Partido en vivo" << endl;
        cout << "6. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            menuUsuarios();
        } else if (opcion == 2) {
            cout << "\n[Modulo de equipos en integracion]" << endl;
            system("pause");
        } else if (opcion == 3) {
            cout << "\n[Modulo de prediccion en integracion]" << endl;
            system("pause");
        } else if (opcion == 4) {
            cout << "\n[Llamar funciones de MotorApuestas.h]" << endl;
            system("pause");
        } else if (opcion == 5) {
            menuSimulador();
        } else if (opcion == 6) {
            salirSistema = true;
            cout << "Saliendo del sistema..." << endl;
        } else {
            cout << "Opcion invalida." << endl;
            system("pause");
        }
    }
    return true;
}
