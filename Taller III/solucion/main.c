#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

#include "checkpoints.h"

int main (void){
	/* Acá pueden realizar sus propias pruebas */
	assert(alternate_sum_4(8,2,5,1) == 10);	
	assert(alternate_sum_4_using_c(8,2,5,1) == 10);
	assert(alternate_sum_4_simplified(8,2,5,1) == 10);
	assert(alternate_sum_8(8,2,5,1,8,2,5,1) == 20);
	uint32_t result = -1;
	product_2_f(&result, 2, 4.0);
	assert(result == 8);
	return 0;    
}


