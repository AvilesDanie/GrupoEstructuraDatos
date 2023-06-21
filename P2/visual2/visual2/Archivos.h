#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "ListaCircularDoble.h"

class Archivos {
public:
    void guardarLista(ListaCircularDoble lista, const std::string& nombreArchivo);
    ListaCircularDoble leerListaTDA(const std::string& nombreArchivo);
};

