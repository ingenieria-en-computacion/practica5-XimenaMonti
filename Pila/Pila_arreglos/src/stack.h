#ifndef __STACK_H__
#define __STACK_H__

#include <stdbool.h>
typedef int Data;
#define TAM 100

typedef struct {
    Data data[TAM];
    int top;
    
} Stack;

Stack stack_create();
void stack_push(Stack*, Data);
Data stack_pop(Stack*);
bool stack_is_empty(Stack* );
void stack_empty(Stack*);
void stack_print(Stack *);

#endif // __STACK_H__