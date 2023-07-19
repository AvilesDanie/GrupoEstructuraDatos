/***********************************************************************
 * Module:  Menu.cpp
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 4 de julio de 2023
 * Purpose: Declaration of the class Menu
 ***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include "ValidacionDatos.h"
#include "Arbol.h"
#include "ListaRegistro.h"
#include "ListaEmpleados.h"
#include "Registro.h"
#include <ctime>
#include "Administrador.h"

#define Tecla_Arriba 72
#define Tecla_Abajo 80
#define Enter 13
using namespace std;

/**
* Muestra y controla el menu de opciones
*
* @param null
*
* @return void
**/
void Menu::menuPrincipal() {
	int opcMP = 0, opcMN = 0;
	bool repetir = true, repetir1 = false, repetirCedula = false, repetirLI;
	Arbol empleados;
	ValidacionDatos validacion;
	ListaRegistro listaRegistros;
	ListaEmpleados listaEmpleados;
	const char* titulo = "BIENVENIDO AL APLICATIVO DE REGISTRO";

	const char* opciones[] = { "REGISTRO DE PERSONAL.","LOG IN.","SALIR."};
	const char* opciones1[] = { "INTENTAR NUEVAMENTE.","SALIR."};
	const char* opciones2[] = {"INGRESAR.","MODIFICAR.","ELIMINAR.","BUSCAR","ORDENAR","SALIR."};


	Empleado e;
	Administrador admin("u","c",e);


	for (int i = 0; i<listaEmpleados.dimencion(); i++) {
		Empleado empleado;
		Registro registro;
		empleado = listaEmpleados.getPosicion(i);
		registro.setEmpleado(empleado);
		listaRegistros.insertar(registro);
	}

	
	do {
		opcMP = menu(titulo, opciones, 3);
		switch (opcMP) {
		case 1: {
			std::system("cls");
			cout << "REGISTRO DE PERSONAL" << endl;

			string cedula;

			do {
				cedula = "";
				cout << "Ingrese la cedula: " << endl;
				cin >> cedula;

				repetirCedula = validacion.validarCedula(cedula);

				if (!(repetirCedula)) {
					std::system("cls");

					
					opcMN = menu("CEDULA NO VALIDA", opciones1, 2);
					switch (opcMN) {
					case 1: {
						std::system("cls");
						repetirCedula = false;

						break;
					}
					case 2: {
						std::system("cls");
						repetirCedula = true;

						break;
					}
					}


				}

			} while (!repetirCedula);

			if (validacion.validarCedula(cedula) && listaRegistros.buscar(cedula)) {

				Registro reg = listaRegistros.Recuperar(cedula);


				time_t now = time(0);
				tm* ltm = localtime(&now);

				int dia = ltm->tm_mday;
				int mes = 1 + ltm->tm_mon;
				int anio = 1900 + ltm->tm_year;
				int hora = ltm->tm_hour;
				int minutos = ltm->tm_min;
				int segundos = ltm->tm_sec;

				Fecha fechaActual(dia, mes, anio, hora, minutos, segundos);

				if (reg.getEntrada().getAnio() == 0) {
					reg.setEntrada(fechaActual);
				}
				else if (reg.getSalidaAlmuerzo().getAnio() == 0) {
					reg.setEntrada(fechaActual);
				}
				else if (reg.getEntradaAlmuerzo().getAnio() == 0) {
					reg.setEntrada(fechaActual);
				}
				else if (reg.getSalida().getAnio() == 0) {
					reg.setEntrada(fechaActual);
				}
				else {
					cout << "YA A REALISADO LOS CUATRO REGISTROS" << endl;
				}

				std::system("pause");

				listaRegistros.Modificar(reg);
			}
			
			break;
		}

		case 2: {
			std::system("cls");
			cout << "LOG IN" << endl;
			string usuario, contrasenia;
			do {
				usuario = "";
				cout << "Ingrese la usuario: " << endl;
				cin >> usuario;

				contrasenia = "";
				cout << "Ingrese la contrasenia: " << endl;
				cin >> contrasenia;

				
				repetirLI = usuario == admin.getUsuario() && contrasenia == admin.getContrasenia();

				
				if (!(repetirLI)) {
					std::system("cls");


					opcMN = menu("INGRESO NO VALIDO", opciones1, 2);
					switch (opcMN) {
					case 1: {
						std::system("cls");
						repetirLI = false;

						break;
					}
					case 2: {
						std::system("cls");
						repetirLI = true;

						break;
					}
					}


				}
				else {
					do {
						opcMN = menu("OPCIONES", opciones2, 6);
						switch (opcMN) {
						case 1: {
							std::system("cls");
							repetirLI = false;

							break;
						}
						case 2: {
							std::system("cls");
							repetirLI = false;

							break;
						}
						case 3: {
							std::system("cls");
							repetirLI = false;

							break;
						}
						case 4: {
							std::system("cls");
							repetirLI = false;

							break;
						}
						case 5: {
							std::system("cls");
							repetirLI = false;

							break;
						}
						case 6: {
							std::system("cls");
							repetirLI = true;

							break;
						}
						}
					} while (!repetirLI);
				}

			} while (!repetirLI);

			

			std::system("pause");
			break;
		}
		case 3: {
			system("cls");
			cout << "\n********************************\n" << endl;
			cout << "\n\t  HASTA PRONTO\n";
			cout << "\n********************************\n" << endl;
			repetir = false;
			break;
		}
		}
	} while (repetir);
}


/**
*
* Controla los punteros de movimiento en el menu de opciones
*
* @param const char* titulo. El titulo de la pestaña del menu
* @param const char* opciones[]. Un arreglo con las opciones del menu
* @param int n. lA opciones que quiere que se inprima en la pantalla
*
* @return int. La opcion seleccionada
**/
int Menu::menu(const char* titulo, const char* opciones[], int n) {
	int opcSeleccionada = 1;
	int tecla;
	bool repetir = true;
	do {
		system("cls");
		gotoxy(5, 3 + opcSeleccionada); cout << "-->";
		gotoxy(15, 2); cout << titulo;
		for (int i = 0; i < n; i++) {
			if (i + 1 == opcSeleccionada) {
				gotoxy(10, 4 + i); cout << "\033[47m\033[30m" << i + 1 << "." << opciones[i] << "\033[0m";
			}
			else {
				gotoxy(10, 4 + i); cout << i + 1 << "." << opciones[i];
			}
		}

		do {
			tecla = _getch();
		} while (tecla != Tecla_Arriba && tecla != Tecla_Abajo && tecla != Enter);

		switch (tecla)
		{
		case Tecla_Arriba:
			opcSeleccionada--;
			if (opcSeleccionada < 1) {
				opcSeleccionada = n;
			}
			break;
		case Tecla_Abajo:
			opcSeleccionada++;
			if (opcSeleccionada > n) {
				opcSeleccionada = 1;
			}
			break;
		case Enter:
			repetir = false;
			break;
		}
	} while (repetir);


	return opcSeleccionada;

}

/**
*
* Gestiona la posicion donde se imprime lineas de texto dentro de la consola
*
* @param int x. Posicicion en x.
* @param int y. Posicicion en y.
*
**/
void Menu::gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}