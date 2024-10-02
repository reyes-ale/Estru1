
#include <iostream>
using namespace std; 

class Nodo {
private:
	int valor;
	Nodo* next;

public:
	Nodo(int valor) {
		this->valor = valor;
	}
	~Nodo() {

	}
	int getValor() {
		return valor; 
	}
	void setNext(Nodo* next) {
		this->next = next; 
	}
	Nodo* getNext() {
		return next; 
	}

};

int push_pila(int elemento, Nodo*& cabeza) {
	Nodo* new_nodo = new Nodo(elemento);
	Nodo* current = cabeza; 

	if (cabeza == NULL) {
		cabeza = new_nodo; 
	}
	else {
		while (current->getNext() != NULL) {
			current = current->getNext(); 
		}
		current->setNext(new_nodo);
		return 1;
	}
	return 0; 
}

int push_pila2(int elemento, Nodo*& cabeza) {
	Nodo* nuevo = new Nodo(elemento);
	Nodo* current = cabeza;

	if (cabeza == NULL) {
		cabeza = nuevo; 
	}
	else {
		nuevo->setNext(cabeza);
		cabeza = nuevo; 
		return 1; 
	}

	return 0; 

}

int push_cola(int elemento, Nodo*& cabeza) {
	Nodo* nuevo = new Nodo(elemento);
	Nodo* current = cabeza;

	if (cabeza == NULL) {
		cabeza = nuevo;
	}
	else {
		while (current->getNext() != NULL) {
			current = current->getNext();
		}
		current->setNext(nuevo);
		return 1;
	}
	return 0;

}

int pop_pila(Nodo*& cabeza) {

	Nodo* temp = cabeza;
	if (cabeza == NULL) {
		cout << "nula" << endl;
		return 0;
	}
	else {
		cabeza = cabeza->getNext();
		delete temp;
		return 1;
	}
}

int pop_pila2(Nodo*& cabeza) {

	Nodo* temp = cabeza;
	if (cabeza == NULL) {
		cout << "nula" << endl;
		return 0;
	}
	else {
		cabeza = cabeza->getNext();
		delete temp;
		return 1;
	}
}

int isEmpty(Nodo*& cabeza) {
	if (cabeza == NULL) {
		return 1;
	}
	else {
		return 0; 
	}
}

int numero_nodos(Nodo*& cabeza) {
	int tamanio = 0;
	Nodo* current = cabeza;

	if (cabeza == NULL) {
		return tamanio;
	}
	else {
		while (current != NULL) {
			current = current->getNext();
			tamanio++;
		}
		return tamanio;
	}
}



int isFull(Nodo*& cabeza, int tamanio) {
	if (numero_nodos(cabeza) == tamanio) {
		return 1;
	}
	else {
		return 0; 
	}
}



void imprimir(Nodo* cabeza) {
	Nodo* current = cabeza;
	int indice = 0;

	while (current != NULL) {
		indice++;
		cout << " Nodo" << indice << " (" << current->getValor() << ") ";

		if (current->getNext() != nullptr) {
			cout << " - ";
		}

		current = current->getNext();
	}
	cout << endl; 
}

int main() {
	Nodo* node = nullptr;
	int tamanio_pila = 5; 

	push_pila(10, node);
	push_pila(4, node);
	push_pila(6, node);
	push_pila(2, node);

	imprimir(node); 
	cout << numero_nodos(node) << endl;
	pop_pila(node); 
	pop_pila(node);
	pop_pila(node);
	imprimir(node); 
	cout << numero_nodos(node) << endl;

	/*push_cola(5, node);

	push_cola(6, node);
	push_cola(100, node);
	imprimir(node); */




    


}

