#include "Persona.h"
#include "Registro.h"
#include "Fecha.h"


int Fecha::getDia(void)
{
	return dia;
}


void Fecha::setDia(int newDia)
{
	dia = newDia;
}



int Fecha::getMes(void)
{
	return mes;
}



void Fecha::setMes(int newMes)
{
	mes = newMes;
}


int Fecha::getAnio(void)
{
	return anio;
}



void Fecha::setAnio(int newAnio)
{
	anio = newAnio;
}



Fecha::Fecha()
{
	persona = nullptr;
	registro = nullptr;
}


Fecha::~Fecha()
{
	// TODO : implement
}



int Fecha::getHora(void)
{
	return hora;
}



void Fecha::setHora(int newHora)
{
	hora = newHora;
}

int Fecha::getMinutos(void)
{
	return minutos;
}



void Fecha::setMinutos(int newMinutos)
{
	minutos = newMinutos;
}



int Fecha::getSegundos(void)
{
	return segundos;
}


void Fecha::setSegundos(int newSegundos)
{
	segundos = newSegundos;
}