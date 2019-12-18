#include <iostream>
#include <iomanip>

using namespace std;

class matrix
{
public:
	int** A;
	int n;
	int m;
	string name;
	matrix(string a)
	{
		cout << "pass size nxm of " << a << " matrix" << endl;
		cin >> n;
		cin >> m;
		A = new int* [n];
		for (int i = 0; i < n; i++)
		{
			A[i] = new int[m];
		}
		fill();
		name = a;
	}
	int fill()
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				cout << i << ':' << j << " = ";
				cin >> A[i][j];
				cout << endl;
			}
		return **A;
	}
	void print()
	{
		cout << name << " =" << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << A[i][j] << " : ";
			}
			cout << endl;
		}
		cout << endl;
	}
};

void ManageYourMemoryWithMallockAndFree(matrix M)
{
	for (int i = 0; i < M.n; ++i)
		delete[] M.A[i];
	delete[] M.A;
}

void solution(matrix b)
{
	int* x = new int (b.m + 2);
	int j = 0;
	for (int i = 0; i < b.n; i++)
	{
		for (j = 0; j < b.m; j++)
		{
			cout << setw(2) << b.A[i][j] << "*x" << j << " : ";
		}
		cout <<"-1*x" <<j+1 << " : 1*x" << j+2 << endl;
	}

}

int main()
{
	bool test = false;
	cout << "Pass value of matrix D1" << endl;
	matrix y("D1");
	cout << "Pass value of matrix D2" << endl;
	matrix z("D2");
	cout << "Pass value of matrix A" << endl;
	matrix a("a");
	// variables

	solution(a);

	if (test)
	{
		y.print();
		z.print();
		a.print();
	}

	ManageYourMemoryWithMallockAndFree(y);
	ManageYourMemoryWithMallockAndFree(z);
	ManageYourMemoryWithMallockAndFree(a);
	return 0;
}
