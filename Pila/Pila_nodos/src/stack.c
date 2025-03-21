#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Crea una nueva pila vacía y la devuelve.
 * 
 * @return Un auntador a la nueva pila creada. Si la creación falla, devuelve NULL.
 * @details Esta función asigna memoria dinámicamente para una nueva pila utilizando `malloc`.
 *          Si la asignación de memoria falla, la función devuelve NULL. La pila creada
 *          está vacía y top apunta a NULL
 */
Stack *stack_create(){
    Stack *s = (Stack *) malloc(sizeof(Stack));
    if (s == NULL) {
        printf("Error: No se pudo asignar memoria para la pila.\n");
        return NULL;
    }
    s->top = NULL;
    return s;
}

/**
 * Inserta un elemento en la parte superior de la pila.
 * 
 * @param s Auntador a la pila donde se insertará el elemento.
 * @param d Dato que se insertará en la pila.
 * @details Esta función añade el dato `d` en la parte superior de la pila. Si la pila está llena
 *          o el puntero `s` es NULL, la función no realiza ninguna operación.
 */
void stack_push(Stack* s, Data d){
    if (s == NULL) {
        printf("Error: Puntero a pila NULL.\n");
        return;
    }
    Node* n = new_node(d);
    if (n == NULL) {
        printf("Error: No se pudo crear el nodo.\n");
        return;
    }
    n->next = s->top;
    s->top = n;
}

/**
 * Elimina y devuelve el elemento en la parte superior de la pila.
 * 
 * @param s Auntador a la pila de la cual se eliminará el elemento.
 * @return El dato que estaba en la parte superior de la pila. Si la pila está vacía o el puntero
 *         `s` es NULL, devuelve un valor que indica error (por ejemplo, -1 o un valor predeterminado).
 * @details Esta función elimina el elemento en la parte superior de la pila y lo devuelve.
 *          Si la pila está vacía, no se realiza ninguna operación y se devuelve un valor de error.
 */
Data stack_pop(Stack* s){
    if (s == NULL) {
        printf("Error: Puntero a pila NULL.\n");
        return -1;
    }
    if (s->top == NULL) {
        printf("Error: La pila está vacía.\n");
        return -1;
    }
    Node* n = s->top;
    Data d = n->data;
    s->top = n->next;
    delete_node(n);
    return d;
}

/**
 * Verifica si la pila está vacía.
 * 
 * @param s Auntador a la pila que se desea verificar.
 * @return 1 si la pila está vacía, 0 si no lo está. Si el puntero `s` es NULL, devuelve -1.
 * @details Esta función comprueba si la pila no contiene elementos. Es útil para evitar operaciones
 *          como `stack_pop` en una pila vacía.
 */
bool stack_is_empty(Stack* s){
    if (s == NULL) {
        return -1;
    }
    return s->top == NULL;
}

/**
 * Vacía la pila, eliminando todos sus elementos.
 * 
 * @param s Auntador a la pila que se desea vaciar.
 * @details Esta función elimina todos los elementos de la pila, dejándola vacía.
 *          Si el puntero `s` es NULL, la función no realiza ninguna operación.
 *          La memoria de los elementos eliminados se libera adecuadamente.
 */
void stack_empty(Stack* s){
    while (s->top != NULL) {
        Node* n = s->top;
        s->top = n->next;
        delete_node(n);
    }
}

/**
 * Elimina la pila y libera la memoria asociada a ella.
 * 
 * @param s Auntador a la pila que se desea eliminar.
 * @details Esta función libera la memoria asignada dinámicamente para la pila y todos sus elementos
 *          utilizando `free`. Si el puntero pasado es NULL, la función no realiza ninguna operación.
 *          Es responsabilidad del llamante asegurarse de que la pila ya no se utiliza después
 *          de ser eliminada.
 */
void stack_delete(Stack *s){
    stack_empty(s);
    free(s);
}

/**
 * Imprime los elementos de la pila.
 * 
 * @param s Auntador a la pila que se desea imprimir.
 * @details Esta función imprime los elementos de la pila en orden, desde la parte superior
 *          hasta la base. Si la pila está vacía o el puntero `s` es NULL, la función imprime
 *          un mensaje indicando que la pila está vacía o es inválida. La salida se dirige a
 *          la salida estándar (stdout).
 */
void stack_print(Stack *s){
    if (s == NULL) {
        printf("Pila inválida.\n");
        return;
    }
    if (stack_is_empty(s)) {
        printf("Pila vacía.\n");
        return;
    }
    printf("Elementos de la pila:\n");
    Node* n = s->top;
    while (n != NULL) {
        printf("%d\n", n->data);
        n = n->next;
    }
}