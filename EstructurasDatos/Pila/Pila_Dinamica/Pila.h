#ifndef _PILA_H_
#define _PILA_H_

#include "Nodo.h"

template <typename T>
class Pila {

	private:

		Nodo<T>* ptr_ultimo;

	public:

		Pila ();
		~Pila ();

		void apilar (T dato);
		T desapilar ();
		T consultar ();
		bool esta_vacia ();
		void vaciar_pila ();
};

template <typename T>
Pila<T> :: Pila () {
	ptr_ultimo = NULL;
}

template <typename T>
Pila<T> :: ~Pila () {
	vaciar_pila ();
}

template <typename T>
void Pila<T> :: apilar (T dato) {

	Nodo<T>* nuevo_nodo = new Nodo<T> (dato, ptr_ultimo);
	ptr_ultimo = nuevo_nodo;
}

template <typename T>
T Pila<T> :: desapilar () {

	Nodo<T>* nodo_auxiliar = ptr_ultimo;
	ptr_ultimo = ptr_ultimo -> obtener_ptr_siguiente ();
	T dato = nodo_auxiliar -> obtener_dato ();
	delete nodo_auxiliar;

	return dato;
}

template <typename T>
T Pila<T> :: consultar () {
	return ptr_ultimo -> obtener_dato ();
}

template <typename T>
void Pila<T> :: vaciar_pila () {
	
	while ( !esta_vacia () ) {
		desapilar ();
	}
}

template <typename T>
bool Pila<T> :: esta_vacia () {
	return ( ptr_ultimo == NULL ? true:false );
}

#endif 