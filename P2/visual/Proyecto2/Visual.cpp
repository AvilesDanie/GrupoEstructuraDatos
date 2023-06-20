#include <iostream>
#include <conio.h>
#include "Menus.h"
#include "operacionesArchivo.h"

using namespace std;
int main() {
	operacionesArchivo arc;
	arc.crearCarpetaYArchivo();
	Menus menu;
	menu.operarMenu();
}

