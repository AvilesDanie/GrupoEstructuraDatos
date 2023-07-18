#pragma once
#include "Nodo.h"
#include <iostream>
#include <string>

class Arbol
{
private:
    Nodo* arbol = NULL;
    void imprimirNivelActual(Nodo*, int); //Metodo para que funcione el recorrido por nivel
public:
    void setArbol(Nodo*);
    Nodo* getArbol();
    Nodo* crearNodo(Empleado);
    void insertarNodoCedula(Nodo*&, Empleado);
    void insertarNodoNombre(Nodo*&, Empleado);
    void insertarNodoApellido(Nodo*&, Empleado);
    void insertarNodoFecha(Nodo*&, Empleado);
    void mostrar(Nodo*, int);
    void buscar(Nodo*, std::string);
    void preOrden(Nodo*);
    void inOrden(Nodo*);
    void recorridoNivel(Nodo*);
    void postOrden(Nodo*);
    int peso(Nodo*);
    int altura(Nodo*);
    bool simetria(Nodo*, Nodo*);
    bool simetrias(Nodo*);
    Nodo* eliminarNodo(Nodo*, std::string);
};
