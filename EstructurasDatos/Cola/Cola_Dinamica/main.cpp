#include "Cola.h"
#include <iostream>
using namespace std;

int main() {
	
    char caracter = 'A';
    Cola<char>* mi_cola = new Cola<char> ();

    while( caracter != 'Z' + 1)
        mi_cola->encolar(caracter++);

    while( !mi_cola->esta_vacia() )
        cout << mi_cola->desencolar() << endl;


    delete mi_cola;
    return 0;
}
