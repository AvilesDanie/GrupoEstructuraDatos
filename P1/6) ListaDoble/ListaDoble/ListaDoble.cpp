#include "ListasDoble.h"
#include <stdlib.h>
using namespace std;

bool esEntero(string);

int main() {
    ListaDoble* lista = new ListaDoble();
    int opcion, dato;
    string linea, i, b, e, m, s;
    bool rep = true;
    bool repite = true;
    bool repetir = true;

    do {
        system("cls");
        cout << "***********Listas Dobles***********" << endl;
        std::cout << "1. Insertar Cabeza" << endl;
        std::cout << "2. Insertar Cola" << endl;
        std::cout << "3. Buscar" << endl;
        std::cout << "4. Eliminar" << endl;
        std::cout << "5. Mostrar" << endl;
        std::cout << "6. Salir" << endl;

        do {
            cout << "Opcion: ";
            getline(cin, linea);

            if (esEntero(linea)) {
                repite = false;
                opcion = atoi(linea.c_str());
                if (opcion > 6 || opcion < 1) {
                    repetir = true;
                }
            }
            else {
                cout << "No has ingresado un valor entero. Intentalo nuevamente" << endl;

            }
        } while (repite);
        opcion = atoi(linea.c_str());
        switch (opcion) {
        case 1:

            do {
                cout << "Ingrese el dato a insertar: ";
                getline(cin, i);

                if (esEntero(i)) {
                    rep = false;
                    dato = atoi(i.c_str());
                }
                else {
                    cout << "No has ingresado un valor entero. Intentalo nuevamente" << endl;
                }
            } while (rep);
            dato = atoi(i.c_str());
            lista->InsertarCabeza(dato);
            break;
        case 2:

            do {
                cout << "Ingrese el dato a insertar: ";
                getline(cin, i);

                if (esEntero(i)) {
                    rep = false;
                    dato = atoi(i.c_str());
                }
                else {
                    cout << "No has ingresado un valor entero. Intentalo nuevamente" << endl;
                }
            } while (rep);
            dato = atoi(i.c_str());
            lista->InsertarCola(dato);
            break;
        case 3:
            do {
                cout << "Ingrese el dato a buscar: ";
                getline(cin, b);

                if (esEntero(b)) {
                    rep = false;
                    dato = atoi(b.c_str());
                }
                else {
                    cout << "No has ingresado un valor entero. Intentalo nuevamente" << endl;
                }
            } while (rep);
            dato = atoi(b.c_str());
            lista->Buscar(dato);
            break;
        case 4:
            do {
                cout << "Ingrese el dato a eliminar: ";
                getline(cin, e);

                if (esEntero(e)) {
                    rep = false;
                    dato = atoi(e.c_str());
                }
                else {
                    cout << "No has ingresado un valor entero. Intentalo nuevamente" << endl;
                }
            } while (rep);
            dato = atoi(e.c_str());
            lista->Eliminar(dato);
            break;
        case 5:
            lista->Mostrar();
            break;
        }
        system("pause");
    } while (opcion != 6);
    return 0;
}

//Fucion para validar
bool esEntero(string linea) {
    bool esEntero = true;
    int longitud = linea.size();

    if (longitud == 0) {
        esEntero = false;
    }
    else if (longitud == 1 && !isdigit(linea[0])) {
        esEntero = false;
    }
    else {
        int indice = 0;
        if (linea[0] == '+' || linea[0] == '-') {
            indice = 1;
        }
        else {
            indice = 0;
        }

        while (indice < longitud) {
            if (!isdigit(linea[indice])) {
                esEntero = false;
                break;
            }
            indice++;
        }
    }


    return esEntero;
}