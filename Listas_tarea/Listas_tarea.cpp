#include <iostream>

struct list_node_s {
    int data;
    struct list_node_s* next;
};

int member(int elemento, struct list_node_s* head_p) {
    struct list_node_s* curr_p = head_p; 
    int contador = 0; 

    while (curr_p != NULL && curr_p->data != elemento) {
        curr_p = curr_p->next;
        contador++; 
    }

    if (curr_p != NULL && curr_p->data == elemento) {
        contador++;
        return contador; 
    }
    else if (curr_p == NULL && curr_p->data == elemento) {
        contador++;
        return contador;
    }
    else if (curr_p == NULL) {
        return 0; 
    }
}

int main() {
    //localizar(6, lista);
}