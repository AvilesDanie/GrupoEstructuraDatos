/***********************************************************************
 * Module:  ValidacionDatos.h
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 3 de julio de 2023
 * Purpose: Declaration of the class ValidacionDatos
 ***********************************************************************/
#pragma once
#include <iostream>
class ValidacionDatos
{
public:
	bool parentesis(std::string);
	bool signos(std::string);
	bool decimales(std::string);
	bool negativos(std::string);
	bool letras(std::string);
	bool general(std::string);



};
