#include "Avl.h"

int main () {

	Avl <int> mi_avl;

	/*mi_avl.insertar(2);
	mi_avl.insertar(1);
	mi_avl.insertar(6);
	mi_avl.insertar(5);
	mi_avl.insertar(10);
	mi_avl.insertar(12);


	mi_avl.insertar(10);
	mi_avl.insertar(8);
	mi_avl.insertar(6);
	mi_avl.insertar(4);
	mi_avl.insertar(2);*/

	mi_avl.insertar (40);
	mi_avl.insertar (30);
	mi_avl.insertar (50);
	mi_avl.insertar (20);
	mi_avl.insertar (35);
	mi_avl.insertar (45);
	mi_avl.insertar (60);
	mi_avl.insertar (50);
	mi_avl.insertar (41);
	mi_avl.insertar (46);
	mi_avl.insertar (70);
	//mi_avl.insertar (49);
	//mi_avl.eliminar (20);
	//mi_avl.eliminar (35);

	cout << "ALTURA DEL ARBOL: " << mi_avl.altura() << endl;

	mi_avl.en_ancho();

	return 0;
}
