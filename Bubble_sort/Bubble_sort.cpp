
#include <iostream>
using namespace std; 

void bbsort(int array[],int tam) {
    
    for (int j = 0; j < tam-1; j++) {
        for (int i = 0; i < tam-1; i++) {
            if (array[i] > array[i + 1]) {
                int temporal = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temporal;
            }
        }
    }
}

void imprimir(int arreglo[], int tam) {
    for (int i = 0; i < tam-1; i++)
    {
        cout << arreglo[i] << endl;
    }
}


int main() {
    int arreglo [] = {1,10,6,4,20,12,2};
    imprimir(arreglo,7);
    cout << "Arreglo ordenado ------------------------------" << endl;
    bbsort(arreglo, 7);
    imprimir(arreglo, 7);


}

