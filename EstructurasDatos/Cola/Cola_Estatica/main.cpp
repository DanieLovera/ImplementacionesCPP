#include "Cola.h"
#include <iostream>

using std :: endl;
using std :: cout;

int main () {

	Cola<int> mi_cola;
	mi_cola.encolar(14);
	mi_cola.encolar(9);
	mi_cola.encolar(50);
	mi_cola.mostrar();
	cout << *mi_cola.consultar() << endl;
	mi_cola.desencolar();
	mi_cola.encolar(23);
	mi_cola.desencolar();
	mi_cola.mostrar();
	cout << *mi_cola.consultar() << endl;

	return 0;
}
