#include "Pila.h"

#include <iostream>
    using std :: cout;
    using std :: endl;

int main () {

	char caracter = 'A';
    Pila<char>* mi_pila = new Pila<char> ();

    while( caracter != ('Z' + 1) ) {
        mi_pila -> apilar (caracter++);
    }

    while( !mi_pila -> esta_vacia () ){
        cout << mi_pila->desapilar() << endl;
    }

    delete mi_pila;

	return 0;
}