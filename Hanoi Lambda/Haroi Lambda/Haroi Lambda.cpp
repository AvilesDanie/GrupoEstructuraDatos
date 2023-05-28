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
