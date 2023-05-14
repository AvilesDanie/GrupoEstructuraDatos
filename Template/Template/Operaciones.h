#pragma once
#include "Proceso.h"
#if !defined(OPERACIONES_H)
#define OPERACIONES_H
class Operaciones:public Proceso
{
public:
	Operaciones();
	~Operaciones();
	Fraccion calculo(Fraccion obj1, Fraccion obj2)override;
	float calculo(float obj1, float obj2)override;

};
#endif


