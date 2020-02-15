#include <iostream>
	using std::cout;
	using std::endl;

//#include <ctime>

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

void merge (int arreglo [], int inicio_1, int fin_1
		, int inicio_2, int fin_2) {

	int tope_1 = inicio_1;
	int tope_2 = inicio_2;

	int arreglo_aux [(fin_2 - inicio_1) + 1];
	int tope_aux = 0;

	while ( (tope_1 <= fin_1) && (tope_2 <= fin_2) ) {

		if ( arreglo [tope_1] < arreglo [tope_2] ) {
			
			arreglo_aux [tope_aux++] = arreglo [tope_1++];
		
		} else {

			arreglo_aux [tope_aux++] = arreglo [tope_2++];
		}
	}

	while ( tope_1 <= fin_1 ) {
		
		arreglo_aux [tope_aux++] = arreglo [tope_1++];
	}

	while ( tope_2 <= fin_2 ) {
		
		arreglo_aux [tope_aux++] = arreglo [tope_2++];
	}

	for (int i = inicio_1; i <= fin_2; i++) {
		
		arreglo [i] = arreglo_aux [i - inicio_1];
	}
}

void mergeSort (int arreglo [], int inicio, int fin) {

	int centro = (inicio + fin)/2;

	if (fin > inicio) {
			
		mergeSort (arreglo, inicio, centro);
		mergeSort (arreglo, centro + 1, fin);
		merge (arreglo, inicio, centro, centro + 1, fin);
	}
}

void mergeSort (int arreglo [], int tope) {
	
	int inicio = 0;
	int fin = tope - 1;

	mergeSort (arreglo, inicio, fin);
}

int main () {

	int tamanio = 13;
	int arreglo[tamanio];
	inicializar_arreglo(arreglo, tamanio);
	
        mostrar_arreglo(arreglo, tamanio);
        mergeSort(arreglo, tamanio);
        mostrar_arreglo(arreglo, tamanio);

	return 0;
}
