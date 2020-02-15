#ifndef _PILA_H_
#define _PILA_H_

#include <iostream>
using std::cout;
using std::endl;

const unsigned int TAMANIO = 10;

template <typename T> 
class Pila {

	private:

		T arreglo[TAMANIO];
		int tope;

	public:

		Pila ();
		~Pila ();

		void apilar (T dato);
		T* desapilar ();
		T* consultar ();
		bool esta_vacia ();
		bool esta_llena ();
		int obtenerTope ();
		void mostrar ();
};


template <typename T>
Pila <T> :: Pila () {
	tope = 0;
}

template <typename T>
Pila<T> :: ~Pila () { }

template <typename T>
void Pila <T> :: apilar (T dato) {

	if ( !esta_llena() ){
		arreglo[tope++] = dato;
	
	} else {
		cout << "Pila llena." << endl;
	}
}

template <typename T>
T* Pila <T> :: desapilar () {
	T* ptr_dato = consultar ();

	if ( ptr_dato != NULL ) {
		--tope;	
	}

	return ptr_dato;
}

template <typename T>
T* Pila <T> :: consultar () {
	T* ptr_dato = NULL;
	if ( !esta_vacia() ) {
		ptr_dato = 	&( arreglo[tope - 1] );
	}
	else {
		cout << "Pila vacia." << endl;
	}
	return ptr_dato;
}

template <typename T>
bool Pila <T> :: esta_vacia () {
	return ( tope == 0 ? true:false );																						
}

template <typename T>
bool Pila <T> :: esta_llena () {
	return ( tope == TAMANIO ? true:false );
}

template <typename T> 
void Pila<T> :: mostrar () {

	if ( !esta_vacia () ){

		cout << "[ ";
		for ( int i = 0; i < tope; i++ ) {
			cout << arreglo[i] << "  ";
		}
		cout << "]" << endl;

	} else {
		cout << "Pila vacia." << endl;
	}
}

template <typename T>
int Pila<T> :: obtenerTope () {
	return tope;
}

#endif