#include "queue.h"
#include <stdlib.h>

Queue* queue_create(){ 
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    q->len = 0;
    return q;

}   

void queue_enqueue(Queue* q, Data d){// esta funcion inserta un nodo en la cola
    Node* n = new_node(d);
    if(q->head == NULL){
        q->head=q->tail=n;
        return;
    } 
        q->tail->next = n;
        q->tail = n;
    }


//INSERTAR NODO TEMPORAL
Data queue_dequeue(Queue* q){ // esta funcion elimina un nodo de la cola 
    if(q->head == NULL){
        return -1;
    }
    Data d = q->head->data;
    Node* temp = q->head;
    q->head = q->head->next;
    delete_node(temp);
    q->len--;
    return d;
}

bool queue_is_empty(Queue* q){// esta funcion  verifica si la cola esta vacia
    return q->head == NULL;
}

Data queue_front(Queue* q){ //esta funcion obtiene el dato enfrentre de la cola 
    if(q->head == NULL){
        return -1;
    }
    return q->head->data;
}

void queue_empty(Queue* q){
    while(q->head != NULL){
        Node* temp = q->head;
        q->head = q->head->next;
        delete_node(temp);
    }
    q->tail = NULL;
    q->len = 0;
}// esta funcion vacia la cola



void queue_delete(Queue* q){// funcion que elimina la cola
    queue_empty(q);
    free(q);
}