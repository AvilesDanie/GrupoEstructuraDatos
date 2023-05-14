#include "Fraccion.h"
/***********************************************************************
 * Module:  Proceso.h
 * Author:  Aviles, Reyes
 * Modified: miércoles, 10 de mayo de 2023 8:20:15
 * Purpose: Declaration of the class Proceso
 ***********************************************************************/

#if !defined(PROCESO_H)
#define PROCESO_H
class Proceso
{
public:
	virtual Fraccion<float> calculo(Fraccion<float> obj1, Fraccion<float> ojb2) = 0;
	virtual float calculo(float obj1, float obj2) = 0;
protected:
private:

};

#endif

