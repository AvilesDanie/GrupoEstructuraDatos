#include "Archivos.h"
#include "Fecha.h"
#include "Persona.h"
#include <iostream>
#include <fstream>

void Archivos::guardarLista(ListaCircularDoble lista, const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        for (int i = 0; i < lista.dimencion(); i++) {
            archivo << lista.getPosicion(i).getCedula() << ",";
            archivo << lista.getPosicion(i).getNombre() << ",";
            archivo << lista.getPosicion(i).getApellido() << std::endl;
        }
        archivo.close();
        std::cout << "Lista de personas guardada exitosamente en " << nombreArchivo << std::endl;
    }
    else {
        std::cerr << "No se pudo abrir el archivo " << nombreArchivo << " para escribir" << std::endl;
    }
}

ListaCircularDoble Archivos::leerListaTDA(const std::string& nombreArchivo) {
    ListaCircularDoble lista;
    std::ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            Persona objeto;
            std::string cedula, nombre, apellido;
            size_t coma_pos = linea.find(",");
            size_t coma_pos2 = linea.find(",", coma_pos + 1);
            if (coma_pos != std::string::npos) {
                cedula = linea.substr(0, coma_pos);
                nombre = linea.substr(coma_pos + 1, coma_pos2 - coma_pos - 1);
                apellido = linea.substr(coma_pos2 + 1);
                Persona persona;
                persona.setCedula(cedula);
                persona.setNombre(nombre);
                persona.setApellido(apellido);
                lista.insertar(persona);
            }
        }
        archivo.close();
        std::cout << "Lista de productos leída exitosamente desde " << nombreArchivo << std::endl;
    }
    else {
        std::cerr << "No se pudo abrir el archivo " << nombreArchivo << " para leer" << std::endl;
    }
    return lista;
}