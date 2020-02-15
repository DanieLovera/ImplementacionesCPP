#ifndef _VECTOR_H_
#define _VECTOR_H_

const int CAPACIDAD = 10;

#include <iostream>
	using std :: cout;
	using std :: endl;
#include <cstddef>
    using std :: size_t;

template <typename T>
class Vector {

	private:

		T* datos;
		size_t capacidad;
		size_t tamanio; 

		void hacer_espacio (size_t desde);
		void cerrar_espacio (size_t desde);
		void intercambiar (size_t posicion_1, size_t posicion_2);
		void clonar_datos(T* datos, size_t desde, size_t hasta);

	public:

		Vector ();
		Vector (size_t capacidad);
		~Vector ();

		void insertar (T dato, size_t posicion);
		void insertar_ultimo (T dato);
		T* eliminar (size_t posicion);
		T* eliminar_ultimo ();
		T* consultar (size_t posicion);
		void redimensionar (size_t capacidad);

		bool esta_lleno ();
		bool esta_vacio ();
		size_t obtener_capacidad ();
		size_t obtener_tamanio ();
		void mostrar ();
};

template <typename T>
Vector <T> :: Vector () : Vector (CAPACIDAD) { }

template <typename T>
Vector <T> :: Vector (size_t capacidad){
	this->capacidad = capacidad;
	datos = new T[capacidad];
	tamanio = 0;
}

template <typename T>
Vector <T> :: ~Vector () {
	delete [] datos;
}

template <typename T>
void Vector <T> :: insertar (T dato, size_t posicion) {

	if ( !esta_lleno() ){
		hacer_espacio (posicion);
		datos[posicion - 1] = dato;
		tamanio ++;
	
	} else {
		cout << "El vector esta lleno." << endl;
	}
}

template <typename T>
void Vector <T> :: insertar_ultimo (T dato) {
	insertar (dato, tamanio + 1);
}

template <typename T>
T* Vector <T> :: eliminar (size_t posicion) {

	T* ptr_dato = NULL;

	if ( !esta_vacio() && posicion <= obtener_tamanio() ) {
		cerrar_espacio(posicion);
		tamanio--;
		ptr_dato = & ( datos[tamanio] );
	}

	return ptr_dato;
}

template <typename T>
T* Vector <T> :: eliminar_ultimo () {
	return eliminar(tamanio);
}

template <typename T>
T* Vector <T> :: consultar (size_t posicion) {
	T* ptr_datos = NULL;
	if ( posicion <= obtener_tamanio() ){
		ptr_datos = & datos[posicion - 1];
	}

	return ptr_datos;
}

template <typename T>
size_t Vector <T> :: obtener_capacidad () {
	return capacidad;
}

template <typename T>
size_t Vector <T> :: obtener_tamanio () {
	return tamanio;
}

template <typename T>
bool Vector <T> :: esta_lleno () {
	return ( obtener_tamanio() == obtener_capacidad() ? true:false );
}

template <typename T>
bool Vector <T> :: esta_vacio () {
	return ( obtener_tamanio () == 0 ? true:false );
}

template <typename T>
void Vector <T> :: redimensionar (size_t capacidad) {

	T* aux_datos = NULL;

	if ( this->capacidad != capacidad ){

		aux_datos = new T[capacidad];

		if ( tamanio >= capacidad ) {
			clonar_datos (aux_datos, 1, capacidad);
			this->tamanio = capacidad;
		} else {
			clonar_datos (aux_datos, 1, tamanio);
		}

		delete [] datos;
		this->capacidad = capacidad;
		datos = aux_datos;
	}
}

template <typename T> 
void Vector <T> :: mostrar () {

	if ( !esta_vacio () ){

		cout << "{ ";
		for ( size_t i = 0; i < tamanio; i++ ) {
			if ( i < tamanio - 1 )
				cout << datos[i] << ", ";
			else
				cout << datos[i] << " ";
		}
		cout << "}" << endl;

	} else {
		cout << "El vector esta vacio." << endl;
	}
}

template <typename T>
void Vector <T> :: cerrar_espacio (size_t desde) {	
	for (size_t i = desde; i < obtener_tamanio(); i++) {
		intercambiar(i-1, i);
	}
}

template <typename T>
void Vector <T> :: hacer_espacio (size_t desde) {	
	for (size_t i = desde; i <= obtener_tamanio(); i++) {
		intercambiar(i, desde - 1);
	}
}

template <typename T>
void Vector <T> :: intercambiar (size_t posicion_1, size_t posicion_2) {	
		T aux_dato = datos[posicion_1];
		datos[posicion_1] = datos[posicion_2];   
		datos[posicion_2] = aux_dato;
}

template <typename T>
void Vector <T> :: clonar_datos (T* datos, size_t desde, size_t hasta) {
	
	for (size_t i = desde - 1; i < hasta; i++) {
		datos[i] = this->datos[i];
	}
}

#endif 
