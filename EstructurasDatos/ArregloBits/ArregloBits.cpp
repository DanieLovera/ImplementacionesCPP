#include "ArregloBits.h"

#include <iostream>
using namespace std;

ArregloBits :: ArregloBits () : ArregloBits (DATOS_A_ALMACENAR_DEFECTO) { }

ArregloBits :: ArregloBits (unsigned int datos_a_almacenar) {

	capacidad = (datos_a_almacenar / DATOS_POR_ENTERO) + 1;
	datos = new unsigned int [capacidad];
}

ArregloBits :: ~ArregloBits () {

	delete [] datos;
}

void ArregloBits :: insertar (unsigned int dato) {

	if (dato < (capacidad * DATOS_POR_ENTERO)) {

		unsigned int posicion = dato / DATOS_POR_ENTERO; // FORMULA PARA SABER A CUAL ENTERO DEL ARREGLO CORRESPONDE
		unsigned int desplazamiento = dato % DATOS_POR_ENTERO; // FORMULA PARA SABER CUAL BIT ACTIVAR EN LA MASCARA
		unsigned int mascara = 0x0001; 

		mascara = mascara << desplazamiento;
		datos[posicion] = datos [posicion] | mascara;

		// EN UNA LINEA SERIA
		// datos[dato / DATOS_POR_ENTERO] |= 0x0001 << (dato % DATOS_POR_ENTERO);
	}
}

bool ArregloBits :: eliminar (unsigned int dato) {

	bool eliminado = false;

	if (dato < (capacidad * DATOS_POR_ENTERO) && consultar(dato)) {

		unsigned int posicion = dato / DATOS_POR_ENTERO;
		unsigned int desplazamiento = dato % DATOS_POR_ENTERO;
		unsigned int mascara = 0x0001; 

		mascara = mascara << desplazamiento;
		mascara = ~mascara;
		datos[posicion]= datos [posicion] & mascara;
		eliminado = true;

		// EN UNA LINEA SERIA
		// datos[dato / DATOS_POR_ENTERO] &= ~(0x0001 << (dato % DATOS_POR_ENTERO));
		// eliminado = true;
	}
	return eliminado;
}

bool ArregloBits :: consultar (unsigned int dato) {

	bool esta = false;

	if (dato < (capacidad * DATOS_POR_ENTERO)) {

		unsigned int posicion = dato / DATOS_POR_ENTERO;
		unsigned int desplazamiento = dato % DATOS_POR_ENTERO;
		unsigned int mascara = 0x0001; 

		mascara = mascara << desplazamiento;
		esta = datos [posicion] & mascara;

		// EN UNA LINEA SERIA
		// esta = datos[dato / DATOS_POR_ENTERO] & 0x0001 << (dato % DATOS_POR_ENTERO);
	}
	return esta;
}