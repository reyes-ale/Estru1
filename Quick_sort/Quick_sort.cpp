
#include <iostream>
using namespace std; 

int determinar_pivote(int arreglo[], int size) {
	int primero = arreglo[0];
	int ultimo = arreglo[size - 1];
	int mitad = arreglo[size / 2];

	if (primero > mitad && primero < ultimo || primero < mitad && primero > ultimo) {
		return 0;

	}
	else if (mitad > primero && mitad < ultimo || mitad < primero && mitad > ultimo) {
		return size / 2;
	}
	else {
		return size - 1;
	}
}

int particionar(int arreglo[], int size) {
	int pivote_pos = determinar_pivote(arreglo, size); 
	int pivote = arreglo[pivote_pos];
	swap(arreglo[pivote_pos], arreglo[size - 1]);
	int i = 0;

	for (int j = 0; j < size - 1; j++) {
		if (arreglo[j] < pivote) {
			swap(arreglo[i], arreglo[j]);
			i++;
		}
	}
	swap(arreglo[i], arreglo[size - 1]); 
	return i;
}

void quickSort(int arreglo[], int size) {
	if (size > 1) {
		int pi = particionar(arreglo, size);  
		quickSort(arreglo, pi); 
		quickSort(arreglo + pi + 1, size - pi - 1); 
	}
}

void imprimir(int arreglo[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arreglo[i] << " "; 
	}
}

int main() {
    int arreglo[] = { 8,1,4,9,0,3,5,2,7,6 };
	int size = 10; 
	
	cout << "Arreglo desordenado: ";
	imprimir(arreglo, size);
	cout << endl; 

	//cout << "Pivote pos:" << determinar_pivote(arreglo, size);
	quickSort(arreglo, size);
	
	cout << "Arreglo ordenado: ";
	imprimir(arreglo, size);

}

