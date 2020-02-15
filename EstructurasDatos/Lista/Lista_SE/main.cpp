#include "Lista.h"

#include <iostream>

using namespace std;
const int MAX_INICIAL = 10;
//const int PRIMERA_POSICION = 1;

int main(){

    Lista<int> lista;

    for (int i = 1; i <= MAX_INICIAL; i++){
        if ( i <= MAX_INICIAL/2 )
            lista.insertar(i*i,i);

        else
            lista.insertar( (i-MAX_INICIAL/2)*(i-MAX_INICIAL/2) , i);
    }

    cout << "Luego de inicializar una lista de " << MAX_INICIAL << " elementos..." << endl;
    cout << "\nElementos de la lista: " << endl;
    lista.mostrar();
    cout << "\nObtener_primer_dato: " << lista.obtenerPrimerObjeto() << endl;
    cout << "Obtener_ultimo_dato: " << lista.obtenerUltimoObjeto() << endl;
    cout << "Obtener_tamanio: " << lista.tamanio() << endl;

    cout << "\nLuego del alta_primero(500) y del alta_ultimo(525)..." << endl;
    lista.insertarPrimero(500);
    lista.insertarUltimo(525);
    lista.mostrar();
    cout << "\nObtener_primer_dato: " << lista.obtenerPrimerObjeto() << endl;
    cout << "Obtener_ultimo_dato: " << lista.obtenerUltimoObjeto() << endl;
    cout << "Obtener_tamanio: " << lista.tamanio() << endl;

    cout << "\nLuego de insertar_ordenado (0) e insertar (116,13)..." << endl;
    lista.insertarOrdenado(0);
    lista.insertar(116,13);
    lista.mostrar();
    cout << "\nObtener_primer_dato: " << lista.obtenerPrimerObjeto() << endl;
    cout << "Obtener_ultimo_dato: " << lista.obtenerUltimoObjeto() << endl;
    cout << "Obtener_tamanio: " << lista.tamanio() << endl;


    cout << "\nLuego del baja_elemento(4) "
         << "y del baja(13)..." << endl;
    lista.eliminarPorObjeto(4); // BAJA POR DATO
    lista.eliminarPorPosicion(13); // BAJA POR POSICION
    lista.mostrar();
    cout << "\nObtener_tamanio: " << lista.tamanio() << endl;

    cout << "\nLuego del baja_primero y del baja_ultimo..." << endl;
    lista.eliminarPrimero();
    lista.eliminarUltimo();
    lista.mostrar();
    cout << "\nObtener_primer_dato: " << lista.obtenerPrimerObjeto() << endl;
    cout << "Obtener_ultimo_dato: " << lista.obtenerUltimoObjeto() << endl;
    cout << "Obtener_tamanio: " << lista.tamanio() << endl;

    cout << "\nLuego del baja_elementos_multiples(9)..." << endl;
    lista.eliminarObjetos(9);
    lista.mostrar();
    cout << "\nObtener_tamanio: " << lista.tamanio() << endl;

    cout << "\nLuego del baja_elementos_multiples(16)..." << endl;
    lista.eliminarObjetos(16);
    lista.mostrar();
    cout << "\nObtener_tamanio: " << lista.tamanio() << endl;

    cout << "\nLuego de la baja_elementos_multiples(4)..." << endl;
    lista.eliminarObjetos(4);
    lista.mostrar();
    cout << "\nObtener_tamanio: " << lista.tamanio() << endl;

    cout << "\nLuego de obtener maximo y minimo de la lista..." << endl;
    lista.mostrar();
    cout << "Obtener_maximo: " << lista.obtenerMaximo() << endl;
    cout << "Obtener_minimo: " << lista.obtenerMinimo() << endl;
    cout << "Obtener_tamanio: " << lista.tamanio() << endl;

    cout << "\nLuego del alta_ordenada(50)..." << endl;
    lista.insertarOrdenado(50);
    lista.mostrar();
    cout << "\nObtener_tamanio: " << lista.tamanio() << endl;

    cout << "\nLuego de dar de baja toda la lista..." << endl;
    lista.eliminarLista();
    lista.mostrar();
    cout << "\nObtener_tamanio: " << lista.tamanio() << endl;

    cout << "\nLuego del alta_ordenada(50)..." << endl;
    lista.insertarOrdenado(1027);
    lista.mostrar();
    cout << "\nObtener_tamanio: " << lista.tamanio() << endl;

    cout << "\nLuego del alta_primero(24) y del alta_ultimo(71)..." << endl;
    lista.insertarPrimero(24);
    lista.insertarUltimo(71);
    lista.mostrar();
    cout << "\nObtener_primer_dato: " << lista.obtenerPrimerObjeto() << endl;
    cout << "Obtener_ultimo_dato: " << lista.obtenerUltimoObjeto() << endl;
    cout << "Obtener_tamanio: " << lista.tamanio() << endl;

    cout << "\nLuego de obtener_elemento(3)" << endl;
    cout << lista.obtenerObjeto(3) << endl;

    cout << "\nLuego del obtener_promedio..." << endl;
    cout << lista.obtenerPromedio() << endl;

    return 0;
}
