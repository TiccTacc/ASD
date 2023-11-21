#include <iostream>
using namespace std;

const unsigned int sizeMatrix = 5; // ������� 5�5
int columnSize, stringSize;

struct matrix
{
	int strCell; //������
	int colCell; //�������
	int cellValue; // �������� ������
	struct matrix* next;
	struct matrix* prev;
};

void outMatrix(matrix* head),
matrixShift(matrix* head, int shift),
matrixDelete(matrix* head);

int main()
{
	srand(time(NULL));

	matrix* head = nullptr, * tail = nullptr;	// ��������� ��� ������ � ������ ������
	matrix* newCell = nullptr;					// ��������� ��� �������� ������ ��������

	for (int i = 0; i < (sizeMatrix); i++) // �������� ���������
	{
		for (int j = 0; j < (sizeMatrix); j++)
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
	outMatrix(head); // ����� ���� �������

	int nShift = 0;
	cout << "Enter the matrix shift: ";
	cin >> nShift;


	// ���� ����� = 0 ����� ������ �� ������
	if (nShift != 0)
		matrixShift(head, nShift);

	outMatrix(head);// �������� �����
	matrixDelete(head); // ��������� ������

	return 0;
}

void outMatrix(matrix* head)
{
	int arrayOut[sizeMatrix][sizeMatrix];
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
	for (int i = 0; i < size(arrayOut); i++) {
		for (int j = 0; j < size(arrayOut[i]); j++) {
			cout << arrayOut[i][j] << " | ";
		}
		cout << endl; // �� ��������� ������ ������ �������, ��������� ��������
	}
}

void matrixShift(matrix* head, int shift)
{
	if (shift > sizeMatrix) { //�������� �� ������� �����, ���� �� ������ ��������� "sizeMatrix" ����� ������ ����� �� ������
		shift = shift % sizeMatrix; //������� �� ������� � ���� �����
	}
	else if (shift < 0 or shift < static_cast<int>(sizeMatrix) * -1) { // �������� �� �������� �����, (sizeMatrix* -1) = ������������� �����
		shift = shift % (static_cast<int>(sizeMatrix) * -1);
	}
	if (shift == 0) {
		return;
	}
	if (head != nullptr) //�������� �� ������ ������
	{
		// ������� � ��������� ������, ��� �������� ������
		while (head != nullptr)
		{
			//head->strCell - ������; head->colCell - �������			
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