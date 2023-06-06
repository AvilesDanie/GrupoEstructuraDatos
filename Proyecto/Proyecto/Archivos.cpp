#include "Archivos.h"
#include "Fecha.h"
#include "Producto.h"
#include <iostream>
#include <fstream>

void Archivos::guardarListaProdctos(ListaDoble* lista, const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        for (int i = 0; i < lista->dimencion(); i++) {
            archivo << lista->getPosicion(i).getNombre() << ",";
            archivo << lista->getPosicion(i).getPrecio() << ",";
            archivo << lista->getPosicion(i).getFabricacion().getDia() << ",";
            archivo << lista->getPosicion(i).getFabricacion().getMes() << ",";
            archivo << lista->getPosicion(i).getFabricacion().getA() << ",";
            archivo << lista->getPosicion(i).getCaducidad().getDia() << ",";
            archivo << lista->getPosicion(i).getCaducidad().getMes() << ",";
            archivo << lista->getPosicion(i).getCaducidad().getA() << ",";
            archivo << lista->getPosicion(i).getStock() << ",";
            archivo << lista->getPosicion(i).getId() << std::endl;
        }
        archivo.close();
        std::cout << "Lista de TDA guardada exitosamente en " << nombreArchivo << std::endl;
    }
    else {
        std::cerr << "No se pudo abrir el archivo " << nombreArchivo << " para escribir" << std::endl;
    }
}

ListaDoble* Archivos::leerListaTDAProductos(const std::string& nombreArchivo) {
    ListaDoble* lista = new ListaDoble();
    std::ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            Producto objeto;
            std::string nombre;
            float precio;
            int stock, id, diaFa, mesFa, aFa, diaCa, mesCa, aCa;
            size_t coma_pos = linea.find(",");
            size_t coma_pos2 = linea.find(",", coma_pos + 1);
            size_t coma_pos3 = linea.find(",", coma_pos2 + 1);
            size_t coma_pos4 = linea.find(",", coma_pos3 + 1);
            size_t coma_pos5 = linea.find(",", coma_pos4 + 1);
            size_t coma_pos6 = linea.find(",", coma_pos5 + 1);
            size_t coma_pos7 = linea.find(",", coma_pos6 + 1);
            size_t coma_pos8 = linea.find(",", coma_pos7 + 1);
            size_t coma_pos9 = linea.find(",", coma_pos7 + 1);
            if (coma_pos != std::string::npos) {
                nombre = linea.substr(0, coma_pos);
                precio = std::stof(linea.substr(coma_pos + 1, coma_pos2 - coma_pos - 1));
                diaFa = std::stoi(linea.substr(coma_pos2 + 1, coma_pos3 - coma_pos2 - 1));
                mesFa = std::stoi(linea.substr(coma_pos3 + 1, coma_pos4 - coma_pos3 - 1));
                aFa = std::stoi(linea.substr(coma_pos4 + 1, coma_pos5 - coma_pos4 - 1));
                diaCa = std::stoi(linea.substr(coma_pos5 + 1, coma_pos6 - coma_pos5 - 1));
                mesCa = std::stoi(linea.substr(coma_pos6 + 1, coma_pos7 - coma_pos6 - 1));
                aCa = std::stoi(linea.substr(coma_pos7 + 1, coma_pos8 - coma_pos7 - 1));
                stock = std::stoi(linea.substr(coma_pos8 + 1, coma_pos9 - coma_pos8 - 1));
                id = std::stoi(linea.substr(coma_pos9 + 1));
                Fecha fabricacion(diaFa, mesFa, aFa);
                Fecha caducidad(diaCa, mesCa, aCa);
                Producto productos(nombre, precio, fabricacion, caducidad, id, stock);
                lista->InsertarCola(productos);
            }
        }
        archivo.close();
        std::cout << "Lista de TDA leída exitosamente desde " << nombreArchivo << std::endl;
    }
    else {
        std::cerr << "No se pudo abrir el archivo " << nombreArchivo << " para leer" << std::endl;
    }
    return lista;
}