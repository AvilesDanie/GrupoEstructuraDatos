#pragma once
#include <iostream>
#include "Empleado.h"
class Administrador
{
private:
	std::string usuario;
	std::string contrasenia;
	Empleado empleado;
public:
	~Administrador();
	Administrador();
	Administrador(string, string, Empleado);
	std::string getUsuario();
	void setUsuario(std::string);
	std::string getContrasenia();
	void setContrasenia(std::string);
	Empleado getEmpleado();
	void setEmpleado(Empleado);

};

