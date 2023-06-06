#pragma once
#include <iostream>
#include <string>

using namespace std;

class Nodo {
private:
    int dato;
    Nodo* siguiente;
    Nodo* anterior;
public:
    Nodo(int);
    void setDato(int);
    void setSiguiente(Nodo*);
    void setAnterior(Nodo*);
    int getDato();
    Nodo* getSiguiente();
    Nodo* getAnterior();
};