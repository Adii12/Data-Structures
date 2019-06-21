#include <iostream>

using namespace std;

int citire(int a[50][50], int n, int m)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			cin >> a[i][j];

	return a[50][50];
}

void afisare(int a[50][50], int n, int m)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}

//Maximul si minimul elem matricii
void max_min(int a[50][50], int n, int m)
{
	int max, min,i,j;
	max = a[0][0];
	min = a[0][0];

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (a[i][j] > max)
				max = a[i][j];
			if (a[i][j] < min)
				min = a[i][j];
		}
	}

	cout << "Maxim=" << max << endl;
	cout << "Minim=" << min << endl;
}

//Maximul elem randului i
int maximRand(int a[50][50], int n, int m, int rand)
{
	int j,max;
	max = a[rand][0];
	for (j = 0; j < m; j++)
	{
		if (a[rand][j] > max)
			max = a[rand][j];
	}

	return max;
}

//Minimul elem coloanei j
int minimCol(int a[50][50], int n, int m, int col)
{
	int i, min;
	min = a[0][col];

	for (i = 0; i < n; i++)
	{
		if (a[i][col] < min)
			min = a[i][col];
	}

	return min;
}

//Maximul pe randuri, minimul pe coloane
void maxRand_minCol(int a[50][50], int n, int m)
{
	int max, min, i, j;
	
	cout << "\nMaxim pe linii:\n";
	for (i = 0; i < n; i++)
	{
		max = a[i][0];
		for (j = 1; j < m; j++)
		{
			if (a[i][j] > max)
				max = a[i][j];
		}
		cout <<"Linia "<<i<<":"<< max << " "<<endl;
	}

	cout << "Minim pe coloane:\n";
	for (j = 0; j<m; j++)
	{
		min = a[0][j];
		for (i = 0; i < n; i++)
		{
			if (a[i][j] < min)
				min = a[i][j];
		}
		cout << "Coloana " << j <<":" << min << " " << endl;
	}
}

int main()
{
	int a[50][50], m, n;
	int rand1, col1;
	cout << "randuri="; cin >> n;
	cout << "col="; cin >> m;

	cout << "Introduceti elem matricei:\n";
	citire(a, n, m);

	//afisare matrice initala
	afisare(a, n, m); 

	cout << endl;
	max_min(a, n, m);

	cout << endl;
	cout << "\nIntroduceti randul pentru care sa se afiseze max:";
	cin >> rand1;
	cout << "Maxim pe rand:" << maximRand(a, n, m, rand1);

	cout << endl;
	cout << "\nIntroduceti coloana pentru care sa se afiseze minimul:";
	cin >> col1;
	cout << "\nMinim pe coloana:" << minimCol(a, n, m, col1);

	cout << endl;
	maxRand_minCol(a, n, m);


	system("pause");
	return 0;

}