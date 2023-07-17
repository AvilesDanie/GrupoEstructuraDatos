#include "Fecha.h"


int Fecha::getDia(void)
{
	return dia;
}


void Fecha::setDia(int newDia)
{
	this->dia = newDia;
}



int Fecha::getMes(void)
{
	return mes;
}



void Fecha::setMes(int newMes)
{
	this->mes = newMes;
}


int Fecha::getAnio(void)
{
	return anio;
}



void Fecha::setAnio(int newAnio)
{
	this->anio = newAnio;
}



int Fecha::getHora(void)
{
	return hora;
}



void Fecha::setHora(int newHora)
{
	this->hora = newHora;
}

int Fecha::getMinutos(void)
{
	return minutos;
}



void Fecha::setMinutos(int newMinutos)
{
	this->minutos = newMinutos;
}



int Fecha::getSegundos(void)
{
	return segundos;
}


void Fecha::setSegundos(int newSegundos)
{
	this->segundos = newSegundos;
}



Fecha::Fecha(int newDia,int newMes, int newAnio, int newHora, int newMinutos, int newSegundos)
{
	this->dia = newDia;
	this->mes = newMes;
	this->anio = newAnio;
	this->hora = newHora;
	this->minutos = newMinutos;
	this->segundos = newSegundos;
}



Fecha::Fecha(int newDia, int newMes, int newAnio)
{
	this->dia = newDia;
	this->mes = newMes;
	this->anio = newAnio;
	this->hora = 0;
	this->minutos = 0;
	this->segundos = 0;
}



Fecha::Fecha()
{
	this->dia = 0;
	this->mes = 0;
	this->anio = 0;
	this->hora = 0;
	this->minutos = 0;
	this->segundos = 0;

}


Fecha::~Fecha()
{

}