#include<iostream>
using namespace std;
template<class t>
class list
{
private:
	class node
	{
	public:
		t data;
		node* next;
	};
	node* head;
	node* tail;
	int size=0;
public:
	list()
	{
		head = tail = nullptr;
		size++;
	}
	void &insertSorted()
	{
		node* p, * pn, c;
		p = head;
		while (p->next != nullptr)
		{
			pn = p->next;
			while (pn != nullptr)
			{
				if (p->data > pn->data)
				{
					c = p->data;
					p->data = pn->data;
					pn->data = c;
				}
				pn = pn->next;
			}
			p = p->next;
		}

	}
	void insertstart(t d)
	{
		node* temp = new node[d];
		temp->data = d;
		temp->next = head;
		if (!head)
		{
			head = tail = temp;
		}
		else
			head = temp;
		insertSorted();


	void print()
	{
		node* current = head;
		while (current != nullptr)
		{
			cout << current->data;
			current = current->next;
		}
	}
	
	bool search(t const& d)
	{
		node* temp = head;
		while (temp != nullptr)
		{
			if (temp->data == d)
			{
				return true;
				break;
			}
			temp = temp->next;
		}
		return false;
	}

	void deleteAtStart()
	{
		if (head != nullptr)
		{
			node* temp = head;
			head = head->next;
			delete temp;
		}
		if (head == nullptr)
		{
			tail = nullptr;
		}
	}
	void deleteAtTail()
	{
		if (head != nullptr)
		{
			if (head == tail)
			{
				delete head;
				head = tail = nullptr;
			}
			else
			{
				node* T = head;
				while (T->next != tail)
				{
					T = T->next;
				}

				delete tail;
				tail = T;
				tail->next = nullptr;
			}
		}


	}
	~list()
	{
		while (head)
		{
			deleteAtStart();
		}
	} 
};

class block
{
		int startbyteid;
		int totalbyte;
	public:
		
		block(int s, int t)
		{
			startbyteid = s;
			totalbyte = t;
		}

	};
class program
{
	int id;
	int size;
	list<block> program;
public:
	program()
	{

	}
};
class memorymanagemet
{
	list<block> pool;
	list<program> progs;
	int sizeofmemory;
	bool stratety;
public:
	memorymanagemet()
	{

	}

};
int main()
{
	

}