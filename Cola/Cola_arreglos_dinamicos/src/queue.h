#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdbool.h>
typedef int Data;

typedef struct {
    Data *data;
    int head;// head es el frente de la cola
    int tail;// tail es el final de la cola
    int len;// len es la cantidad de datos que se pueden guardar en la cola
} Queue;

Queue queue_create(int len);//crea una nueva cola vacía y la devuelve
void queue_enqueue(Queue* , Data);// se inserta un dato en la cola
Data queue_dequeue(Queue*); 
bool queue_is_empty(Queue*);
Data queue_front(Queue*);// se obtiene el dato al frente de la cola
void queue_empty(Queue*);// vacía la cola
void queue_delete(Queue*);

#endif // __QUEUE_H__