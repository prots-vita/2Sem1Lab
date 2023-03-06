#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "func.h"


int getElem(int *e, int *ctn, int c){
	int correct = scanf("%d", e);
	while (correct == 0){
		scanf("%*c");
		printf("Incorrect input\n");
		correct = scanf("%d", e);
	}
	if (correct==1) (*ctn)++;
	if (*ctn==c) scanf("%*[^\n]");
	if (correct<=0) return 0;
	else return 1;
}

int getLine(Line *stp, int iu){
	printf("Enter the number of elements in line {%d} in the Matrix\n", iu+1);
	int num, countNum = 0, elem, countElem = 0;
	do{
		getElem(&num, &countNum, 1);
		if (num<=0) printf("Value must be >=0\n");
	} while (num<=0 || countNum<1);
	stp->numElem = num;
	stp->arrayElem = calloc(num, sizeof(Line));
	printf("Put elements\n");
	while (countElem<num){
		if (getElem(stp->arrayElem+countElem, &countElem, num)==0){
			stp->numElem = countElem;
			return 0;
		}
	}
	return 1;
}

int getMatrix(Matrix *mtr){
	printf("Enter the number of lines in the Matrix\n");
	int num, countNum = 0;
	do{
		getElem(&num, &countNum, 1);
		if (num<=0) printf("Value must be >=0\n");
	} while (num<=0 || countNum<1);
	mtr->numLine = num;
	mtr->stLine = calloc(num, sizeof(Line));
	for (int i = 0; i<num; i++){
		if (getLine(mtr->stLine+i, i)==0){
			printf("Something wrong happened\n");
			mtr->numLine = i;
			clearMatrix(mtr);
			return 0;
		}
	}
	return 1;
}

void printMatrix(const Matrix *mtr){
	for (int i = 0; i<mtr->numLine; i++){
		for (int j = 0; j<mtr->stLine[i].numElem; j++){
			printf("{%d}", mtr->stLine[i].arrayElem[j]);
		}
		printf("\n");
	}
}

void printMatrixB(const Line *mtb){
	for (int i = 0; i<mtb->numElem; i++){
		printf("{%d}", mtb->arrayElem[i]);
	}
	printf("\n");
}

void clearMatrix(Matrix *mtr){
	for (int i = 0; i<mtr->numLine; i++){
		free(mtr->stLine[i].arrayElem);
	}
	free(mtr->stLine);
}
void clearMatrixB(Line *mtb){
	free(mtb->arrayElem);
}

int checkingZero(int n){
	while (n>0){
		if (n%10==0){
			return 0;
		} else {
			n/=10;
		}
	}
	return 1;
}

void getMatrixB(Line *mtb, Matrix *mtr){
	mtb->numElem = mtr->numLine;
	mtb->arrayElem = calloc(mtr->numLine, sizeof(Line));
	for (int i = 0; i<mtr->numLine; i++){
		for (int j = 0; j<mtr->stLine[i].numElem; j++){
			if (checkingZero(mtr->stLine[i].arrayElem[j])==1){
				mtb->arrayElem[i] += mtr->stLine[i].arrayElem[j];
			}
		}
	}
}




