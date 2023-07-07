#include "Menu.h"

#include "ValidacionDatos.h"
#include "Postfija.h"
#include "Prefija.h"
#define Tecla_Arriba 72
#define Tecla_Abajo 80
#define Enter 13
using namespace std;

void Menu::menuPrincipal() {
	int opcMP = 0, opcMN = 0;
	bool repetir = true, repetir1 = false;
	bool ecValida = false;
	ValidacionDatos objValidar;
	char enteroC[10];
	Postfija objPosFija;
	Prefija  objPreFija;
	string ecuacion;
	const char* ecuacionC[100];
	
	int entero;
	const char* titulo = "BIENVENIDO AL APLICATIVO DE NOTACIONES";
	const char* opciones[] = { "Ingresar Ecuacion.","Elegir Notacion.","Cerrar aplicativo." };
	const char* titulo1 = "TIPOS DE NOTACIONES";
	const char* opciones1[] = { "Notacion prefija.","Notacion posfija.","Salir"};
	
	do {
		opcMP = menu(titulo, opciones, 3);
		switch (opcMP) {
		case 1: {
			system("cls");

			bool pasar=false;
			do {
				pasar = false;
				do {
					pasar = false;
					do {
						pasar = false;
						do {
							
							pasar = false;
							do {
								
								pasar = false;
								do {
									cout << "Ingrese la ecuacion-> " << endl;
									cin >> ecuacion;


									pasar = objValidar.general(ecuacion);
									if (pasar) {
										cout << "error de digitacion" << endl;
									}

								} while (pasar);


								pasar = objValidar.letras(ecuacion);
								if (pasar) {
									cout << "error de letras" << endl;
								}

							} while (pasar);



							if (pasar) {
								cout << "error de negativos" << endl;
							}

						} while (pasar);

						pasar = objValidar.decimales(ecuacion);
						if (pasar) {
							cout << "error de decimales" << endl;
						}

					} while (pasar);
					pasar = objValidar.parentesis(ecuacion);
					if (pasar) {
						cout << "error de parentesis" << endl;
					}
				} while (pasar);
				pasar = objValidar.signos(ecuacion);
				if (pasar) {
					cout << "error de signos" << endl;
				}
			} while (pasar);
			repetir1 = true;
			system("pause");
			break;
		}

		case 2: {
			if (repetir1) {
				system("cls");
				do {
					opcMN = menu(titulo1, opciones1, 3);
					switch (opcMN) {
						case 1: {
							system("cls");
							cout << "\nInfija: " << ecuacion << endl;
							string ecuacionPreFija = objPreFija.inAPre(ecuacion);


							cout << "\nEcuacion en notacion prefija" << endl;
							cout << ecuacionPreFija << endl;

							objPreFija.calcularPila();


							system("pause");
							
							break;
						}
						case 2: {
							system("cls");

							cout << "\nInfija: " << ecuacion << endl;
							string ecuacionPosFija = objPosFija.inAPost(ecuacion);

							cout << "\nEcuacion en notacion posfija" << endl;
							cout << ecuacionPosFija << endl;

							objPosFija.calcularPila();

							system("pause");

							break;
						}
						case 3: {
							system("cls");
							repetir1 = false;
						}
					}
				} while (repetir1);
			}
			else {
				system("cls");
				cout << "\n********************************\n" << endl;
				cout << "\Por favor, ingrese una ecuacion" << endl;
				cout << "\n********************************\n" << endl;
				system("pause");
			}
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

int Menu::menu(const char* titulo, const char* opciones[], int n) {
	int opcSeleccionada = 1;
	int tecla;
	bool repetir = true;
	do {
		system("cls");
		gotoxy(5, 3 + opcSeleccionada); cout <<  "-->";
		gotoxy(15, 2); cout << titulo;
		for (int i = 0; i < n; i++) {
			if (i+1 == opcSeleccionada) {
				gotoxy(10, 4 + i); cout <<"\033[47m\033[30m"<< i + 1 << "." << opciones[i]<<"\033[0m";
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

void Menu::gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}