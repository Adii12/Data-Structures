#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;

struct Vectori {
	char* v1;
	char* v2;
};

typedef int (TIP_PF)(const void*, const void*);

int compare(const void* a, const void* b) {
	return(*(int*)a) - (*(int*)b);
}

int compareChar(const void* a, const void* b) {
	return(*(char*)a) - (*(char*)b);
}

int* generareManual(int* v,int n) {
	int i;

	for (i = 0; i < n; i++) {
		cout << "v[" << i << "]=";
		cin >> v[i];
	}
	qsort(v, n, sizeof(int), compare);

	return v;
}

int* generareAutomat(int* v, int n) {
	
	int a, b;

	srand(time(NULL));
	cout << "Introduceti intervalul [a,b] din care sa se genereze nr:\n";
	cout << "a="; cin >> a;
	cout << "b="; cin >> b;

	for (int i = 0; i < n; i++)
	{
		v[i] = rand() % (b - a + 1) + a;
	}
	qsort(v, n, sizeof(int), compare);

	return v;
}

Vectori generareAutomatChar(Vectori vect, int n) {
	int a=33, b=127;

	srand(time(NULL));
	

	for (int i = 0; i < n; i++) {
		vect.v1[i] = rand() % (b - a + 1) + a;
		vect.v2[i] = rand() % (b - a + 1) + a;
	}
	qsort(vect.v1, n, sizeof(char), compareChar);

	return vect;
}

void afisare(int* v, int n) {
	
	for (int i = 0; i < n; i++) {
		cout << "v[" << i << "]=" << v[i] << " " << endl;
	}
}

int* cautare(int* v, int inf, int sup, int key) {
	int mijl;

	while (inf <= sup) {
		mijl = (inf + sup) / 2;
		
		if (v[mijl] == key)
			return &v[mijl];
		else if (v[mijl] < key)
			inf = mijl + 1;
		else
			sup = mijl - 1;
	}

	return NULL;
}

char* cautareC(char* v, int inf, int sup, char key) {
	int mijl;

	while (inf <= sup) {
		mijl = (inf + sup) / 2;

		if (v[mijl] == key)
			return &v[mijl];
		else if (v[mijl] < key)
			inf = mijl + 1;
		else
			sup = mijl - 1;
	}
	
	return NULL;
}

void* cautareSecventiala(const void* key, const void* v, size_t n, size_t dim, int compareChar(const void*, const void*)) {
	for (int i = 0; i < n; i++) {
		char* adrElement = (char*)v + dim * i;
		if (compareChar(key, adrElement) == 0)
			return adrElement;
	}

	return NULL;
}

int main() {

	LARGE_INTEGER start, stop, frequency;
	int meniu, submeniu;
	int n, key;
	int* adrElement;
	char* adrEl;
	char keyC;
	Vectori vect;

	cout << "Introduceti nr de elemente:";
	cin >> n;
	int* v = new int[n];

	vect.v1 = new char[n];
	vect.v2 = new char[n];

	do {
		system("cls");
		cout << "1. Generare vector manual\n";
		cout << "2. Generare vector automat\n";
		cout << "3. Afisare\n";
		cout << "4. Cautare\n";
		cout << "5. Operatii extinse\n";
		cout << "6. Iesire.\n";
		cout << "Introduceti optiunea dorita:";
		cin >> meniu;

		switch (meniu) {
		case 1: 
			generareManual(v,n);
			cout << "\nVector generat!\n";
			break;

		case 2:
			generareAutomat(v, n);
			cout << "\nVector generat!\n";
			break;

		case 3:
			afisare(v, n);
			system("pause");
			break;

		case 4:
			cout << "\nIntroduceti elementul cautat:";
			cin >> key;

			adrElement = cautare(v, 0, n - 1, key);

			if (adrElement != NULL)
				cout << "Elementul a fost gasit\n\n";
			else
				cout << "Elementul cautat nu exista\n\n";

			system("pause");
			break;

		case 5:
			do {
				system("cls");
				cout << "1. Generare automata a celor 2 vectori\n";
				cout << "2. Afisarea elementelor de pe pozitiile n/4, n/2, n \n";
				cout << "3. Timpul de cautare elem de pe pozitia n/4 \n";
				cout << "4. Timpul de cautare elem de pe pozitia n/2 \n";
				cout << "5. Timpul de cautare elem de pe pozitia n \n";
				cout << "6. Inapoi\n";
				cout << "Introduceti optiunea dorita:";
				cin >> submeniu;

				switch (submeniu) {
				case 1:
					vect = generareAutomatChar(vect, n);
					cout << "\n\nVectorii au fost generati!\n";

					/*cout << endl;
					for (int i = 0; i < n; i++)
					{
						cout << "v1=" << vect.v1[i] << " ";		 
					}											 AFISARE VECTORI
					cout << endl;
					for (int i = 0; i < n; i++) {
						cout << "v2=" << vect.v2[i] << " ";
					}*/
					
					system("pause");
					break;

				case 2:
					cout << "Primul vector:\n";
					cout << "Pozitia n/4: " << vect.v1[n / 4];
					cout << "\nPozitia n/2: " << vect.v1[n / 2];
					cout << "\nPozitia n: " << vect.v1[n-1];

					cout << "\n\nAl doilea vector:\n";
					cout << "Pozitia n/4: " << vect.v2[n / 4];
					cout << "\nPozitia n/2: " << vect.v2[n / 2];
					cout << "\nPozitia n: " << vect.v2[n-1];

					cout << endl;
					system("pause");
					break;

				case 3:
					//timp cautare n/4
					keyC = vect.v1[n / 4];
					
					QueryPerformanceCounter(&start);
					adrEl = (char*)cautareSecventiala(&keyC, vect.v1, n, sizeof(char), compareChar);
					QueryPerformanceCounter(&stop);
					QueryPerformanceFrequency(&frequency);

					cout << "Timp de executie cautare secventiala: " << 1000 * (stop.QuadPart - start.QuadPart) / ((float)frequency.QuadPart) << "(ms)\n";


					QueryPerformanceCounter(&start);
					adrEl = (char*)cautareC(vect.v1, 0, n - 1, keyC);
					QueryPerformanceCounter(&stop);
					QueryPerformanceFrequency(&frequency);

					cout << "Timp de executie cautare binara: " << 1000 * (stop.QuadPart - start.QuadPart) / ((float)frequency.QuadPart) << "(ms)\n";
					
					/*if (adrEl != NULL)
						cout << "Element gasit\n";
					else
						cout << "Elementul cautat nu exista\n";*/

					system("pause");
					break;

				case 4:
					//timp cautare n/2
					keyC = vect.v1[n / 2];

					QueryPerformanceCounter(&start);
					adrEl = (char*)cautareSecventiala(&keyC, vect.v1, n, sizeof(char), compareChar);
					QueryPerformanceCounter(&stop);
					QueryPerformanceFrequency(&frequency);

					cout << "Timp de executie cautare secventiala: " << 1000 * (stop.QuadPart - start.QuadPart) / ((float)frequency.QuadPart) << "(ms)\n";


					QueryPerformanceCounter(&start);
					adrEl = (char*)cautareC(vect.v1, 0, n - 1, keyC);
					QueryPerformanceCounter(&stop);
					QueryPerformanceFrequency(&frequency);

					cout << "Timp de executie cautare binara: " << 1000 * (stop.QuadPart - start.QuadPart) / ((float)frequency.QuadPart) << "(ms)\n";

					system("pause");
					break;

				case 5:
					//timp cautare n
					keyC = vect.v1[n];

					QueryPerformanceCounter(&start);
					adrEl = (char*)cautareSecventiala(&keyC, vect.v1, n, sizeof(char), compareChar);
					QueryPerformanceCounter(&stop);
					QueryPerformanceFrequency(&frequency);

					cout << "Timp de executie cautare secventiala: " << 1000 * (stop.QuadPart - start.QuadPart) / ((float)frequency.QuadPart) << "(ms)\n";


					QueryPerformanceCounter(&start);
					adrEl = (char*)cautareC(vect.v1, 0, n - 1, keyC);
					QueryPerformanceCounter(&stop);
					QueryPerformanceFrequency(&frequency);

					cout << "Timp de executie cautare binara: " << 1000 * (stop.QuadPart - start.QuadPart) / ((float)frequency.QuadPart) << "(ms)\n";

					system("pause");
					break;

				case 6:
					//inapoi
					break;
				}
			} while (submeniu != 6);
			
			break;

		case 6:
			//iesire
			break;
		}

	} while (meniu != 6);

	return 0;
}