#include <iostream>
	using std::cout;
	using std::endl;

void intercambiar (int &dato_1, int &dato_2) {

	int auxiliar = std::move (dato_1);
	dato_1 = std::move (dato_2);
	dato_2 = std::move (auxiliar);
}

//ORDENANDO POR DEFECTO DE MENOR A MAYOR
void burbujear (int arreglo [], int tope) {
	 
	bool ordenado = false;
	int iteraciones = tope - 1;

	while (!ordenado && iteraciones > 0) { 
		
		ordenado = true;
		
		for (int j = 0; j < iteraciones; j++) {
		
			if (arreglo [j + 1] < arreglo [j]) {
				
				intercambiar (arreglo [j], arreglo [j + 1]);
				ordenado = false;
			}
		}
		iteraciones--;	
	}
}

void mostrar_vector(int vect[], int tope){
    
	cout << "{ ";
	for(int i = 0; i< tope; i++){
		cout << vect[i] << " ";
	}
	cout << "}" << endl;

}

int main(){

    int vect[5] = {5,4,3,2,1};
    mostrar_vector(vect,5);
    burbujear(vect, 5);
    mostrar_vector(vect,5);

    return 0;
}

