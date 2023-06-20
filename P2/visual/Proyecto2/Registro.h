/***********************************************************************
 * Module:  Registro.h
 * Author:  ASUS
 * Modified: viernes, 16 de junio de 2023 08:41:19
 * Purpose: Declaration of the class Registro
 ***********************************************************************/

#if !defined(__Clases_Registro_h)
#define __Clases_Registro_h

#include "Persona.h"

class Registro
{
public:
	Registro(Persona persona, int horaEntrada, int horaSalida);
	~Registro();

protected:
private:
	Persona persona;
	int horaEntrada;
	int horaSalida;


};

#endif