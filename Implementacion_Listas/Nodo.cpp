#include "Nodo.h"

Nodo::Nodo(int valor) {
	this->valor = valor;
	this->next = nullptr;
}

Nodo::~Nodo() {

}

int Nodo::getValor()
{
	return valor;
}

void Nodo::setNext(Nodo* next)
{
	this->next = next; 
}

Nodo* Nodo::getNext()
{
	return next;
}

