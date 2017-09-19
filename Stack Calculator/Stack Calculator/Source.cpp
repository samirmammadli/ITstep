#include <iostream>
#include <string>
using namespace std;

template <class T>
class Stack
{
	T *arr;
	const int size;
	int count;
public:
	Stack(int size) : size(size)
	{
		arr = new T[size];
		count = 0;
	}
	Stack(const Stack<T> &obj);
	~Stack();
	void push(T data); // Add last element
	T pop(); // Remove last element
	T peek(); // Select last element
	bool isOverflow();
	bool isEmpty();
	int getCount();
	int getSize();
};

template <class T> Stack<T>::Stack(const Stack<T> &obj) : size(obj.size)
{
	this->count = obj.count;
	this->arr = new T[size];
	for (int i = 0; i < count; i++)
	{
		this->arr[i] = obj.arr[i];
	}
}

template<class T>
Stack<T>::~Stack()
{
	delete[] this->arr;
}

template<class T>
void Stack<T>::push(T data)
{
	this->arr[count] = data;
	count++;
}

template<class T>
T Stack<T>::pop()
{
	if (!this->isEmpty())
	return this->arr[count-1];
	this->count--;
}

template<class T>
T Stack<T>::peek()
{
	if (!this->isEmpty())
	return this->arr[count-1];
}

template<class T>
bool Stack<T>::isOverflow()
{
	if (count == size - 1)
		return true;
	else
		return false;
}

template<class T>
bool Stack<T>::isEmpty()
{
	if (count == 0)
		return true;
	else
		return false;
}

template<class T>
int Stack<T>::getCount()
{
	return this->count;
}

template<class T>
int Stack<T>::getSize()
{
	return this->size;
}



void test(Stack<int> s1)
{
	cout << s1.peek() << endl;
	cout << s1.getCount() << endl;
	cout << s1.getSize() << endl;
}

void main()
{
	Stack<int> numbers(100);
	Stack<char> operators(100);

	//numbers.push(15);
	test(numbers);

	/*cout << numbers.peek() << endl;
	cout << numbers.getSize() << endl;*/
	//string math = "1+3*2*4-6";
	//

	
}

