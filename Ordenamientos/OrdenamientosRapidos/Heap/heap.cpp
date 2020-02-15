#include <iostream>
	using std :: cout;
	using std :: endl;
	
	void mostrar_arreglo(int arreglo[], int tope){

	cout <<"{ ";

	for(int i = 0; i< tope; i++) {

		cout << arreglo[i] << " ";
        }

        cout << "}" << endl;

}

int numero_random(int desde, int hasta){

	srand((unsigned int)clock());
	return ( (rand() % (hasta - desde + 1)) + desde );
}

void inicializar_arreglo(int arreglo[], int tope){

	for (int i = 0; i < tope; i++) {

		arreglo[i] = numero_random(1,100);
	}
}

int hijo (int posicion_arreglo) {

	return (2 * posicion_arreglo) + 1;	
}

void filtrar_abajo (int arreglo [], int hueco, int tope) {

	int auxiliar = arreglo [hueco];
	int posicion_hijo = hijo (hueco);
	bool es_posicion_correcta = false;

	while ( !es_posicion_correcta && posicion_hijo < tope ) {

		if ( posicion_hijo != (tope - 1) && arreglo [posicion_hijo] < arreglo [posicion_hijo + 1] ) {
			
			posicion_hijo++;
		}	

		if ( auxiliar  < arreglo [posicion_hijo] ) {

			arreglo [hueco] = arreglo [posicion_hijo];
			hueco = posicion_hijo;
		}	

		else {

			es_posicion_correcta = true;
		}
		
		posicion_hijo = hijo (hueco);
	}

	arreglo [hueco] = auxiliar;
}

void construirHeap (int arreglo [], int tope) {

	for (int i = (tope/2) - 1; i >= 0; i--) {
		
		filtrar_abajo (arreglo, i, tope);
	}	
}

void intercambiar (int &a, int &b) {

	int auxiliar = a;
	a = b;
	b = auxiliar;

}

void heapSort (int arreglo [], int tope) {

	construirHeap (arreglo, tope);

	for (int i = tope - 1; i > 0; i--) {

		intercambiar (arreglo [0], arreglo [i]);
		filtrar_abajo (arreglo, 0, i);
	}
}

int main () {
	
	int tamanio = 13;
	int arreglo [tamanio];
	inicializar_arreglo (arreglo, tamanio);
	
        mostrar_arreglo (arreglo, tamanio);
        heapSort (arreglo, tamanio);
        mostrar_arreglo (arreglo, tamanio);

	return 0;
}
