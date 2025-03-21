#include <stdio.h>
#include "stack.h"

int main() {
   
    Stack s = stack_create();

    //Insetar elementos en la pila
    stack_push(&s, 10);
    stack_push(&s, 20);
    stack_push(&s, 30);

  
    printf("Pila después de insertar elementos:\n");
    stack_print(&s);

    // Elimina un elemento
    printf("\nElemento eliminado: %d\n", stack_pop(&s));

   
    printf("\nPila después de eliminar un elemento:\n");
    stack_print(&s);

    // Verifica si la pila está vacía
    if (stack_is_empty(&s)) {
        printf("\nLa pila está vacía.\n");
    } else {
        printf("\nLa pila NO está vacía.\n");
    }

    // Vacia la pila
    stack_empty(&s);
    printf("\nPila después de vaciarla:\n");
    stack_print(&s);

    return 0;
}
