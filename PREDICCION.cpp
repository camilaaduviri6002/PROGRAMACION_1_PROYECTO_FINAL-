#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Apuesta
{
    int id;
    string usuario;
    string equipo1;
    string equipo2;
    string resultado;
    float monto;
};

void RegistrarApuesta(Apuesta apuestas[], int &n)
{
    cout << "\nID: ";
    cin >> apuestas[n].id;

    cin.ignore();

    cout << "Usuario: ";
    getline(cin, apuestas[n].usuario);

    cout << "Equipo Local: ";
    getline(cin, apuestas[n].equipo1);

    cout << "Equipo Visitante: ";
    getline(cin, apuestas[n].equipo2);

    cout << "Resultado (Local/Empate/Visitante): ";
    getline(cin, apuestas[n].resultado);

    cout << "Monto: ";
    cin >> apuestas[n].monto;

    n++;
}

void MostrarApuestas(Apuesta apuestas[], int n, int pos)
{
    if(pos >= n)
        return;

    cout << "\n------------------------";
    cout << "\nID: " << apuestas[pos].id;
    cout << "\nUsuario: " << apuestas[pos].usuario;
    cout << "\nPartido: "
         << apuestas[pos].equipo1
         << " vs "
         << apuestas[pos].equipo2;
    cout << "\nResultado: "
         << apuestas[pos].resultado;
    cout << "\nMonto: "
         << apuestas[pos].monto;

    MostrarApuestas(apuestas, n, pos + 1);
}

float TotalApostado(Apuesta apuestas[], int n, int pos)
{
    if(pos >= n)
        return 0;

    return apuestas[pos].monto + TotalApostado(apuestas, n, pos + 1);
}

int BuscarApuesta(Apuesta apuestas[],int n,int codigo,int pos)
{
    if(pos >= n)
        return -1;

    if(apuestas[pos].id == codigo)
        return pos;

    return BuscarApuesta(apuestas,n, codigo,pos + 1);
}

void GuardarApuestas(Apuesta apuestas[],int n,int pos,ofstream &archivo)
{
    if(pos >= n)
        return;

    archivo
    << apuestas[pos].id << "|"
    << apuestas[pos].usuario << "|"
    << apuestas[pos].equipo1 << "|"
    << apuestas[pos].equipo2 << "|"
    << apuestas[pos].resultado << "|"
    << apuestas[pos].monto
    << endl;

    GuardarApuestas(apuestas,n,pos + 1,archivo);
}

void GuardarTodo(Apuesta apuestas[], int n)
{
    ofstream archivo("Apuestas.txt");

    if(!archivo)
        return;

    GuardarApuestas(apuestas,n,0,archivo);

    archivo.close();
}

void CargarApuestas(Apuesta apuestas[], int &n)
{
    ifstream archivo("Apuestas.txt");

    if(!archivo)
        return;

    n = 0;

    while(archivo >> apuestas[n].id)
    {
        archivo.ignore();

        getline(archivo,apuestas[n].usuario,'|');

        getline(archivo,apuestas[n].equipo1,'|');

        getline(archivo, apuestas[n].equipo2,'|');

        getline(archivo, apuestas[n].resultado,'|');

        archivo >> apuestas[n].monto;

        archivo.ignore();

        n++;
    }

    archivo.close();
}

void ReporteUsuario(Apuesta apuestas[],int n,string usuario,int pos)
{
    if(pos >= n)
        return;

    if(apuestas[pos].usuario == usuario)
    {
        cout << "\n------------------------";
        cout << "\nID: "
             << apuestas[pos].id;

        cout << "\nUsuario: "
             << apuestas[pos].usuario;

        cout << "\nPartido: "
             << apuestas[pos].equipo1
             << " vs "
             << apuestas[pos].equipo2;

        cout << "\nResultado: "
             << apuestas[pos].resultado;

        cout << "\nMonto: "
             << apuestas[pos].monto;
    }

    ReporteUsuario(apuestas,n,usuario,pos + 1);
}

float TotalUsuario(Apuesta apuestas[],int n,string usuario,int pos)
{
    if(pos >= n)
        return 0;

    if(apuestas[pos].usuario == usuario)
    {
        return apuestas[pos].monto +TotalUsuario(apuestas,n,usuario,pos + 1);
    }

    return TotalUsuario(apuestas,n,usuario, pos + 1);
}

void BuscarUsuario(Apuesta apuestas[], int n)
{
    string usuario;

    cin.ignore();

    cout << "\nIngrese nombre del usuario: ";
    getline(cin, usuario);

    cout << "\n========== REPORTE DEL USUARIO ==========";

    ReporteUsuario(apuestas,n,usuario,0);

    cout << "\n\nTotal Apostado: "
         << TotalUsuario(apuestas,n,usuario,0);

    cout << "\n=========================================";
}
