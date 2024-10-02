#include "Stack.h"
using namespace std; 

Stack::Stack(int tam) {
	this->arreglo = new int[tam]; 
	this->tamanio = tam;
	this->pos_top = -1;
}

Stack::~Stack() {
	delete[] arreglo; 
}

void Stack::setTop(int pos) {
	this->pos_top = pos; 
}

int Stack::getTop() {
	return pos_top;
}

int* Stack::getArreglo() {
	return arreglo; 
}

int Stack::getTamanio() {
	return tamanio;
}
