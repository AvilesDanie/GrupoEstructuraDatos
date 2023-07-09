/***********************************************************************
 * Module:  LecturaDatos.h
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 3 de julio de 2023 
 * Purpose: Declaration of the class LecturaDatos
 ***********************************************************************/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#pragma once
class LecturaDatos {
public:
	virtual char* lecturaEnteros(char const* msj) = 0;
	virtual char* lecturaReales(char const* msj) = 0;
	virtual char* lecturaTexto(char const* msj) = 0;
	virtual char* lecturaTextoNumerico(char const* msj) = 0;
};