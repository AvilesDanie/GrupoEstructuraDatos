#if !defined(__ObjectOrientedModel_1_Validacion_h)
#define __ObjectOrientedModel_1_Validacion_h
#include <iostream>
#include <conio.h>
#include <math.h>
#include "Fecha.h"

class Validacion {
public:
	float ingresarDatosfloat(); 
	int ingresarDatosEnteros(); 
	Fecha ingresarFecha();
	bool validarFechas(Fecha, Fecha);
protected:
private:
};

#endif

