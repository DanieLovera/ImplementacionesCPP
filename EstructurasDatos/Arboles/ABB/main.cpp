#include "Arbol.h"

int numero_random (int desde, int hasta) {

	srand ((unsigned int)clock());
	return ( rand() % (hasta + 1 - desde) ) + desde;
}



int main () {

	Arbol <int> mi_arbol;

	mi_arbol.insertar (18);
	mi_arbol.insertar (5);
	mi_arbol.insertar (24);
	mi_arbol.insertar (2);
	mi_arbol.insertar (7);
	mi_arbol.insertar (20);
	//mi_arbol.insertar (300);
	/*//mi_arbol.insertar (20);
	mi_arbol.insertar(22);
	mi_arbol.insertar(31);
	mi_arbol.insertar(12);
	mi_arbol.insertar(27);*/

	//mi_arbol.en_orden ();
	//mi_arbol.pre_orden ();
	//mi_arbol.pos_orden ();

	cout << "MINIMO " << mi_arbol.encontrar_minimo () << endl;
	cout << "MAXIMO " << mi_arbol.encontrar_maximo () << endl;

	mi_arbol.eliminar(18);
	mi_arbol.en_orden();

	cout << "ALTURA " << mi_arbol.altura() << endl;

	//mi_arbol.arbol_perfecto () ? cout << "ARBOL LLENO " << endl : cout << "ARBOL NO LLENO " << endl;
	cout << "PESO " << mi_arbol.peso () << endl;

	//Arbol <int> arbol_copia(mi_arbol);
	//arbol_copia.en_orden();

	return 0;
}
