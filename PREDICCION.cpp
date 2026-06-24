#include <iostream>
#include <iomanip> // Para redondear los porcentajes a 2 decimales
#include "VARIABLES_GLOBALES.h"
#include "PREDICCION.h"

using namespace std;

// ==========================================
// 1. CÁLCULO DE ÍNDICES (Fuerza del Equipo)
// ==========================================

float calcularIndiceOfensivo(int codigoEquipo) {
    // Evitamos division entre cero si el sistema es nuevo y no hay partidos
    if (equipos[codigoEquipo].partidosJugados == 0) {
        // Si no hay historial, su Nivel dicta su capacidad ofensiva
        return (float)equipos[codigoEquipo].nivel; 
    }
    // Promedio de goles marcados por partido
    return (float)equipos[codigoEquipo].golesFavor / equipos[codigoEquipo].partidosJugados;
}

float calcularIndiceDefensivo(int codigoEquipo) {
    if (equipos[codigoEquipo].partidosJugados == 0) {
        // Nivel alto = buena defensa (por eso se resta de 10)
        return 10.0f - (float)equipos[codigoEquipo].nivel;
    }
    // Promedio de goles recibidos por partido
    return (float)equipos[codigoEquipo].golesContra / equipos[codigoEquipo].partidosJugados;
}

// ==========================================
// 2. CÁLCULO DE PROBABILIDADES
// ==========================================

float calcularProbabilidadLocal(int codigoLocal, int codigoVisitante) {
    // Calculamos los "Puntos de Fuerza" combinando indices, nivel y matriz historica (H2H)
    float fuerzaLocal = calcularIndiceOfensivo(codigoLocal) + equipos[codigoLocal].nivel + matrizVictorias[codigoLocal][codigoVisitante];
    float fuerzaVisitante = calcularIndiceOfensivo(codigoVisitante) + equipos[codigoVisitante].nivel + matrizVictorias[codigoVisitante][codigoLocal];
    float fuerzaEmpate = 5.0f; // Constante base

    float fuerzaTotal = fuerzaLocal + fuerzaVisitante + fuerzaEmpate;
    
    if (fuerzaTotal == 0) return 33.33f; // Seguridad matemática
    
    // Regla de 3 simple + Ventaja de Localia (+5%)
    return ((fuerzaLocal / fuerzaTotal) * 100.0f) + 5.0f;
}

float calcularProbabilidadVisitante(int codigoLocal, int codigoVisitante) {
    float fuerzaLocal = calcularIndiceOfensivo(codigoLocal) + equipos[codigoLocal].nivel + matrizVictorias[codigoLocal][codigoVisitante];
    float fuerzaVisitante = calcularIndiceOfensivo(codigoVisitante) + equipos[codigoVisitante].nivel + matrizVictorias[codigoVisitante][codigoLocal];
    float fuerzaEmpate = 5.0f; 

    float fuerzaTotal = fuerzaLocal + fuerzaVisitante + fuerzaEmpate;
    
    if (fuerzaTotal == 0) return 33.33f;
    
    // Regla de 3 simple - Desventaja de Visita (-5%)
    float probVisitante = ((fuerzaVisitante / fuerzaTotal) * 100.0f) - 5.0f;
    
    if (probVisitante < 0) return 0.0f;
    return probVisitante;
}

float calcularProbabilidadEmpate(int codigoLocal, int codigoVisitante) {
    // El empate es simplemente lo que sobra para llegar al 100% exacto
    float probLocal = calcularProbabilidadLocal(codigoLocal, codigoVisitante);
    float probVisitante = calcularProbabilidadVisitante(codigoLocal, codigoVisitante);
    
    float probEmpate = 100.0f - (probLocal + probVisitante);
    
    if (probEmpate < 0) return 0.0f;
    return probEmpate;
}

// ==========================================
// 3. INTERFAZ DEL MÓDULO (Para el Usuario)
// ==========================================

void mostrarPrediccion() {
    int idLocal, idVisitante;

    system("cls");
    cout << "=== MODULO DE PREDICCION ===" << endl;
    cout << "Ingrese el CODIGO del equipo Local: ";
    cin >> idLocal;
    cout << "Ingrese el CODIGO del equipo Visitante: ";
    cin >> idVisitante;

    // Validacion de errores
    if (idLocal == idVisitante) {
        cout << "Error: Un equipo no puede jugar contra si mismo." << endl;
    } 
    else if (idLocal >= 0 && idLocal < nEquipos && idVisitante >= 0 && idVisitante < nEquipos) {
        
        // Ejecutamos las formulas de Camila
        float pLocal = calcularProbabilidadLocal(idLocal, idVisitante);
        float pEmpate = calcularProbabilidadEmpate(idLocal, idVisitante);
        float pVisitante = calcularProbabilidadVisitante(idLocal, idVisitante);

        // Imprimimos los resultados en pantalla
        cout << "\n--- PRONOSTICO ESTADISTICO ---" << endl;
        cout << equipos[idLocal].nombre << " vs " << equipos[idVisitante].nombre << endl;
        cout << "------------------------------" << endl;
        
        // fixed y setprecision obligan a mostrar solo 2 decimales
        cout << fixed << setprecision(2);
        cout << "Victoria " << equipos[idLocal].nombre << " (Local) : " << pLocal << " %" << endl;
        cout << "Empate                          : " << pEmpate << " %" << endl;
        cout << "Victoria " << equipos[idVisitante].nombre << " (Visita): " << pVisitante << " %" << endl;
        cout << "------------------------------" << endl;
        
        cout << "[Datos Analizados: Nivel base, Indice Ofensivo/Defensivo y Matriz Historica]" << endl;
        
    } else {
        cout << "Error: Codigos de equipo no validos." << endl;
    }
}
