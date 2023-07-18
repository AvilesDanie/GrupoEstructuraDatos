#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "ListaEmpleados.h"
#include "ListaRegistro.h"
#include "Empleado.h"
#include "Registro.h"


class Archivos {
public:
	void guardarListaRegistro(ListaRegistro* lista);
	ListaRegistro* leerListaRegistro();
	void guardarListaEmpleados(ListaEmpleados* lista);
	ListaEmpleados* leerListaEmpleados();
};

