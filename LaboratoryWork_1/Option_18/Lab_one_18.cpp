#include <iostream>
using namespace std;

const int sizelist = 2; //три элемента скуно и не показательно, сделаем побольше


struct list // Определение двухсвязного списка
{
	long int number;
	unsigned int priority; // приоритет. целое число unsigned
	struct list* next;
	struct list* prev;
};

int selectPriority();
void outList(list* head),
deleteList(unsigned int deletePriority, list* head),
deletealllist(list* head);

int main()
{
	list* head = nullptr, * tail = nullptr; // указатели для головы и хвоста списка
	list* newItem = nullptr; // указатель для создания нового элемента
	for (int i = 0; i < sizelist; i++)
	{
		newItem = (struct list*)malloc(sizeof(struct list)); // создаем новый элемент списка
		cout << "Enter the int to list : " << endl;  //заполняем у нового элемента поле number
		cin >> newItem->number;

		//теперь нужно заполнить поля prev и next
		if (i == 0) {
			head = newItem;  //поскольку элемент пока один то он голова, он же - хвост
			tail = newItem;
			tail->prev = nullptr; // так как элемент пока один - у него нет ни предыдущего "соседа", ни следующего
			tail->next = nullptr;
		}
		else {
			tail->next = newItem;		// делаем связку последнего элемента с новым
			newItem->prev = tail;		// делаем связку нового элемента с последним
			newItem->next = nullptr;	// дальше нового элемента пока больше элементов нет
			tail = newItem;				// передвигаем хвост на новый элемент
		}

		newItem->priority = selectPriority();
	}

	outList(head); // выводим все элементы списка (до удаления)

	cout << "Select the priority to which you want to delete." << endl;
	unsigned int deletePriority = selectPriority(); //Выбираем высокий приоритет до него удаляем все элементы ниже этого приоритета.

	deleteList(deletePriority, head);
	if (head->priority > 1 and head->priority < 10)
	{
		outList(head); // Выводим все элементы после удаления
	}
	
	deletealllist(head);

}

void deleteList(unsigned int deletePriority, list* head)
{
	list* deleteList = head;
	//list* nextDeletelist = nullptr;
	//list* prevDeletelist = nullptr;

	while (deleteList != nullptr) {
		if (deleteList->priority < deletePriority)
		{
			if (deleteList->prev != nullptr) {
				if (deleteList->next != nullptr)
				{
					deleteList->next->prev = deleteList->prev;
				}
				else
				{
					deleteList->prev->next = nullptr;
				}
			}
			if (deleteList->next != nullptr) {
				if (deleteList->prev != nullptr)
				{
					deleteList->prev->next = deleteList->next;
				}
				else
				{
					deleteList->next->prev = nullptr;
				}
			}

			//head = head->next;

			deleteList = head->next;
			free(head);
		}

	}
}

void deletealllist(list* head) // Процедура освобождает память, занятыми двухсвязными списками
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
	while (head != nullptr)
	{
		count++;

		cout << "List: " << count << endl
			<< "Element: " << head->number << " with priority: " << head->priority << endl;
		
		if (head->next != nullptr)
		{
			head = head->next;
		}
		else
		{
			break;
		}

	}
}

int selectPriority()
{

	unsigned int priorityList = 0;
	bool finished = false;
	cout << "Choose a priority from 1 to 10:" << endl;
	while (!finished)
	{

		cin >> priorityList;
		if (priorityList > 10)
		{
			cout << "The selected priority is above the threshold above 10" << endl
				<< "enter again." << endl;
			finished = false;
		}
		else if (priorityList < 1)
		{
			cout << "The selected priority is above the threshold below 1" << endl
				<< "enter again." << endl;
			finished = false;
		}
		else if (priorityList >= 1 and priorityList <= 10)
		{
			finished = true;
			return priorityList;
		}
	}
}