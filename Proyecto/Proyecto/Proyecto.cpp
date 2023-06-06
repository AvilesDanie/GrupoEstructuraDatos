#include "ListasDoble.h"
#include <stdlib.h>
#include <iostream>
#include "Validacion.h"
#include "Archivos.h"
using namespace std;

int main() {
    ListaDoble* lista = new ListaDoble();
    int opcion;
    Validacion val;
    Archivos arc;
    lista = arc.leerListaTDAProductos("productos.txt");
    lista = lista->ordenar();

    do {
        std::system("cls");
        cout << "***********Listas Dobles***********" << endl;
        std::cout << "1. Insertar al inicio" << endl;
        std::cout << "2. Insertar al final" << endl;
        std::cout << "3. Buscar" << endl;
        std::cout << "4. Eliminar" << endl;
        std::cout << "5. Mostrar" << endl;
        std::cout << "6. Modificar" << endl;
        std::cout << "7. Salir" << endl;

        std::cout << "Opcion: ";
        opcion = val.ingresarDatosEnteros();
        switch (opcion) {
        case 1: {

            string nombre;
            float precio;
            int dia, mes, a, stock;

            std::cout << "Ingrese el nombre: ";
            cin >> nombre;
            std::cout << "Ingrese el precio: ";
            precio = val.ingresarDatosfloat();

            Fecha fabricacion;
            Fecha caducidad;
            do {
                std::cout << "Ingrese la fecha de fabricacion" << endl;
                fabricacion = val.ingresarFecha();

                std::cout << "Ingrese la fecha de caducidad" << endl;
                caducidad = val.ingresarFecha();
                if (val.validarFechas(fabricacion, caducidad)) {
                    std::cout << "La fecha de caducidad debe ser posterior a la fecha de fabricacion" << std::endl;
                }
            } while (val.validarFechas(fabricacion, caducidad));

            




            int dim = lista->dimencion();

            std::cout << "Ingrese el stock del producto: ";
            stock = val.ingresarDatosEnteros();


            Producto producto(nombre, precio, fabricacion, caducidad,dim,stock);
            lista->InsertarCabeza(producto);
            lista = lista->ordenar();
            arc.guardarListaProdctos(lista, "productos.txt");
            break;
        }
        case 2: {

            string nombre;
            float precio;
            int dia, mes, a, stock;

            std::cout << "Ingrese el nombre: ";
            cin >> nombre;
            std::cout << "Ingrese el precio: ";
            precio = val.ingresarDatosfloat();

            Fecha fabricacion;
            Fecha caducidad;
            do {
                std::cout << "Ingrese la fecha de fabricacion" << endl;
                fabricacion = val.ingresarFecha();

                std::cout << "Ingrese la fecha de caducidad" << endl;
                caducidad = val.ingresarFecha();
                if (val.validarFechas(fabricacion, caducidad)) {
                    std::cout << "La fecha de caducidad debe ser posterior a la fecha de fabricacion" << std::endl;
                }
            } while (val.validarFechas(fabricacion, caducidad));


            int dim = lista->dimencion();

            std::cout << "Ingrese el stock del producto: ";
            stock = val.ingresarDatosEnteros();


            Producto producto(nombre, precio, fabricacion, caducidad, dim, stock);
            lista->InsertarCola(producto);
            lista = lista->ordenar();
            arc.guardarListaProdctos(lista, "productos.txt");
            break;
        }
        case 3: {            
            cout << "Ingrese el ID que quiere buscar: ";
            int id = val.ingresarDatosEnteros();
            lista->Buscar(id);
            break;
        }
        case 4: {
            lista->Mostrar();
            cout << "Ingrese el ID que quiere eliminar: ";
            int id = val.ingresarDatosEnteros();
            lista->Eliminar(id);
            lista = lista->ordenar();
            arc.guardarListaProdctos(lista, "productos.txt");

            break;
        }
        case 5: {
            lista->Mostrar();
            break;
        }
        case 6: {
            int id;
            std::cout << "Ingrese el ide del producto que desea modificar: ";
            id = val.ingresarDatosEnteros();
            lista = lista->Modificar(id);
            lista->Mostrar();
            arc.guardarListaProdctos(lista, "productos.txt");

            break;
        }
        case 7: {
            break;
        }
        default: {
            std::cout << "Opcion invalida" << std::endl;
            break;
        }
        }
        std::system("pause");
    } while (opcion != 7);
    arc.guardarListaProdctos(lista, "productos.txt");

    return 0;

}

