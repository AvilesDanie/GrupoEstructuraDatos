#include "Fecha.h"
Fecha::Fecha(int dia, int mes, int a) {
    this->dia = dia;
    this->mes = mes;
    this->a = a;
}

Fecha::Fecha() {
    this->dia = 0;
    this->mes = 0;
    this->a = 0;
}

int Fecha::getDia() {
    return dia;
}

int Fecha::getMes() {
    return mes;
}

int Fecha::getA() {
    return a;
}

void Fecha::setDia(int nuevoDia) {
    dia = nuevoDia;
}

void Fecha::setMes(int nuevoMes) {
    mes = nuevoMes;
}

void Fecha::setA(int nuevoA) {
    a = nuevoA;
}

void Fecha::imprimir() {
    std::cout << dia << "/" << mes << "/" << a << "\t\t";
}