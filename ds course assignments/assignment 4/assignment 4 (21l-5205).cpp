#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

			   class Record
			   {
			   private:
				   int ISSN;
				   string Title;
				   string* Author;
				   int Ref;
				   int Issue;
				   int NoOfAuthors;

			   public:
				   Record(int i = 0, string t = " ", string* a = NULL, int r = 0, int is = 0, int noa = 0)
				   {
					   ISSN = i;
					   Title = t;
					   Author = a;
					   Ref = r;
					   Issue = is;
					   NoOfAuthors = noa;
				   }
				   void input()
				   {
					   cout << "Enter ISSN: ";
					   cin >> ISSN;
					   cout << "Enter Title: ";
					   cin >> Title;
					   cout << "Enter No. of Authors: ";
					   cin >> NoOfAuthors;
					   Author = new string[NoOfAuthors];
					   for (int i = 0; i < NoOfAuthors; i++)
					   {
						   cout << "Enter Author " << i + 1 << ": ";
						   cin >> Author[i];
					   }
					   cout << "Enter Ref: ";
					   cin >> Ref;
					   cout << "Enter Issue: ";
					   cin >> Issue;
				   }

				   //SET:
				   void setISSN(int i)
				   {
					   ISSN = i;
				   }
				   void setTitle(string t)
				   {
					   Title = t;
				   }
				   void setAuthor(string* a)
				   {
					   Author = a;
				   }
				   void setReference(int r)
				   {
					   Ref = r;
				   }
				   void setIssue(int i)
				   {
					   Issue = i;
				   }
				   void setNOA(int n)
				   {
					   NoOfAuthors = n;
				   }

				   //GET:
				   int getISSN()
				   {
					   return ISSN;
				   }
				   string getTitle()
				   {
					   return Title;
				   }
				   string* getAuthors()
				   {
					   return Author;
				   }
				   int getReference()
				   {
					   return Ref;
				   }
				   int getIssue()
				   {
					   return Issue;
				   }
				   int getNOA()
				   {
					   return NoOfAuthors;
				   }

				   //Print:
				   void PartPrint()
				   {
					   cout << "Information: " << endl << endl;
					   cout << "ISSN: " << ISSN << endl;
					   cout << "Title: " << Title << endl;
					   cout << "Author(s):" << endl;
					   for (int i = 0; i < NoOfAuthors; i++)
					   {
						   cout << Author[i];
					   }
					   cout << endl;
					   cout << "Number Of Reference Books: " << Ref << endl;
					   cout << "Number Of Issueable Books: " << Issue << endl;
				   }

				   void updateRecord()
				   {
					   int inpt = 0;
					   cout << "\t\t\tUPDATE\n\n\n";
					   cout << "Press 1 to update Title." << endl;
					   cout << "Press 2 to update Author." << endl;
					   cout << "Press 3 to update Number Of Reference Books." << endl;
					   cout << "Press 4 to update Number Of Issueable Books." << endl;
					   cout << "Your Choice: ";
					   cin >> inpt;
					   cout << endl;

					   if (inpt == 1)
					   {
						   string Title;
						   cout << "Title: ";
						   cin >> Title;
						   cout << endl;

						   setTitle(Title);
					   }
					   else if (inpt == 2)
					   {
						   int noa = 0;
						   string* a;

						   cout << "Number Of Author(s): ";
						   cin >> noa;
						   cout << endl;

						   a = new string[noa];

						   for (int i = 0; i < noa; i++)
						   {
							   cout << "Author: ";
							   cin >> a[i];
						   }
						   cout << endl;

						   setNOA(noa);
						   setAuthor(a);
					   }
					   else if (inpt == 3)
					   {
						   int nor = 0;
						   cout << "Number Of Reference Books: ";
						   cin >> nor;
						   cout << endl;
						   setReference(nor);
					   }
					   else if (inpt == 4)
					   {
						   int noi = 0;
						   cout << "Number Of Issueable Books: ";
						   cin >> noi;
						   cout << endl;
						   setIssue(noi);
					   }
					   else
					   {
						   cout << "Wrong Input!" << endl;
					   }

				   }
				   // assignment operator for record
				   Record& operator=(const Record& obj)
				   {
					   if (this != &obj)
					   {
						   ISSN = obj.ISSN;
						   Title = obj.Title;
						   Author = obj.Author;
						   Ref = obj.Ref;
						   Issue = obj.Issue;
						   NoOfAuthors = obj.NoOfAuthors;
					   }
					   return *this;
				   }
				   friend bool operator==(const Record& obj, const Record& x);
				   friend bool operator<(const Record& a, const Record& b);

			   };
			   bool operator==(const Record& obj, const Record& x)
			   {
				   return (obj.ISSN == x.ISSN &&
					   obj.Issue == x.Issue &&
					   obj.Ref == x.Ref &&
					   obj.Title == x.Title &&
					   obj.Author == x.Author);
			   }
			   bool operator<(const Record& a, const Record& b)
			   {
				   return (a.ISSN < b.ISSN);
			   }

			   // each hashtable index will have a hash table node which will store the record
			   // as for collision we are using chaining technique so each node will have a pointer to next node

			   struct hashnode {
				   Record* data;
				   hashnode* next;
				   int IssN;
				   hashnode(Record* d, int iss) {
					   data = d;
					   next = NULL;
					   IssN = iss;
				   }

			   };

			   // the hash table is using STL vector to store the hash table nodes
			   // the hash table will have a size which will be the size of the vector(nodes present or record present in the table)
			   class HashTable {
			   private:
				   int SizeOfTable;
				   vector<hashnode*> table;
				   // a universal hash function which will be used to hash the keys 
				   int hash(int key) {
					   return key % SizeOfTable;
				   }

			   public:
				   HashTable(int size = 20) {  //this will initialize the table with 20 size
					   SizeOfTable = size;
					   table.resize(SizeOfTable);
					   for (int i = 0; i < SizeOfTable; i++)
						   table[i] = NULL;
				   }
				  
				   void insertintoTable(int iss, Record* r)
				   {
					   int index = hash(iss);
					   hashnode* temp = table[index];
					   if (temp == NULL)
					   {
						   table[index] = new hashnode(r, iss);
					   }
					   else
					   {
						   while (temp->next != NULL)
						   {
							   if (temp->IssN == iss)
							   {
								   cout << "Record Already Present!" << endl;
								   return;
							   }
							   temp = temp->next;
						   }
						   temp = table[index];
						   while (temp->next != NULL)
						   {
							   temp = temp->next;
						   }
						   temp->next = new hashnode(r, NULL);
					   }

				   }
				 
				   void printspecificrecord(int iss)
				   {
					   int index = hash(iss);
					   bool flag = false;
					   hashnode* temp = table[index];
					   if (temp == NULL)
					   {
						   cout << "No Record Found!" << endl;
					   }
					   else
					   {
						   while (temp != NULL)
						   {
							   if (temp->IssN == iss)
							   {
								   temp->data->PartPrint();
								   flag = true;
							   }
							   temp = temp->next;
						   }
						   if (flag == false)
						   {
							   cout << "No Record Found!" << endl;
						   }

					   }
				   }
				 
				   void deletethebookrecord(int iss)
				   {
					   int index = hash(iss);
					   hashnode* temp = table[index];
					   if (temp == NULL)
					   {
						   cout << "No Record Found!" << endl;
					   }
					   else
					   {
						   bool flag = false;
						   while (temp != NULL)
						   {
							   if (temp->IssN == iss)
							   {
								   temp->data->PartPrint();
								   flag = true;
								   cout << "Are you sure you want to delete this record? (Y/N): ";
								   char ch;
								   cin >> ch;
								   if (ch == 'Y' || ch == 'y')
								   {
									   temp->data = NULL;
									   temp->IssN = -1;
									   cout << "Record Deleted!" << endl;
								   }
								   else
								   {
									   cout << "Record Not Deleted!" << endl;
								   }
							   }
							   temp = temp->next;
						   }
						   if (flag == false)
						   {
							   cout << "No Record Found!" << endl;
						   }
					   }
				   }
				   void updateTheRecord(int iss)
				   {
					   int index = hash(iss);
					   hashnode* temp = table[index];
					   if (temp == NULL)
					   {
						   cout << "No Record Found!" << endl;
					   }
					   else
					   {
						   bool flag = false;
						   while (temp != NULL)
						   {
							   if (temp->IssN == iss)
							   {
								   temp->data->PartPrint();
								   flag = true;
								   cout << "Are you sure you want to update this record? (Y/N): ";
								   char ch;
								   cin >> ch;
								   if (ch == 'Y' || ch == 'y')
								   {
									   temp->data->updateRecord();
									   cout << "Record Updated!" << endl;
								   }
								   else
								   {
									   cout << "Record Not Updated!" << endl;
								   }
							   }
							   temp = temp->next;
						   }
						   if (flag == false)
						   {
							   cout << "No Record Found!" << endl;
						   }
					   }
				   }
				   void printAllRecords()
				   {
					   if (SizeOfTable == 0)
					   {
						   cout << "No Record In The Library!" << endl;
					   }
					   else {

						   for (int i = 0; i < SizeOfTable; i++)
						   {
							   hashnode* temp = table[i];

							   while (temp != NULL)
							   {
								   temp->data->PartPrint();
								   temp = temp->next;
								   cout << endl;
							   }


						   }
					   }
				   }
				   ~HashTable()
				   {
					   for (int i = 0; i < SizeOfTable; i++)
					   {
						   hashnode* temp = table[i];
						   while (temp != NULL)
						   {
							   hashnode* temp2 = temp;
							   temp = temp->next;
							   delete temp2;
						   }
					   }
				   }
			   };
			   class Library
			   {
			   private:
				   HashTable* table;

				   void Createabookrecord()
				   {
					   Record* r = new Record();
					   r->input();
					   table->insertintoTable(r->getISSN(), r);
				   }
				   void Reviewabookrecord()
				   {
					   int iss;
					   cout << "Enter ISSN: ";
					   cin >> iss;
					   table->printspecificrecord(iss);
				   }
				   void deleteRecord()
				   {
					   int iss;
					   cout << "Enter ISSN: ";
					   cin >> iss;
					   table->deletethebookrecord(iss);
				   }
				   void Updateabookrecord()
				   {
					   int iss;
					   cout << "Enter ISSN: ";
					   cin >> iss;
					   table->updateTheRecord(iss);
				   }
			   public:
				   Library()
				   {
					   table = new HashTable();
				   }
				   void Menu()
				   {
					   bool run = true;
					   int input = 0;
					   while (run == true)
					   {
						   //system("CLS");
						   cout << endl;
						   cout << "Press 1 to Insert a Book Record" << endl;
						   cout << "Press 2 to Review a Book Record" << endl;
						   cout << "Press 3 to Update a Book Record" << endl;
						   cout << "Press 4 to Delete a Book Record" << endl;
						   cout << "Press 5 to Print All Records" << endl;
						   cout << "Press 6 to EXIT." << endl;

						   cout << endl;

						   cin >> input;

						   if (input == 1)
						   {
							   Createabookrecord();
						   }
						   else if (input == 2)
						   {
							   Reviewabookrecord();
						   }
						   else if (input == 3)
						   {
							   Updateabookrecord();
						   }
						   else if (input == 4)
						   {
							   deleteRecord();
						   }
						   else if (input == 5)
						   {
							   table->printAllRecords();

						   }
						   else if (input == 7)
						   {
							   run = false;
							   cout << "Program exited." << endl;
						   }
						   else
						   {
							   cout << "Invalid Input. Enter again." << endl;
						   }
					   }
				   }
				   ~Library()
				   {
					   delete table;
				   }
			   };



			   int main()
			   {
				   Library* lib = new Library();
				   lib->Menu();


				   system("pause");
				   return 0;
			   }

			  