/***********************************************************************
 * Module:  Menu.cpp
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 4 de julio de 2023
 * Purpose: Declaration of the class Menu
 ***********************************************************************/
#include "Menu.h"

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
	bool repetir = true;

	const char* titulo = "BIENVENIDO AL APLICATIVO DE REGISTRO";
	const char* opciones[] = { "Registro de personal.","Log In.","Salir."};
	
	do {
		opcMP = menu(titulo, opciones, 3);
		switch (opcMP) {
		case 1: {
			system("cls");
			cout << "Registro de personal" << endl;

			
			system("pause");
			break;
		}

		case 2: {
			system("cls");
			cout << "Log In" << endl;


			system("pause");
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