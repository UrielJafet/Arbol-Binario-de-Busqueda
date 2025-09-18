#include "CArbol.h"
#include <iostream>

CArbol::CArbol() {
	ptrRoot = NULL;
}

CArbol::~CArbol() {
	podarArbol(ptrRoot);
}

void CArbol::insertN(float value) {
	insertNode(value, ptrRoot);
}

void CArbol::raiz() {
	std::cout << "\nLa raiz del arbol es: " << ptrRoot->fDato;
}

void CArbol::insertNode(float value, CNodo* &ptrNode) {
	if (ptrNode == NULL)//Buscamos una hoja
	{
		ptrNode = new CNodo();//Crea nuevo nodo
		ptrNode->fDato = value;//Asigna valor
		ptrNode->ptrLeft = NULL;//Asigna null a la izq. y der.
		ptrNode->ptrRight = NULL;
	}
	else if (value <= ptrNode->fDato)//Verifica si el valor es menor que el dato
	{
		insertNode(value, ptrNode->ptrLeft);//Llama el metodo, moviendose a la izq.
	}
	else if (value >= ptrNode->fDato)//Verifica si el valor es mayor que el dato
	{
		insertNode(value, ptrNode->ptrRight);//Llama el metodo, moviendose a la der.
	}
}

void CArbol::order() {
	inOrder(ptrRoot);
}

void CArbol::inOrder(CNodo* ptrNode) {
	if (ptrNode == NULL)//Evita errores de acceder a un ptr nulo
		return;

	inOrder(ptrNode->ptrLeft);//Recorre subárbol izquierdo
	std::cout << ptrNode->fDato << ",";//Procesa el nodo actual
	inOrder(ptrNode->ptrRight);//Recorre subárbol derecho
}

void CArbol::podarArbol(CNodo* &ptrNode) {
	if (ptrNode == NULL)
		return;
	//Se elimina el subnodo izquierdo
	podarArbol(ptrNode->ptrLeft);
	//Se elimina el subnodo derecho
	podarArbol(ptrNode->ptrRight);
	//Se elimina el nodo actual
	delete ptrNode;
}

CNodo* CArbol::buscarMenor(CNodo* ptrNode) {
	if (ptrNode == NULL)
		return NULL;
	else if (ptrNode->ptrLeft == NULL)
		return ptrNode;
	else
		return buscarMenor(ptrNode->ptrLeft);
}

CNodo* CArbol::buscarMayor(CNodo* ptrNode) {
	if (ptrNode == NULL)
		return NULL;
	else if (ptrNode->ptrRight == NULL)
		return ptrNode;
	else
		return buscarMenor(ptrNode->ptrRight);
}

void CArbol::eliminarIzq(float x) {
	eliminarIzquierda(x, ptrRoot);
}

void CArbol::eliminarIzquierda(float x, CNodo*& ptrNode) {
	//Busca el nodo que tiene x
	if (ptrNode == NULL)
		return;
	else if (x < ptrNode->fDato)
		eliminarIzquierda(x, ptrNode->ptrLeft);
	else if (x > ptrNode->fDato)
		eliminarIzquierda(x, ptrNode->ptrRight);
	else if (ptrNode->ptrLeft && ptrNode->ptrRight) {//Tiene nodo izq. y der.
		//Tiene dos hijos
		CNodo* mayor = buscarMayor(ptrNode->ptrLeft);
		ptrNode->fDato = mayor->fDato;
		eliminarIzquierda(mayor->fDato, ptrNode->ptrLeft);
	}
	else {
		//Tiene solo un hijo 
		CNodo* temp = ptrNode;
		if (ptrNode->ptrLeft == NULL)
			ptrNode = ptrNode->ptrRight;
		else if (ptrNode->ptrRight == NULL)
			ptrNode = ptrNode->ptrLeft;

		delete temp;
	}
}

void CArbol::eliminarDer(float x) {
	eliminarDerecha(x, ptrRoot);
}

void CArbol::eliminarDerecha(float x, CNodo*& ptrNode) {
	//Busca el nodo que tiene x
	if (ptrNode == NULL)
		return;
	else if (x < ptrNode->fDato)
		eliminarDerecha(x, ptrNode->ptrLeft);
	else if (x > ptrNode->fDato)
		eliminarDerecha(x, ptrNode->ptrRight);
	else if (ptrNode->ptrLeft && ptrNode->ptrRight) {//Tiene nodo izq. y der.
		//Tiene dos hijos
		CNodo* menor = buscarMenor(ptrNode->ptrRight);
		ptrNode->fDato = menor->fDato;
		eliminarDerecha(menor->fDato, ptrNode->ptrRight);
	}
	else {
		//Tiene solo un hijo 
		CNodo* temp = ptrNode;
		if (ptrNode->ptrLeft == NULL)
			ptrNode = ptrNode->ptrRight;
		else if (ptrNode->ptrRight == NULL)
			ptrNode = ptrNode->ptrLeft;

		delete temp;
	}
}
