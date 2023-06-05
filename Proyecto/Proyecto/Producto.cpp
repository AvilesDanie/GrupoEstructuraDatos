#include "Producto.h"
#include <iostream>
using namespace std;
Producto::Producto(std::string nombre, float precio, Fecha fabricacion, Fecha caducidad, int id, int stock) {
    this->nombre = nombre;
    this->precio = precio;
    this->fabricacion = fabricacion;
    this->caducidad = caducidad;
    this->id = id;
    this->stock = stock;
}

Producto::Producto() {
    this->nombre = "NULL";
    this->precio = 0;
    this->fabricacion;
    this->caducidad;
    this->id = 0;
    this->stock = 0;
}

std::string Producto::getNombre() {
    return nombre;
}

float Producto::getPrecio() {
    return precio;
}

Fecha Producto::getFabricacion() {
    return fabricacion;
}

Fecha Producto::getCaducidad() {
    return caducidad;
}

int Producto::getId() {
    return id;
}

int Producto::getStock() {
    return stock;
}

void Producto::setNombre(std::string nuevoNombre) {
    nombre = nuevoNombre;
}

void Producto::setPrecio(float nuevoPrecio) {
    precio = nuevoPrecio;
}

void Producto::setFabricacion(Fecha nuevaFabricacion) {
    fabricacion = nuevaFabricacion;
}

void Producto::setCaducidad(Fecha nuevaCaducidad) {
    caducidad = nuevaCaducidad;
}

void Producto::setId(int nuevoId) {
    id = nuevoId;
}

void Producto::imprimir() {
    cout << "Nombre: " << nombre << endl;
    cout << "Precio: " << precio << endl;
    cout << "Fabricacion: ";
    fabricacion.imprimir();
    cout << endl;
    cout << "Caducidad: ";
    caducidad.imprimir();
    cout << endl;
    cout << "Stock: " << stock << endl;
    cout << "ID: " << id << endl;
}
