#include <iostream>
	using std::cout;
	using std::endl;

void ordenar_insercion (int arreglo [], int tope) {


	for (int i = 1; i < tope; i++) {
	
		int auxiliar = arreglo [i];	
		int j = 0;

		for (j = i; j > 0 && auxiliar < arreglo [j - 1] ; j--) {
			
			arreglo [j] = arreglo [j - 1];
		}

		arreglo [j] = auxiliar;
	}
}

void mostrar_arreglo (int arreglo [], int tope) {

	cout << "{ ";
	for (int i = 0; i < tope; i++) {
		cout << arreglo [i] << " ";
	}
	cout << "}" << endl;
}

int main () {

	int arreglo [5] = {5,4,3,2,1};
	mostrar_arreglo (arreglo, 5);

	ordenar_insercion (arreglo, 5);
	mostrar_arreglo (arreglo, 5);

	return 0;
}
