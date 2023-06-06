#include "ListasDoble.h"
#include "Validacion.h"
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
            cout << ":::::::::::::::::::::::::::::::::::::::::::::" << endl;
            aux->getDato().imprimir();
            cout << ":::::::::::::::::::::::::::::::::::::::::::::" << endl;
            return;
        }
        aux = aux->getSiguiente();
    }
    cout << "El dato " << _dato << " no se encuentra en la lista" << endl;
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
    int dim=0;
    while (aux != NULL) {
        aux = aux->getSiguiente();
        dim += 1;
    }
    return dim;
}

ListaDoble* ListaDoble::ordenar() {
    Nodo* aux = primero;
    Producto nuevo;

    int nuevoId = 1;
    ListaDoble* lista = new ListaDoble();

    while (aux != NULL) {
        nuevo = aux->getDato();
        nuevo.setId(nuevoId);
        nuevoId += 1;
        lista->InsertarCola(nuevo);
        aux = aux->getSiguiente();
    }
    return(lista);
}



ListaDoble* ListaDoble::Modificar(int id) {
    Nodo* aux = primero;
    ListaDoble* lista = new ListaDoble();
    Validacion val;
    Producto nuevo, modificar;
    int opcion;
    while (aux != NULL) {
        if (aux->getDato().getId() == id) {

            cout << "El dato " << id << " se encuentra en la lista" << endl;
            cout << ":::::::::::::::::::::::::::::::::::::::::::::" << endl;
            aux->getDato().imprimir();
            modificar = aux->getDato();
            do {
                cout << ":::::::::::::::::::::::::::::::::::::::::::::" << endl;
                cout << "***********Modificar***********" << endl;
                std::cout << "1. Nombre" << endl;
                std::cout << "2. Precio" << endl;
                std::cout << "3. Fecha de fabricacion" << endl;
                std::cout << "4. Fecha de caducidad" << endl;
                std::cout << "5. Stock" << endl;
                std::cout << "6. Salir" << endl;
                cout << ":::::::::::::::::::::::::::::::::::::::::::::" << endl;
                opcion = val.ingresarDatosEnteros();
                switch (opcion) {
                case 1: {
                    string nombre;
                    std::cout << "Ingrese el nombre: ";
                    cin >> nombre;
                    modificar.setNombre(nombre);
                    break;
                }
                case 2: {
                    float precio;
                    std::cout << "Ingrese el precio: ";
                    precio = val.ingresarDatosfloat();
                    modificar.setPrecio(precio);
                    break;
                }
                case 3: {
                    Fecha fabricacion;
                    do {
                        std::cout << "Ingrese la fecha de fabricacion" << endl;
                        fabricacion = val.ingresarFecha();
                        if (val.validarFechas(fabricacion, modificar.getCaducidad())) {
                            std::cout << "La fecha de caducidad debe ser posterior a la fecha de fabricacion" << std::endl;
                            cout << "Caducidad: ";
                            modificar.getCaducidad().imprimir();
                        }
                    } while (val.validarFechas(fabricacion, modificar.getCaducidad()));
                    modificar.setFabricacion(fabricacion);
                    break;
                }
                case 4: {
                    Fecha caducidad;
                    do {
                        std::cout << "Ingrese la fecha de caducidad" << endl;
                        caducidad = val.ingresarFecha();
                        if (val.validarFechas(modificar.getFabricacion(), caducidad)) {
                            std::cout << "La fecha de caducidad debe ser posterior a la fecha de fabricacion" << std::endl;
                            cout << "Fabricacion: ";
                            modificar.getFabricacion().imprimir();
                        }
                    } while (val.validarFechas(modificar.getFabricacion(), caducidad));
                    modificar.setCaducidad(caducidad);
                    break;
                }
                case 5: {
                    int stock;
                    std::cout << "Ingrese el stock del producto: ";
                    stock = val.ingresarDatosEnteros();
                    modificar.setStock(stock);
                    break;
                }
                case 6: {
                    break;
                }
                default: {
                    std::cout << "Opcion invalida" << std::endl;
                    break;
                }
                }
            } while (opcion != 6);

            aux = primero;

            while (aux != NULL) {
                nuevo = aux->getDato();
                if (id == nuevo.getId()) {
                    lista->InsertarCola(modificar);
                }
                else {
                    lista->InsertarCola(nuevo);
                }
                aux = aux->getSiguiente();
            }

            return lista;
        }
        aux = aux->getSiguiente();
    }
    cout << "El dato " << id << " no se encuentra en la lista" << endl;

    aux = primero;

    while (aux != NULL) {
        nuevo = aux->getDato();
        lista->InsertarCola(nuevo);
        aux = aux->getSiguiente();
    }
    return lista;
}

Producto ListaDoble::getPosicion(int indice) {
    Nodo* aux = primero;
    for (int i = 0; i < indice; i++) {
        aux = aux->getSiguiente();
    }
    return aux->getDato();
}