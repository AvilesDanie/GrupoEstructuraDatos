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
#include "Archivos.h"
#include "ListaRegistro.h"
#include "ListaEmpleados.h"
#include "Registro.h"
#include <ctime>
#include "Administrador.h"
#include <thread>
#include <chrono>

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
	bool repetir = true, repetir1 = false, repetirCedula = false, repetirLI, repetirL2=false;
	Arbol empleados;
	ValidacionDatos validacion;
	Archivos objArc;
	ListaRegistro* listaRegistros = new ListaRegistro();
	ListaRegistro* listaRegistrosR = new ListaRegistro();
	ListaEmpleados* listaEmpleados = new ListaEmpleados();
	const char* titulo = "BIENVENIDO AL APLICATIVO DE REGISTRO";

	const char* opciones[] = { "REGISTRO DE PERSONAL.","LOG IN.","SALIR."};
	const char* opciones1[] = { "INTENTAR NUEVAMENTE.","SALIR."};
	const char* opciones2[] = {"INGRESAR.","MODIFICAR.","ELIMINAR.","BUSCAR","ORDENAR","SALIR."};
	const char* opciones3[] = { "Nombre.","Apellido.","Sueldo","Atras"};
	const char* opciones4[] = { "Ordenar por cedula" ,"Ordenar por nombre","Ordenar por apellido","Ordenas por nacimiento"};


	Empleado e;
	Administrador admin("u","c",e);
	time_t now = time(0);
	tm* ltm = localtime(&now);

	int dia = ltm->tm_mday;
	int mes = 1 + ltm->tm_mon;
	int anio = 1900 + ltm->tm_year;

	listaRegistros = objArc.leerListaRegistro();
	listaRegistrosR = objArc.leerListaRegistro(anio, mes, dia);
	listaEmpleados = objArc.leerListaEmpleados();
	std::system("pause");
	
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



					bool funcionTerminada = false;

					std::thread hilo([&]() {
						opcMN = menu("CEDULA NO VALIDA", opciones1, 2);
						funcionTerminada = true;
						});

					int tiempoLimite = 5;

					for (int segundos = 0; segundos < tiempoLimite; ++segundos)
					{
						if (funcionTerminada)
						{
							break;
						}
						std::this_thread::sleep_for(std::chrono::seconds(1));
					}

					if (!funcionTerminada)
					{
						
						hilo.detach();

						opcMN = 2;
					}
					else
					{
						hilo.join();
					}

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

			if (validacion.validarCedula(cedula) || (listaRegistros->buscar(cedula)||listaRegistros->getCabeza() == NULL)) {
				Registro reg;

				if (listaRegistros->getCabeza() == NULL|| !listaRegistros->buscar(cedula)) {
					reg.setEmpleado(listaEmpleados->Recuperar(cedula));
				}
				else {
					reg = listaRegistrosR->Recuperar(cedula);
				}


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
					reg.setSalidaAlmuerzo(fechaActual);
				}
				else if (reg.getEntradaAlmuerzo().getAnio() == 0) {
					reg.setEntradaAlmuerzo(fechaActual);
				}
				else if (reg.getSalida().getAnio() == 0) {
					reg.setSalida(fechaActual);
				}
				else {
					cout << "YA A REALISADO LOS CUATRO REGISTROS" << endl;
				}
				if (listaRegistrosR->buscar(cedula)) {
					listaRegistrosR->Modificar(reg);
					listaRegistros->Modificar(reg);
				}
				else {
					listaRegistrosR->insertar(reg);
					listaRegistros->insertar(reg);
				}
				objArc.guardarListaRegistro(listaRegistros);
				std::system("pause");
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
							cout << "INGRESE LOS DATOS DEL EMPLEADO" << endl;
							string cedula,nombre,apellido;
							Fecha nacimiento;
							double sueldo;
							repetirCedula = false;
							do {
								cedula = "";
								cout << "Ingrese la cedula: " << endl;
								cin >> cedula;

								repetirCedula = validacion.validarCedula(cedula);
								if (listaEmpleados->buscar(cedula)) {
									repetirCedula = false;
								}

								if (!(repetirCedula)) {
									std::system("cls");

									bool funcionTerminada = false;

									std::thread hilo([&]() {
										opcMN = menu("CEDULA NO VALIDA", opciones1, 2);
										funcionTerminada = true;
										});

									int tiempoLimite = 5;

									for (int segundos = 0; segundos < tiempoLimite; ++segundos)
									{
										if (funcionTerminada)
										{
											break;
										}
										std::this_thread::sleep_for(std::chrono::seconds(1));
									}

									if (!funcionTerminada)
									{

										hilo.detach();

										opcMN = 2;
	
									}
									else
									{
										hilo.join();

									}

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
							cout << "Ingrese el nombre: ";
							cin >> nombre;
							cout << "Ingrese el apellido: ";
							cin >> apellido;
							cout << "Ingrese la fecha de nacimiento" << endl;
							nacimiento = validacion.ingresarFecha();
							do {
								cout << "Ingrese el sueldo: ";
								cin >> sueldo;
								if (!(sueldo >= 360 && sueldo <= 7000)) {
									cout << "Ingrese un sueldo entre 360 y 7000 dolares" << endl;
								}
							} while (!(sueldo >= 360 && sueldo <= 7000));

							Empleado empleado(cedula, nombre, apellido,nacimiento, sueldo);
							listaEmpleados->insertar(empleado);
							objArc.guardarListaEmpleados(listaEmpleados);
							std::system("pause");
							break;
						}
						case 2: {
								std::system("cls");
								string cedula, nombre, apellido;
								Fecha nacimiento;
								double sueldo;
								repetirCedula = false;
								cout << "MODIFICAR DATOS EMPLEADO" << endl;
								cout << "Ingrese la identidad de la persona que desea modificar" << endl;
								do {
								cedula = "";
								cout << "Ingrese la cedula: " << endl;
								cin >> cedula;

								repetirCedula = validacion.validarCedula(cedula);

								if (!(repetirCedula)) {
									std::system("cls");

									bool funcionTerminada = false;

									std::thread hilo([&]() {
										opcMN = menu("CEDULA NO VALIDA", opciones1, 2);
										funcionTerminada = true;
										});

									int tiempoLimite = 5;

									for (int segundos = 0; segundos < tiempoLimite; ++segundos)
									{
										if (funcionTerminada)
										{
											break;
										}
										std::this_thread::sleep_for(std::chrono::seconds(1));
									}

									if (!funcionTerminada)
									{

										hilo.detach();

										opcMN = 2;

									}
									else
									{
										hilo.join();

									}

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
								if (!listaEmpleados->buscar(cedula)) {
									cout << "No se encutra la cedula en la lista de empleados" << endl;
									std::system("pause");
									break;
								}
								else{
								Empleado empleado = listaEmpleados->Recuperar(cedula);
								empleado.imprimir();
								std::system("pause");
								int op = menu("¿QUE ATRIBUTO DESEA CAMBIAR",opciones3,4);
								std::system("cls");
								switch (op)
								{
								case 1: {
									cout << "Ingrese el nombre: ";
									cin >> nombre;
									empleado.setNombre(nombre);
									break;
								}
								case 2: {
									cout << "Ingrese el apellido: ";
									cin >> apellido;
									empleado.setApellido(apellido);
									break;
								}
								case 3: {
									do {
										cout << "Ingrese el sueldo: ";
										cin >> sueldo;
										if (!(sueldo >= 360 && sueldo <= 7000)) {
											cout << "Ingrese un sueldo entre 360 y 7000 dolares" << endl;
										}
									} while (!(sueldo >= 360 && sueldo <= 7000));
									empleado.setSalario(sueldo);
									break;
								}
								case 4: {
									break;
								}
								}
								listaEmpleados->Modificar(empleado);
							}
								objArc.guardarListaEmpleados(listaEmpleados);
								std::system("pause");
							break;
						}
						case 3: {
							std::system("cls");
							cout << "ELIMINAR EMPLEADO" << endl;
							string cedula;
							do {
								cedula = "";
								cout << "Ingrese la cedula: " << endl;
								cin >> cedula;

								repetirCedula = validacion.validarCedula(cedula);

								if (!(repetirCedula)) {
									std::system("cls");

									bool funcionTerminada = false;

									std::thread hilo([&]() {
										opcMN = menu("CEDULA NO VALIDA", opciones1, 2);
										funcionTerminada = true;
										});

									int tiempoLimite = 5;

									for (int segundos = 0; segundos < tiempoLimite; ++segundos)
									{
										if (funcionTerminada)
										{
											break;
										}
										std::this_thread::sleep_for(std::chrono::seconds(1));
									}

									if (!funcionTerminada)
									{

										hilo.detach();

										opcMN = 2;

									}
									else
									{
										hilo.join();

									}

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
							listaEmpleados->eliminar(cedula);
							objArc.guardarListaEmpleados(listaEmpleados);
							break;
						}
						case 4: {
							std::system("cls");
							cout << "BUSCAR EMPLEADO" << endl;
							Arbol arbol;
							Nodo* aux = arbol.getArbol();
							string cedula;
							do {
								cedula = "";
								cout << "Ingrese la cedula: " << endl;
								cin >> cedula;

								repetirCedula = validacion.validarCedula(cedula);

								if (!(repetirCedula)) {
									std::system("cls");

									bool funcionTerminada = false;

									std::thread hilo([&]() {
										opcMN = menu("CEDULA NO VALIDA", opciones1, 2);
										funcionTerminada = true;
										});

									int tiempoLimite = 5;

									for (int segundos = 0; segundos < tiempoLimite; ++segundos)
									{
										if (funcionTerminada)
										{
											break;
										}
										std::this_thread::sleep_for(std::chrono::seconds(1));
									}

									if (!funcionTerminada)
									{

										hilo.detach();

										opcMN = 2;

									}
									else
									{
										hilo.join();

									}

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
							for (int i = 0; i < listaEmpleados->dimencion();i++) {
								arbol.insertarNodoCedula(aux, listaEmpleados->getPosicion(i));
							}
							arbol.buscar(aux,cedula);
							std::system("pause");
							break;
						}
						case 5: {
							std::system("cls");
							int op = menu("Tipos de ordenamiento",opciones4,4);
							switch (op)
							{
							case 1: {
								Arbol arbol;
								Nodo* aux = arbol.getArbol();
								for (int i = 0; i < listaEmpleados->dimencion(); i++) {
									arbol.insertarNodoCedula(aux, listaEmpleados->getPosicion(i));
								}
								arbol.inOrden(aux);
								std::system("pause");
								break;
							}
							case 2: {
								Arbol arbol;
								Nodo* aux = arbol.getArbol();
								for (int i = 0; i < listaEmpleados->dimencion(); i++) {
									arbol.insertarNodoNombre(aux, listaEmpleados->getPosicion(i));
								}
								arbol.inOrden(aux);
								std::system("pause");
								break;
							}
							case 3: {
								Arbol arbol;
								Nodo* aux = arbol.getArbol();
								for (int i = 0; i < listaEmpleados->dimencion(); i++) {
									arbol.insertarNodoApellido(aux, listaEmpleados->getPosicion(i));
								}
								arbol.inOrden(aux);
								std::system("pause");
								break;
							}
							case 4: {
								Arbol arbol;
								Nodo* aux = arbol.getArbol();
								for (int i = 0; i < listaEmpleados->dimencion(); i++) {
									arbol.insertarNodoFecha(aux, listaEmpleados->getPosicion(i));
								}
								arbol.inOrden(aux);
								std::system("pause");
								break;
							}
							}
							break;
						}
						case 6: {
							std::system("cls");
							repetirL2 = true;

							break;
						}
						}
					} while (!repetirL2);
				}

			} while (!repetirLI);

			


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