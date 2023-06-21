#pragma once
#include "Validaciones.h"
#include "ListaCircularDoble.h"
class Menus {
private:
    ListaCircularDoble lista;
    Validaciones v1;
public:
    void regresarMenu();
    void mostrarMenu(int opcionActual);
    void menuBusqueda();
    void menuEliminacion();
    int operarMenu();
    Persona ingresoPersona();
    char* pedirCedula(void);
};