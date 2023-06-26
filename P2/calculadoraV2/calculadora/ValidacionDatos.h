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


};
