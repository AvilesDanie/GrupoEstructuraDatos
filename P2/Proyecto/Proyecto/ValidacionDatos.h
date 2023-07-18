#pragma once
#include <iostream>
#include "Fecha.h"
class ValidacionDatos
{
public:
	bool validarCedula(std::string);
	Fecha ingresarFecha();
	int ingresarDatosEnteros();
};

