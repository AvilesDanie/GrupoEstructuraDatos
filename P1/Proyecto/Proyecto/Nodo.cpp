#include "Nodo.h"

Nodo::Nodo(Producto produc) {
    producto = produc;
    siguiente = nullptr;
    anterior = nullptr;
}

void Nodo::setDato(Producto _dato) {
    producto = _dato;
}

void Nodo::setSiguiente(Nodo* _siguiente) {
    siguiente = _siguiente;
}

void Nodo::setAnterior(Nodo* _anterior) {
    anterior = _anterior;
}

Producto Nodo::getDato() {
    return producto;
}

Nodo* Nodo::getSiguiente() {
    return siguiente;
}

Nodo* Nodo::getAnterior() {
    return anterior;
}
