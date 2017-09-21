#pragma once
#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

class Calculator;

template <class T>
class Stack
{
private:
	
	const int size;
	int count;
public:
	T *arr;
	friend Calculator;
	Stack(int size);
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


template <class T>
Stack<T>::Stack(int size) : size(size)
{
	arr = new T[size]{};
	count = 0;
}

template <class T>
Stack<T>::Stack(const Stack<T> &obj) : size(obj.size)
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
	{
		this->count--;
		return this->arr[count - 1];
	}
}

template<class T>
T Stack<T>::peek()
{
	if (!this->isEmpty())
		return this->arr[count - 1];
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