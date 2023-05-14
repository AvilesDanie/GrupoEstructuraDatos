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


