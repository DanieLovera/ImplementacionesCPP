#ifndef _ARREGLO_BITS_H
#define _ARREGLO_BITS_H

const int TAMANIO_ENTERO = sizeof(int);
const int TAMANIO_BYTE = 8;
const int DATOS_POR_ENTERO = TAMANIO_ENTERO * TAMANIO_BYTE;
const int DATOS_A_ALMACENAR_DEFECTO = 1000;

class ArregloBits {

	private:

		unsigned int *datos;
		unsigned int capacidad;

	public:

		ArregloBits ();
		ArregloBits (unsigned int datos_a_almacenar);
		~ArregloBits ();

		void insertar (unsigned int dato);
		bool eliminar (unsigned int dato);
		bool consultar (unsigned int dato);
};

#endif // _ARREGLO_BITS_H_