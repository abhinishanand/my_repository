#include<iostream>
using namespace std;


class myarray {
	int** temp;
	int row;
	int col;

public:
	myarray(int m, int n)
	{
		cout << "Table is created\n";
		row = m;
		col = n;
		temp = new int* [m];
		for (int i = 0; i < m; i++)
			temp[i] = new int[n];


		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				temp[i][j] = 0;


	}

	~myarray()
	{
		cout << "table is deleted\n";
		for (int i = 0; i < row; i++)
			delete(temp[i]);

		delete(temp);
	}
	void display()
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				cout << temp[i][j] << "  ";

			cout << endl;
		}
	}

	void insert(int m, int n, int val)
	{
		temp[m][n] = val;
	}

	int pop(int m, int n) {
		return temp[m][n];
	}
		


};



int coinchange(int S[], int m, int N) {

	int row = m + 1;
	int col = N + 1;
	myarray table(row, col);

	for (int i = 0; i < row; i++)
		table.insert(i, 0, 1);
		//table[i][0] = 1;

	


	for(int i=1;i<m+1;i++)
		for (int j = 1; j < N+1; j++)
		{
			int den = S[i-1];
			int value;
			if (j - den < 0)
				value = 0;
			else
				value = table.pop(i, j - den);
				//value = table[i][j - den];

			int ctr = value + table.pop(i - 1, j);
			table.insert(i, j, ctr);
			//table[i][j] = value + table[i - 1][j];
		}

		table.display();

		return table.pop(m, N);
	//return table[m][N];
}

int main()
{
	int S[] = { 1,2,5 };
	int m = 3;
	int N = 5;

	int out = coinchange(S,m,N);

	cout << "The maximum number of combinations are " << out << endl;
	return 0;
}