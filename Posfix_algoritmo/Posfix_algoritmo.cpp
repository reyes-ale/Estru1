
#include <iostream>
using  namespace  std; 

class Stack {
	int tamanio;
	int* arreglo;
	int pos_top;

public:
	Stack(int tam) {
		this->arreglo = new int[tam];
		this->tamanio = tam;
		this->pos_top = -1;
	}

	~Stack() {
		delete[] arreglo;
	}

	void setTop(int pos) {
		this->pos_top = pos;
	}

	int getTop() {
		return pos_top;
	}

	int* getArreglo() {
		return arreglo;
	}

	int getTamanio() {
		return tamanio;
	}

};

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

void impresion(Stack* stack) {
	cout << "tope --> " << endl;
	for (int i = stack->getTop(); i >= 0; i--) {
		cout << "         " << stack->getArreglo()[i] << endl;

	}
	cout << "inicio --> " << endl;
	cout << endl;
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


int main() {
	Stack *stack = new Stack(7);
	//int instruccion [] = {2,3,1,'*','+',9,'-'};
	int num1, num2;
	string ins;  
	
	cout << "Ingrese la instruccion (7 elementos por lo menos): ";
	cin >> ins;    

	while (ins.size() > 7) {
		cout << "Instruccion con elementos de mas. Ingrese nuevamente: ";
		cin >> ins;
	}

	if (ins[1] == '+' || ins[1] == '-' || ins[1] == '*') {
		cout << "La instruccion intenta operar con un solo operando. Ingrese nuevamente: ";
		cin >> ins; 
	}

	int *instruccion = new int[ins.size()]; 

	for (int i = 0; i < ins.size(); i++) {
		if (ins[i] != '+' && ins[i] != '-' && ins[i] != '*') {
			instruccion[i] = ins[i]-'0';
		}
		else {
			instruccion[i] = ins[i];
		}
	}

	for (int i = 0; i < 7; i++) {
		if (instruccion[i] != '+' && instruccion[i] != '-' && instruccion[i] != '*') {
			push(stack, instruccion[i]);
		}
		else if (instruccion[i] == '+') {
			num1 = pop(stack) ;
			num2 = pop(stack) ;
			int sum = num1 + num2;
			push(stack, sum);
		}
		else if (instruccion[i] == '-') {
			num1 = pop(stack);
			num2 = pop(stack) ;
			int res = num2 - num1;
			push(stack, res);
		}
		else if (instruccion[i] == '*') {
			num1 = pop(stack) ;
			num2 = pop(stack) ;
			int prod = num1 * num2;
			push(stack, prod);
		}
	}

	impresion(stack); 
}
