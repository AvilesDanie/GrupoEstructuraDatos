/***********************************************************************
 * Module:  Operaciones.h
 * Author:  Aviles, Reyes
 * Modified: Domingo, 28 de mayo de 2023 12:44
 * Purpose: Implementation of the class Operaciones.h
 ***********************************************************************/
#pragma once
#include <iostream>
#include <functional>
class TorresHanoi {
public:
    TorresHanoi(int numDiscos) : numDiscos_(numDiscos) {}

    void resolver();

private:
    int numDiscos_;
};

