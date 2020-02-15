#ifndef _NODE_H_
#define _NODE_H_

template < typename T >
class Nodo {

    private:
        T objeto;
        Nodo* siguiente;

    public:
        Nodo(T objeto);
        Nodo(T objeto, Nodo* siguiente);
        ~Nodo();

        T obtenerObjeto();
        void asignarObjeto(T objeto);
        Nodo* obtenerSiguiente();
        void asignarSiguiente(Nodo* nodo);
};

template < typename T >
Nodo<T>::Nodo(T objeto) : Nodo(objeto, nullptr) { }

template < typename T >
Nodo<T>::Nodo(T objeto, Nodo* siguiente){
    asignarObjeto(objeto);
    asignarSiguiente(siguiente);
}

template < typename T >
Nodo<T>::~Nodo() { }

template < typename T >
T Nodo<T>::obtenerObjeto(){
    return objeto;
}

template < typename T >
void Nodo<T>::asignarObjeto(T objeto){
    this->objeto = objeto;
}

template < typename T >
Nodo<T>* Nodo<T>::obtenerSiguiente(){
    return siguiente;
}

template < typename T >
void Nodo<T>::asignarSiguiente(Nodo<T>* siguiente){
    this->siguiente = siguiente;
}

#endif // _NODE_H_
