#pragma once
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Nodo {
private:
    int dato;
    Nodo* siguiente;
public:
    Nodo(int);
    void setDato(int);
    int getDato();
    void setSiguiente(Nodo*);
    Nodo* getSiguiente();
    friend class ListaSimples;
};


