#pragma once
#include <iostream>
using namespace std;
class Persona
{
public:
	string getCedula(void);
	void setCedula(string newCedula);
	string getNombre(void);
	void setNombre(string newNombre);
	string getApellido(void);
	void setApellido(string newApellido);
	//   Fecha getFecha(void);
	  // void setFecha(Fecha newFecha);
	Persona();
	~Persona();


protected:
private:
	string cedula;
	string nombre;
	string apellido;
	//   Fecha fecha;


};
