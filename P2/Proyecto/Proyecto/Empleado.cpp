#include "Empleado.h"


string Empleado::getCedula(void)
{
	return Persona::getCedula();
}



void Empleado::setCedula(string newCedula)
{
	Persona::setCedula(newCedula);
}



string Empleado::getNombre(void)
{
	return Persona::getNombre();
}



void Empleado::setNombre(string newNombre)
{
	Persona::setNombre(newNombre);
}



string Empleado::getApellido(void)
{
	return Persona::getApellido();
}



void Empleado::setApellido(string newApellido)
{
	Persona::setApellido(newApellido);
}



Fecha Empleado::getFecha(void)
{
	return Persona::getFecha();
}



void Empleado::setFecha(Fecha newFecha)
{
	Persona::setFecha(newFecha);
}





double Empleado::getSalario(void)
{
	return salario;
}



void Empleado::setSalario(double newSalario)
{
	this->salario = newSalario;
}



Empleado::Empleado()
{
	Persona::Persona();
	this->salario = 0.0;
}



Empleado::Empleado(string newCedula, string newNombre, string newApellido, Fecha newFecha, double newSalario)
{
	Persona::Persona(newCedula, newNombre, newApellido, newFecha);
	this->salario = newSalario;
}


Empleado::~Empleado()
{

}

void Empleado::imprimir() {
	cout << "*************************" << endl;
	cout << "Nombre: " << getNombre() << endl;
	cout << "Apellido: " << getApellido() << endl;
	cout << "Cedula: " << getCedula() << endl;
	cout << "Sueldo: " << getSalario() << endl;
	cout << "*************************" << endl;
}