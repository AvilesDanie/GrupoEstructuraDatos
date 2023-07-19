#include "Persona.h"


string Persona::getCedula(void)
{
	return cedula;
}



void Persona::setCedula(string newCedula)
{
	this->cedula = newCedula;
}



string Persona::getNombre(void)
{
	return nombre;
}



void Persona::setNombre(string newNombre)
{
	this->nombre = newNombre;
}



string Persona::getApellido(void)
{
	return apellido;
}



void Persona::setApellido(string newApellido)
{
	this->apellido = newApellido;
}



Fecha Persona::getFecha(void)
{
	return fecha;
}



void Persona::setFecha(Fecha newFecha)
{
	this->fecha = newFecha;
}



Persona::Persona()
{
	this->cedula = "NULL";
	this->nombre = "NULL";
	this->apellido = "NULL";
	this->fecha;
}



Persona::Persona(string newCedula, string newNombre, string newApellido, Fecha newFecha)
{
	this->cedula = newCedula;
	this->nombre = newNombre;
	this->apellido = newApellido;
	this->fecha = newFecha;
}


Persona::~Persona()
{

}