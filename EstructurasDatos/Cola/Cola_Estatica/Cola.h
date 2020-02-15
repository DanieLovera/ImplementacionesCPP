#ifndef _COLA_H_
#define _COLA_H_

#include <iostream>
using std :: cout;
using std :: endl;

const unsigned int TAMANIO = 10;
const unsigned int PRIMERO = 0;

template <typename T> 
class Cola {
	
	private:

		T arreglo[TAMANIO];
		int ultimo;

		void correr_cola ();

	public:

		Cola ();
		~Cola ();

		void encolar (T dato);
		T* desencolar ();
		T* consultar ();
		bool esta_vacia ();
		bool esta_llena ();
		void mostrar ();
};

template <typename T>
Cola <T> :: Cola () {
	ultimo = 0;
}

template <typename T>
Cola <T> :: ~Cola () { }

template <typename T>
void Cola <T> :: encolar (T dato) {
	
	if ( !esta_llena() ){
		arreglo[ultimo++] = dato;
	
	} else{
		cout << "Cola llena." << endl;
	}
}

template <typename T>
T* Cola <T> :: desencolar () {
	
	T* ptr_dato = consultar();

	if ( ptr_dato != NULL ){
		correr_cola();
		ultimo--;
	}

	return ptr_dato;
}

template <typename T>
T* Cola<T> :: consultar () {
	T* ptr_dato = NULL;
	
	if ( !esta_vacia () ) {
		ptr_dato = &( arreglo[PRIMERO] );
	
	} else {
		cout << "Cola vacia." << endl;
	}

	return ptr_dato;
}

template <typename T>
void Cola <T> :: correr_cola () {

	for ( int i = 0; i < ultimo - 1; i++ ) {
		arreglo[i] = arreglo[i+1];
	}
}

template <typename T>
bool Cola<T> :: esta_vacia () {
	return ( ultimo == 0 ? true:false );
}

template <typename T>
bool Cola<T> :: esta_llena () {
	return ( ultimo == TAMANIO ? true:false );
}

template <typename T> 
void Cola<T> :: mostrar () {

	if ( !esta_vacia () ){

		cout << "[ ";
		for ( int i = 0; i < ultimo; i++ ) {
			cout << arreglo[i] << "  ";
		}
		cout << "]" << endl;

	} else {
		cout << "Cola vacia." << endl;
	}
}

#endif
