#include<iostream>
using namespace std;


class Queue {

	int capacity;
	int size;
	int front;
	int rear;
	int* arr;

public:

	Queue(int temp)
	{
		capacity = temp;
		arr = new int[temp];
		front = 0;
		rear = 0;
		size = 0;
	}

	bool isfull()
	{
		if (size == capacity)
			return true;
		else
			return false;
	}

	bool isempty()
	{
		if (size == 0)
			return true;
		else
			return false;
	}

	void enqueue(int temp)
	{
		if (isfull() == true)
		{
			cout << "Queue is full\n";
			return;
		}
		else
		{
			arr[rear] = temp;
			rear = (rear + 1) % capacity;
			size++;

		}
	}

	void dequeue()
	{
		if (isempty() == true)
		{
			cout << "Queue underflow\n";
			return;
		}
		else
		{
			front = (front + 1) % capacity;
			size--;
		}
	}

	int front_disp()
	{
		if (size == 0)
			return -999;
		else
			return arr[front];
	}

	int rear_disp()
	{
		int index = (rear + capacity - 1) % capacity;
		if (size == 0)
			return -999;
		else
			return arr[index];

	}

	void display()
	{
		
		int i = 1;
		while (i <= size)
		{
			int index = (front + i - 1) % capacity;
			cout << arr[index]<<"   ";
			i++;
		}
		cout << endl;
	}
};


int main()
{
	Queue q(4);
	q.enqueue(15);
	q.enqueue(24);
	q.enqueue(415);
	q.enqueue(244);
	q.enqueue(355);
	q.display();
	q.dequeue();
	q.display();
	q.dequeue();
	q.display();
	q.dequeue();
	q.display();
	q.dequeue();
	q.display();
	q.dequeue();
	q.display();


	cout<<q.front_disp()<<endl;
	cout<<q.rear_disp() << endl;

	q.enqueue(415);
	q.enqueue(41536);
	cout << q.front_disp() << endl;
	cout << q.rear_disp() << endl;
	return 0;
}
