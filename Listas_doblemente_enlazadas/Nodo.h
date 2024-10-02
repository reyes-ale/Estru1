#pragma once
class Nodo {
private:
	int valor;
	Nodo* next;
	Nodo* previo; 

public:
	Nodo(int valor);
	~Nodo();
	int getValor();
	void setNext(Nodo* next); 
	void setPrevio(Nodo* previo);
	Nodo* getNext();
	Nodo* getPrevio();

};

