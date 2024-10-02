
#include <iostream>

struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo(int valor) : dato(valor), siguiente(nullptr) {}
};

// Función para fusionar dos listas ordenadas
//Nodo* fusionar(Nodo* izquierda, Nodo* derecha) {
//    Nodo* cabeza = nullptr;
//    Nodo* actual = nullptr;
//
//    // Determina el primer nodo de la lista fusionada
//    if (izquierda->dato <= derecha->dato) {
//        cabeza = izquierda;
//        izquierda = izquierda->siguiente;
//    }
//    else {
//        cabeza = derecha;
//        derecha = derecha->siguiente;
//    }
//    actual = cabeza;
//
//    // Fusiona las dos listas ordenadas
//    while (izquierda != nullptr && derecha != nullptr) {
//        if (izquierda->dato <= derecha->dato) {
//            actual->siguiente = izquierda;
//            izquierda = izquierda->siguiente;
//        }
//        else {
//            actual->siguiente = derecha;
//            derecha = derecha->siguiente;
//        }
//        actual = actual->siguiente;
//    }
//
//    // Si queda alguna lista, se añade al final
//    if (izquierda != nullptr) {
//        actual->siguiente = izquierda;
//    }
//    else {
//        actual->siguiente = derecha;
//    }
//
//    return cabeza;  // Devuelve la cabeza de la lista fusionada
//}
//
//// Función para dividir la lista en mitades
//Nodo* dividir(Nodo* cabeza) {
//    if (cabeza == nullptr || cabeza->siguiente == nullptr) {
//        return nullptr;
//    }
//
//    Nodo* lento = cabeza;
//    Nodo* rapido = cabeza->siguiente;
//
//    while (rapido != nullptr && rapido->siguiente != nullptr) {
//        lento = lento->siguiente;
//        rapido = rapido->siguiente->siguiente;
//    }
//    
//
//    Nodo* mitad = lento->siguiente;
//    lento->siguiente = nullptr;
//    return mitad;
//}
//
//// Función para realizar un Merge Sort iterativo
//Nodo* mergeSort(Nodo* cabeza) {
//    if (cabeza == nullptr || cabeza->siguiente == nullptr) {
//        return cabeza;
//    }
//
//    // Divide la lista en mitades
//    Nodo* mitad = dividir(cabeza);
//
//    // Ordena ambas mitades recursivamente
//    Nodo* izquierda = mergeSort(cabeza);
//    Nodo* derecha = mergeSort(mitad);
//
//    // Fusiona las dos mitades ordenadas
//    return fusionar(izquierda, derecha);
//}
//
//int main() {
//    /*Nodo* lista = new Nodo(4);
//    lista->siguiente = new Nodo(2);
//    lista->siguiente->siguiente = new Nodo(1);
//    lista->siguiente->siguiente->siguiente = new Nodo(3);
//
//    lista = mergeSort(lista);
//
//    Nodo* temp = lista;
//    while (temp != nullptr) {
//        std::cout << temp->dato << " ";
//        temp = temp->siguiente;
//    }
//
//    return 0;*/
//
//    std::cout << "######### \n Holi \n#########"; 
//}

Nodo* Lista::unir(Nodo* izquierda, Nodo* derecha, int tipo) {
	Nodo* cabeza = nullptr;
	Nodo* current = nullptr;

	if (tipo == 3) {
		if (izquierda->getPersona()->getApellido() <= derecha->getPersona()->getApellido()) {
			cabeza = izquierda;
			izquierda = izquierda->getNext();
		}
		else {
			cabeza = derecha;
			derecha = derecha->getNext();
		}
	}
	else {
		if (stoi(izquierda->getPersona()->getMovil()) <= stoi(derecha->getPersona()->getFijo())) {
			cabeza = izquierda;
			izquierda = izquierda->getNext();
		}
		else {
			cabeza = derecha;
			derecha = derecha->getNext();
		}
	}
	current = cabeza;

	while (izquierda != nullptr && derecha != nullptr) {
		if (tipo == 3) {
			if (izquierda->getPersona()->getApellido() <= derecha->getPersona()->getApellido()) {
				current->setNext(izquierda);
				izquierda = izquierda->getNext();
			}
			else {
				current->setNext(derecha);
				derecha = derecha->getNext();
			}
		}
		else {
			if (stoi(izquierda->getPersona()->getMovil()) <= stoi(derecha->getPersona()->getFijo())) {
				current->setNext(izquierda);
				izquierda = izquierda->getNext();
			}
			else {
				current->setNext(derecha);
				derecha = derecha->getNext();
			}
		}
		current = current->getNext();
	}

	if (izquierda != nullptr) {
		current->setNext(izquierda);
	}
	else {
		current->setNext(derecha);
	}

	return cabeza;
}

Nodo* Lista::dividir(Nodo* cabeza) {
	if (cabeza == nullptr || cabeza->getNext() == nullptr) {
		return nullptr;
	}

	Nodo* lento = cabeza;
	Nodo* rapido = cabeza->getNext();

	while (rapido != nullptr && rapido->getNext() != nullptr) {
		lento = lento->getNext();
		rapido = rapido->getNext()->getNext();
	}

	Nodo* mitad = lento->getNext();
	lento->setNext(nullptr);
	return mitad;
}

Nodo* Lista::mergeSort(Nodo* cabeza, int tipo) {

	if (cabeza == nullptr || cabeza->getNext() == nullptr) {
		return cabeza;
	}

	Nodo* mitad = dividir(cabeza);
	Nodo* izquierda = mergeSort(cabeza, tipo);
	Nodo* derecha = mergeSort(mitad, tipo);

	return unir(izquierda, derecha, tipo);
}