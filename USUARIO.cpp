#include <iostream>
#include <cstring>

#include "ESTRUCTURAS.h"
#include "VARIABLES_GLOBALES.h"
#include "BASE_DE_DATOS.h"
#include "USUARIO.h"

using namespace std;


//==================== EXISTE USUARIO ====================

bool existeUsuario(char username[])
{
    for(int i=0;i<nUsuarios;i++)
    {
        if(strcmp(username,usuarios[i].username)==0)
        {
            return true;
        }
    }

    return false;
}


//==================== BUSCAR USUARIO ====================

int buscarUsuario(char username[])
{
    for(int i=0;i<nUsuarios;i++)
    {
        if(strcmp(username,usuarios[i].username)==0)
        {
            return i;
        }
    }

    return -1;
}


//==================== REGISTRAR USUARIO ====================

void registrarUsuario()
{
    char username[30];
    char password[30];

    cout<<"\nREGISTRO DE USUARIO\n"<<endl;

    cout<<"Username: ";
    cin>>username;

    if(existeUsuario(username))
    {
        cout<<"\nEse usuario ya existe.\n"<<endl;

        return;
    }

    cout<<"Password: ";
    cin>>password;

    strcpy(usuarios[nUsuarios].username,username);

    strcpy(usuarios[nUsuarios].password,password);

    usuarios[nUsuarios].saldo=0;

    usuarios[nUsuarios].administrador=false;

    nUsuarios++;

    guardarUsuarios();

    cout<<"\nUsuario registrado correctamente.\n"<<endl;
}


//==================== INICIAR SESION ====================

bool iniciarSesion()
{
    char username[30];
    char password[30];

    cout<<"\nINICIAR SESION\n"<<endl;

    cout<<"Username: ";
    cin>>username;

    cout<<"Password: ";
    cin>>password;

    for(int i=0;i<nUsuarios;i++)
    {
        if(strcmp(username,usuarios[i].username)==0 &&
           strcmp(password,usuarios[i].password)==0)
        {
            cout<<"\nBienvenido "<<usuarios[i].username<<endl;

            return true;
        }
    }

    cout<<"\nUsuario o password incorrectos.\n"<<endl;

    return false;
}


//==================== MOSTRAR USUARIOS ====================

void mostrarUsuarios()
{
    cout<<"\nLISTA DE USUARIOS\n"<<endl;

    for(int i=0;i<nUsuarios;i++)
    {
        cout<<usuarios[i].username<<"    ";

        cout<<"Saldo: "<<usuarios[i].saldo<<" Bs"<<endl;
    }
}


//==================== MOSTRAR SALDO ====================

void mostrarSaldo(int posicionUsuario)
{
    cout<<"\nSaldo actual: ";

    cout<<usuarios[posicionUsuario].saldo;

    cout<<" Bs"<<endl;
}


//==================== DEPOSITAR SALDO ====================

void depositarSaldo(int posicionUsuario,float monto)
{
    usuarios[posicionUsuario].saldo+=monto;

    guardarUsuarios();
}


//==================== RETIRAR SALDO ====================

void retirarSaldo(int posicionUsuario,float monto)
{
    usuarios[posicionUsuario].saldo-=monto;

    guardarUsuarios();
}
