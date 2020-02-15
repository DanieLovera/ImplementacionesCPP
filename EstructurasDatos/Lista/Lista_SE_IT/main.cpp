#include "Lista.h"

#include <iostream>
	using std::cout;
	using std::endl;

/** NOTA:
 *
 *	- En el iterador el inicio internamente no es el nodo requerido, sino el nodo anterior.
 *
 *	- Se usa un nodo de centinela para evitar casos particulares al eliminar.
 *
 *	- El final del iterador es una posicion pasada al ultimo nodo, es decir si la lista tiene 
 *	5 elementos entonces, el final sera el "elemento" 6, en este caso sera la direccion de memoria 
 * 	NULL que significa que el nodo esta pasado del ultimo. Esto es asi en las implementaciones de iteradores.
 *
 *	- No se puede usar el iterador y luego el metodo final(), para insertar al final porque intentariamos,
 *	insertar en una posicion invalida, realmente no es la ultima sino una pasada.
 *
 *	- Como no uso una variable para guardar el tamanio, necesito para eliminar al final llamar al metodo para conocer
 *	el tamanio de la lista, luego ubicar el iterador en esa posicion y luego si llamar al metodo del iterador
 *	para que elimine el ultimo de los nodos del contenedor, puesto que no es doblemente enlazada y no puedo
 *	aunque conozca el ultimo volver al anterior.
 *
 *	- El puntero a la lista, se supone es para verificar que el iterador que se usara para eliminar o insertar
 *	sea el mismo que se uso para la creacion de ese iterador.
 */


int main () {

	Lista <int> lista;
	
	Lista <int> :: Iterador iterador = lista.crear_iterador();

	lista.insertar (lista.final(),10);
	iterador = lista.insertar (lista.final(),80);
	//lista.insertar (lista.final(),5);	

	//iterador = lista.inicio();

	//iterador = lista.insertar (iterador,1);
	//iterador.avanzar();
	//cout << iterador.actual() << endl;

	//lista.mostrar();
	//cout << lista.final().actual() << endl;
	//cout << lista.eliminar(lista.inicio()).actual() << endl;;
	//cout << lista.final().actual() << endl;
	lista.mostrar ();

	//cout << lista.tamanio () << endl;

	cout << "POST METODOS ITERADOR... INSERCIONES" << endl;
	lista.insertar_inicio (1000);
	lista.insertar (7, 3);
	lista.insertar_final (337);
	lista.mostrar ();

	cout << "POST METODOS ITERADOR... BAJAS" << endl;
	lista.eliminar_inicio();
	lista.eliminar(3);
	lista.eliminar_final();
	lista.mostrar();

	cout << "POST METODOS ITERADOR... CONSULTAS" << endl;
	cout << lista.consultar_inicio() << endl;
	cout << lista.consultar_final() << endl;
	cout << lista.consultar(1) << endl;
	cout << lista.consultar(2) << endl;


	return 0;
}