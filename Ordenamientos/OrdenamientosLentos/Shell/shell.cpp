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

void shellSort (int arreglo [], int tope) {
	
	for (int brecha = tope/2; brecha > 0; brecha /= 2) {

		for (int i = brecha; i < tope; i++) {

			int j = 0;
			int auxiliar = arreglo [i];

			for (j = i; j >= brecha && auxiliar < arreglo [j - brecha] ; j -= brecha) {

				arreglo [j] = arreglo [j - brecha];
			}

			arreglo [j] = auxiliar;
		}
	}
}

int main () {

	int tamanio = 13;
	int arreglo [tamanio];
	inicializar_arreglo (arreglo, tamanio);
	
        mostrar_arreglo (arreglo, tamanio);
        shellSort (arreglo, tamanio);
        mostrar_arreglo (arreglo, tamanio);

	return 0;
}
