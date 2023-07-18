#include "ValidacionDatos.h"
#include <string>
#include <conio.h>

bool ValidacionDatos::validarCedula(std::string cedula) {
	if (cedula.length() != 10) {
		return false;
	}

	for (int i = 0; i < cedula.length();i++) {
		char c;
		c = cedula[i];
		if (!std::isdigit(c)) {
			return false;
		}
	}

	int provincia = std::stoi(cedula.substr(0, 2));

	if ((provincia < 1 || provincia > 24) && (provincia != 30)) {
		return false;
	}

	int tercero = std::stoi(cedula.substr(2, 3));

	if (tercero > 6) {
		return false;
	}

	int suma = 0;
	for (int i = 0; i < 9; i++) {
		int digito = cedula[i] - '0';
		int producto = digito * (((i + 1) % 2) + 1);

		if (producto >= 10) {
			producto -= 9;
		}

		suma += producto;
	}

	int digitoVerificador = (10 - (suma % 10)) % 10;

	return digitoVerificador == (cedula[9] - '0');
}



Fecha ValidacionDatos::ingresarFecha() {
	int dia, mes, a;
	bool pasar = false;
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
			if (mes > 12 || mes < 1) {
				std::cout << "Mes invalido" << std::endl;
				pasar = true;
			}
			else if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
				std::cout << "Dia invalido para el mes" << std::endl;
				pasar = true;
			}
			else if ((mes == 2) && (dia > 29)) {
				std::cout << "Dia invalido para el mes" << std::endl;
				pasar = true;
			}
		} while (pasar);

		std::cout << "Ingrese el año: ";
		a = ingresarDatosEnteros();
		if (a < 2020) {
			std::cout << "Año invalido" << std::endl;
			pasar = true;
		}

		if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0) {
		}
		else {
			if (dia == 29 && mes == 2) {
				std::cout << "Dia invalido para el año" << std::endl;
				pasar = true;
			}
		}
	} while (pasar);

	Fecha fecha(dia, mes, a);
	return fecha;
}



int ValidacionDatos::ingresarDatosEnteros() {
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



