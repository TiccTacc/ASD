#include <iostream>
using namespace std;

struct list // Определение двухсвязного списка
{
	int number; // значение 
	struct list* next;
	struct list* prev;
};

//определение функций
int questionOfCompletion(), strLeght(char str[]);
void outList(list* head), matrixDelete(list* head);
 
int main()
{
	list* head = nullptr, * tail = nullptr, * nextlist = nullptr; // Установка связок, для создания двухсвязного списка, очишаем связи.
	char finishing_enter = 'y';

	do {
		nextlist = (struct list*)malloc(sizeof(struct list)); // выделение памяти
		nextlist->next = nextlist->prev = nullptr; // установка связей списка (т.к. список нулевой, то и связи равны NULL).
			
		cout << "Enter the int to list : " << endl;	
		cin>> nextlist->number;

		if (tail == nullptr) 
		{
			nextlist->prev = nullptr;	// Т.к. список только создался, он считается первым в списке, и связ на предыдущий список отсутствует
			head = nextlist;			// Устанавливаем элемент как начальный.
			tail = nextlist;			// Устанавливаем элемент как конечный.
		}
		else
		{
			tail->next = nextlist;	// устанавливаем связь предыдущего списка, на новый список
			nextlist->prev = tail;	// так-же необходимо установить связь у текущего списка.
			tail = nextlist;		// указываем что список теперь конечный.
		}

		finishing_enter = questionOfCompletion(); // спрашиваем у пользователя, закончить ввод или нет.

	} while (finishing_enter == 'n');

	outList(head); // выводим все элементы списка.

	matrixDelete(head); // очистка памяти

}

void matrixDelete(list* head) // Процедура освобождает память, занятыми двухсвязными списками
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
	cout << "Total number: " << --count << endl; // -1 т.к. список считает +1 элемент в двухсвязном списке.
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

