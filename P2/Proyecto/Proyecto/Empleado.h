#pragma once
#include <iostream>
#include "Persona.h"
using namespace std;

class Empleado : public Persona
{
public:
    Empleado();
    Empleado(string, string, string, Fecha, double);
    ~Empleado();
    string getCedula(void);
    void setCedula(string newCedula);
    string getNombre(void);
    void setNombre(string newNombre);
    string getApellido(void);
    void setApellido(string newApellido);
    Fecha getFecha(void);
    void setFecha(Fecha newFecha);
    double getSalario(void);
    void setSalario(double newSalario);

private:
    double salario;
};

