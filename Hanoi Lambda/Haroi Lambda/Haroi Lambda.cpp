/***************************************************
Universidad de las Fuerzas Armadas ESPE
Autores: Daniel Aviles, Ariel Reyes
Fechas de Creacion: 28/05/2023
Fecha de modificacion: 28/05/2023
****************************************************/
#include <iostream>
#include <functional>
#include "TorresHanoi.h"


int main() {
    int numDiscos;
    std::cout << "Ingrese el numero de discos: ";
    std::cin >> numDiscos;
    TorresHanoi torres(numDiscos);
    torres.resolver();

    return 0;
}
