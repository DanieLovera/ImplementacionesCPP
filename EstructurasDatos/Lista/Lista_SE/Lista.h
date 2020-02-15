#ifndef _LISTA_SE_H_
#define _LISTA_SE_H_

#include "Nodo.h"
#include <iostream>
using namespace std;

const int PRIMERA_POSICION = 1;

template <typename T>
class Lista{

    private:

        Nodo<T>* primero;
        int tope;

    public:
    	
        Lista();
        ~Lista();

        void insertar(T objeto, int posicion);
        void insertarOrdenado(T objeto);
        void insertarPrimero(T objeto);
        void insertarUltimo(T objeto);

        T eliminarPorPosicion(int posicion);
        bool eliminarPorObjeto(T objeto);
        bool eliminarObjetos(T objeto);
        void eliminarLista();
        T eliminarPrimero();
        T eliminarUltimo();

        Nodo<T>* obtenerNodo(int posicion);
        Nodo<T>* obtenerPrimerNodo();
        Nodo<T>* obtenerUltimoNodo();
        T obtenerPrimerObjeto();
        T obtenerUltimoObjeto();
        T obtenerObjeto(int posicion);
        T obtenerMaximo();
        T obtenerMinimo();
        float obtenerPromedio();

        bool esVacia();
        void mostrar();
        int tamanio();
};

template <typename T>
Lista<T>::Lista() {
    primero = nullptr;
    tope = 0;
}

template <typename T>
Lista<T>::~Lista(){
    eliminarLista();
}

template < typename T>
int Lista<T>::tamanio(){
    return tope;
}

template <typename T>
void Lista<T>::insertar(T objeto, int posicion) {
    Nodo<T>* nuevoNodo = new Nodo<T>(objeto);

    if (posicion == PRIMERA_POSICION) {
        nuevoNodo->asignarSiguiente(primero);
        primero = nuevoNodo;

    } else {
        Nodo<T>* nodoAnterior = obtenerNodo(posicion - 1);
        nuevoNodo->asignarSiguiente(nodoAnterior->obtenerSiguiente());
        nodoAnterior->asignarSiguiente(nuevoNodo);
    }
    tope++;
}

template <typename T>
void Lista<T>::insertarPrimero(T objeto) {
    insertar(objeto, PRIMERA_POSICION);
}

template <typename T>
void Lista<T>::insertarUltimo(T objeto){
    insertar(objeto, tope + 1);
}

template <typename T>
void Lista<T>::insertarOrdenado(T objeto){

    Nodo<T>* nodoAux = primero;
    int posicion = PRIMERA_POSICION;

    bool inserto = false;

    while ( (!inserto && posicion <= tope) && !esVacia() ){

        if(objeto < nodoAux->obtenerObjeto()){
            insertar(objeto, posicion);
            inserto = true;
        }
        nodoAux = nodoAux->obtenerSiguiente();
        posicion++;
    }

    if ( !inserto )
        insertarUltimo(objeto);
}

template < typename T >
T Lista<T>::eliminarPorPosicion(int posicion){
    Nodo<T>* nodoAux = primero;

    if ( posicion == PRIMERA_POSICION ){
        primero = nodoAux->obtenerSiguiente();

    } else {
        Nodo<T>* nodoAnterior = obtenerNodo(posicion - 1);
        nodoAux = nodoAnterior->obtenerSiguiente();
        nodoAnterior->asignarSiguiente(nodoAux->obtenerSiguiente());
    }
    T objeto = nodoAux->obtenerObjeto();
    delete nodoAux;
    tope --;

    return objeto;
}

template < typename T >
bool Lista<T>::eliminarPorObjeto(T objeto){

    Nodo<T>* nodoActual = primero;
    int posicionActual = PRIMERA_POSICION;
    bool elimino = false;

    while ( (!elimino) && (posicionActual <= tope) ) {
        T objetoActual = nodoActual->obtenerObjeto();
        nodoActual = nodoActual->obtenerSiguiente();

        if ( objetoActual == objeto ){
            eliminarPorPosicion(posicionActual);
            elimino = true;
        }
        posicionActual++;
    }
    return elimino;
}

template < typename T>
bool Lista<T>::eliminarObjetos(T objeto){
    Nodo<T>* nodoActual = primero;
    bool elimino = false;

    for ( int posicionActual = PRIMERA_POSICION; posicionActual <= tope; posicionActual++ ){
        T objetoActual = nodoActual->obtenerObjeto();
        nodoActual = nodoActual->obtenerSiguiente();

        if ( objetoActual == objeto ) {
            eliminarPorPosicion(posicionActual);
            posicionActual--;
            elimino = true;
        }
    }
    return elimino;
}

template < typename T >
T Lista<T>::eliminarPrimero(){
    return eliminarPorPosicion(PRIMERA_POSICION);
}

template < typename T >
T Lista<T>::eliminarUltimo(){
    return eliminarPorPosicion(tope);
}

template < typename T >
void Lista<T>::eliminarLista(){
    while ( !esVacia() ){
        eliminarPrimero();
    }
}

template <typename T>
Nodo<T>* Lista<T>::obtenerNodo(int posicionNodo){
    Nodo<T>* nodoBuscado = primero;

    for (int i = PRIMERA_POSICION; i < posicionNodo; i++)
        nodoBuscado = nodoBuscado->obtenerSiguiente();

    return nodoBuscado;
}

template < typename T >
Nodo<T>* Lista<T>::obtenerPrimerNodo(){
    return primero;
}

template < typename T >
Nodo<T>* Lista<T>::obtenerUltimoNodo(){
    return obtenerNodo(tope);
}

template < typename T >
T Lista<T>::obtenerPrimerObjeto(){
    return obtenerPrimerNodo()->obtenerObjeto();
}

template < typename T >
T Lista<T>::obtenerUltimoObjeto(){
    return obtenerUltimoNodo()->obtenerObjeto();
}

template < typename T >
T Lista<T>::obtenerObjeto (int posicion){
    return obtenerNodo(posicion)->obtenerObjeto();
}

template < typename T >
T Lista<T>::obtenerMaximo(){
    Nodo<T>* nodoAux = primero;
    T maximo = nodoAux->obtenerObjeto();

    for ( int posicionActual = PRIMERA_POSICION; posicionActual <= tope; posicionActual++ ) {
        if ( nodoAux->obtenerObjeto() > maximo ){
            maximo = nodoAux->obtenerObjeto();
        }
        nodoAux = nodoAux->obtenerSiguiente();
    }
    return maximo;
}

template < typename T >
T Lista<T>::obtenerMinimo(){
    Nodo<T>* nodoAux = primero;
    T minimo = nodoAux->obtenerObjeto();

    for ( int posicionActual = PRIMERA_POSICION; posicionActual <= tope; posicionActual++ ) {
        if ( nodoAux->obtenerObjeto() < minimo ){
            minimo = nodoAux->obtenerObjeto();
        }
        nodoAux = nodoAux->obtenerSiguiente();
    }
    return minimo;
}

template < typename T >
float Lista<T>::obtenerPromedio(){
    Nodo<T>* nodoAux = primero;
    float sumaTotal = 0;

    for ( int posicionActual = PRIMERA_POSICION; posicionActual <= tope; posicionActual++ ){
        sumaTotal += (float)nodoAux->obtenerObjeto();
        nodoAux = nodoAux->obtenerSiguiente();
    }
    return (sumaTotal/(float)tope);
}

template < typename T >
bool Lista<T>::esVacia(){
    return (primero == nullptr);
}

template < typename T >
void Lista<T>::mostrar() {
    Nodo<T>* aux = primero;
    for (int i = 1; i <= tope; i++){
        cout << aux->obtenerObjeto() << endl;
        aux = aux->obtenerSiguiente();
    }
}

#endif // _LISTA_SE_H_
