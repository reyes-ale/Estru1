#pragma once
class Nodo {
private:
	int valor;
	Nodo* next;

public:
	Nodo(int valor);
	~Nodo();
	int getValor();
	void setNext(Nodo* next);
	Nodo* getNext();

};
