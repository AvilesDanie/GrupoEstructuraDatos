#include <iostream>
#include "Matriz2x2.cpp"

int main()
{
    Matriz2x2<int> mi1(1,2,3,4);
    Matriz2x2<int> mi2(9,8,7,6);
    Matriz2x2<int> mi3(0, 0, 0, 0);

    mi1.imprimir();
    std::cout << std::endl;
    mi2.imprimir();
    std::cout << std::endl;

    mi3 = mi1 + mi2;
    
    mi3.imprimir();
    std::cout << std::endl;

    mi3 = mi1 - mi2;

    mi3.imprimir();
    std::cout << std::endl;

}