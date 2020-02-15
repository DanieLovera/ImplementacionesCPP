#ifndef _HEAP_BINARIO_H
#define _HEAP_BINARIO_H

const int CAPACIDAD_INICIAL = 2;
const int POSICION_EXTRA = 0;
const int PRIMERA_POSICION = 1;

#include <iostream>
 using std::cout;
 using std::endl;

// IMPLEMENTACION COMO HEAP DE MINIMA

template <typename T>
class HeapBinario {

	private:

		T *datos;
		int capacidad;
		int tamanio;

		void redimensionar (int nueva_capacidad);
		void copiar_datos (T* datos, int desde, int hasta);
		void filtrar_arriba (int hueco);
		void filtrar_abajo (int hueco);
		int posicion_padre (int posicion_hijo);
		int posicion_hijo (int posicion_padre);
		void construir_heap (const T arreglo [], int tope);

	public:
		
		HeapBinario ();
		HeapBinario (int capacidad_heap);
		HeapBinario (const T arreglo [], int tope, int capacidad);
		~HeapBinario ();
		
		void insertar (const T &dato);
		T eliminar_minimo ();
		const T& consultar_minimo ();

		bool esta_vacio ();
		void vaciar_heap ();
		void mostrar_heap ();	
};

template <typename T>
HeapBinario <T> :: HeapBinario () : HeapBinario (CAPACIDAD_INICIAL + 1) { }

template <typename T>
HeapBinario <T> :: HeapBinario (int capacidad_heap) { 

	datos = new int [capacidad_heap];
	capacidad = capacidad_heap;
	tamanio = 0;
}


template <typename T>
HeapBinario <T> :: HeapBinario (const T arreglo [], int tope, int capacidad) {

	this -> datos = new int [capacidad + 1];
	this -> tamanio = tope;
	this -> capacidad = capacidad + 1;
	construir_heap (arreglo, tope);
}

template <typename T>
void HeapBinario <T> :: construir_heap (const T arreglo [], int tope) {

	for (int i = 0; i < tope; i++) { // ESTO COPIA EL VECTOR QUE PASARON

		datos[i + 1] = arreglo [i];
	}

	int i;
	//for (i = tope / 2; i > 0; i--) { // ESTO LO ORDENA CON LA CONDICION DEL HEAP MINIMO

	for (i = 1; i <= tope / 2; i++) { // ESTO LO ORDENA CON LA CONDICION DEL HEAP MINIMO
		
		filtrar_abajo (i);
	} // SE DIVIDE ENTRE DOS EL TOPE PARA NO TOMAR ENCUENTA A LOS NODOS HOJAS!!! SOLO LOS NODOS CON HIJOS,
	  // TIENEN LA POSIBILIDAD DE SER MOVIDOS PORQUE PUEDEN NO CUMPLIR CON LA CONDICION DEL HEAP 
}

template <typename T>
HeapBinario <T> :: ~HeapBinario () {

	delete [] datos;
}

template <typename T>
void HeapBinario <T> :: vaciar_heap () {
	
	redimensionar (CAPACIDAD_INICIAL + 1);
	tamanio = 0; 
}

template <typename T>
void HeapBinario <T> :: insertar (const T &dato) {

	if (tamanio == capacidad - 1) {

		redimensionar (2 * capacidad);
	}

	int hueco = ++tamanio;
	datos [POSICION_EXTRA] = dato;
	filtrar_arriba (hueco);
}

template <typename T>
void HeapBinario <T> :: filtrar_arriba (int hueco) {

	while (datos [POSICION_EXTRA] < datos [posicion_padre (hueco)]) {

		datos [hueco] = datos [posicion_padre (hueco)];
		hueco = posicion_padre (hueco);
	}
	datos [hueco] = datos [POSICION_EXTRA];
}

template <typename T>
T HeapBinario <T> :: eliminar_minimo () {

	int hueco = PRIMERA_POSICION;
	T dato_eliminado = datos [hueco];
	datos [PRIMERA_POSICION] = datos [tamanio--];
	filtrar_abajo (hueco);
	
	return dato_eliminado;
}

template <typename T>
void HeapBinario <T> :: filtrar_abajo (int hueco) {

	bool insertar_ultimo = false;
	//T dato_a_filtrar = datos [hueco];
	datos [POSICION_EXTRA] = datos [hueco];

	while (!insertar_ultimo && posicion_hijo (hueco) <= tamanio) {

		int hijo = posicion_hijo (hueco);
		
		if (hijo != tamanio && datos [hijo + 1] < datos [hijo]) {
			
			hijo++;
		}	

		if (datos [hijo] < datos [POSICION_EXTRA]) {

			datos [hueco] = datos [hijo];
			hueco = hijo;
		
		} else {

			insertar_ultimo = true;
		}
	}
	datos [hueco] = datos [POSICION_EXTRA];
}

template <typename T>
const T& HeapBinario <T> :: consultar_minimo () {

	return datos [PRIMERA_POSICION]; 
}	

template <typename T>
bool HeapBinario <T> :: esta_vacio () {
	
	return tamanio == 0;
}

template <typename T>
void HeapBinario <T> :: redimensionar (int nueva_capacidad) {

	if (capacidad != nueva_capacidad) {

		T *datos_tmp = new T [nueva_capacidad];

		if (tamanio >= nueva_capacidad) {

			copiar_datos (datos_tmp, 1, nueva_capacidad - 1);
			tamanio = nueva_capacidad;

		} else {

			copiar_datos (datos_tmp, 1, tamanio);
		}

		delete [] datos;
		capacidad = nueva_capacidad;
		datos = datos_tmp;
	}
}

template <typename T>
void HeapBinario <T> :: copiar_datos (T* datos, int desde, int hasta) {

	for (int i = desde; i <= hasta; i++) {

		datos[i] = this -> datos [i];
	}
}

template <typename T>
int HeapBinario <T> :: posicion_padre (int posicion_hijo) {

	return posicion_hijo/2;
}

template <typename T>
int HeapBinario <T> :: posicion_hijo (int posicion_padre) {

	return posicion_padre * 2;
}	

template <typename T>
void HeapBinario <T> :: mostrar_heap () {

	for (int i = PRIMERA_POSICION; i <= tamanio; i++) {

		cout << datos[i] << endl;
	}
}

#endif //_HEAP_BINARIO_
