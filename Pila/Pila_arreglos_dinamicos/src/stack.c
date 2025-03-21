#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Crea una nueva pila vacía y la devuelve.
 * 
 * @param len valor que indica cuantos elementos se pueden guardar en la pila
 * @return Una nueva pila vacía. Si la creación falla, el estado de la cola es inválido.
 * @details Esta función inicializa una pila vacía. 
 *          Asigna memoria dinámica a data mediante malloc con un número de elementos igual a len
 */
Stack stack_create(int len){
    Stack s;
    s.top = -1;  // Inicializa la pila como vacía
    s.data = (Data*)malloc(len*sizeof(Data));
    s.len = len;
    return s;

}


/**
 * 
 * Inserta un elemento en la parte superior de la pila.
 * 
 * @param s Referencia a la pila donde se insertará el elemento.
 * @param d Dato que se insertará en la pila.
 * @details Esta función añade el dato `d` en la parte superior de la pila. Si la pila está llena, 
 *          la función no realiza ninguna operación.
 */
void stack_push(Stack* s, Data d){
    if (s->top < s->len - 1) {  // Verifica si hay espacio en la pila
        s->top++;
        s->data[s->top] = d;
    } else {
        printf("Error: La pila está llena.\n");
    }
}

/**
 * Elimina y devuelve el elemento en la parte superior de la pila.
 * 
 * @param s Referencia a la pila de la cual se eliminará el elemento.
 * @return El dato que estaba en la parte superior de la pila. Si la pila está vacía 
 *         devuelve un valor que indica error (por ejemplo, -1 o un valor predeterminado).
 * @details Esta función elimina el elemento en la parte superior de la pila y lo devuelve.
 *          Si la pila está vacía, no se realiza ninguna operación y se devuelve un valor de error.
 */
Data stack_pop(Stack* s){
    if (s->top >= 0) {
        return s->data[s->top--];
    } else {
        printf("Error: La pila está vacía.\n");
        return -1;
    }
}

/**
 * Verifica si la pila está vacía.
 * 
 * @param s Referencia a la pila que se desea verificar.
 * @return 1 si la pila está vacía, 0 si no lo está. Si el puntero `s` es NULL, devuelve -1.
 * @details Esta función comprueba si la pila no contiene elementos. Es útil para evitar operaciones
 *          como `stack_pop` en una pila vacía.
 */
bool stack_is_empty(Stack* s){
    if (s == NULL) {
        return -1;
    }
    return s->top == -1;
}

/**
 * Vacía la pila, eliminando todos sus elementos.
 * 
 * @param s Referencia a la pila que se desea vaciar.
 * @details Esta función hace que top sea igual a -1
 */
void stack_empty(Stack* s){
    s->top = -1;
}

/**
 * Elimina data y libera la memoria asociada.
 * 
 * @param s Referencia a la pila que se desea liberar la memoria de data
 * @details Esta función libera la memoria asignada dinámicamente para data dentro de la pila
 */
void stack_delete(Stack *s){
    free(s->data);
}

/**
 * Imprime los elementos de la pila.
 * 
 * @param s Referencia a la pila que se desea imprimir.
 * @details Esta función imprime los elementos de la pila en orden, desde la parte superior
 *          hasta la base. Si la pila está vacía la función imprime
 *          un mensaje indicando que la pila está vacía o es inválida. La salida se dirige a
 *          la salida estándar (stdout).
 */
void stack_print(Stack *s){
    if (s == NULL) {
        printf("Pila inválida.\n");
        return;
    }
    if (s->top == -1) {
        printf("Pila vacía.\n");
        return;
    }
    printf("Pila:\n");
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->data[i]);
    }
    printf("\n");
}