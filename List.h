#include<iostream>
#include<assert.h>
using namespace std;

template<class T>
struct ListNode
{
	T _data;
	ListNode<T>* _next;
	ListNode<T>* _prev;

	ListNode(const T& x)
		:_data(x)
		, _next(NULL)
		, _prev(NULL)
	{}
};

template<class T>
class List
{
	typedef ListNode<T> Node;
public:
	List()
	{
		_head = new Node(T());
		_head->_next = _head;
		_head->_prev = _head;
	}

	List(const List& l)
		:_head(new Node(T()))
	{
		_head->_next = _head;
		_head->_prev = _head;
		Node* cur = l._head->_next;
		while (cur != l._head)
		{
			PushBack(cur->_data);
			cur = cur->_next;
		}
	}
	List<T>& operator=(const List<T>& l)
	{
		if (this != &l)
		{
			Node* cur = l._head->_next;
			while (cur != l._head)
			{
				PushBack(cur->_data);
				cur = cur->_next;
			}
		}
		return *this;
	}

	~List()
	{
		/*Node* next = _head->_next;
		while (next != _head)
		{
			Node* cur = next;
			next = next->_next;
			delete cur;
		}*/
		Clear();
		delete _head;
		_head = NULL;
	}

	void PushBack(const T& x)
	{
		/*Node* tail = _head->_prev;

		Node* tmp = new Node(x);
		tail->_next = tmp;
		tmp->_prev = tail;

		_head->_prev = tmp;
		tmp->_next = _head;*/
		Inerst(_head, x);
	}

	void PopBack()
	{
		/*Node* tail = _head->_prev;
		Node* last = tail->_prev;
		delete tail;
		last->_next = _head;
		_head->_prev = last;*/
		Erase(_head->_prev);
	}

	void Inerst(Node* pos, const T& x)
	{
		assert(pos);

		Node* Pos = pos;
		Node* prev = Pos->_prev;
		Node* tmp = new Node(x);

		prev->_next = tmp;
		tmp->_prev = prev;
		tmp->_next = Pos;
		Pos->_prev = tmp;
	}
	void Erase(Node* pos)
	{
		Node* prev = pos->_prev;
		Node* next = pos->_next;
		delete pos;
		prev->_next = next;
		next->_prev = prev;
	}

	void PushFront(const T& x)
	{
		/*Node* tail = _head->_next;
		Node* tmp = new Node(x);

		_head->_next = tmp;
		tmp->_prev = _head;
		tmp->_next = tail;
		tail->_prev = tmp;*/
		Inerst(_head->_next, x);
	}
	void PopFront()
	{
		/*Node* begin = _head->_next;
		Node* tail = begin->_next;
		delete begin;
		_head->_next = tail;
		tail->_prev = _head;*/
		Erase(_head->_next);
	}
	Node* Find(const T& x)
	{
		Node* begin = _head->_next;
		while (begin != _head)
		{
			if (begin->_data == x)
			{
				return begin;
			}
			begin = begin->_next;
		}
		return (Node*)-1;
	}
	void Clear()
	{
		Node* next = _head->_next;
		while (next != _head)
		{
			Node* cur = next;
			next = next->_next;
			delete cur;
		}
		_head->_next = _head;
		_head->_prev = _head;
	}

public:
	void Print()
	{
		Node* begin = _head->_next;
		while (begin != _head)
		{
			cout << begin->_data << "--";
			begin = begin->_next;
		}
		cout << endl;
	}

private:
	Node* _head;
};

void TextList()
{
	List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	l.Print();
	l.PopBack();
	l.Print();
	l.Inerst(l.Find(2), 20);
	l.Print();
	l.Erase(l.Find(20));
	l.Print();
	l.PushFront(30);
	l.Print();
	l.PopFront();
	l.Print();
	List<int> l1(l);
	l1.Print();
	List<int> l2;
	l2 = l1;
	l2.Print();
}
