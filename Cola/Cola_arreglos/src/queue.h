#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdbool.h>
typedef int Data;
#define TAM 100

typedef struct {
    Data datos[TAM];
    int head;
    int tail;
    int len;
} Queue;

Queue queue_create();
void queue_enqueue(Queue* , Data);
Data queue_dequeue(Queue*);
bool queue_is_empty(Queue*);
Data queue_front(Queue*);
void queue_empty(Queue*);
void queue_delete(Queue*);


#endif // __QUEUE_H__