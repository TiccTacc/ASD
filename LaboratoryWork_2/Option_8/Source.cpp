#include <iostream>
using namespace std;

const unsigned int sizeMatrix = 5; // ������� 5�5

struct matrix
{
	int strCell; //������
	int colCell; //�������
	int cellValue; // �������� ������
	struct matrix* next;
	struct matrix* prev;
};

void matrixDelete(matrix* head), 
	outMatrix(matrix* head, int columnSize, int stringSize),
	withdrawalAmount(matrix* head, int columnSize, int stringSize),
	enterValueSizedMatrix(int columnSize, int stringSize);

int main()
{
	srand(time(NULL)); // ����� �������� �������

	//�������� �� ���������, ����� �� ���������
	int columnSize = sizeMatrix;
	int stringSize = sizeMatrix;

	enterValueSizedMatrix(columnSize, stringSize);


	matrix* head = nullptr, * tail = nullptr; // ��������� ��� ������ � ������ ������
	matrix* newCell = nullptr; // ��������� ��� �������� ������ ��������

	for (int i = 0; i < (stringSize); i++) // �������� ���������
	{
		for (int j = 0; j < (columnSize); j++)
		{
			newCell = (struct matrix*)malloc(sizeof(struct matrix)); // C������ ����� ������� ������
			if (head == nullptr) // ��������� �� ��������� ������� ������, ���� ���������, �� ��������� ��� ��� ��������
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

			newCell->cellValue = rand() % 999; // �� 0 �� 999.
			newCell->colCell = j;
			newCell->strCell = i;
		}
	}
	outMatrix(head, columnSize, stringSize); // ����� ���� �������

	//����� ����� ���� ������ �����
	withdrawalAmount(head, columnSize, stringSize);

	matrixDelete(head); // ��������� ������

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
	if (head != nullptr) //�������� �� ������ ������
	{
		// ������� � ��������� ������, ��� �������� ������
		while (head != nullptr)
		{
			//cout << "str -" << head->strCell << " col - " << head->colCell << " value - " << head->cellValue << endl; // ���������� ����� ����� 
			arrayOut[head->strCell][head->colCell] = head->cellValue;
			head = head->next;
		}
	}
	//����� ���������� �������
	for (int i = 0; i < stringSize; i++) {
		for (int j = 0; j < columnSize; j++) {
			cout << arrayOut[i][j] << " | ";
		}
		cout << endl; // �� ��������� ������ ������ �������, ��������� �������
	}

	//��������� ������, �� ������������� �������.
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
	// �������� ������
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

	//������������ ������ ���������� �������
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