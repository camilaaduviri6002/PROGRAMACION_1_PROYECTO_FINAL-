#include <fstream>
using namespace std;

#include "VARIABLES GLOBALES.h"
#include "BASE DE DATOS.h"

//==================== USUARIOS ====================

void guardarUsuarios()
{
    ofstream archivo("Usuarios.bin", ios::binary);
    archivo.write((char*)&nUsuarios, sizeof(int));
    archivo.write((char*)usuarios, sizeof(Usuario) * nUsuarios);
    archivo.close();
}

void cargarUsuarios()
{
    ifstream archivo("Usuarios.bin", ios::binary);

    if (archivo)
    {
        archivo.read((char*)&nUsuarios, sizeof(int));

        archivo.read((char*)usuarios, sizeof(Usuario) * nUsuarios);
    }

    archivo.close();
}

//==================== EQUIPOS ====================

void guardarEquipos()
{
    ofstream archivo("Equipos.bin", ios::binary);

    archivo.write((char*)&nEquipos, sizeof(int));

    archivo.write((char*)equipos, sizeof(Equipo) * nEquipos);

    archivo.close();
}

void cargarEquipos()
{
    ifstream archivo("Equipos.bin", ios::binary);

    if (archivo)
    {
        archivo.read((char*)&nEquipos, sizeof(int));
        archivo.read((char*)equipos, sizeof(Equipo) * nEquipos);
    }

    archivo.close();
}

//==================== MATRIZ DE GOLES ====================

void guardarMatrizGoles()
{
    ofstream archivo("MatrizGoles.bin", ios::binary);
    archivo.write((char*)matrizGoles, sizeof(matrizGoles));

    archivo.close();
}

void cargarMatrizGoles()
{
    ifstream archivo("MatrizGoles.bin", ios::binary);

    if (archivo)
    {
        archivo.read((char*)matrizGoles, sizeof(matrizGoles));
    }

    archivo.close();
}

//==================== MATRIZ DE VICTORIAS ====================

void guardarMatrizVictorias()
{
    ofstream archivo("MatrizVictorias.bin", ios::binary);

    archivo.write((char*)matrizVictorias, sizeof(matrizVictorias));

    archivo.close();
}

void cargarMatrizVictorias()
{
    ifstream archivo("MatrizVictorias.bin", ios::binary);

    if (archivo)
    {
        archivo.read((char*)matrizVictorias, sizeof(matrizVictorias));
    }

    archivo.close();
}

//==================== APUESTAS ====================

void guardarApuestas()
{
    ofstream archivo("Apuestas.bin", ios::binary);
    archivo.write((char*)&nApuestas, sizeof(int));
    archivo.write((char*)apuestas, sizeof(Apuesta) * nApuestas);

    archivo.close();
}

void cargarApuestas()
{
    ifstream archivo("Apuestas.bin", ios::binary);

    if (archivo)
    {
        archivo.read((char*)&nApuestas, sizeof(int));
        archivo.read((char*)apuestas, sizeof(Apuesta) * nApuestas);
    }

    archivo.close();
}
