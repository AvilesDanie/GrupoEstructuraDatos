#include "ListasDoble.h"
#include <stdlib.h>
#include <iostream>
#include "Validacion.h"
using namespace std;

int main() {
    ListaDoble* lista = new ListaDoble();
    int opcion;
    Validacion val;

    do {
        std::system("cls");
        cout << "***********Listas Dobles***********" << endl;
        std::cout << "1. Insertar al inicio" << endl;
        std::cout << "2. Insertar al final" << endl;
        std::cout << "3. Buscar" << endl;
        std::cout << "4. Eliminar" << endl;
        std::cout << "5. Mostrar" << endl;
        std::cout << "6. Salir" << endl;

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
            precio=val.ingresarDatosfloat();

            std::cout << "Ingrese la fecha de caducidad" << endl;
            std::cout << "Ingrese el dia: ";
            dia = val.ingresarDatosEnteros();

            std::cout << "Ingrese el mes: ";
            mes = val.ingresarDatosEnteros();
                
            std::cout << "Ingrese el año: ";
            a = val.ingresarDatosEnteros();
               
            Fecha caducidad(dia, mes, a);


            std::cout << "Ingrese la fecha de fabricacion" << endl;
            std::cout << "Ingrese el dia: ";
            dia = val.ingresarDatosEnteros();

            std::cout << "Ingrese el mes: ";
            mes = val.ingresarDatosEnteros();

            std::cout << "Ingrese el año: ";
            a = val.ingresarDatosEnteros();

            std::cout << "Ingrese el stock: ";
            stock = val.ingresarDatosEnteros();
            Fecha fabricacion(dia, mes, a);
            int dim = lista->dimencion();


            Producto producto(nombre, precio, fabricacion, caducidad,dim,stock);
            lista->InsertarCabeza(producto);
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

            std::cout << "Ingrese la fecha de caducidad" << endl;
            std::cout << "Ingrese el dia: ";
            dia = val.ingresarDatosEnteros();

            std::cout << "Ingrese el mes: ";
            mes = val.ingresarDatosEnteros();

            std::cout << "Ingrese el año: ";
            a = val.ingresarDatosEnteros();

            Fecha caducidad(dia, mes, a);


            std::cout << "Ingrese la fecha de fabricacion" << endl;
            std::cout << "Ingrese el dia: ";
            dia = val.ingresarDatosEnteros();

            std::cout << "Ingrese el mes: ";
            mes = val.ingresarDatosEnteros();

            std::cout << "Ingrese el año: ";
            a = val.ingresarDatosEnteros();

            std::cout << "Ingrese el stock: ";
            stock = val.ingresarDatosEnteros();
            Fecha fabricacion(dia, mes, a);
            int dim = lista->dimencion();


            Producto producto(nombre, precio, fabricacion, caducidad, dim, stock);
            lista->InsertarCola(producto);
            break;
        }
        case 3: {            
            cout << "Ingrese el ID que quiere buscar: ";
            int id = val.ingresarDatosEnteros();
            lista->Buscar(id);
            break;
        }
        case 4: {
            
            break;
        }
        case 5: {
            lista->Mostrar();
            break;
        }
        }
        std::system("pause");
    } while (opcion != 6);
    return 0;

}