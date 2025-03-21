#ifndef __QUEUE_H__
#define __QUEUE_H__
#include "node.h"
#include <stdbool.h>

typedef struct {
    Node* head;
    Node *tail;
    int len;
} Queue;

Queue* queue_create();
void queue_enqueue(Queue* , Data);
int queue_dequeue(Queue*);
bool queue_is_empty(Queue*);
Data queue_front(Queue*);
void queue_empty(Queue*);
void queue_delete(Queue*);

#endif // __QUEUE_H__