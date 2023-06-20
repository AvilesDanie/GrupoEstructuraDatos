#include <iostream>
#include <fstream>
#include "operacionesArchivo.h"
#include <sys/stat.h> // Para la función mkdir en sistemas POSIX

#ifdef _WIN32
#include <direct.h> // Para la función mkdir en Windows
#endif

void operacionesArchivo::crearCarpetaYArchivo()
{
    std::string carpeta = "Registros";
    std::string archivo = carpeta + "/Registros.txt";

#ifdef _WIN32
    int resultado = _mkdir(carpeta.c_str());
#else
    mode_t modo = 0755; // Permisos para la carpeta (lectura, escritura y ejecución para el propietario, solo lectura para los demás)
    int resultado = mkdir(carpeta.c_str(), modo);
#endif

    if (resultado != 0)
    {
        std::cerr << "La carpeta ya ha sido creada." << std::endl;
        return;
    }

    std::ofstream archivoTxt(archivo);
    if (!archivoTxt)
    {
        std::cerr << "Error al crear el archivo de texto." << std::endl;
        return;
    }

    archivoTxt << "Contenido del archivo de texto." << std::endl;
    archivoTxt.close();

    std::cout << "Carpeta y archivo creados exitosamente." << std::endl;
}

