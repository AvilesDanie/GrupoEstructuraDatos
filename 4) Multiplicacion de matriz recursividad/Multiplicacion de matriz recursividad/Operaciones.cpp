#include "Operaciones.h"
#include "Matriz.h"

template <typename T>
Operaciones<T>::Operaciones() {};

template <typename T>
void Operaciones<T>::sumaRecursivaMatrices(Matriz<T> mat1, Matriz<T> mat2,Matriz<T> matR, int f, int c) {
	if ((f < 3) && (c < 3)) {
		*(*(matR.getMatriz() + f) + c) = *(*(mat1.getMatriz() + f) + c) + *(*(mat2.getMatriz() + f) + c);
		sumaRecursivaMatrices(mat1, mat2,matR, f + 1, c);
		sumaRecursivaMatrices(mat1, mat2,matR, f, c + 1);
	}
}

template <typename T>
void Operaciones<T>::multiplicarRecursivaMatrices(Matriz<T> mat1, Matriz<T> mat2, Matriz<T> matR, int f, int c) {
    if (f >= 0 && c >= 0) {
        T sum = 0;
        for (int k = 0; k < 3; ++k) {
            sum += (*(*(mat1.getMatriz() + f) + k)) * (*(*(mat2.getMatriz() + k) + c));
        }
        *(*(matR.getMatriz() + f) + c) = sum;
        multiplicarRecursivaMatrices(mat1, mat2, matR, f, c - 1);
        multiplicarRecursivaMatrices(mat1, mat2, matR, f - 1, c);
    }
}