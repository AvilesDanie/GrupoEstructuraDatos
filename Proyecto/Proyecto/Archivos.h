#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "ListasDoble.h"

class Archivos {
public:
    void guardarListaProdctos(ListaDoble* lista, const std::string& nombreArchivo);
    ListaDoble* leerListaTDAProductos(const std::string& nombreArchivo);
};

