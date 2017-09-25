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
	~List()
	{
		Node* temp = head;
		temp->previous = nullptr;
		for (int i = 0; i < count-2; i++)
		{
			temp = temp->next;
			delete temp->previous;
		}
		delete temp;
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
		else if (count == 1)
		{
			Node* node = new Node;
			head->next = node;
			head->previous = node;
			node->previous = head;
			node->next = nullptr;
			node->data = data;
			count++;
		}
		else
		{
			Node* node = new Node;
			node->previous = head->previous;
			head->previous = node;
			node->previous->next = node;
			node->next = nullptr;
			node->data = data;
			count++;
		}
	}

	void remove(int index)
	{
		Node* node = head;
		if (index == 0)
		{
			head = head->next;
			head->previous = node->previous;
			count--;
			delete node;
		}
		else if (index == count - 1)
		{
			node = head->previous;
			head->previous = node->previous;
			node->previous->next = nullptr;
			count--;
			delete node;
		}
		else if (index < count)
		{
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
		if (index < 0 || index >= count)
			return;
		if (index == 0)
		{
			if (count > 1)
			{
				Node* temp = head;
				head = new Node;
				head->next = temp;
				head->previous = temp->previous;
				head->data = data;
				temp->previous = head;
			}
			else
			{
				Node* temp = head;
				head = new Node;
				head->next = temp;
				head->previous = temp;
				head->data = data;
				temp->previous = head;
			}
			count++;
		}
		else if (index < count /2)
		{
			Node* node = head;
			for (int i = 0; i < index; i++)
			{
				node = node->next;
			}
			Node* temp = new Node;
			temp->data = data;
			temp->next = node;
			temp->previous = node->previous;
			node->previous->next = temp;
			node->previous = temp;
			count++;
		}
		else if (index == count - 1)
		{
			Node* temp = new Node;
			temp->data = data;
			temp->next = nullptr;
			temp->previous = head->previous;
			head->previous->next = temp;
			head->previous = temp;
			count++;
		}
		else
		{
			Node* node = head->previous;
			for (int i = index + 1; i < count; i++)
			{
				node = node->previous;
			}
			Node* temp = new Node;
			temp->data = data;
			temp->next = node;
			temp->previous = node->previous;
			node->previous = temp;
			count++;
		}
	}

	int& operator[](int index)
	{
		if (index < 0) index *= -1;
		if (index == 0)
			return head->data;
		else if (index < count)
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
	int getCount()
	{
		return this->count;
	}
};

void main()
{
	List list;
	list.add(0);
	list.insert(100, 0);
	list.add(1);
	list.add(2);
	list.add(3);
	list.add(4);
	list.add(5);
	list.add(6);
	list.add(7);
	list.add(8);
	list.add(9);
	list.add(10);
	list.add(11);
	list.add(12);
	list.add(13);
	list.add(14);
	list.add(15);
	list.remove(0);
	list.remove(15);
	list.remove(10);
	list.insert(10, 10);
	list.insert(15, 14);
	
	cout << "Count: " << list.getCount() << endl;

	for (size_t i = 0; i < list.getCount(); i++)
	{
		cout << list[i] << endl;
	}

}