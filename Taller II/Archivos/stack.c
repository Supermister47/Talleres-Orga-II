#include "stack.h"
#include <stdlib.h>

/* Desapila el último elemento (i.e. lo devuelve y lo elimina de la pila)
*/
uint64_t pop(stack_t *stack)
{
    uint64_t top = stack->top(stack);
    stack->esp += 1;
    return top;
}


/* Devuelve el contenido del tope de la pila (y lo mantiene).
*/
uint64_t top(stack_t *stack)
{
    return *(stack->esp+1);
}

/* Apila el contenido de 'data'
*/
void push(stack_t* stack, uint64_t data)
{
    // Debería chequear que esp != _stackMem para evitar excederse del límite de memoria asignado en el heap
    *(stack->esp) = data;
    stack->esp -= 1;
}

stack_t* createStack(size_t size)
{
    // Primero tengo que reservar memoria para todas las variables del struct stack
    stack_t* stack = malloc(6 * sizeof(uint64_t));

    // Ahora que está creado el stack en el heap, puedo asignarle los valores a sus variables
    stack->_stackMem = malloc(size * sizeof(uint64_t));

    stack->ebp = stack->_stackMem + size - 1;  // La base del stack es la dirección numéricamente más grande.
    stack->esp = stack->ebp;  // Al comienzo, la base y el tope coinciden

    stack->pop = pop;
    stack->top = top;
    stack->push = push;

    return stack;
}

void deleteStack(stack_t *stack)
{
    free(stack->_stackMem);
    free(stack);
}
