#include <iostream>

using namespace std;



int lungime = 0;



int citire(int v[100])
{
	int i=1;
	cin >> v[0];
	while (v[i-1]!=0)
	{
		cin >> v[i];
		i++;
		lungime++;
	}

	return v[100];
}

int modifica(int v[100], int poz, int val)
{
	
	v[poz] = val;


	return v[100];
}

int inserare(int v[100], int poz, int val)
{
	for (int i = lungime; i >=poz; i--)
		v[i+1] = v[i];


	v[poz] = val;
	lungime ++;

	return v[100];
}

int stergere(int v[100], int poz)
{
	for (int i = poz; i < lungime-1; i++)
		v[i] = v[i + 1];

	lungime--;

	return v[100];
}

void afisare(int v[100])
{
	for (int i = 0; i < lungime; i++)
		cout << v[i] << " ";
}

int main()
{
	int v[100], poz, val, poz2, val2, poz3;

	cout << "Introduceti elementele sirului:\n";
	citire(v);

	cout << "Sir=";
	afisare(v);
	cout << endl;

	cout << "Introduceti pozitia elementului pe care doriti sa-l schimbati:";
	cin >> poz;

	if (poz > lungime)
		cout << "Pozitia inserata nu exista!\n";
	else
	{
		cout << "Introduceti valoarea pe care doriti sa o schimbati:";
		cin >> val;
		modifica(v, poz, val);
		cout << "Sir=";
		afisare(v);
		cout << endl;
	}

	cout << "Introduceti pozitia pe care doriti sa inserati elementul:";
	cin >> poz2;
	if (poz > lungime)
		cout << "Pozitia inserata nu exista!\n";
	else 
	{
		cout << "Introduceti valoarea pe care doriti sa o inserati:";
		cin >> val2;
		inserare(v, poz2, val2);
		cout << "Sir=";
		afisare(v);
		cout << endl;
	}

	
	cout << "Introduceti pozita pe care doriti sa o stergeti: ";
	cin >> poz3;
	if (poz > lungime)
		cout << "Pozitia inserata nu exista!\n";
	else
	{
		stergere(v, poz3);
		cout << "Sir=";
		afisare(v);
		cout << endl;
	}


	system("pause");
	return 0;
}