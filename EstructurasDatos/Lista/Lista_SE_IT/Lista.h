#ifndef _LISTA_H_
#define _LISTA_H_


#include <iostream>

using std::cout;
using std::endl;

template <typename T >
class Lista {

	private: 

		struct Nodo;
		Nodo *cabeza;

		struct Nodo {
		
			T dato;
			Nodo *siguiente;

			Nodo ();
			Nodo (const T &dato);
			Nodo (const T &dato, Nodo *siguiente);
		};

		Nodo* primer_nodo ();

	public:

		class Iterador;

		Lista ();
		~Lista ();

		Iterador crear_iterador ();
		Iterador inicio ();
		Iterador final ();
		Iterador insertar (Iterador iterador, const T &dato);
		Iterador eliminar (Iterador iterador);
		Iterador obtener_iterador (int posicion);

		void insertar (const T &dato, int posicion);
		void insertar_inicio (const T &dato);
		void insertar_final (const T &dato);
		T eliminar (int posicion);
		T eliminar_inicio ();
		T eliminar_final ();
		const T& consultar (int posicion);
		const T& consultar_inicio ();
		const T& consultar_final ();

		bool esta_vacia ();
		int tamanio();
		void mostrar ();

		// LUEGO IMPLEMENTAR LOS OPERADORES PARA HACER LAS OPERACIONES FACILES
		/*T & operator *();
		bool operator ==( const Lista <T >:: Iterator & otro ) const ;
		bool operator !=( const Lista <T >:: Iterator & otro ) const ;
		Iterator & operator ++();
		Iterator operator ++( int );
		Iterator & operator --();
		Iterator operator --( int );*/

		class Iterador {

			private: 

				Lista *lista_datos;
				Nodo *nodo_actual;

				Iterador (Lista <T> *lista_datos, Nodo *nodo_actual);
				friend class Lista <T>;

			public: 	
				
				const T& actual ();
				void avanzar ();
				bool hay_mas();
		};
};

template <typename T>
Lista <T> :: Nodo :: Nodo () : siguiente {nullptr} { }

template <typename T>
Lista <T> :: Nodo :: Nodo (const T &dato) : Nodo {dato, nullptr} { }

template <typename T> 
Lista <T> :: Nodo :: Nodo (const T &dato, Nodo* siguiente) {

	this -> dato = dato;
	this -> siguiente = siguiente;
}

template <typename T> 
Lista <T> :: Iterador :: Iterador (Lista <T> *lista_datos, Nodo *nodo_actual) {

	this->lista_datos = lista_datos;
	this->nodo_actual = nodo_actual;
}

template <typename T> 
typename Lista <T> :: Iterador 
Lista <T> :: crear_iterador () {

	return inicio ();
}

template <typename T> 
typename Lista <T> :: Iterador 
Lista <T> :: inicio () {

	return Iterador (this, cabeza);
}

template <typename T> 
typename Lista <T> :: Iterador 
Lista <T> :: final () {

	Iterador iterador(this, cabeza);  

	while ( iterador.hay_mas () ){
		iterador.avanzar ();
	}

	return iterador;
}

template <typename T> 
typename Lista <T> :: Iterador 
Lista <T> :: insertar (Iterador iterador, const T &dato) {

	Nodo* nuevo_nodo = new Nodo (dato, iterador.nodo_actual -> siguiente);
	iterador.nodo_actual -> siguiente = nuevo_nodo;

	return iterador;
}

template <typename T> 
typename Lista <T> :: Iterador 
Lista <T> :: eliminar (Iterador iterador) {

	Nodo* nodo_aux = iterador.nodo_actual -> siguiente;
	iterador.nodo_actual -> siguiente = nodo_aux -> siguiente;
	delete nodo_aux;

	return iterador;
}

template <typename T>
const T& Lista <T> :: Iterador :: actual () {
	return nodo_actual -> siguiente -> dato;
}

template <typename T>
void Lista <T> :: Iterador :: avanzar () {
	nodo_actual = nodo_actual -> siguiente;
}

template <typename T>
bool Lista <T> :: Iterador :: hay_mas () {
	return nodo_actual -> siguiente != nullptr;
}

template <typename T>
Lista <T> :: Lista () {
	cabeza = new Nodo ();
}

template <typename T>
Lista <T> :: ~Lista () { 

	Iterador iterador = crear_iterador();

	while ( iterador.hay_mas() ) {
		eliminar(iterador);
	}
	delete cabeza;
}

template <typename T>
void Lista <T> :: insertar_inicio (const T &dato) {
	
	insertar(inicio (), dato);
}

template <typename T>
void Lista <T> :: insertar_final (const T &dato) {
	
	insertar(final (), dato);
}

template <typename T>
void Lista <T> :: insertar (const T &dato, int posicion) {
	
	insertar (obtener_iterador (posicion), dato);
}

template <typename T>
T Lista <T> :: eliminar_inicio () {

	Iterador it = inicio();
	T dato = it.actual();
	eliminar (it);
	
	return dato;
}

template <typename T>
T Lista <T> :: eliminar_final () {
	
	Iterador it = obtener_iterador(tamanio());
	T dato = it.actual();
	eliminar (it);
	
	return dato;
}

template <typename T>
T Lista <T> :: eliminar (int posicion) {
	
	Iterador it = obtener_iterador(posicion);
	T dato = it.actual();
	eliminar (it);
	
	return dato;
}

template <typename T>
const T& Lista <T> ::consultar_inicio () {
	return inicio().actual ();
}

template <typename T>
const T& Lista <T> ::consultar_final () {
	return obtener_iterador (tamanio()).actual ();
}

template <typename T>
const T& Lista <T> ::consultar (int posicion) {
	return obtener_iterador (posicion).actual ();
}

template <typename T>
typename Lista<T> :: Iterador
Lista <T> :: obtener_iterador (int posicion) {
	
	Iterador iterador = crear_iterador ();

	for (int i = 1; i < posicion; i++) {
		iterador.avanzar ();
	}

	return iterador;
}

template <typename T>
typename Lista <T> :: Nodo* 
Lista <T> :: primer_nodo () {
	return cabeza -> siguiente;
}

template <typename T>
bool Lista <T> :: esta_vacia () {
	return primer_nodo () == nullptr;
}

template < typename T >
int Lista<T> :: tamanio () {
    
    int tam = 0;
    for (Iterador it = crear_iterador (); it.hay_mas (); it.avanzar()){
        tam++;
    }
    return tam;
}

template < typename T >
void Lista<T> :: mostrar () {
    
    for (Iterador it = crear_iterador (); it.hay_mas (); it.avanzar()){
        cout << it.actual() << endl;
    }
}

#endif // _LISTA_H