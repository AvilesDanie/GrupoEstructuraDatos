#if !defined(Validaciones_h)
#define Validaciones_h

#include <string>
using namespace std;

class Validaciones
{
public:

	int validarEnteros();
	int LongitudCadena(char* cedula);
	bool verificarLongitud(char* p);
	char* validarEnterosCedula();
	double validarDoubles();
	char* validarStrings();
	int* splitNumber(char* number);
	bool verificacion1(char* numCedula);
	bool verificacion2(char* numCedula);
	bool verificacion3(char* numCedula);
	bool verificacionCedula(char* numCedula);
	int validarDia(int mes);
	Validaciones();
	~Validaciones();

protected:
private:

};

#endif