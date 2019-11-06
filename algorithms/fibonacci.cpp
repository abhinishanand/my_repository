#include<iostream>
using namespace std;

#define MAX 100
#define NIL -1
long long int lookup[MAX];
long long int fib(int n)
{
	long long int a, b;
	a = 0;
	b = 1;

	long long sum = 0;
	for (int i = 2; i < n + 1; i++)
	{

		sum = a + b;
		a = b;
		b = sum;
		cout << sum << endl;
	}

	return sum;
}


long long int fib2(int n)
{
	

	if (n <= 1)
		return n;
	else
		return fib2(n - 1) + fib2(n - 2);

}


void __initialize()
{
	for (int i = 0; i < MAX; i++)
		lookup[i] = NIL;
}

long long int fib3(int n)
{

	if (n <= 1) 
		lookup[n] = n;
	else
		lookup[n] = fib3(n - 1) + fib3(n - 2);
			
	return lookup[n];
}

int main()
{
	int n;
	cout << "Enter the number to find the fibonacci no \n";
	cin >> n;

	__initialize();
	long long int fb = fib3(n);

	cout << "Fibonacci no of " << n << " = " << fb << endl;
	return 0;
}