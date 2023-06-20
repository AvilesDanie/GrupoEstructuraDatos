#pragma once
#include <iostream>
#include <string>
#include "Producto.h"

using namespace std;

class Nodo {
private:
    Producto producto;
    Nodo* siguiente;
    Nodo* anterior;
public:
    Nodo(Producto);
    void setDato(Producto);
    void setSiguiente(Nodo*);
    void setAnterior(Nodo*);
    Producto getDato();
    Nodo* getSiguiente();
    Nodo* getAnterior();
};

