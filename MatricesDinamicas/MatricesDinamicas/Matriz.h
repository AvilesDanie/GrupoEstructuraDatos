#pragma once
#include <iostream>
template <typename T>
class Matriz {
private:
	T** matriz;
	int dim;
public:
	Matriz();
	Matriz(T**, int);
	Matriz(int);
	int getDim();
	void setDim(int);
	T** getMatriz();
	void setMatriz(T**);
};