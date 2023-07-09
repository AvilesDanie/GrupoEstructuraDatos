/***********************************************************************
 * Module:  ValidacionDatos.h
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 3 de julio de 2023
 * Purpose: Declaration of the class ValidacionDatos
 ***********************************************************************/
#include"LecturaDatos.h"
#pragma once
class ValidacionDatos :public LecturaDatos
{
public:
	char* lecturaEnteros(char const* msj) override;
	char* lecturaReales(char const* msj) override;
	char* lecturaTexto(char const* msj) override;
	char* lecturaTextoNumerico(char const* msj) override;
	int casteoEnteros(char* dato, char const* msj);
	double casteoReales(char* dato, char const* msj);

	bool parentesis(std::string);
	bool signos(std::string);
	bool decimales(std::string);
	bool negativos(std::string);
	bool letras(std::string);
	bool general(std::string);



};
