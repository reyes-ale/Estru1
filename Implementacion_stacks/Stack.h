#pragma once
class Stack {
	int tamanio; 
	int* arreglo; 
	int pos_top; 

public:
	Stack(int tam); 
	~Stack(); 
	int* getArreglo();
	int getTamanio();
	void setTop(int pos); 
	int getTop(); 

};

