//#include "Registro.h"
//#include "NodoDoble.cpp"
//#include "ListaCircularDoble.cpp"
#include "Persona.h"


string Persona::getCedula(void)
{
	return cedula;
}



void Persona::setCedula(string newCedula)
{
	cedula = newCedula;
}



string Persona::getNombre(void)
{
	return nombre;
}



void Persona::setNombre(string newNombre)
{
	nombre = newNombre;
}



string Persona::getApellido(void)
{
	return apellido;
}



void Persona::setApellido(string newApellido)
{
	apellido = newApellido;
}



Persona::Persona()
{
}


Persona::~Persona()
{
	// TODO : implement
}