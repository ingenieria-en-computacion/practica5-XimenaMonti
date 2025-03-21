#include <stdio.h>
#include "stack.h"

int main(void) {
    // Crear una nueva pila.
    Stack *s = stack_create();

    // Insertar elementos en la pila.
    stack_push(s, 50);
    stack_push(s, 75);
    stack_push(s, 100);

    // Imprimir la pila.
    printf("Contenido de la pila:\n");
    stack_print(s);

    // Sacar el elemento superior y mostrarlo.
    Data eliminado = stack_pop(s);
    printf("\nElemento eliminado: %d\n", eliminado);

    // Imprimir la pila después de eliminar un elemento.
    printf("\nPila actualizada:\n");
    stack_print(s);

    // Vaciar la pila.
    stack_empty(s);
    printf("\nPila después de vaciarla:\n");
    stack_print(s);

    // Liberar la memoria de la pila.
    stack_delete(s);

    return 0;
}
