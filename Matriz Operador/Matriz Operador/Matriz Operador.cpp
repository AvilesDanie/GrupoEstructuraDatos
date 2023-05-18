/***************************************************
Universidad de las Fuerzas Armadas ESPE
Autores: Daniel Aviles, Ariel Reyes
Fechas de Creacion: 18/05/2023
Fecha de modificacion: 18/05/2023
****************************************************/
#include <iostream>
#include "Matriz2x2.cpp"

int main()
{
    Matriz2x2<int> mi1(1, 2, 3, 4);
    Matriz2x2<int> mi2(9, 8, 7, 6);
    Matriz2x2<int> mi3(0, 0, 0, 0);

    std::cout << "MATRIZ 1" << std::endl;
    mi1.imprimir();
    std::cout << std::endl;

    std::cout << "MATRIZ 2" << std::endl;
    mi2.imprimir();
    std::cout << std::endl;

    std::cout << "SUMA MATRIZES" << std::endl;
    mi3 = mi1 + mi2;

    mi3.imprimir();
    std::cout << std::endl;

    std::cout << "RESTA MATRIZES" << std::endl;
    mi3 = mi1 - mi2;

    mi3.imprimir();
    std::cout << std::endl;

    std::cout << "MULTIPLICACION MATRIZES" << std::endl;
    mi3 = mi1 * mi2;

    mi3.imprimir();
    std::cout << std::endl;

    std::cout << "SOBRECARGA ==" << std::endl;
    if(mi1==mi1)
        std::cout <<"Son iguales"<< std::endl;
}