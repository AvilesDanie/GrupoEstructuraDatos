/***********************************************************************
 * Module:  Operaciones.h
 * Author:  Aviles, Reyes
 * Modified: Domingo, 14 de mayo de 2023 12:31:19
 * Purpose: Implementation of the class Operaciones.h
 ***********************************************************************/
#pragma once
#include "Proceso.h"
#if !defined(OPERACIONES_H)
#define OPERACIONES_H
class Operaciones:public Proceso
{
public:
	Operaciones();
	~Operaciones();
	Fraccion<float> calculo(Fraccion<float> obj1, Fraccion<float> obj2);
	float calculo(float obj1, float obj2);

};
#endif


