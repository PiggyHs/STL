#include<iostream>
using namespace std;

template<class T>//数组实现
class stack
{
public:
	stack(const int& Maxsize)
	{
		MaxTop = Maxsize - 1;
		stack = new T[Maxsize];
		top = -1;
	}
	~stack()
	{
		delete[] Stack;
		Stack = NULL;
	}
	bool IsEmpty()
	{
		return top == -1;
	}
	bool IsFull()
	{
		return top == MaxTop;
	}
	T Top()
	{
		assert(IsEmpty());
		return Stack[top];
	}
	stack<T>&push(const T& x)
	{
		assert(IsFull());
		Stack[++top] = x;
			
	}
	stack<T>&pop()
	{
		assert(IsEmpty());
		--top;
	}
protected:
	int top;
	int MaxTop;
	int* Stack;
};