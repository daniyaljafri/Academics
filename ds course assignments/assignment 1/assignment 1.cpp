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
	void insert(iterator it, t d)
	{
		node* te = it.current;
		node* temp = new node;
		temp->data = d;
		temp->next = te->next;
		te->next = temp;

	}
	iterator remove(iterator it)
	{
		node* te = it.current;
		te->data=te->next->data
		node* temp = te->next;
		 te->next=temp->next;
		 delete temp;

	}

	list()
	{
		head = tail = nullptr;
		size++;
	}
	node& insertSorted()
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

	block(int s = 0, int t = 0)
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
	void insertb(int d,block& b)
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
class memorymanagement
{
	list<block> pool;
	list<program> progs;
	int sizeofmemory;
	bool strategy;
public:
	memorymanagement(int s, int a)
	{
		sizeofmemory = s;
		if (a == 1)
			cout << "best fit";
		else if (a == 0)
			cout << "first fit";
	}
	bool getter(int, int)
	{


	}
	bool setter(int a)
	{
		

	}
	int findprogram(int){
	}
	block getbytes(int){}
	void printpool(){}
	void printprogs(){}
	void deleteprogram(int){}
	void poolmerge(){}

};
int main()
{	bool strategy = false;
		bool run = true;
		int RAM = 0;
		int input = 0;

		cout << "Enter True (1) for First Come Strategy && False (0) for Best Fit Strategy" << endl;
		cin >> strategy;
		cout << endl;

		cout << "Enter RAM size" << endl;
		cin >> RAM;

		memorymanagement object(RAM, strategy);
		object.insertb(0, RAM);

		while (run == true)
		{
			cout << endl;
			cout << "Press 1 to enter a program" << endl;
			cout << "Press 2 to delete a program" << endl;
			cout << "Press 3 to view the Pool (Memory of free blocks)" << endl;
			cout << "Press 4 to view the Programs in Memory" << endl;
			cout << "Press 5 to exit the program" << endl;
			cout << endl;

			cin >> input;

			if (input == 1)
			{
				int programId;
				int memoryRequired = 0;
				cout << "Enter Program ID" << endl;
				cin >> programId;
				cout << "Enter memory required for the program" << endl;
				cin >> memoryRequired;
				if (object.getter(programId, memoryRequired))
				{
					cout << "Memory succesfully allocated" << endl;
				}
				else
				{
					cout << "Memory not available" << endl;
				}
			}
			else if (input == 2)
			{
				int programId ;
				cout << "Enter Program ID which you wish to delete for eg P1" << endl;
				cin >> programId;
				if (object.deleteprogram(programId))
				{
					cout << "Memory succesfully deallocated" << endl;
				}
				else
				{
					cout << "Memory can't be deallocated. Program does not exist" << endl;
				}
			}
			else if (input == 3)
			{
				object.printpool();
			}
			else if (input == 4)
			{
				object.printprogs();
			}
			else if (input == 5)
			{
				run = false;
				cout << "Program exited." << endl;
			}
			else
			{
				cout << "Invalid Input. Enter again" << endl;
			}
		}
	}

