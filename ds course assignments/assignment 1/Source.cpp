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
	int size = 0;
public:
	class iterator
	{ 
		friend class list<t>;
	private:
		node* current;
	public:
	iterator()
	{
		current = nullptr;
	}
	iterator(node* ptr)
	{
		current = ptr;
	}
	t& operator *()
	{
		return current->data;
	}
	iterator& operator++()
	{
		current = current->next;
		return *this;
	}
	bool operator!=(iterator& it)
	{
		if (current != it.current)
			return true;
		else
			return false;
	}
	
	};
	iterator begin()
	{
		iterator it;
		it.current = head->next;
		return it;
	}
	iterator end()
	{
		iterator it;
		it.current = tail;
		return it;
	}
	void insertatstart(t d)
	{
		insert(begin(), d);
	}
	void insertbefore(iterator it, t d)
	{
		node* t = it.current;
		node* temp = new node;
		temp->data = d;
			temp->next = t;
			temp->

	}
	iterator remove(iterator it)
	{
		node* t = it.current;

	}

	list()
	{
		head = tail = nullptr;
		size++;
	}
	node & insertSorted()
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
	}
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

		block(int s=0, int t=0)
		{
			startbyteid = s;
			totalbyte = t;
		}
		void setstartbyteid(int a)
		{
			startbyteid = a;
		}
		void settotalbyte(int a)
		{
			totalbyte = a;
		}
		int getstartbyteid()
		{
			return startbyteid;
		}
		int gettotalbyte()
		{
			return totalbyte;
		}
		bool operator >(block& b)
		{
			if (startbyteid > b.startbyteid)
				return true;
			else 
				return false;
		}
		bool operator <(block& b)
		{
			if (startbyteid < b.startbyteid)
				return true;
			else
				return false;

		}
		friend ostream& operator<<(ostream& out, block& b)
		{
			out << "starting id is";
			out << b.startbyteid;
			out << "total byte is";
			out << b.totalbyte;

		}

	};
	class program
	{
		int id;
		int size;
		list<block> programs;
	public:
		program()
		{
			size = 0;
			id = 0;
		}
		void setid(int a)
		{
			id = a;
		}
		void setsize(int a)
		{
			size = a;
		}
		int getid()
		{
			return id;
		}
		int getsize()
		{
			return size;
		}
		void insertb(block& b)
		{

		}
		block returnfirstb()
		{

		}
		void programmerge()
		{

		}
		friend ostream& operator<<(ostream& out, program& p)
		{
			out << "program id is";
			out << p.id;
			out << "program size is";
			out << p.size;
		}

	};
	class memorymanagemet
	{
		list<block> pool;
		list<program> progs;
		int sizeofmemory;
		bool strategy;
	public:
		memorymanagemet(int s,int a)
		{
			sizeofmemory = s;
			if (a == 1)
				strategy;
			else if (a == 0)
				strategy;
		}
		bool getter(int, int)
		{

		}
		bool setter(int)
		{

		}

	};
	int main()
	{


	}