#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>

#include "VARIABLES GLOBALES.h"
#include "BASE DE DATOS.h"
#include "INICIAR SISTEMA.h"

using namespace std;


//==================== EXISTE BASE DE DATOS ====================

bool existeBaseDatos()
{
    ifstream archivo("Equipos.bin", ios::binary);

    bool existe = archivo.good();

    archivo.close();

    return existe;
}


//==================== CARGAR EQUIPOS DESDE TXT ====================

void cargarEquiposTXT()
{
    ifstream archivo("Equipos.txt");

    nEquipos = 0;

    while (archivo.getline(equipos[nEquipos].nombre, 30))
    {
        equipos[nEquipos].codigo = nEquipos;

        equipos[nEquipos].nivel = rand()%10 + 1;

        equipos[nEquipos].partidosJugados = 0;

        equipos[nEquipos].golesFavor = 0;
        equipos[nEquipos].golesContra = 0;

        equipos[nEquipos].victorias = 0;
        equipos[nEquipos].empates = 0;
        equipos[nEquipos].derrotas = 0;

        strcpy(equipos[nEquipos].racha, "-----");

        nEquipos++;
    }

    archivo.close();
}


//==================== GENERAR MATRIZ DE GOLES ====================

void generarMatrizGoles()
{
    for(int i=0; i<nEquipos; i++)
    {
        for(int j=0; j<nEquipos; j++)
        {
            if(i==j)
            {
                matrizGoles[i][j]=0;
            }
            else
            {
                matrizGoles[i][j]=rand()%21;
            }
        }
    }
}


//==================== GENERAR MATRIZ DE VICTORIAS ====================

void generarMatrizVictorias()
{
    for(int i=0; i<nEquipos; i++)
    {
        for(int j=0; j<nEquipos; j++)
        {
            if(i==j)
            {
                matrizVictorias[i][j]=0;
            }
            else
            {
                matrizVictorias[i][j]=rand()%11;
            }
        }
    }
}


//==================== INICIALIZAR SISTEMA ====================

void inicializarSistema()
{
    srand(time(NULL));

    if(existeBaseDatos())
    {
        cargarUsuarios();

        cargarEquipos();

        cargarMatrizGoles();

        cargarMatrizVictorias();

        cargarApuestas();
    }
    else
    {
        cargarEquiposTXT();

        generarMatrizGoles();

        generarMatrizVictorias();

        guardarUsuarios();

        guardarEquipos();

        guardarMatrizGoles();

        guardarMatrizVictorias();
        guardarApuestas();
    }
}
