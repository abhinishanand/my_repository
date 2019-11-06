
#include<iostream>
using namespace std;

#define size 10

int heap_size = 0;

int parent(int i)
{
	int p = ((i - 1) / 2);
	if (p >= 0 && p < heap_size)
		return p;
	else
		return -1;
}

int left(int i)
{

	int p = (2 * i + 1);
	if (p >= 0 && p < heap_size)
		return p;
	else
		return -1;
}


int rgt(int i)
{

	int p = (2 * i + 2);
	if (p >= 0 && p < heap_size)
		return p;
	else
		return -1;
}
void swap(int* p, int* q)
{
	int tmp = *p;
	*p = *q;
	*q = tmp;
}



int min_child(int* arr, int l, int r)
{
	if (arr[l] < arr[r])
		return l;
	else
		return r;
}

void heapify_up(int* arr, int i)
{
	int l = left(i);
	int r = rgt(i);
	int p = parent(i);

	if (p == -1)
		return;
	
	if (arr[i] < arr[p])
	{
		swap(&arr[i], &arr[p]);
		heapify_up(arr, p);
	}
}

void heapify_down(int* arr, int i)
{
	int l = left(i);
	int r = rgt(i);

	if (l == -1 && r == -1)
		return;

	if (r == -1)
	{
		if (arr[l] < arr[i])
		{
			swap(&arr[l], &arr[i]);
			heapify_down(arr, l);
		}
	}
	else
	{
		int min = min_child(arr, l, r);
		if (arr[min] < arr[i])
		{
			swap(&arr[min], &arr[i]);
			heapify_down(arr, min);
		}

	}
}



void buildheap(int* arr)
{
	for (int i = size / 2; i >= 0; i--)
	{
		heapify_down(arr, i);
	}
}

void display(int* arr)
{
	for (int i = 0; i < heap_size; i++)
		cout << arr[i] << " ";

	cout << endl;

}


void insert(int* heap, int data)
{
	if (heap_size >= size)
		cout << "Heap overflow\n";
	else
	{
		heap[heap_size] = data;
		heap_size++;
		heapify_up(heap, heap_size-1);
	}

}


void delete_min(int* heap)
{
	heap[0] = heap[heap_size - 1];
	heap_size--;

	heapify_down(heap, 0);
}

void heapsort(int* heap)
{
	int msize = heap_size;
	for (int i = 0; i < msize; i++)
	{
		swap(&heap[0], &heap[heap_size - 1]);
		heap_size--;
		heapify_down(heap, 0);
	}

	cout << "Heap sort\n";
	for (int i = 0; i < msize; i++)
		cout << heap[i] << " ";

	cout << endl;

	heap_size = msize;
}


int main()
{

	int heap[size] = {};
	insert(heap, 5);
	insert(heap, 12);
	insert(heap, 3);
	insert(heap, 42);
	insert(heap, 14);
	//display(heap);
	insert(heap, 2);
	insert(heap, 15);
	insert(heap, 7);
	insert(heap, 4);
	insert(heap, 132);

	
	display(heap);
	//delete_min(heap);
	//heapsort(heap);
	//display(heap);
	return 0;

}