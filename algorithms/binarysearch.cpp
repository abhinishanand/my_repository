#include<iostream>
using namespace std;



int binarysearch(int ar[], int n, int left, int rgt)
{
	int mid = (left + rgt) / 2;

	if (left >= rgt)
		return 0;

	if (ar[mid] == n)
		return 1;
	else
	{
		if (n < ar[mid])
			rgt = mid - 1;
		else if (n > ar[mid])
			left = mid + 1;

		return binarysearch(ar, n, left, rgt);

	}

}


int main()
{
	int ar[10] = { 1, 3, 4,8,19, 43, 273,4747, 5775,274849 };
	int n;
	cout << "Enter the element to search \n";
	cin >> n;

	int out = binarysearch(ar, n, 0, 9);

	if (out == 1)
		cout << n << " is present in  array\n";
	else
		cout << n << " is not present in array\n";

	return 0;



}