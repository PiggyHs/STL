#include<iostream>
#include<windows.h>
#include<assert.h>
#include<string>

using namespace std;

template<typename T>
class Vector
{
public:
	Vector()
		: _data(NULL)
		, _size(0)
		, _capacity(0)
	{}

	Vector(const T& t)
		: _data(NULL)
		, _size(0)
		, _capacity(0)
	{
		PushBack(t);
	}

	Vector(const Vector& v)
		: _size(v._size)
		, _capacity(v._capacity)
		, _data(new T[_size])
	{
		T* tmp = new T[v._size];
		for (size_t i = 0; i < _size; i++)
		{
			tmp[i] = v._data[i];
		}
		delete[] tmp;
		_data = tmp;
	}

	Vector& operator = (Vector v)
	{
		this->Swap(v);
		return *this;
	}
	void Swap(Vector &v)
	{
		swap(_size, v._size);
		swap(_capacity, v._capacity);
		swap(_data, v._data);
	}
	~Vector()
	{
		delete[] _data;
		_data = NULL;
		_size = _capacity = 0;
	}

	void PushBack(const T& t)
	{
		_CheckCapacity();
		_data[_size++] = t;
	}

	void PopBack()
	{
		assert(_size > 0);
		--_size;
	}

	void Insert(size_t pos, const T& t)
	{
		assert(pos <= _size);
		CheckCapacity();
	
		size_t end = _size - 1;
		while (end >= pos)
		{
			_data[end + 1] = _data[end];
			--end;
		}
		_data[pos] = t;
		_size++;
	}

	void Erase(size_t pos)
	{
		assert(pos < _size);
		size_t begin = pos;
		while (begin <= _size)
		{
			_data[begin] = _data[begin + 1];
		}
		_size--;
	}
	void Print()
	{
		size_t i = 0;
		while (i < _size)
		{
			cout << _data[i] <<" ";
			i++;
		}
		cout << endl;
	}

	T& operator[](size_t pos)
	{
		assert(pos < _size);
		return _data[pos];
	}
private:
	T* _data;
	size_t _size;//数组大小
	size_t _capacity;//容量大小
	void _CheckCapacity()
	{
		if (_capacity == 0)
		{
			_capacity = 1;
			_data = new T[_capacity];
		}
		if (_size >= _capacity)
		{
			size_t NewCapacity = _capacity * 2;
			T* tmp = new T[NewCapacity];
			for (size_t i = 0; i < _size; i++)
			{
				tmp[i] = _data[i];  
			}
			
			delete[] _data;
			_data = tmp;
			_capacity = NewCapacity;
		}
	}
};

void Text()
{
	Vector<int>v1;
	v1.PushBack(1);
	v1.PushBack(2);
	v1.PushBack(3);
	v1.PushBack(4);
	v1.Print();
	v1[0] = 40;
	v1.Print();
	v1.PopBack();
	v1.PopBack();
	v1.PopBack();
	v1.PopBack();
	v1.Print();

	Vector<double>v2;
	v2.PushBack(1.11);
	v2.PushBack(2.22);
	v2.PushBack(3.33);
	v2.PushBack(4.44);
	v2.Print();

	Vector<string>v3;
	v3.PushBack("2dddddddddddddddddddddddddddddddddddd2");
	v3.PushBack("22");
	v3.PushBack("22");
	v3.PushBack("22");
	v3.Print();
}
#pragma once

#include<assert.h>
#include<iostream>
using namespace std;

template<class T>
class Vector
{
public:
	typedef T* Interator;
	Vector()
		:_start(NULL)
		, _finish(NULL)
		, _end_of_stroge(NULL)
	{}
	size_t Size()
	{
		return _finish - _start;
	}
	size_t Capacity()
	{
		return _end_of_stroge - _start;
	}
	void PushBack(const T& x)
	{
		Erend(Capacity() * 2 + 1);
		*_finish = x;
		_finish++;
	}

	void Reserve(size_t n)
	{
		if (n > Capacity())
		{
			Erend(n);
		}
	}

	void Resize(size_t n, const T& val = T())
	{
		if (n > Capacity())
			Erend(n);
		if (n <= Size())
		{
			_finish = _start + n;
		}
		else
		{
			for (size_t i = Size(); i < n; i++)
			{
				*_finish = val;
				_finish++;
				
			}
		}
	}

protected:
	void Erend(size_t n)
	{
		assert(n > 0);
		assert(n > Capacity());
		T* tmp = new T[n];
		size_t size = Size();

		for (size_t i = 0; i < Size(); ++i)
		{
			tmp[i] = _start[i];
		}
		delete[] _start;

		_start = tmp;
		_finish = _start + size;
		_end_of_stroge = _start + n;
	}
protected:
	Interator _start;
	Interator _finish;
	Interator _end_of_stroge;
};
