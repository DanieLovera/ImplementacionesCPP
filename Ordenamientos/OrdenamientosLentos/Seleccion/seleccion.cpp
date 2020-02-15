#include <iostream>
	using std::cout;
	using std::endl;

void intercambiar (int &dato_1, int &dato_2) {

	int auxiliar = std::move (dato_1);
	dato_1 = std::move (dato_2);
	dato_2 = std::move (auxiliar);
}

void seleccionar (int arreglo [], int tope) {
	
	for (int i = 0; i < (tope - 1); i++) {
		
		int pos_menor_dato = i;

		for (int j = i + 1; j < tope; j++) {

			if (arreglo [j] < arreglo [pos_menor_dato]) {
				
				pos_menor_dato = j;
			}
		}
		intercambiar (arreglo [i], arreglo [pos_menor_dato]);
	}
}

void mostrar_vector (int arreglo [], int tope) {
	
	cout << "{ ";
	
	for (int i = 0; i < tope; i++) {
		cout << arreglo [i] << " ";
	}
	cout << "}" << endl;
}

int main () {

	int arreglo [5] = {5,4,3,2,1};
	mostrar_vector (arreglo, 5);

	seleccionar (arreglo,5);
	mostrar_vector (arreglo,5);

	return 0;
}
