/***********************************************************************
 * Module:  Operaciones.h
 * Author:  Aviles, Reyes
 * Modified: Domingo, 28 de mayo de 2023 12:44
 * Purpose: Implementation of the class Operaciones.h
 ***********************************************************************/
#include "TorresHanoi.h"

 ////////////////////////////////////////////////////////////////////////
 // Name:       TorresHanoi::resolver()
 // Purpose:    Implementation of TorresHanoi::resolver()
 // Return:     void
 ////////////////////////////////////////////////////////////////////////

void TorresHanoi::resolver() {
    std::function<void(int, char, char, char)> moverDiscos = [&](int n, char origen, char destino, char auxiliar) {
        if (n == 1) {
            std::cout << "Mover disco 1 de " << origen << " a " << destino << std::endl;
        }
        else {
            moverDiscos(n - 1, origen, auxiliar, destino);
            std::cout << "Mover disco " << n << " de " << origen << " a " << destino << std::endl;
            moverDiscos(n - 1, auxiliar, destino, origen);
        }
    };

    moverDiscos(numDiscos_, 'A', 'C', 'B');
}