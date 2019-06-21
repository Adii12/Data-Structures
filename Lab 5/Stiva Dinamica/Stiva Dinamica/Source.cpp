#include <iostream>

using namespace std;

struct nodLSI {
	char data;
	nodLSI* succ;
};

struct StackD {
	nodLSI* LIST=NULL;
	nodLSI* TOP=0;
};

nodLSI* alocare_nod(char info) {
	nodLSI* nod = new nodLSI;
	nod->data = info;
	nod->succ = NULL;

	return nod;
}

bool isEmpty(StackD stiva) {
	if (stiva.TOP == 0)
		return true;
	else
		return false;

}

StackD pop_SD(StackD stiva, char* elementScos) {
	if (isEmpty(stiva)) {
		cout<<"Stiva este goala\n";
		*elementScos = NULL;
	}
	else {
		*elementScos = stiva.TOP->data;
		nodLSI* tmp = stiva.LIST;
		nodLSI* penultim = tmp;
		while (tmp->succ != NULL) {
			penultim = tmp;
			tmp = tmp->succ;
		}
		nodLSI* ultim = tmp;
		if (penultim->succ == NULL) {
			nodLSI* salv = penultim;
			penultim = NULL;
			delete salv;
		}
		else {
			penultim->succ = NULL;
			delete ultim;
		}
		stiva.TOP = penultim;
	}
	return stiva;
}

StackD push_SD(StackD stiva, char info) {
	if (stiva.LIST == NULL) {
		nodLSI* nou = alocare_nod(info);

		stiva.LIST = nou;
		stiva.TOP = nou;
		nou->data = info;
		nou->succ = NULL;
	}
	else {
		nodLSI* tmp = stiva.LIST;

		while (tmp->succ) {
			tmp = tmp->succ;
		}
		nodLSI* ultim = tmp;
		nodLSI* nou = alocare_nod(info);
		ultim->succ = nou;
		nou->succ = NULL;
		nou->data = info;
		stiva.TOP = nou;
	}
	
	return stiva;

}

void peek_SD(StackD stiva) {
	if (!isEmpty(stiva))
		cout << "TOP=" << stiva.TOP->data << endl;
	else
		cout << "Stiva este goala\n";
}

StackD clear_SD(StackD stiva) {
	char elementScos;
	while (!isEmpty(stiva)) {
		stiva = pop_SD(stiva, &elementScos);
	}
	
	return stiva;
}


StackD initializare_SD(StackD stiva) {
	char elementScos;

	while (stiva.TOP != NULL) {
			stiva = pop_SD(stiva,&elementScos);
	}
	return stiva;
}


int main() {
	int meniu;
	StackD stiva;
	
	char info;
	char elementScos=NULL;
	char sir[30];

	stiva = initializare_SD(stiva);
	do {
		
		system("cls");
		cout << "1. Push\n";
		cout << "2. Pop\n";
		cout << "3. Peek\n";
		cout << "4. Is full\n";
		cout << "5. Is empty\n";
		cout << "6. Clear\n";
		cout << "7. Verificare expresie\n";
		cout << "8. Iesire\n";
		cout<<"Introduceti optiunea dorita:\n";
		cin >> meniu;

		switch (meniu) {

		case 1:
			//push
			cout << "Introduceti noul caracter:";
			cin >> info;

			stiva = push_SD(stiva, info);
			break;

		case 2:
			//pop
			stiva = pop_SD(stiva, &elementScos);

			if (elementScos != NULL)
				cout << "Caracter = " << elementScos << endl;
			else
				cout << "Elementul nu a fost scos\n";

			system("pause");
			break;

		case 3:
			//peek
			peek_SD(stiva);
			system("pause");
			break;

		case 4:
			//is full
			break;

		case 5:
			//is empty
			if (isEmpty(stiva))
				cout << "Stiva este goala\n";
			else
				cout << "Stiva nu este goala\n";

			system("pause");
			break;

		case 6:
			stiva = clear_SD(stiva);
			cout << "Stiva a fost initializata\n";

			system("pause");
			break;

		case 7:
			//verificare expresie
			stiva = initializare_SD(stiva);
			system("cls");
			cout << "Introduceti sirul: ";
			cin >> sir;

			for (int i = 0; i < strlen(sir); i++) {
				if (sir[i] == '(' || sir[i] == '[' || sir[i] == '{') {
					stiva = push_SD(stiva, sir[i]);
				}

				if (sir[i] == ')') {
					for (int j = 0; j < i; j++) {
						if (sir[j] == '(') {
							stiva = pop_SD(stiva,&elementScos);
							break;
						}
					}
				}
				if (sir[i] == ']') {
					for (int j = 0; j < i; j++) {
						if (sir[j] == '[') {
							stiva = pop_SD(stiva, &elementScos);
							break;
						}
					}
				}
				if (sir[i] == '}') {
					for (int j = 0; j < i; j++) {
						if (sir[j] == '{') {
							stiva = pop_SD(stiva, &elementScos);
							break;
						}
					}
				}
			}

			break;

		case 8:
			//iesire
			break;
		}
	} while (meniu != 8);

	return 0;
}