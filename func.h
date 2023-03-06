#ifndef _func_h_
#define _func_h_

//строки в матрице
typedef struct Line{
	int numElem; //кол-во элементов в строке
	int *arrayElem; //массив элементов
} Line;

//матрица собсной персоной
typedef struct Matrix{
	int numLine; //кол-во строк в матрице
	struct Line *stLine; //массив строк матрицы
} Matrix;

//прототипы функций
int getElem(int *, int *, int); //ввод и проверка на число
			   //функция вводит только определееное
			   //кол-во чисел, заданое вторым параметром
int getLine(Line *, int); //ввод элементов в строку
int getMatrix(Matrix *); //ввод строк в матрицу
void clearLine(Line *, int); //очистка строки
void clearMatrix(Matrix *); //очистка матрицы b
void clearMatrixB(Line *); //очистка матрицы
void printMatrix(const Matrix *); //принт матрицы
void printMatrixB(const Line *); //принт матрицы b
void getMatrixB(Line *, Matrix *); //создание матрицы b по заданию
int checkingZero(int); //проверка числа на 0

#endif
