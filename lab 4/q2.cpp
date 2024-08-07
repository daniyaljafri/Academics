#include<iostream>
using namespace std;
template<class t>
class dlist {
private:
	class dnode {
	public:
		t data;
		dnode* next;
	};
	dnode* tail;
public:
	dlist() {
		tail = new dnode;
		tail->next = tail;
	}
	void ifempty() {
		if (tail->next == tail) {
			cout << "List is empty." << endl;
		}
		else {
			cout << "List is not empty." << endl;
		}
	}
	void destroythelist() {
		dnode* temp = tail->next;
		for (; temp->next != tail;) {
			temp->data = temp->next->data;
			temp->next = temp->next->next;
			delete temp->next;
			temp = temp->next;
		}
	}
	void print() {
		dnode* temp = tail->next;
		for (; temp->next != tail;) {
			cout << temp->data << endl;
			temp = temp->next;
		}
		cout << temp->data << endl;
	}
	void length() {
		dnode* temp = tail->next; int count = 0;
		for (; temp->next != tail->next;) {
			count++;
			temp = temp->next;
		}
		cout << "Length of the list: " << count << endl;
	}
	bool search(t d) {
		dnode* temp = tail->next;
		for (; temp->next != tail;) {
			if (temp->data == d) {
				return true;
			}
		}
		return false;
	}
	void insertatstart(t d) {
		dnode* temp = new dnode;
		temp->data = d;
		temp->next = tail->next;
		tail->next = temp;
	}
	void insertatend(t d) {
		dnode* temp = new dnode;
		dnode* cur = tail->next;
		temp->data = d;
		for (; cur->next != tail;) {
			cur = cur->next;
		}
		cur->next = temp;
		temp->next = tail;
	}
	void inseratgivenposition(t& d, t dd) {
		dnode* temp = new dnode;
		dnode* cur = tail;
		temp->data = dd;
		for (int i = 2; i <= d; i++) {
			cur = cur->next;
		}
		temp->next = cur->next;
		cur->next = temp;
	}
	void deleteatstart() {
		dnode* temp = tail->next;
		tail->next = temp->next;
		delete temp;
	}
	void deleteatgivenposition() {
		int position;
		cout << "Enter position: ";
		cin >> position;

	}
	void deleteatend() {

	}
	~dlist() {

	}
};
int main() {
	dlist<int>obj; int d, i;
	obj.ifempty();
	obj.insertatstart(3);
	obj.insertatstart(5);
	
	obj.insertatend(8);
	obj.insertatend(9);
	obj.print();
	obj.length();
	cout << "Enter the position you want to enter data: ";
	cin >> i;
	cout << "Enter data: ";
	cin >> d;
	obj.inseratgivenposition(i, d);
	obj.print();
	obj.ifempty();
	obj.length();
	cout << "After deleting from start: ";
	obj.deleteatstart();
	obj.print();
	
	system("pause");
	
}