#pragma once
class Cola {
	int pos_ultimo; 
	int  capacidad;
	int* arreglo; 

public:
	Cola();
	Cola(int capacidad); 
	~Cola();
	int encolar(int elemento);
	int desencolar(); 
	bool isEmpty();
	bool isFull();
	void imprimir();


};

