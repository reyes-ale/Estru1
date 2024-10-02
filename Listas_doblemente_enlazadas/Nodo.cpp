#include "Nodo.h"

#include "Nodo.h"

Nodo::Nodo(int valor) {
	this->valor = valor;
	this->next = nullptr;
	this->previo = nullptr; 
}

Nodo::~Nodo() {

}

int Nodo::getValor() {
	return valor; 
}

Nodo* Nodo::getNext() {
	return next; 
}

void Nodo::setNext(Nodo* next) {
	this->next = next; 
}

void Nodo::setPrevio(Nodo* previo) {
	this->previo = previo;
}

Nodo* Nodo::getPrevio() {
	return previo; 
}