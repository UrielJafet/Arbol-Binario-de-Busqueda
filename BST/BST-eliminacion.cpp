#include <iostream>
#include "CArbol.h"
using namespace std;

int main()
{
    int value;
    CArbol arbol;

	arbol.insertN(8);
	arbol.insertN(4);
	arbol.insertN(2);
	arbol.insertN(3);
	arbol.insertN(20);
	arbol.insertN(14);
	arbol.insertN(10);
	arbol.insertN(15);
	arbol.insertN(7);

	cout << "\nRecorrido inOrder\n";
	arbol.order();
	arbol.raiz();
	cout << "\n\n";

	cout << "Valor a eliminar izquierda: 8";
	arbol.eliminarIzq(8);

	cout << "\nRecorrido inOrder\n";
	arbol.order();
	arbol.raiz();
	cout << "\n\n";

	cout << "Valor a eliminar derecha: 14";
	arbol.eliminarDer(14);
	
	cout << "\nRecorrido inOrder\n";
	arbol.order();
	arbol.raiz();
	cout << "\n\n";

	system("pause");
	return 0;
}
