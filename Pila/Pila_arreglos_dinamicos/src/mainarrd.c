#include <stdio.h>
#include "stack.h"

int main(void) {
    // Crear una pila con capacidad para 10 elementos.
    Stack s = stack_create(10);

    // Insertar elementos en la pila.
    stack_push(&s, 5);
    stack_push(&s, 10);
    stack_push(&s, 15);
    stack_push(&s, 20);

    // Imprimir la pila.
    printf("Contenido de la pila:\n");
    stack_print(&s);

    // Eliminar un elemento de la pila y mostrarlo.
    Data eliminado = stack_pop(&s);
    printf("\nElemento eliminado: %d\n", eliminado);

    // Imprimir la pila después de eliminar un elemento.
    printf("\nPila después de eliminar un elemento:\n");
    stack_print(&s);

    // Vaciar la pila.
    stack_empty(&s);
    printf("\nPila después de vaciarla:\n");
    stack_print(&s);

    // Liberar la memoria asignada a la pila.
    stack_delete(&s);

    return 0;
}
