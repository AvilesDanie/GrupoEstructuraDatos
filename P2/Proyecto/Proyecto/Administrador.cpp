#include "Administrador.h"
Administrador::~Administrador() {

}


Administrador::Administrador() {
	this->usuario = nullptr;
	this->contrasenia = nullptr;
	this->empleado;

}


Administrador::Administrador(string newUsuario, string newContrasenia, Empleado newEmpleado) {
	this->usuario = newUsuario;
	this->contrasenia = newContrasenia;
	this->empleado = newEmpleado;
}


std::string Administrador::getUsuario() {
	return usuario;
}


void Administrador::setUsuario(std::string newUsuario) {
	this->usuario = newUsuario;

}


std::string Administrador::getContrasenia() {
	return contrasenia;
}


void Administrador::setContrasenia(std::string newContrasenia) {
	this->contrasenia = newContrasenia;

}


Empleado Administrador::getEmpleado() {
	return empleado;
}


void Administrador::setEmpleado(Empleado newEmpleado) {
	this->empleado = newEmpleado;

}