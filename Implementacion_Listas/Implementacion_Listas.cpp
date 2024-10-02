
#include <iostream>
#include "Nodo.h"
using namespace std;

void insertar(int valor_insertar, Nodo*& cabeza) {
    Nodo* nuevo_nodo = new Nodo(valor_insertar);
    Nodo* current = cabeza;
    Nodo* pred = NULL;

    if (cabeza == NULL) {
        cabeza = nuevo_nodo;
        nuevo_nodo->setNext(NULL);
    }
    else if (valor_insertar <= current->getValor()) {
        nuevo_nodo->setNext(cabeza);
        cabeza = nuevo_nodo;
    }
    else {
        while (current != NULL && current->getValor() < valor_insertar) {
            pred = current;
            current = current->getNext();
        }
        nuevo_nodo->setNext(current);
        pred->setNext(nuevo_nodo);
    }
}

int eliminar(int valor_eliminar, Nodo*& cabeza) {
    Nodo* current = cabeza;
    Nodo* pred = NULL;

    if (cabeza == NULL) {
        cout << "Lista vacia no se puede eliminar nada" << endl;
    }
    else if (cabeza->getValor() == valor_eliminar) {
        cabeza = current->getNext();
        delete current;
        return 1;
    }

    while (current != NULL && current->getValor() != valor_eliminar) {
        pred = current;
        current = current->getNext();
    }

    if (current == NULL) {
        return 0;
    }
    pred->setNext(current->getNext());
    delete current;
    return 1;

}

Nodo* buscar(int valor_buscar, Nodo* cabeza) {
    Nodo* current = cabeza;
    int contador = 0;

    if (cabeza == NULL) {
        cout << "Lista vacia no se puede buscar nada" << endl;
    }

    while (current != NULL && current->getValor() != valor_buscar) {
        current = current->getNext();
    }

    if (current != NULL && current->getValor() == valor_buscar) {
        return current;
    }
    else {
        return nullptr;
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

void limpiar(Nodo* cabeza) {
    Nodo* current = cabeza;

    while (current != NULL) {
        delete current;
        current = current->getNext();
    }
    cout << endl;
}

void pruebas_aleatorias(int opcion, Nodo*& cabeza) {
    int num_random;

    switch (opcion) {
    case 1:
        num_random = rand() % 10 + 1;
        cout << "Insercion de " << num_random << " --> ";
        insertar(num_random, cabeza);
        imprimir(cabeza);
        break;

    case 2:
        num_random = rand() % 10 + 1;
        cout << "Despues de eliminar " << num_random << " --> ";
        if (eliminar(num_random, cabeza) == 0) {
            cout << "No se encontro el numero a eliminar." << endl;
        }
        else {
            imprimir(cabeza);
        }
        break;

    case 3:
        num_random = rand() % 10 + 1;
        if (buscar(num_random, cabeza) == nullptr) {
            cout << "No se encontro el numero " << num_random << " en la lista." << endl;
        }
        else {
            cout << "Se encontro el numero " << num_random << " en la referencia " << buscar(num_random, cabeza) << endl;
        }
        break;
    }
}


int main() {
    srand(time(NULL));
    Nodo* cabeza = nullptr;

    for (int i = 0; i < 7; i++) {
        pruebas_aleatorias(1, cabeza);
    }
    cout << endl;

    for (int i = 0; i < 4; i++) {
        pruebas_aleatorias(2, cabeza);
    }

    cout << endl;

    for (int i = 0; i < 4; i++) {
        pruebas_aleatorias(3, cabeza);
    }

    limpiar(cabeza);
}

