#include "vector.h"

#include <iostream>
	using std :: cout;
	using std :: endl;

int main () {

	Vector <int> mi_vector;
	mi_vector.insertar(5,1);
	mi_vector.insertar(10,2);
	mi_vector.insertar_ultimo(103);
	mi_vector.mostrar();
	//cout << *mi_vector.eliminar(1) << endl;
	//mi_vector.mostrar();
	//cout << *mi_vector.eliminar() << endl;
	//mi_vector.mostrar();
	cout << *mi_vector.consultar(1) << endl;

	mi_vector.redimensionar(1000);
	mi_vector.mostrar();

	return 0;
}
