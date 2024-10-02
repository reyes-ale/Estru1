	#include "Cola.h"
#include <iostream>
using  namespace  std; 

Cola::Cola()   {
	arreglo = nullptr;  
}


Cola::Cola(int capacidad) {
	this->capacidad = capacidad;
	arreglo = new int[capacidad];
	pos_ultimo = -1; 
}

Cola::~Cola()  {
	delete[] arreglo; 
}

int Cola::encolar(int elemento) {
	if (!(isFull())) {
		pos_ultimo++;
		arreglo[pos_ultimo] = elemento;
		return 1;
	}
	else {
		cout << "Cola llena, no se pudo encolar" << endl;
		return 0;
	}
	 
}

int Cola::desencolar() {
	if (!(isEmpty())) {

		for (int i = 0; i < pos_ultimo; i++){
			arreglo[i] = arreglo[i + 1];
		}
		pos_ultimo--;
		return 1;
	}
	else {
		cout << "Cola vacia. No se pudo desencolar" << endl;
		return 0;
	}

}

bool Cola::isEmpty() {
	if (pos_ultimo == -1) {
		return 1; 
	}
	else {
		return 0;  
	}
}

bool Cola::isFull() {
	if (pos_ultimo == capacidad-1) {
		return 1;
	}
	else {
		return 0; 
	}
}

void Cola::imprimir() {
	if (isEmpty()) {
		cout << "La cola está vacía." << endl;
	}
	for (int i = 0; i <= pos_ultimo; ++i) {
		cout  << "[" << arreglo[i] << "]";
		if (i < pos_ultimo) {
			cout << " - ";
		}
	}
	cout << endl;
}