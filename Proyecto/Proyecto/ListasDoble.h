#pragma once
#include "Nodo.h"

using namespace std;

class ListaDoble {
private:
    Nodo* primero;
    Nodo* ultimo;
public:
    ListaDoble();
    void InsertarCabeza(Producto);
    void InsertarCola(Producto);
    void Buscar(int);
    void Eliminar(int);
    void Mostrar();
    int dimencion();
    ListaDoble* ordenar();
    ListaDoble* Modificar(int);
    Producto getPosicion(int);
};


