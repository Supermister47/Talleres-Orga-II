#include "student.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>


void printStudent(student_t *stud)
{
    /* Imprime por consola una estructura de tipo student_t
    */
    
    printf("Nombre: %s\n", stud->name);
    printf("dni: %d\n", stud->dni);
    printf("Calificaciones: ");
    for(int i=0; i < NUM_CALIFICATIONS; i++) {
    	printf("%d, ", (stud->califications)[i]);
    }
    printf("\n");
    printf("Concepto: %d\n", stud->concept);
    printf("----------\n");

}

void printStudentp(studentp_t *stud)
{
    /* Imprime por consola una estructura de tipo studentp_t
    */
    
    printf("Nombre: %s\n", stud->name);
    printf("dni: %d\n", stud->dni);
    printf("Calificaciones: ");
    for(int i=0; i < NUM_CALIFICATIONS; i++) {
    	printf("%d, ", (stud->califications)[i]);
    }
    printf("\n");
    printf("Concepto: %d\n", stud->concept);
    printf("----------\n");
    
}
