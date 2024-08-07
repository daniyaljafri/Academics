#include<iostream>
using namespace std;
template<class T>
class list
{
private:
	class node
	{
	public:
		T data;
		node* next;
	};
	node* head;
	node* tail;
	int size = 0;
public:
	list()
	{
		head =new node;
			tail = new node;
			head->next = tail;
			tail->next = head;
	}
	class iterator
	{
		friend class list<T>;
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
		T& operator*()
		{
			return current->data;
		}
		iterator& operator++(int)
		{
			current = current->next;
			return *this;
		}
		bool operator!=(iterator it)
		{
			if (current != it.current)
			{
				return true;
			}
			else {
				return false;
			}
		}
		bool operator==(iterator it)
		{
			if (current == it.current)
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
		
			void insert(iterator it,T d)
			{
				
				node* temp = new node;
				temp->data = d;
				temp->next = it.current->next;
				it.current->next = temp;
				if (tail == it.current)
				{
					T tem;
					tem = temp->data;
					temp->data = it.current->data;
					it.current->data = tem;
					tail = temp;
				}
				

			}
			void print()
			{
				
				for (iterator it=begin(); it!=end(); it++)
				{
					cout << *it;
				}
			}
			void printNth(int index)
			{
				int a = 0;
				for (iterator it = begin(); it != end(); it++)
				{
					if (a == index)
					{
						cout << *it;
					}
					a++;
				}

			}
			bool search(T const& element)
			{
				for (iterator it = begin(); it != end(); it++)
				{
					if (*it==element)
					{
						return true;
					}
				}
				
			}
			void deleteatstart(iterator it)
			{
				iterator it=begin();
				
				
				node* temp = it.current;
				if (temp == tail)
					return;
				head->next = temp->next;
				
				delete temp;
				
			}
			int sum()
			{
				int sum = 0;
				for (iterator it = begin(); it != end(); it++)
				{
					sum = sum + (*it);
				}
				return sum;

			}
		
	/*	~list()
			{
				iterator it = begin();
				while (it!=end())
				{
				it++;
					delete deleteatstart();
				
				}
				delete head;
				delete tail;
			}*/


	};
	int main()
	{
		list<int> l1;
		list<int>::iterator it = l1.begin();
		l1.insert(it,5);
		l1.insert(it,6);
		l1.insert(it,7);
		l1.print();
		l1.sum();
		l1.printNth(2);
		


	}