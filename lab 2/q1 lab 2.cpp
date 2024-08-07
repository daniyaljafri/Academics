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
public:
	list()
	{
		head = tail = nullptr;
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

	}
	void insertend(t d)
	{
		if (head == nullptr)
		{
			insertstart(d);
		}
		else
		{
			node* temp = new node;
			temp->data = d;
			temp->next = NULL;
			tail->next = temp;
			tail = temp;
		}
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
	bool search(t const&d)
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
	bool isempty()const
	{
		if (head == nullptr)
			return true;
		else
			return false;
	}
	void printrev() 
	{
		node* current = head;
		node* prev = NULL, * next = NULL;
		
		while (current != nullptr)
		{
			
			next= current->next;
			current->next=prev;
			prev = current;
			current = next;
		}
		head = prev;
		print();

	}

};
int main()
{
	list<int> l1;
	l1.insertstart(4);
	l1.insertstart(7);
	l1.insertstart(9);
	l1.insertend(2);
	l1.insertstart(3);
	l1.insertstart(7);
	l1.insertstart(1);
	l1.print();
	cout << endl;
	cout<< "number found" << l1.search(2);
	cout << endl;
	cout<< "number found" << l1.search(9);
	cout << endl;
	cout<<"number found"<<l1.search(7);
	cout << endl;
	l1.printrev();

}
