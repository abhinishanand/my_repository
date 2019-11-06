#include<iostream>
using namespace std;

void swap(char *p1, char *p2)
{
	char temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void permute(char *arr, int l, int r)
{

	if (l == r)
		cout << arr << endl;
	else {
		for (int i = l; i<=r; i++)
		{
			swap(&arr[i], &arr[l]);
			permute(arr, l + 1, r);
			swap(&arr[i], &arr[l]);
		}
	}
	
}
int main()
{	
	const int size = 4;
	char arr[size] = "abc";
	permute(arr, 0, size - 2);
	return 0;
}