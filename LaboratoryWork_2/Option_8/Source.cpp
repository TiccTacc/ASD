#include <iostream>
using namespace std;

const unsigned int sizeMatrix = 5; // Матрица 5х5

struct matrix
{
	int strCell; //Строка
	int colCell; //Колонка
	int cellValue; // Значение ячейки
	struct matrix* next;
	struct matrix* prev;
};

void matrixDelete(matrix* head), 
	outMatrix(matrix* head, int columnSize, int stringSize),
	withdrawalAmount(matrix* head, int columnSize, int stringSize),
	enterValueSizedMatrix(int columnSize, int stringSize);

int main()
{
	srand(time(NULL)); // сброс счетчика рандома

	//Значения по умолчанию, берем из константы
	int columnSize = sizeMatrix;
	int stringSize = sizeMatrix;

	enterValueSizedMatrix(columnSize, stringSize);


	matrix* head = nullptr, * tail = nullptr; // указатели для головы и хвоста списка
	matrix* newCell = nullptr; // указатель для создания нового элемента

	for (int i = 0; i < (stringSize); i++) // Заполним построчно
	{
		for (int j = 0; j < (columnSize); j++)
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
	outMatrix(head, columnSize, stringSize); // Вывод всей матрицы

	//Вывод суммы всех четных ячеек
	withdrawalAmount(head, columnSize, stringSize);

	matrixDelete(head); // Освободим память

	return 0;
}

void enterValueSizedMatrix(int columnSize, int stringSize) {

	bool valueIsCorrect = true;

	do
	{
		cout << "Enter the number of rows or columns: " << endl;
		cin >> stringSize >> columnSize;
		
		if (columnSize <= 0)
		{
			cout << "The value columns is incorrect and cannot take negative values. Enter again..." << endl;
			valueIsCorrect = false;
		}
		if (columnSize <= 0)
		{
			cout << "The value rows is incorrect and cannot take negative values. Enter again..." << endl;
			valueIsCorrect = false;
		}
	} while (!valueIsCorrect);
}

void outMatrix(matrix* head, int columnSize, int stringSize)
{
	//int arrayOut[sizeMatrix][sizeMatrix];
	int** arrayOut = new int* [stringSize]; 
	for (int i = 0; i < stringSize; i++)
	{
		arrayOut[i] = new int[columnSize];

	}
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
	for (int i = 0; i < stringSize; i++) {
		for (int j = 0; j < columnSize; j++) {
			cout << arrayOut[i][j] << " | ";
		}
		cout << endl; // по окончанию вывода строки массива, переносим коретку
	}

	//Освободим память, от динамического массива.
	for (int i = 0; i < stringSize; i++)
	{
		delete[] arrayOut[i];
	}
	delete[]arrayOut;
}

void withdrawalAmount(matrix* head, int columnSize, int stringSize)
{
	// int matrixarray[sizeMatrix][sizeMatrix];																																																										//Var 12
	int** arrayAmount = new int* [stringSize];
	for (int i = 0; i < stringSize; i++)
	{
		arrayAmount[i] = new int[columnSize];

	}
	// Заполним массив
	if (head != nullptr) 
	{
		while (head != nullptr) 
		{
			arrayAmount[head->strCell][head->colCell] = head->cellValue;
			head = head->next;
		}
	}

	int AmountCells = 0;
	for (int i = 0; i < stringSize; i++)
	{
		for (int j = 0; j < columnSize; j++)
		{
			int sumOfCoordinates = i + j;
			if ((sumOfCoordinates % 2) == 0) {
				AmountCells = AmountCells + arrayAmount[i][j];
			}
		}
	}

	//Освобождение памяти двумерного массива
	for (int i = 0; i < stringSize; i++)
	{
		delete[] arrayAmount[i];
	}
	delete[]arrayAmount;

	cout << "Sum of all values, even coordinates:" << AmountCells << endl;
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