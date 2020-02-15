#include "ArregloBits.h"

#include <iostream>
using namespace std;

int main () {

	ArregloBits mi_arreglo_bits;
	mi_arreglo_bits.insertar (2);
	mi_arreglo_bits.insertar (107);
	cout << (mi_arreglo_bits.consultar (107) == true ? "ESTA EL VALOR" : "NO ESTA EL VALOR") << endl;
	mi_arreglo_bits.eliminar (107);
	cout << (mi_arreglo_bits.consultar (107) == true ? "ESTA EL VALOR" : "NO ESTA EL VALOR") << endl;

	return 0;
}