#include "Validacion.h"
#include <iostream>
#include <conio.h>
#include <math.h>

float Validacion:: ingresarDatosfloat() {
	char* dato = new char[100];
	char c;
	int p = 0, x = 0, e = 1, i = 0;
	float n = 0.0;
	while ((c = _getch()) != 13) {
		if (c >= '0' && c <= '9') {
			std::cout << c;;
			dato[i++] = c;
		}
		if (p == 0) {
			if (c == '.') {
				printf("%c", c);
				dato[i++] = c;
				p++;
			}
		}
		if (i != 0) {
			if (c == 8) {
				i--;
				putchar(8);
				putchar(32);
				putchar(8);
				if (dato[i] == '.') {
					p--;
				}
			}
		}
	}
	dato[i] = '\0';
	while (dato[x] != '\0') {
		if (dato[x] == '.') {
			x++;
			while (dato[x] != '\0') {
				n = n + (dato[x] - '0') * pow(0.1, e);
				e++;
				x++;
			}
		}
		else {
			n = (n * 10) + (dato[x] - '0');
			x++;
		}
	}
	std::cout << "\n";
	return n;
}
/**
* @brief ingresarDatosEntero Valida la entrada de datos int
* @return Validacion de un tipo de dato entero
*/
int Validacion::ingresarDatosEnteros() {
	char* dato = new char[100];
	char c;
	int i = 0;
	int x = 0, n = 0;
	int result = 0;
	while ((c = _getch()) != 13) {
		if (c >= '0' && c <= '9') {
			std::cout << c;;
			dato[i++] = c;
		}
		else {
			if (i != 0) {
				if (c == 8) {
					i--;
					putchar(8);
					putchar(32);
					putchar(8);
				}
			}
		}
	}
	dato[i] = '\0';
	while (dato[x] != '\0') {
		n = 10 * n + (dato[x] - '0');
		x++;
	}
	std::cout << "\n";
	return n;
}


Fecha Validacion::ingresarFecha() {
	int dia, mes, a;
	bool pasar=false;
	do {
		do {
			do {
				pasar = false;
				std::cout << "Ingrese el dia: ";
				dia = ingresarDatosEnteros();
				if (dia < 1 || dia>31) {
					std::cout << "Dia invalido" << std::endl;
					pasar = true;
				}
			} while (pasar);

			std::cout << "Ingrese el mes: ";
			mes = ingresarDatosEnteros();

			if ((mes == 4 || mes == 6 || mes == 8 || mes == 10 || mes == 12)&&dia>30) {
				std::cout << "Dia invalido para el mes" << std::endl;
				pasar = true;
			}
			else if ((mes == 2) && (dia > 29)) {
				std::cout << "Dia invalido para el mes" << std::endl;
				pasar = true;
			}
		} while (pasar);

		std::cout << "Ingrese el a�o: ";
		a = ingresarDatosEnteros();
		if (a < 2020) {
			std::cout << "A�o invalido" << std::endl;
			pasar = true;
		}

		if (a % 4 == 0 and a % 100 != 0 or a % 400 == 0) {
		}
		else {
			if (dia == 29) {
				std::cout << "Dia invalido para el a�o" << std::endl;
				pasar = true;
			}
		}
	} while (pasar);
	
	Fecha fecha(dia, mes, a);
	return fecha;

}

bool Validacion::validarFechas(Fecha fabricacion, Fecha caducidad) {
	bool pasar=false;
	if (fabricacion.getA() > caducidad.getA()) {
		pasar = true;
	}
	else if(fabricacion.getA() == caducidad.getA()){
		if (fabricacion.getMes() > caducidad.getMes()) {
			pasar = true;
		}
		else if (fabricacion.getMes() == caducidad.getMes()) {
			if (fabricacion.getDia() > caducidad.getDia()) {
				pasar = true;
			}
			else if (fabricacion.getDia() == caducidad.getDia()) {
				pasar = true;
			}
		}
	}
	return pasar;
}
