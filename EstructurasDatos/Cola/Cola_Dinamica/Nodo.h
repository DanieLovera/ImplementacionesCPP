#ifndef _NODO_H_
#define _NODO_H_

#include <iostream>

template <typename T>
class Nodo {

    private:

        T dato;
        Nodo* ptr_siguiente;

    public:

        Nodo (T dato);
        Nodo (T dato, Nodo* ptr_siguiente);
        ~Nodo ();

        T obtener_dato ();
        void asignar_dato (T dato);
        Nodo* obtener_ptr_siguiente ();
        void asignar_ptr_siguiente (Nodo* nodo);
};

template <typename T>
Nodo <T> ::Nodo (T dato) : Nodo(dato, NULL) { }

template <typename T>
Nodo <T> ::Nodo (T dato, Nodo* ptr_siguiente) {
    asignar_dato (dato);
    asignar_ptr_siguiente (ptr_siguiente);
}

template <typename T>
Nodo <T> :: ~Nodo () { }

template <typename T>
T Nodo <T> :: obtener_dato () {
    return dato;
}

template <typename T>
void Nodo<T> :: asignar_dato (T dato) {
    this->dato = dato;
}

template <typename T>
Nodo<T>* Nodo<T> :: obtener_ptr_siguiente () {
    return ptr_siguiente;
}

template <typename T>
void Nodo<T> :: asignar_ptr_siguiente (Nodo<T>* ptr_siguiente) {
    this->ptr_siguiente = ptr_siguiente;
}

#endif 
