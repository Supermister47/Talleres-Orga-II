#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "student.h"
#include "teacher.h"

stack_t* stack;

/* Desapila k veces a la pila */
void multipop(stack_t* stack, uint16_t k) {
    for (int i = 0; i < 4; i++) {
        stack->pop(stack);
    }

    return;
}


int main()
{
    stack = createStack(100);

    student_t stud1 = {
        .name = "Steve Balmer",
        .dni = 12345678,
        .califications = {3,2,1},
        .concept = -2,
    };

    studentp_t stud2 = {
        .name = "Linus Torvalds",
        .dni = 23456789,
        .califications = {9,7,8},
        .concept = 1,
    };

    student_t* st1p = &stud1;
    studentp_t* st2p = &stud2;

    uint64_t* pintAux;

    // Completar: pushear en la pila ambos estudiantes

    pintAux = (uint64_t*)st1p + 5;

    for (int i = 0; i < 6; i++)
    {
        stack->push(stack, *pintAux);
        pintAux--;
    }
    
    pintAux = ((uint64_t*)st2p) + 3;

    for (int i = 0; i < 4; i++)
    {
        stack->push(stack, *pintAux);
        pintAux--;
    }
    


    // Una "lista" de profesores:
    teacher_t* teachers = malloc(3*sizeof(teacher_t));

    

    //stack->push(stack, (uint64_t)teachers);


    teachers[0].name = "Alejandro Furfaro";
    teachers[1].name = "Julián Bonder";
    teachers[2].name = "Javier Marenco";


    // Cada teacher_t ocupa 16bytes en memoria. Siendo que el stack tiene un ancho de 64bits (8bytes)
    // hay que hacer dos pushes a la pila por cada struct de teacher, cada uno casteado como un uint64_t.
    // Además, los structs deben añadirse a la pila de abajo hacia arriba
    
    pintAux = (uint64_t*)teachers + 5;

    for (int i=0; i < 3; i++) {

        for (int i = 0; i < 2; i++)
        {
            stack->push(stack, *pintAux);
            pintAux--;
        }
    }
    

    printf("Nombre del profesor: %s\n", (((teacher_t *) (stack->esp+1))[0].name));
    printf("Nombre del profesor: %s\n", (((teacher_t *) (stack->esp+1))[1].name));
    printf("Nombre del profesor: %s\n", (((teacher_t *) (stack->esp+1))[2].name));

    multipop(stack, 6);
    
    /*
    //teachers[0].name = "Alejandro Furfaro";
    printf("Nombre del profesor: %s\n", ((teacher_t *) stack->top(stack))[0].name);
    printf("Nombre del profesor: %s\n", ((teacher_t *) stack->top(stack))[1].name);
    printf("Nombre del profesor: %s\n", ((teacher_t *) stack->top(stack))[2].name);

    stack->pop(stack);
    */
    

    printStudentp((studentp_t*)(stack->esp+1));
    multipop(stack, 4);

    printStudent((student_t*)(stack->esp+1));
    multipop(stack, 6);
    
    return 0;
}
