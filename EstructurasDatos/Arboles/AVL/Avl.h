#ifndef _AVL_H_
#define _AVL_H_

const int ALTURA_NODO_NULL = -1;
const int DESBALANCE_PERMITIDO = 1;

#include <iostream>
	using std::cout;
	using std::endl;

#include "/home/daniel/Documents/Algoritmos2/Implementaciones/Cola/Cola_Dinamica/Cola.h"

template <typename T>
class Avl {

	private: 

		struct NodoBinario;
		NodoBinario* raiz;

		struct NodoBinario {

			T dato;
			NodoBinario* hijo_izquierdo;
			NodoBinario* hijo_derecho;
			int altura;

			NodoBinario ();
			NodoBinario (const T &dato);
			NodoBinario (const T &dato, NodoBinario *hijo_izquierdo, NodoBinario *hijo_derecho);
		};

		void insertar (const T &dato, NodoBinario *&raiz);
		void eliminar (const T &dato, NodoBinario *&raiz);
		void eliminar_minimo (T &dato, NodoBinario *&raiz);
		bool buscar (const T &dato, NodoBinario *raiz) const;

		int altura (NodoBinario *raiz);
		void actualizar_altura (NodoBinario *raiz);
		const int& maximo (const int &altura_izquierda, const int &altura_derecha);
		
		void balancear (NodoBinario *&raiz);
		void rotacion_simple_DD(NodoBinario *&raiz);
		void rotacion_simple_II(NodoBinario *&raiz);
		void rotacion_doble_DI(NodoBinario *&raiz);
		void rotacion_doble_ID(NodoBinario *&raiz);

		void pre_orden (NodoBinario *raiz);
		void limpiar_arbol(NodoBinario *&raiz);

	public:

		Avl ();
		~Avl ();

		void insertar (const T &dato);
		void eliminar (const T &dato);
		bool buscar (const T &dato) const;

		int altura (); 
		void pre_orden();
		void en_ancho ();
};

template <typename T>
Avl <T> :: NodoBinario :: NodoBinario () {

	this -> hijo_izquierdo = nullptr;
	this -> hijo_derecho = nullptr;
	this -> altura = 0;
}

template <typename T>
Avl <T> :: NodoBinario :: NodoBinario (const T &dato) : NodoBinario (dato, nullptr, nullptr) { }

template <typename T>
Avl <T> :: NodoBinario :: NodoBinario (const T &dato, NodoBinario *hijo_izquierdo, NodoBinario *hijo_derecho) {

	this -> dato = dato;
	this -> hijo_izquierdo = hijo_izquierdo;
	this -> hijo_derecho = hijo_derecho;
	this -> altura = 0;
}

template <typename T>
Avl <T> :: Avl () {

	raiz = nullptr;
}

template <typename T>
Avl <T> :: ~Avl () {
	limpiar_arbol(raiz);
}

template <typename T>
void Avl <T> :: limpiar_arbol (NodoBinario *&raiz) {

	if (raiz != nullptr) {

		limpiar_arbol (raiz -> hijo_izquierdo);
		limpiar_arbol (raiz -> hijo_derecho);
		delete raiz;
		raiz = nullptr;
	}
}

template <typename T>
void Avl <T> :: insertar (const T &dato) {

	insertar (dato, raiz);
}

template <typename T>
void Avl <T> :: insertar (const T &dato, NodoBinario *&raiz) {

	if (raiz == nullptr) {

		raiz = new NodoBinario (dato);

	} else if (raiz -> dato > dato) {

		insertar (dato, raiz -> hijo_izquierdo);

	} else if (dato > raiz -> dato) {

		insertar (dato, raiz -> hijo_derecho);
	}

	balancear (raiz);
	actualizar_altura (raiz);
}

template <typename T> 
void Avl <T> :: eliminar (const T &dato) {
	
	eliminar (dato, raiz);
}

template <typename T>
void Avl <T> :: eliminar (const T &dato, NodoBinario *&raiz) {

	if (raiz != nullptr) {
		
		if (raiz -> dato > dato) {

			eliminar (dato, raiz -> hijo_izquierdo);
		
		} else if (dato > raiz -> dato) {

			eliminar (dato, raiz -> hijo_derecho);
		
		} else {

			if (raiz -> hijo_izquierdo != nullptr && raiz -> hijo_derecho != nullptr) {
		
				eliminar_minimo(raiz -> dato, raiz -> hijo_derecho);
		
			} else {

				NodoBinario* nodo_eliminar = raiz;
				raiz = raiz -> hijo_izquierdo == nullptr ? raiz -> hijo_derecho : raiz -> hijo_izquierdo;
				delete nodo_eliminar;
			}
		}
	}
	balancear (raiz);
	actualizar_altura (raiz);
}

template <typename T>
void Avl <T> :: eliminar_minimo (T &dato, NodoBinario *&raiz) {
	
	if (raiz != nullptr) {

		if (raiz -> hijo_izquierdo != nullptr) {
		
			eliminar_minimo (dato, raiz -> hijo_izquierdo);

		} else {

			NodoBinario* nodo_eliminar = raiz;
			dato = raiz -> dato;
			raiz = nodo_eliminar -> hijo_derecho;
			delete nodo_eliminar;	
		}
	}
}

template <typename T>
bool Avl <T> :: buscar (const T &dato) const {

	return buscar (dato, raiz);
}

template <typename T>
bool Avl <T> :: buscar (const T &dato, NodoBinario *raiz) const {

	if (raiz != nullptr) {
		
		if (dato < raiz -> dato) {
			
			return buscar (dato, raiz -> hijo_izquierdo);
	
		} else if (raiz -> dato < dato) {
			
			return buscar (dato, raiz -> hijo_derecho);
		}

		return true;
	}

	return false;
}

template <typename T>
int Avl <T> :: altura () {

	return altura (raiz);
}

template <typename T> 
int Avl <T> :: altura (NodoBinario *raiz) {

	return (raiz == nullptr) ? ALTURA_NODO_NULL : raiz -> altura; 
}

template <typename T>
void Avl <T> :: actualizar_altura (NodoBinario *raiz) {
	
	if (raiz != nullptr) {
	
		raiz -> altura = maximo (altura (raiz -> hijo_izquierdo), altura (raiz -> hijo_derecho)) + 1;
	}
}

template <typename T> 
const int& Avl <T> :: maximo (const int &altura_izquierda, const int &altura_derecha) {

	return altura_izquierda >= altura_derecha ? altura_izquierda : altura_derecha;
}

template <typename T>
void Avl <T> :: balancear (NodoBinario *&raiz) {

	if (raiz != nullptr) {
		
		if (altura (raiz -> hijo_derecho) - altura (raiz -> hijo_izquierdo) > DESBALANCE_PERMITIDO) {
			
			if (altura (raiz -> hijo_derecho -> hijo_derecho) >= altura (raiz -> hijo_derecho -> hijo_izquierdo)) {
				
				rotacion_simple_DD (raiz);
			
			} else {

				rotacion_doble_DI (raiz);
			}
		
		} else if (altura (raiz -> hijo_izquierdo) - altura (raiz -> hijo_derecho) > DESBALANCE_PERMITIDO) {

			if (altura (raiz -> hijo_izquierdo -> hijo_izquierdo) >= altura (raiz -> hijo_izquierdo -> hijo_derecho))  {

				rotacion_simple_II (raiz);
			
			} else {

				rotacion_doble_ID (raiz);
			}
		}
	}
} 

template <typename T>
void Avl <T> :: rotacion_simple_DD (NodoBinario *&raiz) {

	NodoBinario *nodo_aux = raiz;
	raiz = nodo_aux -> hijo_derecho;
	nodo_aux -> hijo_derecho = raiz -> hijo_izquierdo;
	raiz -> hijo_izquierdo = nodo_aux;
	actualizar_altura(raiz -> hijo_izquierdo);
}

template <typename T>
void Avl <T> :: rotacion_simple_II (NodoBinario *&raiz) {

	NodoBinario *nodo_aux = raiz;
	raiz = nodo_aux -> hijo_izquierdo;
	nodo_aux -> hijo_izquierdo = raiz -> hijo_derecho;
	raiz -> hijo_derecho = nodo_aux;
	actualizar_altura(raiz -> hijo_derecho);
}

template <typename T>
void Avl <T> :: rotacion_doble_DI (NodoBinario *&raiz) {

	rotacion_simple_II (raiz -> hijo_derecho);
	rotacion_simple_DD (raiz);
}

template <typename T>
void Avl <T> :: rotacion_doble_ID (NodoBinario *&raiz) {

	rotacion_simple_DD (raiz -> hijo_izquierdo);
	rotacion_simple_II (raiz);
}

template <typename T>
void Avl <T> :: pre_orden () {

	pre_orden (raiz);
}

template <typename T>
void Avl <T> :: pre_orden (NodoBinario *raiz) {

	if (raiz != nullptr) {

		cout << raiz -> dato << endl;
		pre_orden (raiz -> hijo_izquierdo);
		pre_orden (raiz -> hijo_derecho);
	}
}

template <typename T>
void Avl <T> :: en_ancho () {

	Cola<NodoBinario*> cola_nodos;
	NodoBinario* nodo_a_procesar = nullptr;
	
	cola_nodos.encolar (raiz);
	while (!cola_nodos.esta_vacia ()) {

		nodo_a_procesar = cola_nodos.desencolar();
		cout << nodo_a_procesar -> dato << endl;
	
		if (nodo_a_procesar -> hijo_izquierdo != nullptr) {
			cola_nodos.encolar (nodo_a_procesar -> hijo_izquierdo);
		}

		if (nodo_a_procesar -> hijo_derecho != nullptr) {
			cola_nodos.encolar (nodo_a_procesar -> hijo_derecho);	
		}
	}
}

#endif //_AVL_H_
