#include "Operador.h"


bool Operador::operator==(const Operador& other) const {
    return valor != other.valor;
}