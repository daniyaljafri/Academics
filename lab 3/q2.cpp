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
		node* prev;
	};
	node* head;
	node* tail;
public:
	list()
	{
		head = new node;
		tail = new node;
		head->next = tail;
		head->prev = nullptr;
		tail->next = nullptr;
		tail->prev = head;
	}
	void insertAtHead(t const element)
	{
		node* temp = new node;
		temp->data = element;
	
		temp->prev = head;
		temp->next = head->next;
		head->next->prev = temp;
		head->next = temp;
		
		
	}
	void insertAtTail(t const element)
	{
		node* temp = new node;
		temp->data = element;
		temp->next = tail;
		temp->prev = tail->prev;
		tail->prev->next = temp;
		tail->prev = temp;

	}
	void print()
	{
		node* current = head->next;
		while (current != nullptr)
		{
			cout << current->data;
			current = current->next;
		}
	}
	void deleteAtStart()
	{
		if (head != nullptr) {
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
		if (head->next != tail)
		{
			node* temp = tail->prev;
			temp->prev->next = tail;
			tail->prev = temp->prev;
			delete temp;
		}
	}
	void printrev()
	{
		node* current = head;
		node* prev = NULL, * next = NULL;

		while (current != nullptr)
		{

			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
		print();

	}

	~list()
	{
		while (head)
		{
			deleteAtStart();
		}
	}
};
int main()
{
	list<int> l1;
	l1.insertAtHead(4);
	l1.insertAtHead(7);
	l1.insertAtHead(9);
	
	l1.print();
	cout << endl;
	l1.printrev();
	cout << endl;
	l1.deleteAtStart();
	l1.print();

	


}