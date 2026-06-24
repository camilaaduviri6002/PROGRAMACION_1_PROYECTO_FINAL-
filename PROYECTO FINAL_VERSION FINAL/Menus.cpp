#include <iostream>
#include <cstdlib>

#include "VARIABLES_GLOBALES.h"
#include "USUARIO.h"
#include "SIMULADOR.h"
#include "MOTOR_APUESTAS.h"
#include "PREDICCION.h"
#include "MENUS.h"

using namespace std;

// ==========================================
// SUBMENÚ: USUARIOS
// ==========================================
bool menuUsuarios() {
    int opcion;
    bool salirSubmenu = false;

    while (!salirSubmenu) {
        system("cls");
        cout << "=== MENU USUARIOS ===" << endl;
        cout << "1. Registrar usuario" << endl;
        cout << "2. Iniciar sesion" << endl;
        cout << "3. Mostrar todos los usuarios" << endl;
        cout << "4. Anadir Saldo a una cuenta" << endl;
        cout << "5. Retirar Saldo de una cuenta" << endl; 
        cout << "6. Volver" << endl;
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
            char userDeposito[30];
            float montoDeposito;

            cout << "\nIngrese su username: ";
            cin >> userDeposito;

            int pos = buscarUsuario(userDeposito);

            if (pos != -1) {
                cout << "Ingrese el monto a depositar (Bs): ";
                cin >> montoDeposito;

                if (montoDeposito > 0) {
                    depositarSaldo(pos, montoDeposito);
                    cout << "\n¡Deposito exitoso!" << endl;
                    mostrarSaldo(pos);
                } else {
                    cout << "Error: El monto debe ser mayor a 0." << endl;
                }
            } else {
                cout << "Error: Usuario no encontrado." << endl;
            }
            system("pause");
        } else if (opcion == 5) {
            char userRetiro[30];
            float montoRetiro;

            cout << "\nIngrese su username: ";
            cin >> userRetiro;

            int pos = buscarUsuario(userRetiro);

            if (pos != -1) {
                mostrarSaldo(pos); 
                cout << "Ingrese el monto a retirar (Bs): ";
                cin >> montoRetiro;

                if (montoRetiro > 0) {
                    if (usuarios[pos].saldo >= montoRetiro) {
                        retirarSaldo(pos, montoRetiro); 
                        cout << "\n¡Retiro procesado exitosamente!" << endl;
                        mostrarSaldo(pos);
                    } else {
                        cout << "\nError: Saldo insuficiente para realizar el retiro." << endl;
                    }
                } else {
                    cout << "Error: El monto debe ser mayor a 0." << endl;
                }
            } else {
                cout << "Error: Usuario no encontrado." << endl;
            }
            system("pause");
        } else if (opcion == 6) {
            salirSubmenu = true;
        } else {
            cout << "Opcion invalida." << endl;
            system("pause");
        }
    }
    return true;
}
// ==========================================
// SUBMENÚ: EQUIPOS
// ==========================================
bool menuEquipos()
{
    int opcion;

    bool salirSubmenu = false;

    while (!salirSubmenu)
    {
        system("cls");

        cout << "========== MENU EQUIPOS ==========" << endl;

        cout << "1. Mostrar equipos disponibles" << endl;

        cout << "2. Mostrar estadisticas de equipos" << endl;

        cout << "3. Mostrar matriz de goles" << endl;

        cout << "4. Mostrar matriz de victorias" << endl;

        cout << "5. Volver" << endl;

        cout << "Opcion: ";

        cin >> opcion;


        if (opcion == 1)
        {
            cout << "\nLISTA DE EQUIPOS EN LA BASE DE DATOS:\n" << endl;

            for(int i=0;i<nEquipos;i++)
            {
                cout
                << equipos[i].codigo
                << ". "
                << equipos[i].nombre
                << " (Nivel: "
                << equipos[i].nivel
                << ")"
                << endl;
            }

            cout << endl;

            system("pause");
        }


        else if(opcion == 2)
        {
            mostrarEstadisticasEquipos();

            cout << endl;

            system("pause");
        }


        else if(opcion == 3)
        {
            mostrarMatrizGoles();

            cout << endl;

            system("pause");
        }


        else if(opcion == 4)
        {
            mostrarMatrizVictorias();

            cout << endl;

            system("pause");
        }


        else if(opcion == 5)
        {
            salirSubmenu = true;
        }


        else
        {
            cout << "Opcion invalida." << endl;

            system("pause");
        }
    }

    return true;
}
// ==========================================
// SUBMENÚ: APUESTAS
// ==========================================
bool menuApuestas() {
    int opcion;
    bool salirSubmenu = false;

    while (!salirSubmenu) {
        system("cls");
        cout << "=== MENU APUESTAS ===" << endl;
        cout << "1. Registrar nueva apuesta" << endl;
        cout << "2. Ver todas las apuestas" << endl;
        cout << "3. Buscar historial por usuario" << endl;
        cout << "4. Volver" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            registrarApuesta();
            system("pause");
        } else if (opcion == 2) {
            cout << "\n--- REGISTRO HISTORICO DE APUESTAS ---" << endl;
            mostrarApuestas();
            system("pause");
        } else if (opcion == 3) {
            char userApuesta[30];
            cout << "\nIngrese el username a buscar: ";
            cin >> userApuesta;

            cout << "\n--- HISTORIAL DE " << userApuesta << " ---" << endl;
            mostrarHistorialUsuario(userApuesta);
            cout << ">> TOTAL APOSTADO: " << totalApostadoUsuario(userApuesta) << " Bs <<" << endl;
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

// ==========================================
// SUBMENÚ: SIMULADOR DE PARTIDOS
// ==========================================
bool menuSimulador() {
    int idLocal;
    int idVisitante;
    bool simulacionExitosa = false;

    system("cls");
    cout << "=== PREPARAR PARTIDO EN VIVO ===" << endl;

    cout << "(Consejo: Puedes revisar los codigos de los equipos en el Menu Equipos)\n" << endl;

    cout << "Ingrese el CODIGO del equipo Local: ";
    cin >> idLocal;
    cout << "Ingrese el CODIGO del equipo Visitante: ";
    cin >> idVisitante;

    if (idLocal == idVisitante) {
        cout << "Error: Un equipo no puede jugar contra si mismo." << endl;
        system("pause");
    } else if (idLocal >= 0 && idLocal < nEquipos && idVisitante >= 0 && idVisitante < nEquipos) {
        simulacionExitosa = simularPartidoVivo(idLocal, idVisitante);
    } else {
        cout << "Error: Codigos de equipo no validos." << endl;
        system("pause");
    }

    return simulacionExitosa;
}

// ==========================================
// MENÚ PRINCIPAL
// ==========================================
bool menuPrincipal() {
    int opcion;
    bool salirSistema = false;

    while (!salirSistema) {
        system("cls");
        cout << "====================================" << endl;
        cout << "  SISTEMA DE PREDICCION DE FUTBOL   " << endl;
        cout << "====================================" << endl;
        cout << "1. Usuarios" << endl;
        cout << "2. Equipos" << endl;
        cout << "3. Prediccion" << endl;
        cout << "4. Apuestas" << endl;
        cout << "5. Partido en vivo" << endl;
        cout << "6. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            menuUsuarios();
        } else if (opcion == 2) {
            menuEquipos();
        } else if (opcion == 3) {
            mostrarPrediccion();
            system("pause");
        } else if (opcion == 4) {
            menuApuestas();
        } else if (opcion == 5) {
            menuSimulador();
        } else if (opcion == 6) {
            salirSistema = true;
            system("cls");
            cout << "Guardando informacion y cerrando el sistema..." << endl;
        } else {
            cout << "Opcion invalida." << endl;
            system("pause");
        }
    }
    return true;
}
