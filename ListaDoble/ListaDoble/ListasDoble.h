#pragma once
#include "Nodo.h"

using namespace std;

class ListaDoble {
private:
    Nodo* primero;
    Nodo* ultimo;
public:
    ListaDoble();
    void InsertarCabeza(int);
    void InsertarCola(int);
    void Buscar(int);
    void Eliminar(int);
    void Mostrar();
};

