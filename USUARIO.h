#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

void registrarUsuario();

bool iniciarSesion();

bool existeUsuario(char username[]);

int buscarUsuario(char username[]);

void mostrarUsuarios();

void mostrarSaldo(int posicionUsuario);

void depositarSaldo(int posicionUsuario,float monto);

void retirarSaldo(int posicionUsuario,float monto);

#endif
