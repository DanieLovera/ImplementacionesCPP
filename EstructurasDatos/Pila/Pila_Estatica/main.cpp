#include "Pila.h"

#include <iostream>
using std::cout;
using std::endl;

int main() {

	Pila<int> mi_pila;
	mi_pila.apilar(10);
	mi_pila.apilar(7);
	mi_pila.mostrar();


	cout << *mi_pila.consultar() << endl;
	cout << *mi_pila.desapilar() << endl;
	cout << *mi_pila.consultar() << endl;
	cout << *mi_pila.desapilar() << endl;

	mi_pila.desapilar();
	mi_pila.desapilar();


}
