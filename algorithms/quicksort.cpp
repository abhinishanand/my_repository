#include<iostream>
using namespace std;

void display(int ar[], int size)
{
	cout << "[";
	for (int i = 0; i < size; i++)
	{

		cout << ar[i] << " ";

	}
	cout << "]" << endl;
}


int partition(int ar[], int left, int rgt)
{
	int pivot;
	pivot = ar[left];

	int i, j;
	i = left;
	j = rgt;

	while (i < j) {
		do
		{
			i++;
		} while (ar[i] <= pivot);

		do {
			j--;
		} while (ar[j] > pivot);

		if (i < j)
		{
			int temp = ar[i];
			ar[i] = ar[j];
			ar[j] = temp;
		}

	}

	ar[left] = ar[j];
	ar[j] = pivot;


	return j;
}

void quicksort(int ar[], int left, int rgt)
{
	int j;
	if (left < rgt) {
		j = partition(ar, left, rgt);
		quicksort(ar, left, j);
		quicksort(ar, j + 1, rgt);

	}

}

int main()
{
	const int size = 10;
	int ar[size] = { 4,3,211,13,34,21,-443,32,0,45 };

	ar[size - 1] = 200000;
	display(ar, size);
	quicksort(ar, 0, size - 1);
	display(ar, size);

	return 0;

}