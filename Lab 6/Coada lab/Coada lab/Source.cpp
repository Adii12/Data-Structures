#include <iostream>

using namespace std;

struct QueueS {
	int* v = NULL;
	int FRONT;
	int END;
	int MAX;
};

QueueS initializare_CS(QueueS coada) {
	if (coada.v != NULL)
		delete[] coada.v;

	cout << "Max=";
	cin >> coada.MAX;
	coada.v = new int(coada.MAX);
	coada.FRONT = 0;
	coada.END = 0;

	return coada;
}

int main() {
	int meniu;
	QueueS coada;
	
	do {
		system("cls");
		cout << "Introduceti o varianta de la 0-7\n";
		cout << "0. Iesire din program\n";
		cout << "1. Initializare Coada\n";
		cout << "2. Enqueue\n";
		cout << "3. Dequeue\n";
		cout << "4. Top=Peek (afisare vf)\n";
		cout << "5. Empty\n";
		cout << "6. Full\n";
		cout << "7. Afisare stiva\n";
		cin >> meniu;
		
		switch (meniu) {
		case 0: break;
		
		case 1: {
			coada = initializare_CS(coada);
			cout << "Coada intializata\n";
			system("pause");
			break;
		}
		
		case 2: {
			break;
		}//case 2 inchis
		
		case 3: {
			break;
		}//case 3 inchis
		
		case 4: {
			break;
		}
		
		case 5: {
			break;
		}
		
		case 6: {

			break;
		}
		
		case 7: {

			break;
		}
		
		default: {
			cout << "Varianta gresita.\n Introduceti o valoare de la 0-7\n";
		}
		}//switch inchis
				system("cls");
	}//do inchis
	while (meniu != 0);
	
	return 0;
}