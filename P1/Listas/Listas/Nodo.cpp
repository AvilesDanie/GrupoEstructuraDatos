#include "Nodo.h"

using namespace std;

Nodo::Nodo(int _dato) {
    dato = _dato;
    siguiente = NULL;
}

inline void Nodo::setDato(int _dato) {
    dato = _dato;
}

int Nodo::getDato() {
    return dato;
}

void Nodo::setSiguiente(Nodo* _siguiente) {
    siguiente = _siguiente;
}

Nodo* Nodo::getSiguiente() {
    return siguiente;
}

