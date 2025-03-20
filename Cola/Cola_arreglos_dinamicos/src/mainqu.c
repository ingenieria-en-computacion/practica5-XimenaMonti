#include <stdio.h>
#include "queue.h"

int main() {
    Queue q = queue_create(5); // Crear una cola con capacidad para 5 elementos

    queue_enqueue(&q, 10);
    queue_enqueue(&q, 20);
    queue_enqueue(&q, 30);

    printf("Frente de la cola: %d\n", queue_front(&q));

    printf("Eliminando: %d\n", queue_dequeue(&q));
    printf("Eliminando: %d\n", queue_dequeue(&q));

    if (queue_is_empty(&q)) {
        printf("La cola está vacía.\n");
    } else {
        printf("Frente de la cola después de eliminar: %d\n", queue_front(&q));
    }

    queue_delete(&q); // Liberar memoria

    return 0;
}
