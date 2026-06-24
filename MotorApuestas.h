#ifndef MOTORAPUESTAS_H_INCLUDED
#define MOTORAPUESTAS_H_INCLUDED

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MAX_APUESTAS = 100;
const int MAX_EQUIPOS  = 20;

struct Apuesta
{
    char username[30];
    int codigoLocal;
    int codigoVisitante;
    int opcion;
    float monto;
    float cuota;
    bool resuelta;
    float ganancia;
};

struct Partido
{
    int codigoLocal;
    int codigoVisitante;
    int golesLocal;
    int golesVisitante;
    bool jugado;
};

extern Apuesta apuestas[MAX_APUESTAS];
extern int matrizGoles[MAX_EQUIPOS][MAX_EQUIPOS];
extern int matrizVictorias[MAX_EQUIPOS][MAX_EQUIPOS];
extern int nUsuarios;
extern int nEquipos;
extern int nApuestas;

void RegistrarApuesta()
{
    cout << "\nUsuario: ";
    cin.ignore();
    cin.getline(apuestas[nApuestas].username, 30);

    cout << "Codigo Equipo Local: ";
    cin >> apuestas[nApuestas].codigoLocal;

    cout << "Codigo Equipo Visitante: ";
    cin >> apuestas[nApuestas].codigoVisitante;

    cout << "Opcion (1=Local/2=Empate/3=Visitante): ";
    cin >> apuestas[nApuestas].opcion;

    cout << "Monto: ";
    cin >> apuestas[nApuestas].monto;

    cout << "Cuota: ";
    cin >> apuestas[nApuestas].cuota;

    apuestas[nApuestas].resuelta = false;
    apuestas[nApuestas].ganancia = 0;

    nApuestas++;
}

void MostrarApuestas(int pos)
{
    if(pos >= nApuestas)
        return;

    cout << "\n------------------------";
    cout << "\nUsuario: " << apuestas[pos].username;
    cout << "\nPartido: Equipo "
         << apuestas[pos].codigoLocal
         << " vs Equipo "
         << apuestas[pos].codigoVisitante;
    cout << "\nOpcion: "
         << apuestas[pos].opcion;
    cout << "\nMonto: "
         << apuestas[pos].monto;
    cout << "\nCuota: "
         << apuestas[pos].cuota;
    cout << "\nResuelta: "
         << (apuestas[pos].resuelta ? "Si" : "No");
    cout << "\nGanancia: "
         << apuestas[pos].ganancia;

    MostrarApuestas(pos + 1);
}

float TotalApostado(int pos)
{
    if(pos >= nApuestas)
        return 0;

    return apuestas[pos].monto + TotalApostado(pos + 1);
}

int BuscarApuesta(int codigoLocal,
                  int codigoVisitante,
                  const char usuario[30],
                  int pos)
{
    if(pos >= nApuestas)
        return -1;

    if(apuestas[pos].codigoLocal == codigoLocal &&
       apuestas[pos].codigoVisitante == codigoVisitante &&
       strcmp(apuestas[pos].username, usuario) == 0)
        return pos;

    return BuscarApuesta(
            codigoLocal,
            codigoVisitante,
            usuario,
            pos + 1);
}

void GuardarApuestas(int pos, ofstream &archivo)
{
    if(pos >= nApuestas)
        return;

    archivo
    << apuestas[pos].username << "|"
    << apuestas[pos].codigoLocal << "|"
    << apuestas[pos].codigoVisitante << "|"
    << apuestas[pos].opcion << "|"
    << apuestas[pos].monto << "|"
    << apuestas[pos].cuota << "|"
    << apuestas[pos].resuelta << "|"
    << apuestas[pos].ganancia
    << endl;

    GuardarApuestas(pos + 1, archivo);
}

void GuardarTodo()
{
    ofstream archivo("Apuestas.txt");

    if(!archivo)
        return;

    GuardarApuestas(0, archivo);

    archivo.close();
}

void CargarApuestas()
{
    ifstream archivo("Apuestas.txt");

    if(!archivo)
        return;

    nApuestas = 0;

    string linea;
    while(getline(archivo, linea))
    {
        if(linea.empty())
            continue;

        size_t p1 = linea.find('|');
        size_t p2 = linea.find('|', p1 + 1);
        size_t p3 = linea.find('|', p2 + 1);
        size_t p4 = linea.find('|', p3 + 1);
        size_t p5 = linea.find('|', p4 + 1);
        size_t p6 = linea.find('|', p5 + 1);
        size_t p7 = linea.find('|', p6 + 1);

        string usuarioStr = linea.substr(0, p1);
        strcpy(apuestas[nApuestas].username, usuarioStr.c_str());

        apuestas[nApuestas].codigoLocal =
            stoi(linea.substr(p1 + 1, p2 - p1 - 1));

        apuestas[nApuestas].codigoVisitante =
            stoi(linea.substr(p2 + 1, p3 - p2 - 1));

        apuestas[nApuestas].opcion =
            stoi(linea.substr(p3 + 1, p4 - p3 - 1));

        apuestas[nApuestas].monto =
            stof(linea.substr(p4 + 1, p5 - p4 - 1));

        apuestas[nApuestas].cuota =
            stof(linea.substr(p5 + 1, p6 - p5 - 1));

        apuestas[nApuestas].resuelta =
            stoi(linea.substr(p6 + 1, p7 - p6 - 1)) != 0;

        apuestas[nApuestas].ganancia =
            stof(linea.substr(p7 + 1));

        nApuestas++;
    }

    archivo.close();
}

void ReporteUsuario(const char usuario[30], int pos)
{
    if(pos >= nApuestas)
        return;

    if(strcmp(apuestas[pos].username, usuario) == 0)
    {
        cout << "\n------------------------";
        cout << "\nUsuario: "
             << apuestas[pos].username;

        cout << "\nPartido: Equipo "
             << apuestas[pos].codigoLocal
             << " vs Equipo "
             << apuestas[pos].codigoVisitante;

        cout << "\nOpcion: "
             << apuestas[pos].opcion;

        cout << "\nMonto: "
             << apuestas[pos].monto;

        cout << "\nCuota: "
             << apuestas[pos].cuota;

        cout << "\nResuelta: "
             << (apuestas[pos].resuelta ? "Si" : "No");

        cout << "\nGanancia: "
             << apuestas[pos].ganancia;
    }

    ReporteUsuario(usuario, pos + 1);
}

float TotalUsuario(const char usuario[30], int pos)
{
    if(pos >= nApuestas)
        return 0;

    if(strcmp(apuestas[pos].username, usuario) == 0)
    {
        return apuestas[pos].monto +
               TotalUsuario(usuario, pos + 1);
    }

    return TotalUsuario(usuario, pos + 1);
}

void BuscarUsuario()
{
    char usuario[30];

    cin.ignore();

    cout << "\nIngrese nombre del usuario: ";
    cin.getline(usuario, 30);

    cout << "\n========== REPORTE DEL USUARIO ==========";

    ReporteUsuario(usuario, 0);

    cout << "\n\nTotal Apostado: " << TotalUsuario(usuario, 0);

    cout << "\n=========================================";
}

#endif
