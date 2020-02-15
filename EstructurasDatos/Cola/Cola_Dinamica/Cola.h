#ifndef _COLA_H
#define _COLA_H

#include "Nodo.h"

template <typename T>
class Cola {
	
	private: 
		
		Nodo<T> * primero;
		Nodo<T> * ultimo;
		
	public:

		Cola();
		~Cola();

		void encolar (T dato);
		T desencolar ();
		T consultar ();
		bool esta_vacia ();
};

template <typename T>
Cola<T> :: Cola () {
	
	primero = NULL;
	ultimo = NULL;
}

template <typename T>
Cola<T> :: ~Cola () {

	while ( !esta_vacia () ){
		desencolar ();
	}
}

template <typename T>
void Cola<T> :: encolar (T dato) {

	Nodo<T>* nuevo_nodo = new Nodo<T> (dato);

	if ( esta_vacia () ) {
		primero = nuevo_nodo;
	
	} else {
		ultimo -> asignar_ptr_siguiente (nuevo_nodo);
	}
	
	ultimo = nuevo_nodo;	
}

template <typename T>
T Cola<T> :: desencolar () {
	
	Nodo<T>* nodo_auxiliar = primero;
	primero = nodo_auxiliar -> obtener_ptr_siguiente ();
	T dato = nodo_auxiliar -> obtener_dato ();
	delete nodo_auxiliar;

	return dato;
}

template <typename T> 
T Cola<T> :: consultar () {
	return primero -> obtener_dato ();
}

template <typename T>
bool Cola<T> ::  esta_vacia () {
	return ( primero == NULL ? true:false );
}

#endif
