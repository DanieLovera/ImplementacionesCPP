#include <iostream>
	using std :: cout;
	using std :: endl;

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

void intercambiar (int &a, int &b) {

	int aux = std::move (a);
	a = std::move (b);
	b = std::move (aux);
}

int elegirPivote (int arreglo [], int inicio, int fin) {

	int centro = (inicio + fin)/2;

	if (arreglo [inicio] > arreglo [centro]) {

		intercambiar (arreglo [inicio], arreglo [centro]);
	}

	if (arreglo [inicio] > arreglo [fin]) {

		intercambiar (arreglo [inicio], arreglo [fin]);
	}

	if (arreglo [centro] > arreglo [fin]) {

		intercambiar (arreglo [centro], arreglo [fin]);
	}

	intercambiar (arreglo [centro], arreglo [fin - 1]);

	return arreglo [fin - 1];
}

void ordenar_insercion (int arreglo [], int inicio, int fin) {


	for (int i = inicio + 1; i <= fin; i++) {
		
		int j = i;

		while (j > 0 && arreglo [j] < arreglo [j - 1]) {
			
			intercambiar (arreglo [j], arreglo [j - 1]);
			j--;
		}	
	}
}

void quickSort (int arreglo [], int inicio ,int fin) {

	if ((fin - inicio) <= 10) {

		ordenar_insercion (arreglo, inicio, fin);

	} else {

		int pivote = elegirPivote (arreglo, inicio, fin);
		int i = inicio + 1;
		int j = fin - 2;

		while (i < j) {

			while (arreglo [i] < pivote) {
		
				i++;
			}

			while (pivote < arreglo [j]) {
			
				j--;
			}

			if (i < j) {
			
				intercambiar (arreglo [i], arreglo [j]);
			}
		}

		intercambiar (arreglo [fin - 1], arreglo [i]);

		quickSort (arreglo, inicio, i - 1);
		quickSort (arreglo, i + 1, fin); 
	}
}

void quickSort (int arreglo [], int tope) {

	quickSort (arreglo, 0, (tope - 1)); 
}

int main () {
	
	int tamanio = 13;
	int arreglo [tamanio];
	inicializar_arreglo (arreglo, tamanio);
	
        mostrar_arreglo (arreglo, tamanio);
        quickSort (arreglo, tamanio);
        mostrar_arreglo (arreglo, tamanio);

	return 0;
}
