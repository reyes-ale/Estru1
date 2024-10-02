#include <iostream>
#include "Stack.h"
using namespace std; 

int isEmpty(Stack* stack) {
	if (stack->getTop() == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

int isFull(Stack* stack) {
	if (stack->getTop() == stack->getTamanio() - 1) {
		return 1;
	}
	else {
		return 0;
	}
}

void push(Stack* stack, int elemento) {
	if (!(isFull(stack))) {
		int pos_top = stack->getTop(); 
		pos_top++; 
		stack->setTop(pos_top);
		stack->getArreglo()[pos_top] = elemento;
	}
	else {
		cout << "Pila llena, no se pudo insertar el elemento " << elemento << endl;
	}
}

int pop(Stack* stack) {
	int pos_top = stack->getTop();

	if (!(isEmpty(stack))) {
		int  valor_top = stack->getArreglo()[pos_top]; 
		pos_top--;
		stack->setTop(pos_top);
		return valor_top; 

	}
	else {
		cout << "Stack vacia, no puede eliminar el elemento del tope" << endl;
		return 0; 
	}
}

void create(Stack*& stack) {
	stack = new Stack(5); 
}

void impresion(Stack *stack) {
	cout << "tope --> " << endl;
	for (int i = stack->getTop(); i >= 0; i--) {
		cout << "         " << stack->getArreglo()[i] << endl;

	}
	cout << "inicio --> " << endl;
	cout << endl; 
}


int main() {
	Stack* stack;  
	create(stack); 

	cout << "PUSH -------------------------------------- " << endl << endl; 
    push(stack, 10);//primer elemento
    push(stack, 7);
    push(stack, 400);
	push(stack, 3);
	push(stack, 99);//top(ultimo)
	push(stack, 988888889);

	impresion(stack);
	cout << "------------------------------------------- " << endl << endl;

	cout << "POP --------------------------------------- " << endl << endl;
	
	for (int i = 0; i < stack->getTamanio(); i++) {
		cout << "Valor popped: " << pop(stack) << endl;
		impresion(stack);
	}
	cout << "-------------------------------------------- " << endl << endl;

	delete stack;
}
