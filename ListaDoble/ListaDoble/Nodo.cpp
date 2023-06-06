#include "Nodo.h"

Nodo::Nodo(int _dato) {
    dato = _dato;
    siguiente = NULL;
    anterior = NULL;
}

void Nodo::setDato(int _dato) {
    dato = _dato;
}

void Nodo::setSiguiente(Nodo* _siguiente) {
    siguiente = _siguiente;
}

void Nodo::setAnterior(Nodo* _anterior) {
    anterior = _anterior;
}

int Nodo::getDato() {
    return dato;
}

Nodo* Nodo::getSiguiente() {
    return siguiente;
}

Nodo* Nodo::getAnterior() {
    return anterior;
}
