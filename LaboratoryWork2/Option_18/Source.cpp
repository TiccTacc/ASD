#include <iostream>
using namespace std;

const unsigned int sizeMatrix = 5; // Матрица 5х5
int columnSize, stringSize;

struct matrix
{
	int strCell; //Строка
	int colCell; //Колонка
	int cellValue; // Значение ячейки
	struct matrix* next;
	struct matrix* prev;
};

void outMatrix(matrix* head),
matrixShift(matrix* head, int shift),
matrixDelete(matrix* head);

int main()
{
	srand(time(NULL));

	matrix* head = nullptr, * tail = nullptr;	// указатели для головы и хвоста списка
	matrix* newCell = nullptr;					// указатель для создания нового элемента

	for (int i = 0; i < (sizeMatrix); i++) // Заполним построчно
	{
		for (int j = 0; j < (sizeMatrix); j++)
		{
			newCell = (struct matrix*)malloc(sizeof(struct matrix)); // Cоздаем новый элемент списка
			if (head == nullptr) // Проверяем на начальный элемент списка, если начальный, то указываем его как головной
			{
				head = newCell;
				tail = newCell;
				tail->next = nullptr;
				tail->prev = nullptr;
			}
			else
			{
				tail->next = newCell;
				newCell->prev = tail;
				newCell->next = nullptr;
				tail = newCell;
			}

			newCell->cellValue = rand() % 999; // От 0 до 999.
			newCell->colCell = j;
			newCell->strCell = i;
		}
	}
	outMatrix(head); // Вывод всей матрицы

	int nShift = 0;
	cout << "Enter the matrix shift: ";
	cin >> nShift;


	// Если сдвиг = 0 тогда ничего не делаем
	if (nShift != 0)
		matrixShift(head, nShift);

	outMatrix(head);// Проверим сдвиг
	matrixDelete(head); // Освободим память

	return 0;
}

void outMatrix(matrix* head)
{
	int arrayOut[sizeMatrix][sizeMatrix];
	if (head != nullptr) //проверка на пустой список
	{
		// Перевод в двумерный массив, для удобство вывода
		while (head != nullptr)
		{
			//cout << "str -" << head->strCell << " col - " << head->colCell << " value - " << head->cellValue << endl; // Построчный вывод ячеек 
			arrayOut[head->strCell][head->colCell] = head->cellValue;
			head = head->next;

		}
	}
	//Вывод двумерного массива
	for (int i = 0; i < size(arrayOut); i++) {
		for (int j = 0; j < size(arrayOut[i]); j++) {
			cout << arrayOut[i][j] << " | ";
		}
		cout << endl; // по окончанию вывода строки массива, переносим корретку
	}
}

void matrixShift(matrix* head, int shift)
{
	if (shift > sizeMatrix) { //Проверим на большой сдвиг, если он больше константы "sizeMatrix" тогда делаем сдвиг по модулю
		shift = shift % sizeMatrix; //остаток от деления и есть сдвиг
	}
	else if (shift < 0 or shift < static_cast<int>(sizeMatrix) * -1) { // Проверим на обратный сдвиг, (sizeMatrix* -1) = отрицательное число
		shift = shift % (static_cast<int>(sizeMatrix) * -1);
	}
	if (shift == 0) {
		return;
	}
	if (head != nullptr) //проверка на пустой список
	{
		// Перевод в двумерный массив, для удобство вывода
		while (head != nullptr)
		{
			//head->strCell - строка; head->colCell - Колонка			
			int newCell = head->colCell + shift;
			if (newCell >= sizeMatrix)
			{
				newCell = newCell - sizeMatrix;
			}
			else if (newCell <= (static_cast<int>(sizeMatrix) * -1)) {
				newCell = newCell - (static_cast<int>(sizeMatrix) * -1);
			}
			head->colCell = newCell;
			head = head->next;
		}
	}
}

void matrixDelete(matrix* head) {
	matrix* nextDelete = head;
	while (head != nullptr)
	{
		matrix* nextDelete = head->next;
		free(head);
		head = nextDelete;
	}
}