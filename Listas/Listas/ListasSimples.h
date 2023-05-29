#pragma once
#include "Nodo.h"

using namespace std;

class ListaSimples {

private:
    Nodo* cabeza;
public:
    ListaSimples();
    void InsertarCabeza(int);
    void InsertarCola(int);
    void Buscar(int);
    void Eliminar(int);
    void Mostrar();
};


