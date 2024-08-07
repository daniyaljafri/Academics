#include <iostream>
using namespace std;

template <class T> class LinkedList;
class block;
class program;

class block
{
	int start_byte_ID;
	int total_bytes;
public:
	block(int a = 0, int b = 0)
	{
		start_byte_ID = a;
		total_bytes = b;
	}

	int getStart_byte_ID()
	{
		return start_byte_ID;
	}

	int getTotal_bytes()
	{
		return total_bytes;
	}

	void setStart_byte_ID(int a = 0)
	{
		start_byte_ID = a;
	}

	void setTotal_bytes(int a = 0)
	{
		total_bytes = a;
	}

	friend ostream& operator <<(ostream&, const block&);
};


ostream& operator <<(ostream& out, const block& data)
{
	out << data.start_byte_ID << "\t" << data.total_bytes;

	return out;
}

template <class T> class LinkedList
{
	class node
	{
	public:
		T data;
		node* next;
	};
	node* head;
	node* tail;
	int size;
public:
	LinkedList()
	{
		head = createNode(-1);
		tail = createNode(-1);
		head->next = tail;
		size = 0;
	}

	node* createNode(T val)
	{
		node* temp = new node();
		temp->data = val;
		temp->next = nullptr;
		return temp;
	}

	void push(T val)
	{
		tail->data = val;
		tail->next = createNode(-1);
		tail = tail->next;
		size++;
	}

	T pop()
	{
		if (head->next != tail)
		{
			node* temp = head->next;
			T val = temp->data;
			head->next = temp->next;
			delete temp;
			size--;
			return val;
		}
		return -1;
	}

	bool search(T val)
	{
		node* ptr = head->next;
		while (ptr != tail)
		{
			if (ptr->data == val)
			{
				return true;
			}
			ptr = ptr->next;
		}
		return false;
	}

	bool freememorycheck(int memory)
	{
		node* ptr = head->next;
		while (ptr != tail)
		{
			if (ptr->data.getTotal_bytes() >= memory)
			{
				return true;
			}
			ptr = ptr->next;
		}
		return false;
	}

	bool searchprogramid(int ID)
	{
		node* ptr = head->next;
		while (ptr != tail)
		{
			if (ptr->data.getID() == ID)
			{
				return true;
			}
			ptr = ptr->next;
		}
		return false;
	}

	void searchreplaceprogramid(int ID, block programdata)
	{
		node* ptr = head->next;
		while (ptr != tail)
		{
			if (ptr->data.getID() == ID)
			{
				ptr->data.push(programdata);
				ptr->data.addSize(programdata.getTotal_bytes());
				break;
			}
			ptr = ptr->next;
		}
	}

	block splitfirst(int memory)
	{
		node* ptr = head->next;
		while (ptr != tail)
		{
			if (ptr->data.getTotal_bytes() >= memory)
			{
				block object((ptr->data.getStart_byte_ID() + memory), (ptr->data.getTotal_bytes() - memory));
				ptr->data.setTotal_bytes(memory);
				push(object);
				return ptr->data;
			}
			ptr = ptr->next;
		}
	}

	block splitbest(int memory)
	{
		node* temp = head->next;
		node* ptr = head->next;
		while (ptr != tail)
		{
			if (ptr->data.getTotal_bytes() >= memory && ptr->data.getTotal_bytes() < temp->data.getTotal_bytes())
			{
				temp = ptr;
			}
			ptr = ptr->next;
		}

		block object((temp->data.getStart_byte_ID() + memory), (temp->data.getTotal_bytes() - memory));
		temp->data.setTotal_bytes(memory);
		push(object);
		return temp->data;
	}

	void deleteElement(T val)
	{
		node* ptr = head;
		while (ptr != tail && ptr->next->data != val)
			ptr = ptr->next;
		if (ptr != tail)
		{
			node* temp = ptr->next;
			ptr->next = temp->next;
			delete temp;
			size--;
			cout << "Deleted\n";
		}
		else
			cout << "Not Found\n";
	}

	void printList()
	{
		node* ptr = head->next;
		while (ptr != tail)
		{
			cout << ptr->data << "\n";
			ptr = ptr->next;
		}
		cout << endl;
	}

	~LinkedList()
	{
		node* temp;
		while (head->next != tail)
		{
			temp = head->next->next;
			delete head->next;
			size--;
			head->next = temp;
		}
	}
};

class program
{
	int ID;
	int size;
	LinkedList<block> blocks;
public:
	program(int a = 0, int b = 0)
	{
		ID = a;
		size = b;
		blocks = LinkedList<block>();
	}

	int getID()
	{
		return ID;
	}

	int getSize()
	{
		return size;
	}

	void addSize(int a)
	{
		size += a;
	}

	void printList()
	{
		cout << endl;
		blocks.printList();
	}

	void push(block data)
	{
		blocks.push(data);
	}

	friend ostream& operator <<(ostream&, program&);

};

ostream& operator <<(ostream& out, program& data)
{
	out << data.ID << "\t" << data.size << "\n";
	data.printList();

	return out;
}

class memoryManagementSystem
{
	int sizeOfMemory;
	bool strategy;
	LinkedList<block> pool;
	LinkedList<program> programs;
public:
	memoryManagementSystem(int a = 0, bool b = 0)
	{
		sizeOfMemory = a;
		strategy = b;
		pool = LinkedList<block>();
		programs = LinkedList<program>();
	}

	void addBlockToPool(int start_byte_ID, int total_bytes)
	{
		block object(start_byte_ID, total_bytes);
		pool.push(object);
	}

	bool GetMem(int programID, int memoryRequired)
	{
		if (strategy)
		{
			if (pool.freememorycheck(memoryRequired))
			{
				if (programs.searchprogramid(programID))
				{
					block temp;
					temp = pool.splitfirst(memoryRequired);
					programs.searchreplaceprogramid(programID, temp);
					return true;
				}
				else
				{
					program add(programID, 0);
					programs.push(add);
					block temp;
					temp = pool.splitfirst(memoryRequired);
					programs.searchreplaceprogramid(programID, temp);
					return true;
				}
			}
			return false;
		}
		else
		{
			if (pool.freememorycheck(memoryRequired))
			{
				if (programs.searchprogramid(programID))
				{
					block temp;
					temp = pool.splitbest(memoryRequired);
					programs.searchreplaceprogramid(programID, temp);
					return true;
				}
				else
				{
					program add(programID, 0);
					programs.push(add);
					block temp;
					temp = pool.splitbest(memoryRequired);
					programs.searchreplaceprogramid(programID, temp);
					return true;
				}
			}
			return false;
		}
	}

	bool deleteProgram(int programId)
	{
		return true;
	}

	void printMemoryPool()
	{
		cout << endl;
		pool.printList();
	}

	void printProgs()
	{
		cout << endl;
		programs.printList();
	}
};

int main()
{
	bool strategy = false;
	bool run = true;
	int RAM = 0;
	int input = 0;

	cout << "Enter True (1) for First Come Strategy or False (0) for Best Fit Strategy" << endl;
	cin >> strategy;
	cout << endl;

	cout << "Enter RAM size" << endl;
	cin >> RAM;

	memoryManagementSystem object(RAM, strategy);
	object.addBlockToPool(0, RAM);

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
			int programId = 0;
			int memoryRequired = 0;
			cout << "Enter Program ID" << endl;
			cin >> programId;
			cout << "Enter memory required for the program" << endl;
			cin >> memoryRequired;
			if (object.GetMem(programId, memoryRequired))
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
			int programId = 0;
			cout << "Enter Program ID which you wish to delete for eg 1" << endl;
			cin >> programId;
			if (object.deleteProgram(programId))
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
			object.printMemoryPool();
		}
		else if (input == 4)
		{
			object.printProgs();
		}
		else if (input == 5)
		{
			run = false;
			cout << "Program exited." << endl << endl;
		}
		else
		{
			cout << "Invalid Input. Enter again!!" << endl;
		}
	}

	system("pause");
	return 0;
}
