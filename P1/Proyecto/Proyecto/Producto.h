#pragma once
#include <iostream>
#include "Fecha.h"
class Producto {
private:
	int id;
    std::string nombre;
    float precio;
    Fecha fabricacion;
    Fecha caducidad;
	int stock;

public:
	Producto(std::string, float, Fecha, Fecha, int, int);
	Producto();
	std::string getNombre();
	float getPrecio();
	Fecha getFabricacion();
	Fecha getCaducidad();
	int getId();
	int getStock();
	void setNombre(std::string);
	void setPrecio(float);
	void setFabricacion(Fecha);
	void setCaducidad(Fecha);
	void setId(int);
	void setStock(int);

	void imprimir();
};

