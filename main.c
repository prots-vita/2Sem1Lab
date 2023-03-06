#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "func.h"


int main(){
//	Matrix *mtr = calloc(1, sizeof(Matrix));
	Matrix mtr;
	if (getMatrix(&mtr)==0){
		printf("Try again\n");
		return 1;
	}
	Line mtb;
	getMatrixB(&mtb, &mtr);
	printf("The original Matrix\n");
	printMatrix(&mtr);
	printf("The resulting matrix\n");
	printMatrixB(&mtb);
	clearMatrix(&mtr);
	clearMatrixB(&mtb);
	return 0;
}

