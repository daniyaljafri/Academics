#include<iostream>
using namespace std;
int ismember(int arr[], int s, int n)
{
	if (s == 0)
		return -1;
	else if (arr[s - 1] == n)
		return 0;
	else
		ismember(arr, s - 1, n);

}

void pfact(int n)
{
	if (n == -1)
		return;
	int f = 1;
	for (int i = 1; i < n+1; i++)
	{
		f = f * i;
	}
	pfact(n - 1);
	cout << f << " ";
}
int sumdigit(int x)
{
	
	if (x / 10 == 0)
		return x;
	int sum = 0;
	while (x != 0)
	{

		sum = sum + (x % 10);
		x = x / 10;

	}
	return sumdigit(sum);
	
}
void flip(float arr[], int s, int starting, int ending)
{
	if (starting < ending)
	{
		swap(arr[starting], arr[ending]);
		flip(arr,s, starting + 1, ending - 1);
	}
}
int stringCompare(char const* string1, char const* string2, int i)
{
	if (string1[i] == '\0' && string2[i] == '\0')
		return 0;
	else if (string1[i] > string2[i])
	{
		return 1;
	}
	else if (string1[i] < string2[i])
	{
		return -1;
	}

	else
	return stringCompare(string1, string2, i + 1);
	
}

int main()
{
	int arr[] = { 1,2,3,4 };
	int size = 4;
	cout << "is member:"<<endl<<ismember(arr, size, 4) << endl;
	cout << "factorials:" << endl;
	pfact(4);
	cout <<endl<< "sum digit:"<<endl<<sumdigit(795) << endl;
	float arr1[5] = { 1.0,5.4,0.85,91.2,6.5};
	flip(arr1, 5, 0, 4);
	cout << "flip function:" << endl;
	for (int i = 0; i < 5; i++) {
		cout << arr1[i] << " ";
	}
	cout << endl;
	cout << "string comparison:"<<endl;
	char const* str1 = "lab6";
	char const* str2 = "lab6";
	cout << stringCompare(str1, str2, 0);


	

	return 0;
}
