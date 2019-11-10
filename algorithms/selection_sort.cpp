#include<iostream>
using namespace std;

int comparison = 0;
void swap(int& a, int& b)
{
	
	int temp = a;
	a = b;
	b = temp;
}
void display(int* ar, const int size)
{
	for (int i = 0; i < size; i++)
		cout << ar[i] << " ";

	cout << endl;
}

int tcomp = 0;

void selection_sort(int* ar, int size)
{
	for (int i = 0; i < size; i++)
	{
		int min = 200000000;
		int index = i;
		for (int j = i; j < size; j++)
		{
			tcomp++;
			comparison++;
			if (ar[j] < min)
			{
				
				min = ar[j];
				index = j;
			}
		}

		swap(ar[i], ar[index]);
	}
}



int main()
{
	const int size = 10;
	int ar[size] = {3,4,5,2,4,-6,77,2,-2,4 };
	display(ar, size);
	selection_sort(ar, size);
	display(ar, size);

	cout << "Time complexity = " << tcomp << "  #comparisons = " << comparison << endl;

	return 0;
}
