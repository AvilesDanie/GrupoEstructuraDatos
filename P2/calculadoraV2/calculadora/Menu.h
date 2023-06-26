#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
using namespace std;
class Menu {
public:
	void menuPrincipal();
	int menu(const char* titulo, const char* opciones[], int n);
	void gotoxy(int x, int y);
	//int validarCedula(char *cedulaC);
	static bool verificarCedula(const string& cedula);
};
