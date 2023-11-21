#include <iostream>
using namespace std;

struct list // ����������� ������������ ������
{
	int number; // �������� 
	struct list* next;
	struct list* prev;
};

//����������� �������
int questionOfCompletion(), strLeght(char str[]);
void outList(list* head), matrixDelete(list* head);
 
int main()
{
	list* head = nullptr, * tail = nullptr, * nextlist = nullptr; // ��������� ������, ��� �������� ������������ ������, ������� �����.
	char finishing_enter = 'y';

	do {
		nextlist = (struct list*)malloc(sizeof(struct list)); // ��������� ������
		nextlist->next = nextlist->prev = nullptr; // ��������� ������ ������ (�.�. ������ �������, �� � ����� ����� NULL).
			
		cout << "Enter the int to list : " << endl;	
		cin>> nextlist->number;

		if (tail == nullptr) 
		{
			nextlist->prev = nullptr;	// �.�. ������ ������ ��������, �� ��������� ������ � ������, � ���� �� ���������� ������ �����������
			head = nextlist;			// ������������� ������� ��� ���������.
			tail = nextlist;			// ������������� ������� ��� ��������.
		}
		else
		{
			tail->next = nextlist;	// ������������� ����� ����������� ������, �� ����� ������
			nextlist->prev = tail;	// ���-�� ���������� ���������� ����� � �������� ������.
			tail = nextlist;		// ��������� ��� ������ ������ ��������.
		}

		finishing_enter = questionOfCompletion(); // ���������� � ������������, ��������� ���� ��� ���.

	} while (finishing_enter == 'n');

	outList(head); // ������� ��� �������� ������.

	matrixDelete(head); // ������� ������

}

void matrixDelete(list* head) // ��������� ����������� ������, �������� ������������ ��������
{
	list* nextDelete = head;
	while (head != nullptr)
	{
		nextDelete = head->next;
		free(head);
		head = nextDelete;
	}
}

void outList(list* head)
{
	unsigned int count = 0;
	unsigned int summElements = 0;
	list* tailList = nullptr;
	if (head != nullptr)
	{
		while (head->next != nullptr)
		{
			++count;
			head = head->next;
		}

		list* tailList = head;

		while (head->prev != nullptr)
		{
			++count;
			head = head->prev;
		}
	}
	cout << "Total number: " << --count << endl; // -1 �.�. ������ ������� +1 ������� � ����������� ������.
}

int questionOfCompletion()
{
	
	char finishing = 'n';
	bool finish_while = false;
	cout << "Finish Typing (y/n) ?" << endl;
	while(finish_while == false)
	{
		cin.clear();
		cin >> finishing;

		if (finishing == 'y' or finishing == 'n')
		{
			finish_while = true;
			return finishing;
		}
		else
		{
			cout << "An incorrect value was entered." << endl
				<< "enter y or n." << endl;
			finish_while = false;
		}
	}

}

