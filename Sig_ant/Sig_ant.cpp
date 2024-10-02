
#include <iostream>
using namespace std;


class Nodo {
private:
    int valor;
    Nodo* next;
    Nodo* previo;

public:
    Nodo(int valor) {
        this->valor = valor;
        this->next = nullptr;
        this->previo = nullptr;
    }

    ~Nodo() {

    }

    Nodo* getNext() {
        return next;
    }

    Nodo* getPrevio() {
        return previo;
    }

    void setNext(Nodo* next) {
        this->next = next;
    }

    void setPrevio(Nodo* previo) {
        this->previo = previo; 
    }

    int getValor() {
        return valor;
    }


};


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



int siguiente(int p, Nodo*&cabeza) {
    Nodo* current = cabeza;
    int cont = 1;
    int tamanio = numero_nodos(cabeza);

    if (cabeza == nullptr || cabeza->getNext() == nullptr) {
        cout << "Lista con muy pocos elementos. No se puede intercalar nada" << endl;
        return 0; 
    }
    else if (p>tamanio || p < 0) {
        cout << "Posicion fuera de rango" << endl; 
        return 0; 
    }
    else {
        while (current != nullptr && cont != p) {
            current = current->getNext();
            cont++;
        }

        if (cont == p && current->getPrevio() == nullptr && current->getNext()!= nullptr) { //primero de la lista
            
            cabeza = current->getNext(); 
            current->getNext()->setPrevio(nullptr);
            current->getNext()->setNext(current);
            current->setPrevio(current->getNext());
            current->setNext(current->getNext()->getNext());
        }
        else if (cont == p && current->getNext() != nullptr && current->getPrevio()!= nullptr) {
           current->getPrevio()->setNext(current->getNext());
            current->getNext()->setPrevio(current->getPrevio());
            current->getNext()->setNext(current);
            current->setPrevio(current->getNext());
            current->setNext(current->getNext()->getNext());

            return 1;
        }
        else if (cont==p && current->getNext() == nullptr) {
            cout << "Esa posicion no tiene siguiente para cambiar." << endl;
            return 0; 
        }

    }
}


int anterior(int p, Nodo*& cabeza) {
    Nodo* current = cabeza;
    int cont = 1;
    int tamanio = numero_nodos(cabeza);

    if (cabeza == nullptr || cabeza->getNext() == nullptr) {
        cout << "Lista con muy pocos elementos. No se puede intercalar nada" << endl;
        return 0;
    }
    else if (p > tamanio || p < 0) {
        cout << "Posicion fuera de rango" << endl;
        return 0;
    }
    else {
        while (current != nullptr && cont != p) {
            current = current->getNext();
            cont++;
        }

        if (cont == p && current->getPrevio() != nullptr && current->getNext() == nullptr) { //ultimo de la lista
            current->getPrevio()->setNext(nullptr);
            current->getPrevio()->setPrevio(current);
            current->setNext(current->getPrevio());
            current->setPrevio(current->getPrevio()->getPrevio());
        }
        else if (cont == p && current->getNext() != nullptr && current->getPrevio() != nullptr) {
            current->getPrevio()->setNext(current->getNext());
            current->getPrevio()->setPrevio(current);
            current->setNext(current->getPrevio());
            current->setPrevio(current->getPrevio()->getPrevio());

            return 1;
        }
        else if (cont == p && current->getPrevio() == nullptr) {
            cout << "Esa posicion no tiene anterior para cambiar." << endl;
        }

    }
}


int push_pila(int elemento, Nodo*& cabeza) {
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

int main()
{
    Nodo* node = nullptr;
    int tamanio_pila = 5;

    push_pila(10, node);
    push_pila(4, node);
    push_pila(6, node);
    push_pila(2, node);

    imprimir(node);


    intercalar(2, node);

    imprimir(node);
}
