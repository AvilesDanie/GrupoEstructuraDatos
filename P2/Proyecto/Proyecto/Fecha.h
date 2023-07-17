#pragma once
#include <iostream>

using namespace std;
class Fecha
{
public:
	int getDia(void);
	void setDia(int newDia);
	int getMes(void);
	void setMes(int newMes);
	int getAnio(void);
	void setAnio(int newAnio);
	int getHora(void);
	void setHora(int newHora);
	int getMinutos(void);
	void setMinutos(int newMinutos);
	int getSegundos(void);
	void setSegundos(int newSegundos);
	Fecha(int, int, int);
	Fecha(int,int,int,int,int,int);

	Fecha();
	~Fecha();

protected:
private:
	int dia;
	int mes;
	int anio;
	int hora;
	int minutos;
	int segundos;

};
