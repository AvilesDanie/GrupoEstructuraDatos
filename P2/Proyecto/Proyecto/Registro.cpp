#include "Registro.h"

Registro::Registro() {
	this->empleado = Empleado("null","null","null",Fecha(0,0,0),0);
	this->entrada = Fecha(0, 0, 0);
	this->entradaAlmuerzo = Fecha(0, 0, 0);
	this->salidaAlmuerzo = Fecha(0, 0, 0);
	this->salida = Fecha(0, 0, 0);
}

Registro::Registro(Empleado empleado) {
	this->empleado = empleado;
	this->entrada = Fecha(0, 0, 0);
	this->entradaAlmuerzo = Fecha(0, 0, 0);
	this->salidaAlmuerzo = Fecha(0, 0, 0);
	this ->salida = Fecha(0, 0, 0);
}

Registro::Registro(Empleado empleado, Fecha entrada, Fecha salidaAlmuerzo, Fecha entradaAlmuerzo, Fecha salida) {
	this->empleado = empleado;
	this->entrada = entrada;
	this->entradaAlmuerzo = entradaAlmuerzo;
	this->salidaAlmuerzo = salidaAlmuerzo;
	this->salida = salida;
}


Registro::Registro(Fecha entrada, Fecha salidaAlmuerzo, Fecha entradaAlmuerzo, Fecha salida) {
	this->empleado = Empleado(NULL, NULL, NULL, Fecha(0, 0, 0), 0);
	this->entrada = entrada;
	this->entradaAlmuerzo = entradaAlmuerzo;
	this->salidaAlmuerzo = salidaAlmuerzo;
	this->salida = salida;
}

Registro::~Registro() {

}

Empleado Registro::getEmpleado() {
	return empleado;
}

void Registro::setEmpleado(Empleado newEmpleado) {
	empleado = newEmpleado;
}

Fecha Registro::getEntrada() {
	return entrada;
}

void Registro::setEntrada(Fecha newEntrada) {
	entrada = newEntrada;
}

Fecha Registro::getSalidaAlmuerzo() {
	return salidaAlmuerzo;
}

void Registro::setSalidaAlmuerzo(Fecha newSalidaAlmuerzo) {
	salidaAlmuerzo = newSalidaAlmuerzo;
}

Fecha Registro::getEntradaAlmuerzo() {
	return entradaAlmuerzo;
}

void Registro::setEntradaAlmuerzo(Fecha newEntradaAlmuerzo ) {
	entradaAlmuerzo = newEntradaAlmuerzo;
}

Fecha Registro::getSalida() {
	return salida;
}

void Registro::setSalida(Fecha newSalida) {
	salida = newSalida;
}

void Registro::imprimir() {

}