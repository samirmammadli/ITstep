#include <iostream>
#include <string>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* previous;
};

class List
{
	Node* head;
	int count;

public:
	List()
	{
		head = nullptr;
		count = 0;
	}

	void add(int data)
	{
		if (head == nullptr)
		{
			head = new Node;
			head->data = data;
			head->next = nullptr;
			head->previous = nullptr;
			count++;
		}
		else
		{
			Node* node = head;
			for (int i = 0; i < count - 1; i++)
			{
				node = node->next;
			}
			node->next = new Node;
			node->next->data = data;
			node->next->next = nullptr;
			node->next->previous = node;
			head->previous = node->next;
			count++;
		}
	}

	void remove(int index)
	{
		if (index < count)
		{
			Node* node = head;
			if (index < count / 2)
			{
				for (int i = 0; i < index; i++)
				{
					node = node->next;
				}
				node->next->previous = node->previous;
				node->previous->next = node->next;
				count--;
				delete node;
			}
			else
			{
				node = head->previous;
				for (int i = index + 1; i < count; i++)
				{
					node = node->previous;
				}
				node->next->previous = node->previous;
				node->previous->next = node->next;
				count--;
				delete node;
			}
		}
	}

	void insert(int data, int index)
	{
		
	}

	int& operator[](int index)
	{
		if (index < count)
		{
			Node* node = head;
			if (index < count / 2)
			{
				for (int i = 0; i < index; i++)
				{
					node = node->next;
				}
				return node->data;
			}
			else
			{
				node = head->previous;
				for (int i = index + 1; i < count; i++)
				{
					node = node->previous;
				}
				return node->data;
			}
			
		}
	}
};

void main()
{
	List list;
	list.add(01);
	list.add(11);
	list.add(22);
	list.add(33);
	list.add(44);
	list.add(55);
	list.add(66);
	list.add(77);
	list.add(88);
	list.add(99);
	list.remove(8);
	for (size_t i = 0; i < 10; i++)
	{
		
		//cout << i << "   ";
		cout << list[i] << endl;
		//list[i];
	}
	
}