#pragma once
#include "Arbol.h"
#include <vector>

/**
 * Establece el valor de la variable privada arbol al valor del parámetro _arbol.
 *
 * @param _arbol El nodo raíz del árbol.
 */
void Arbol::setArbol(Nodo* _arbol)
{
    arbol = _arbol;
}

/**
 * Devuelve la raíz del árbol.
 *
 * @return El nodo raíz del árbol.
 */
Nodo* Arbol::getArbol()
{
    return arbol;
}

/**
 * Crea un nuevo nodo con el valor del parámetro.
 *
 * @param dato El valor del nodo
 *
 * @return Un puntero a un objeto Nodo.
 */
Nodo* Arbol::crearNodo(Empleado dato)
{
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->setValor(dato);
    nuevoNodo->setDerecha(NULL);
    nuevoNodo->setIzquierda(NULL);
    return nuevoNodo;
}

/**
 * Si el árbol está vacío, cree un nuevo nodo y asígnelo al árbol. De lo contrario, si los datos son
 * menores que la raíz, insértelos en el subárbol izquierdo. De lo contrario, insértelo en el subárbol
 * derecho
 *
 * @param arbol El árbol
 * @param dato el valor a insertar
 */
void Arbol::insertarNodoCedula(Nodo*& arbol, Empleado dato)
{
    if (arbol == NULL)
    {
        Nodo* nuevoNodo = crearNodo(dato);
        arbol = nuevoNodo;
        cout << "Dato ingresado correctamente...\n";
    }
    else
    {
        string raiz = arbol->getValor().getCedula();
        if (dato.getCedula() < raiz)
        {
            insertarNodoCedula(arbol->getIzquierda(), dato);
            cout << "Dato ingresado correctamente...\n";
        }
        else
        {
            insertarNodoCedula(arbol->getDerecha(), dato);
            cout << "Dato ingresado correctamente...\n";
        }
    }
}

/**
 * Si el árbol está vacío, cree un nuevo nodo y asígnelo al árbol. De lo contrario, si los datos son
 * menores que la raíz, insértelos en el subárbol izquierdo. De lo contrario, insértelo en el subárbol
 * derecho
 *
 * @param arbol El árbol
 * @param dato el valor a insertar
 */
void Arbol::insertarNodoNombre(Nodo*& arbol, Empleado dato)
{
    if (arbol == NULL)
    {
        Nodo* nuevoNodo = crearNodo(dato);
        arbol = nuevoNodo;
        cout << "Dato ingresado correctamente...\n";
    }
    else
    {
        string raiz = arbol->getValor().getNombre();
        if (dato.getNombre() < raiz)
        {
            insertarNodoNombre(arbol->getIzquierda(), dato);
            cout << "Dato ingresado correctamente...\n";
        }
        else
        {
            insertarNodoNombre(arbol->getDerecha(), dato);
            cout << "Dato ingresado correctamente...\n";
        }
    }
}

/**
 * Si el árbol está vacío, cree un nuevo nodo y asígnelo al árbol. De lo contrario, si los datos son
 * menores que la raíz, insértelos en el subárbol izquierdo. De lo contrario, insértelo en el subárbol
 * derecho
 *
 * @param arbol El árbol
 * @param dato el valor a insertar
 */
void Arbol::insertarNodoApellido(Nodo*& arbol, Empleado dato)
{
    if (arbol == NULL)
    {
        Nodo* nuevoNodo = crearNodo(dato);
        arbol = nuevoNodo;
        cout << "Dato ingresado correctamente...\n";
    }
    else
    {
        string raiz = arbol->getValor().getApellido();
        if (dato.getApellido() < raiz)
        {
            insertarNodoApellido(arbol->getIzquierda(), dato);
            cout << "Dato ingresado correctamente...\n";
        }
        else
        {
            insertarNodoApellido(arbol->getDerecha(), dato);
            cout << "Dato ingresado correctamente...\n";
        }
    }
}

/**
 * Si el árbol está vacío, cree un nuevo nodo y asígnelo al árbol. De lo contrario, si los datos son
 * menores que la raíz, insértelos en el subárbol izquierdo. De lo contrario, insértelo en el subárbol
 * derecho
 *
 * @param arbol El árbol
 * @param dato el valor a insertar
 */
void Arbol::insertarNodoFecha(Nodo*& arbol, Empleado dato)
{
    if (arbol == NULL)
    {
        Nodo* nuevoNodo = crearNodo(dato);
        arbol = nuevoNodo;
        cout << "Dato ingresado correctamente...\n";
    }
    else
    {
        Fecha raiz = arbol->getValor().getFecha();
        if (dato.getFecha().getAnio() < raiz.getAnio())
        {
            insertarNodoFecha(arbol->getIzquierda(), dato);
            cout << "Dato ingresado correctamente...\n";
        }
        else if (dato.getFecha().getAnio() > raiz.getAnio())
        {
            insertarNodoFecha(arbol->getDerecha(), dato);
            cout << "Dato ingresado correctamente...\n";
        }
        else if (dato.getFecha().getMes() < raiz.getMes())
        {
            insertarNodoFecha(arbol->getIzquierda(), dato);
            cout << "Dato ingresado correctamente...\n";
        }
        else if (dato.getFecha().getMes() > raiz.getMes())
        {
            insertarNodoFecha(arbol->getDerecha(), dato);
            cout << "Dato ingresado correctamente...\n";
        }
        else if (dato.getFecha().getDia() < raiz.getDia())
        {
            insertarNodoFecha(arbol->getIzquierda(), dato);
            cout << "Dato ingresado correctamente...\n";
        }
        else if (dato.getFecha().getDia() > raiz.getDia())
        {
            insertarNodoFecha(arbol->getDerecha(), dato);
            cout << "Dato ingresado correctamente...\n";
        }
        else {
            insertarNodoFecha(arbol->getDerecha(), dato);
            cout << "Dato ingresado correctamente...\n";
        }
    }
}


//Función mostrar
void Arbol::mostrar(Nodo* arbol, int contador)
{
    if (arbol == NULL)
    {
        return;
    }
    else
    {
        mostrar(arbol->getDerecha(), contador + 1);
        for (int i = 0; i < contador; i++)
        {
            cout << "  ";
        }
        arbol->getValor().imprimir();
        mostrar(arbol->getIzquierda(), contador + 1);
    }
}

//Calcula el peso de un árbol binario
int Arbol::peso(Nodo* arbol)
{
    if (arbol == NULL)
        return 0;
    else
        return 1 + peso(arbol->getIzquierda()) + peso(arbol->getDerecha());
}

//Calcula la altura (nivel + 1) de un árbol binario
int Arbol::altura(Nodo* aux)
{
    if (aux == NULL)
        return 0;
    if (aux->getIzquierda() == NULL && aux->getDerecha() == NULL)
        return 1;
    return max(altura(aux->getIzquierda()), altura(aux->getDerecha())) + 1;
}

//Se complementa con la función "simetrias" y calcula
//si el árbol es perfecto o imperfecto
bool Arbol::simetria(Nodo* X, Nodo* Y) {
    if (X == NULL && Y == NULL) {
        return true;
    }
    return (X != NULL && Y != NULL) &&
        simetria(X->getIzquierda(), Y->getDerecha()) &&
        simetria(X->getDerecha(), Y->getIzquierda());
}

bool Arbol::simetrias(Nodo* aux) {
    if (aux == NULL) {
        return true;
    }

    return simetria(aux->getIzquierda(), aux->getDerecha());
}

//RECORRIDO EN PREORDEN
/**
 * *|CURSOR_MARCADOR|*
 *
 * @param arbol es la raiz del arbol
 *
 * @return el valor del nodo.
 */
void Arbol::preOrden(Nodo* arbol)
{
    if (arbol == NULL)
    {
        return;
        cout << "No se encuentran datos en el arbol, \narbol vacio...\n";
    }
    else
    {
        arbol->getValor().imprimir();
        preOrden(arbol->getIzquierda());
        preOrden(arbol->getDerecha());
    }
}

/**
 * Recorrido inOrden.
 *
 * @param arbol Un puntero al nodo de la raíz.
 *
 * @return Dato entero del nodo.
 */
void Arbol::inOrden(Nodo* arbol)
{
    if (arbol == NULL)
    {
        return;
        cout << "No se encuentran datos en el arbol" << endl;
        cout << "El arbol se encuentra vacio" << endl;
    }
    else
    {
        inOrden(arbol->getIzquierda());
        arbol->getValor().imprimir();
        inOrden(arbol->getDerecha());
    }
}

void Arbol::buscar(Nodo* arbol, std::string dato) {
    if (arbol == NULL) {
        cout << "No se encuentran datos en el arbol\n";
    }
    else if (arbol->getValor().getCedula() == dato) {
        arbol->getValor().imprimir();
        cout << "Dato encontrado correctamente...\n";
    }
    else if (dato < arbol->getValor().getCedula()) {
        buscar(arbol->getIzquierda(), dato);
    }
    else {
        buscar(arbol->getDerecha(), dato);
    }
}

//Es una función para buscar datos que cuenta con dos parámetros

/**
 * Imprime el árbol en orden posterior.
 *
 * @param arbol El nodo raíz del árbol.
 *
 * @return Dato entero del nodo.
 */
void Arbol::postOrden(Nodo* arbol) {

    if (arbol == NULL)
    {
        return;
        cout << "No se encuentran datos en el arbol, \narbol vacio...\n";
    }
    else
    {
        postOrden(arbol->getIzquierda());
        postOrden(arbol->getDerecha());
        arbol->getValor().imprimir();
    }
}

/**
 *  Imprimir nodos en un nivel actual
 *
 * @param arbol Un puntero al nodo de la raíz.
 */
void Arbol::imprimirNivelActual(Nodo* arbol, int nivel)
{
    if (arbol == NULL)
        return;
    if (nivel == 1)
        arbol->getValor().imprimir();
    else if (nivel > 1) {
        imprimirNivelActual(arbol->getIzquierda(), nivel - 1);
        imprimirNivelActual(arbol->getDerecha(), nivel - 1);
    }
}

/**
 * Imprime Recorrido por Amplitud del nodo.
 *
 * @param arbol El nodo raíz del árbol
 *
 * @return valor del Nodo.
 */
void Arbol::recorridoNivel(Nodo* arbol)
{
    if (arbol == NULL)
    {
        cout << "No se encuentran datos en el arbol" << endl;
        cout << "El arbol se encuentra vacio" << endl;
        return;
    }
    int h = altura(arbol);
    int i;
    for (i = 1; i <= h; i++)
        imprimirNivelActual(arbol, i);
}

Nodo* Arbol::eliminarNodo(Nodo* raiz, std::string dato) {

    if (raiz == NULL)
        return raiz;
    if (dato < raiz->getValor().getCedula())
        raiz->setIzquierda(eliminarNodo(raiz->getIzquierda(), dato));

    else if (dato > raiz->getValor().getCedula())
        raiz->setDerecha(eliminarNodo(raiz->getDerecha(), dato));
    else {
        if (raiz->getIzquierda() == NULL) {
            Nodo* temp = raiz->getDerecha();
            delete(raiz);
            return temp;
        }
        else if (raiz->getDerecha() == NULL) {
            Nodo* temp = raiz->getIzquierda();
            delete(raiz);
            return temp;
        }
        else {
            auto getmax = [](Nodo* raiz) {
                Nodo* aux = new Nodo();
                aux = raiz;
                while (aux && aux->getDerecha()) {
                    aux = aux->getDerecha();
                }
                return aux;
            };

            Nodo* temp = getmax(raiz->getIzquierda());

            raiz->setValor(temp->getValor());
            raiz->setIzquierda(eliminarNodo(raiz->getIzquierda(), temp->getValor().getCedula()));
        }
    }
    return raiz;
}