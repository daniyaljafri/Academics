#include<iostream>
using namespace std;

template <class t>

class simplevector
{
	t* a;
	int s;
public:
	simplevector()
	{
		s = 0;
		a = NULL;
	}
	simplevector(int size)
	{
		s = size;
		a = new t[s];
		for (int i = 0; i < s; i++)
		{
			a[i] = 0;
		}
	}
	simplevector(const simplevector& sv)
	{
		s = sv.s;
		a = new t[s];
		for (int i = 0; i < s; i++)
		{
			a[i] = sv.a[i];
		}
	}
	~simplevector()
	{
		delete[]a;
		a = NULL;
	}
	void setsize(int size)
	{
		s = size;
	}
	void seta(t* b)
	{
		for (int i = 0; i < s; i++)
		{
			a[i] = b[i];

		}
	}
	int getsize()
	{
		return s;
	}
	void getarray()
	{
		for (int i = 0; i < s; i++)
		{
			cout<< a[i];
		}
		
	}
	void sortarray(simplevector& sv)
	{
		t temp;
		for (int i = 0; i < sv.s; i++)
		{
			for (int j = 0; j < sv.s - 1; j++)
			{
				if (a[j] > a[j + 1])
				{
					temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}

			}
		}
	}
	int find(t v) {

		for (int i = 0; i < s; i++) {
			if (a[i] == v) {
				return i;
			}
		}
		return -1;
	}
	t* operator+(t c)
	{
		s += 1;
		t* b = new t[s];
		for (int i = 0; i < s - 1; i++)
		{
			b[i] = a[i];
		}
		b[s - 1] = c;
		delete[]a;
		a = new t[s];
		for (int i = 0; i < s; i++)
		{
			a[i] = b[i];
		}
		return a;

	}
	t operator-()
	{
		s -= 1;
		t* b = new t[s];
		for (int i = 0; i < s; i++)
		{
			b[i] = a[i];
		}
		delete[]a;
		a = new t[s];
		for (int i = 0; i < s; i++)
		{
			a[i] = b[i];
		}
		return a;

	}
};
int main()
{
	simplevector<int> s1(3);
	int b[3] = { 2,4,3 };
	s1.seta(b);
	s1.getarray();
	cout<< endl;
	cout << s1.getsize()<<endl;
	simplevector<int> s2(s1);
	int a;
	cout << "enter any element to find" << endl;
	cin >> a;
	cout<<s1.find(a)<<endl;
	s1.sortarray(s1);
	s1.getarray();
cout<<endl;
s1 + 5;
s1.getarray();
	return 0;
}