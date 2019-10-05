#include<iostream>
using namespace std;

void display(int ar[], int size)
{
	cout << "[";
	for (int i = 0; i < size; i++)
		cout << ar[i] << " ";
	cout << "]"<<endl;
}
void merge(int ar[], int left, int mid, int rgt, int size)
{
	static int j;
	
	int k1, k2;
	k1 = left;
	k2 = mid+1;

	while ((k1 <= mid) && (k2 <= rgt))
	{
		/*cout << "Merge(" << j << "): ";
		j++;
		cout << "left=" << left << "  mid=" << mid << "  rgt=" << rgt << "   [";
		display(ar, size);*/
		if (ar[k2] < ar[k1])
		{
			int temp;
			temp = ar[k1];
			ar[k1] = ar[k2];
			ar[k2] = temp;
			k2++;
		}
		else
			k1++;

	}

	if (k1 <= mid)
	{
		for (int i = mid; i >= k1; i--)
		{
			for (int j = i; j < rgt; j++)
			{
				if (ar[j] > ar[j + 1])
				{
					int temp = ar[j];
					ar[j] = ar[j + 1];
					ar[j + 1] = temp;
				}
			}
		}
	}

}

void mergesort(int ar[], int left, int rgt, int size)
{
	static int i;
	
	if (left >= rgt)
		return;
	else
	{
		/*cout << "Mergesort(" << i << "): ";
		i++;
		cout << "left=" << left << "  rgt=" << rgt << "   [";
		display(ar, size);*/
		int mid = (left + rgt) / 2;
		
		mergesort(ar, left, mid, size);
		mergesort(ar, mid + 1, rgt, size);
		merge(ar, left, mid, rgt, size);
	}
}

int main()
{
	const int size = 10;
	int ar[size] = { 2554,532,431, 334, 285, 187, 133, 122, 44, 3 };
	display(ar, size);


	mergesort(ar, 0, size - 1, size);

	display(ar, size);
	return 0;
}