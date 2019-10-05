#include<iostream>
using namespace std;



void bubblesort(int ar[], int size)
{
	for(int i=0;i<size-1; i++){
		for (int j = 0; j < size - 1; j++)
		{
			if (ar[j] > ar[j + 1])
			{
				int temp = ar[j];
				ar[j] = ar[j + 1];
				ar[j + 1] = temp;
			}
		}

		for (int i = 0; i < size; i++)
			cout << ar[i] << " ";
		cout << endl;
	}
		
}




int main()
{
	const int size = 10;
	int ar[size] = { 743737, 373444,4423, 4337, 2494, 2134, 773, 373, -464, -474 };

	for (int i = 0; i < size ;i++)
		cout << ar[i] << " ";
	cout << endl;

	bubblesort(ar, size);

	

	return 0;


}