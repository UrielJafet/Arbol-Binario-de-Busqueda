#pragma once
#include "CNodo.h"

class CArbol
{
private:
	CNodo* ptrRoot;

public:
	CArbol();
	~CArbol();

	void insertN(float value);
	void insertNode(float value, CNodo* &ptrNode);
	void order();
	void inOrder(CNodo* ptrNode);
	void podarArbol(CNodo* &ptrNode);
	void raiz();
	/* ELIMINACION */
	CNodo* buscarMenor(CNodo* ptrNode);
	CNodo* buscarMayor(CNodo* ptrNode);
	void eliminarIzq(float x);
	void eliminarDer(float x);
	void eliminarIzquierda(float x, CNodo*& ptrNode);
	void eliminarDerecha(float x, CNodo*& ptrNode);

};

