#pragma once

#if !defined(__SobreCargaDeDatos_Coordenada_h)
#define __SobreCargaDeDatos_Coordenada_h

class Operador
{
public:
    Operador(int value) : valor(value) {}

    bool operator==(const Operador& other) const;

private:
    int valor;
};

#endif