#include <iostream>
#include "Cola.h"
using namespace std;

int main() {
	int tamanio;

	cout << "Ingrese el  tamanio de  la Cola: ";
	cin >> tamanio; 

	Cola* cola = new Cola(tamanio);

	cola->encolar(10);
	cola->encolar(3);
	cola->encolar(154);
	cola->encolar(32);
	cola->encolar(15);
	cola->encolar(7);
	cola->imprimir(); 

	for (int i = 0; i < 5; i++)
	{
		cola->desencolar();
		cola->imprimir();
	}
	
	



	delete cola;
}

