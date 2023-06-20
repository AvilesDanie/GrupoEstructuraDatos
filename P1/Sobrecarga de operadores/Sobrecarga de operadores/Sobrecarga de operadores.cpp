#include <iostream>
#include "Operador.h"


int main() {
    Operador num1(5);
    Operador num2(5);
    Operador num3(10);

    if (num1 == num2) {
        std::cout << "numero 1 es igual a numero 2" << std::endl;
    }

    if (num1 == num3) {
        std::cout << "numero 1 es igual a numero 3" << std::endl;
    }
    else {
        std::cout << "numero 1 no es igual a numero 3" << std::endl;
    }

    return 0;
}