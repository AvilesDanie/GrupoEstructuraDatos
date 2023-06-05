#include "ListasDoble.h"
ListaDoble::ListaDoble() {
    primero = NULL;
    ultimo = NULL;
}

void ListaDoble::InsertarCola(Producto _dato) {
    Nodo* nuevo = new Nodo(_dato);
    if (primero == NULL) {
        primero = nuevo;
        ultimo = nuevo;
    }
    else {
        ultimo->setSiguiente(nuevo);
        nuevo->setAnterior(ultimo);
        ultimo = nuevo;
    }
}

void ListaDoble::InsertarCabeza(Producto _dato) {
    Nodo* nuevo = new Nodo(_dato);
    if (primero == NULL) {
        primero = nuevo;
        ultimo = nuevo;
    }
    else {
        nuevo->setSiguiente(primero);
        primero = nuevo;
    }
}

void ListaDoble::Buscar(int _dato) {
    Nodo* aux = primero;
    while (aux != NULL) {
        if (aux->getDato().getId() == _dato) {
            cout << "El dato " << _dato << " se encuentra en la lista" << endl;
            return;
        }
        aux = aux->getSiguiente();
    }
    cout << "El dato " << _dato << " no se encuentra en la lista" << endl;
    aux->getDato().imprimir();
}

void ListaDoble::Eliminar(int _dato) {
    Nodo* aux = primero;
    while (aux != NULL) {
        if (aux->getDato().getId() == _dato) {
            if (aux == primero) {
                primero = primero->getSiguiente();
                primero->setAnterior(NULL);
            }
            else if (aux == ultimo) {
                ultimo = ultimo->getAnterior();
                ultimo->setSiguiente(NULL);
            }
            else {
                aux->getAnterior()->setSiguiente(aux->getSiguiente());
                aux->getSiguiente()->setAnterior(aux->getAnterior());
            }
            delete aux;
            cout << "El dato " << _dato << " se ha eliminado de la lista" << endl;
            return;
        }
        aux = aux->getSiguiente();
    }
    cout << "El dato " << _dato << " no se encuentra en la lista" << endl;
}

void ListaDoble::Mostrar() {
    Nodo* aux = primero;
    while (aux != NULL) {
        cout << "::::::::::::::::::::::::::::::::::::::::::::\n";
        aux->getDato().imprimir();
        aux = aux->getSiguiente();
    }
    cout << endl;
}


int ListaDoble::dimencion() {
    Nodo* aux = primero;
    int dim=1;
    while (aux != NULL) {
        aux = aux->getSiguiente();
        dim += 1;
    }
    return dim;
}