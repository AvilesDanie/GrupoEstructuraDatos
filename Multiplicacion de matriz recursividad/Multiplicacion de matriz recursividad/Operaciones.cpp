#include "Operaciones.h"
#include "Matriz.h"

Operaciones::Operaciones() {};

void Operaciones::sumaRecursivaMatrices(Matriz mat1, Matriz mat2,Matriz matR, int f, int c) {
	if ((f < 3) && (c < 3)) {
		*(*(matR.getMatriz() + f) + c) = *(*(mat1.getMatriz() + f) + c) + *(*(mat2.getMatriz() + f) + c);
		sumaRecursivaMatrices(mat1, mat2,matR, f + 1, c);
		sumaRecursivaMatrices(mat1, mat2,matR, f, c + 1);
	}
}

void Operaciones::multiplicarRecursivaMatrices(Matriz mat1, Matriz mat2, Matriz matR, int f, int c) {
    if (f >= 0 && c >= 0) {
        int sum = 0;
        for (int k = 0; k < 3; ++k) {
            sum += (*(*(mat1.getMatriz() + f) + k)) * (*(*(mat2.getMatriz() + k) + c));
        }
        *(*(matR.getMatriz() + f) + c) = sum;
        multiplicarRecursivaMatrices(mat1, mat2, matR, f, c - 1);
    }
    else if (f >= 0 && c < 0) {
        multiplicarRecursivaMatrices(mat1, mat2, matR, f - 1, 2);
    }
}