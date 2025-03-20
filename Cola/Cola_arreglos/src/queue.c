#include "queue.h"
#include <stdio.h>

/**
 * Crea una nueva cola vacía.
 */
Queue queue_create() {
    Queue q;
    q.head = -1;
    q.tail = -1;
    q.len = TAM;
    return q;
}

/**
 * Inserta un elemento en la cola.
 */
void queue_enqueue(Queue* q, Data d) {
    if (q->tail == q->len - 1) {  // Si la cola está llena
        printf("Error: La cola está llena.\n");
        return;
    }
    
    if (q->head == -1) {  // Si la cola estaba vacía, inicializamos head
        q->head = 0;
    }
    
    q->tail++;
    q->datos[q->tail] = d;
}

/**
 * Elimina y devuelve el elemento del frente de la cola.
 */
Data queue_dequeue(Queue* q) {
    if (q->head == -1) {  // Si la cola está vacía
        printf("Error: La cola está vacía.\n");
        return -1;  
    }
    
    Data d = q->datos[q->head];
    q->head++;

    if (q->head > q->tail) {  // Si la cola se vació
        q->head = -1;
        q->tail = -1;
    }
    
    return d;
}

/**
 * Verifica si la cola está vacía.
 */
bool queue_is_empty(Queue* q) {
    return (q->head == -1);
}

/**
 * Obtiene el elemento en el frente de la cola sin eliminarlo.
 */
Data queue_front(Queue* q) {
    if (q->head == -1) {  // Si la cola está vacía
        printf("Error: La cola está vacía.\n");
        return -1;
    }
    return q->datos[q->head];
}

/**
 * Vacía la cola.
 */
void queue_empty(Queue* q) {
    q->head = -1;
    q->tail = -1;
}

/**
 * "Elimina" la cola (solo la vacía, ya que no hay memoria dinámica).
 */
void queue_delete(Queue* q) {
    queue_empty(q);
}
