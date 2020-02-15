#include "HeapBinario.h"

int main () {

	HeapBinario <int> mi_heap;
	mi_heap.insertar (15);
	mi_heap.insertar (3);
	mi_heap.insertar (18);
	mi_heap.insertar (21);
	mi_heap.insertar (32);
	mi_heap.insertar (4);
	mi_heap.insertar (9);
	mi_heap.insertar (1);


	mi_heap.mostrar_heap ();
/*
	cout << "\nLUEGO DE ELIMINAR EL MINIMO " << endl;
	mi_heap.eliminar_minimo ();	
	mi_heap.mostrar_heap ();

	mi_heap.vaciar_heap ();
	cout << "\nLUEGO DE VACIAR EL HEAP " << endl;
	mi_heap.insertar (19);
	mi_heap.mostrar_heap ();

	int arreglo [4];
	arreglo [0] = 5;
	arreglo [1] = 4;
	arreglo [2] = 2;
	//arreglo [3] = 1;
	HeapBinario <int> segundo_heap (arreglo,3,4);
	cout << "\nSEGUNDO HEAP " << endl;
	segundo_heap.mostrar_heap ();*/

	return 0;
}
