#ifndef _Arbol_H_
#define _Arbol_H_

#include <iostream>
	using std :: cout;
	using std :: endl;
#include <cmath>

const int ALTURA_NODO_NULL = -1;
const int PESO_NODO_NULL = 0;

template < typename T >
class Arbol {

	private:

		struct NodoBinario;
		NodoBinario* raiz;

		struct NodoBinario {

			T dato;
			NodoBinario *hijo_izquierdo;
			NodoBinario *hijo_derecho;

			NodoBinario ();
			NodoBinario (const T &dato);
			NodoBinario (const T &dato, NodoBinario *hijo_izquierdo, NodoBinario *hijo_derecho);
		};

		void insertar (const T &dato, NodoBinario *&raiz);
		void eliminar (const T &dato, NodoBinario *&raiz);
		bool buscar (const T &dato, NodoBinario *raiz) const;


		void en_orden (NodoBinario *raiz) const;
		void pre_orden (NodoBinario *raiz) const;
		void pos_orden (NodoBinario *raiz) const;

		NodoBinario* encontrar_minimo (NodoBinario *raiz);
		NodoBinario* encontrar_maximo (NodoBinario *raiz);
		void mostrar_dato (NodoBinario* raiz) const;

		void eliminar_minimo (T &dato, NodoBinario *&raiz);

		int altura(NodoBinario *raiz) const;
		bool arbol_perfecto (NodoBinario *raiz) const;
		int peso (NodoBinario *raiz) const;
		NodoBinario* copiar_arbol (NodoBinario *raiz) const; 


	public:

		Arbol ();
		Arbol (const Arbol &arbol_a_copiar);
		~Arbol ();

		void insertar (const T &dato);
		void eliminar (const T &dato);
		bool buscar (const T &dato) const;

		void  en_orden () const;
		void  pre_orden () const;
		void  pos_orden () const;

		const T& encontrar_minimo ();
		const T& encontrar_maximo ();

		void vaciar_arbol (NodoBinario *&raiz);
		bool esta_vacio () const;

		int altura () const;
		bool arbol_perfecto () const;
		int peso () const;
		void copiar_arbol () const; 
};

template <typename T>
Arbol <T> :: NodoBinario :: NodoBinario () {

	this -> hijo_izquierdo = nullptr;
	this -> hijo_derecho = nullptr;
}

template <typename T>
Arbol <T> :: NodoBinario :: NodoBinario (const T &dato) { 

	this -> dato = dato;
	this -> hijo_izquierdo = nullptr;
	this -> hijo_derecho = nullptr;
}

template <typename T>
Arbol <T> :: NodoBinario :: NodoBinario (const T &dato, NodoBinario *hijo_izquierdo, NodoBinario *hijo_derecho) {
	
	this -> dato = dato;
	this -> hijo_izquierdo = hijo_izquierdo;
	this -> hijo_derecho = hijo_derecho;
}

template <typename T>
Arbol <T> :: Arbol () {

	this -> raiz = nullptr;
}

template <typename T>
Arbol <T> :: Arbol (const Arbol &arbol_a_copiar) {

	this -> raiz = copiar_arbol(arbol_a_copiar.raiz);
}

template <typename T>
Arbol <T> :: ~Arbol () {

	vaciar_arbol (raiz);
}

template <typename T>
void Arbol <T> :: vaciar_arbol (NodoBinario *&raiz) {

	if (raiz != nullptr) {

		vaciar_arbol (raiz -> hijo_izquierdo);
		vaciar_arbol (raiz -> hijo_derecho);
		delete raiz;
		raiz = nullptr;
	}
}

template <typename T>
void Arbol <T> :: insertar (const T &dato) {
	
	insertar (dato, raiz);
}

template <typename T>
void Arbol <T> :: insertar (const T &dato, NodoBinario *&raiz) {

	if (raiz == nullptr) {

		raiz = new NodoBinario (dato);	
	
	} else if (dato < raiz -> dato) {

		insertar (dato, raiz -> hijo_izquierdo);
	
	} else if (raiz -> dato < dato) {

		insertar (dato, raiz -> hijo_derecho);
	
	}
}

template <typename T>
bool Arbol <T> :: buscar (const T &dato) const{

	return buscar (dato, raiz);
}

template <typename T>
bool Arbol <T> :: buscar (const T &dato, NodoBinario *raiz) const {

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
void Arbol <T> :: eliminar (const T &dato) {
	
	eliminar (dato, raiz);
}

template <typename T>
void Arbol <T> :: eliminar (const T &dato, NodoBinario *&raiz) {

	if (raiz != nullptr) {
		
		//if (raiz -> dato < dato) {
		if (dato < raiz -> dato) {

			eliminar (dato, raiz -> hijo_izquierdo);
		
		//} else if (dato < raiz -> dato) {
		} else if (raiz -> dato < dato) {

			eliminar (dato, raiz -> hijo_derecho);
		
		} else {

			if (raiz -> hijo_izquierdo != nullptr && raiz -> hijo_derecho != nullptr) {
		
				eliminar_minimo (raiz -> dato, raiz -> hijo_derecho);
		
			} else {

				NodoBinario* nodo_eliminar = raiz;
				raiz = raiz -> hijo_izquierdo == nullptr ? raiz -> hijo_derecho : raiz -> hijo_izquierdo;
				delete nodo_eliminar;
			}
		}
	}
}

template <typename T>
void Arbol <T> :: eliminar_minimo (T &dato, NodoBinario *&raiz) {
	
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
void Arbol <T> :: en_orden () const {

	en_orden (raiz);
}

template <typename T>
void Arbol <T> :: en_orden (NodoBinario *raiz) const {

	if (raiz != nullptr) {

		en_orden (raiz -> hijo_izquierdo);
		mostrar_dato (raiz);
		en_orden (raiz -> hijo_derecho);
	}
}

template <typename T>
void Arbol <T> :: pre_orden () const {

	pre_orden (raiz);
}

template <typename T>
void Arbol <T> :: pre_orden (NodoBinario *raiz) const {

	if (raiz != nullptr) {

		mostrar_dato (raiz);
		pre_orden (raiz -> hijo_izquierdo);
		pre_orden (raiz -> hijo_derecho);
	}
}

template <typename T>
void Arbol <T> :: pos_orden () const {

	pos_orden (raiz);
}

template <typename T>
void Arbol <T> :: pos_orden (NodoBinario *raiz) const {

	if (raiz != nullptr) {

		pos_orden (raiz -> hijo_izquierdo);
		pos_orden (raiz -> hijo_derecho);
		mostrar_dato (raiz);
	}
}

template <typename T>
void Arbol <T> :: mostrar_dato (NodoBinario *raiz) const {
	
	cout << raiz -> dato << endl;
}

template <typename T>
const T& Arbol <T> :: encontrar_minimo () {

	return encontrar_minimo(raiz) -> dato;
	// EL ARBOL NO PUEDE ESTAR VACIO
}

template <typename T>
typename Arbol <T> :: NodoBinario* 
Arbol <T> :: encontrar_minimo (NodoBinario *raiz) {

	if (raiz -> hijo_izquierdo != nullptr) {
		return encontrar_minimo (raiz -> hijo_izquierdo); 
	}
	return raiz;
} 

template <typename T>
const T& Arbol <T> :: encontrar_maximo () {

	return encontrar_maximo(raiz) -> dato;
	// EL ARBOL NO PUEDE ESTAR VACIO
}

template <typename T>
typename Arbol <T> :: NodoBinario* 
Arbol <T> :: encontrar_maximo (NodoBinario *raiz) {

	if (raiz -> hijo_derecho != nullptr) {
		return encontrar_maximo (raiz -> hijo_derecho); 
	}
	return raiz;
} 


template <typename T>
bool Arbol <T> :: esta_vacio () const {

	return this -> raiz == nullptr;
}

template <typename T>
int Arbol <T> :: altura () const {

	return altura (raiz);
}

template <typename T>
int Arbol <T> :: altura (NodoBinario *raiz) const {

	if (raiz != nullptr) {

		int altura_sub_izquierdo = altura (raiz -> hijo_izquierdo);
		int altura_sub_derecho = altura (raiz -> hijo_derecho);

		return altura_sub_izquierdo > altura_sub_derecho ? altura_sub_izquierdo + 1 : altura_sub_derecho + 1;
	}
	return ALTURA_NODO_NULL;
}

template <typename T> 
bool Arbol <T> :: arbol_perfecto () const {
	
	return arbol_perfecto (raiz);
}

template <typename T> 
bool Arbol <T> :: arbol_perfecto (NodoBinario *raiz) const {

	if (raiz != nullptr) {

		if (altura (raiz -> hijo_izquierdo) != altura (raiz -> hijo_derecho)) {
			
			return false;
		
		} else {

			return (arbol_perfecto (raiz -> hijo_izquierdo) && arbol_perfecto (raiz -> hijo_derecho));
		}
	}
	return true;
}

template <typename T>
int Arbol <T> :: peso () const {

	return peso (raiz);
}

template <typename T>
int Arbol <T> :: peso (NodoBinario *raiz) const {

	if (raiz != nullptr) {

			return peso (raiz -> hijo_izquierdo) + peso (raiz -> hijo_derecho) + 1;
	}
	return PESO_NODO_NULL;
}

template <typename T>
void Arbol <T> :: copiar_arbol () const {

	copiar_arbol (raiz);
}

template <typename T>
typename Arbol <T> :: NodoBinario* 
Arbol <T> :: copiar_arbol (NodoBinario *raiz) const {

	if (raiz != nullptr) {

		return new NodoBinario (raiz -> dato, copiar_arbol (raiz -> hijo_izquierdo)
			, copiar_arbol (raiz ->hijo_derecho));
	}
	return nullptr;
}

#endif //_Arbol_H_
