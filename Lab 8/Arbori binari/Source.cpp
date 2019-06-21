#include <iostream>
#include <time.h>

using namespace std;

struct nodABC {
	int info=0;
	nodABC* fiu_st=NULL;
	nodABC* fiu_dr=NULL;
};

nodABC* alocare_nod_ABC(int info_nou) {
	nodABC* nou = new nodABC;
	nou->info = info_nou;
	nou->fiu_dr = NULL;
	nou->fiu_st = NULL;

	return nou;
}

nodABC* distrugere_ABC(nodABC* ROOT) {
	if (ROOT != NULL) {
		distrugere_ABC(ROOT->fiu_st);
		distrugere_ABC(ROOT->fiu_dr);
		delete ROOT;
	}

	ROOT = NULL;
	return ROOT;
}

nodABC* inserare_ABC(nodABC* ROOT, int info_nou) {
	if (ROOT == NULL) {
		nodABC* nou = alocare_nod_ABC(info_nou);
		ROOT = nou;
	}
	else {
		nodABC* tmp = ROOT;
		nodABC* tata = NULL;

		while (tmp != NULL) {
			tata = tmp;
			if (tmp->info > info_nou)
				tmp = tmp->fiu_st;
			else if (tmp->info < info_nou)
				tmp = tmp->fiu_dr;
			else {
				cout << "Cheie dubla\n";
				return ROOT;
			}
		}

		nodABC* nou = alocare_nod_ABC(info_nou);
		if (tata->info > info_nou)
			tata->fiu_st = nou;
		else
			tata->fiu_dr = nou;
	}

	return ROOT;
}

nodABC* cautare_ABC(nodABC* ROOT, int key) {
	nodABC* tmp = ROOT;
	
	while (tmp != NULL) {
		if (key < tmp->info)
			tmp = tmp->fiu_st;
		else if (key > tmp->info)
			tmp = tmp->fiu_dr;
		else
			return tmp;
	}

	return NULL;
}

int adancime_max(nodABC* ROOT) {
	nodABC* tmp;
	int nr = 0;
	
	int dreapta = 0;  
	int stanga = 0;	  

	if (ROOT == NULL) {
		return 0;
	}
	else {
		dreapta = adancime_max(ROOT->fiu_dr);
		stanga = adancime_max(ROOT->fiu_st);

		if (stanga > dreapta || stanga == dreapta)
			return (stanga + 1);
		else
			return (dreapta + 1);
	}

}

void noduri_nivel(nodABC* ROOT, int nivel, int nivel_dorit) {
	int ajuns = 0;
	if (ROOT == NULL) {
	}
	else {
		if (nivel == nivel_dorit-1) {
			if (ROOT->fiu_dr != NULL)
				cout << ROOT->fiu_dr->info << endl;
			if (ROOT->fiu_st != NULL)
				cout << ROOT->fiu_st->info << endl;
		}
		else {
			noduri_nivel(ROOT->fiu_st, nivel + 1, nivel_dorit);
			noduri_nivel(ROOT->fiu_dr, nivel + 1, nivel_dorit);
		}
	}
}

void inordine(nodABC* ROOT) {
	if (ROOT != NULL) {
		inordine(ROOT->fiu_st);
		cout << "Info:" << ROOT->info << endl;
		inordine(ROOT->fiu_dr);
	}
}

void preordine(nodABC* ROOT) {
	if (ROOT != NULL) {
		cout << "Info:" << ROOT->info << endl;
		preordine(ROOT->fiu_st);
		preordine(ROOT->fiu_dr);
	}
}

void postordine(nodABC* ROOT) {
	if (ROOT != NULL) {
		preordine(ROOT->fiu_st);
		preordine(ROOT->fiu_dr);
		cout << "Info:" << ROOT->info << endl;
	}
}


int main() {
	int meniu, submeniu;
	int info_nou,key,adancime,nivel;
	nodABC* ROOT=NULL;
	nodABC* adr;
	int n, nr;

	do {
		system("cls");
		cout << "1. Operatii de baza\n";
		cout << "2. Operatii extinse\n";
		cout << "3. Iesire\n";
		cout << "Introduceti optiunea:";
		cin >> meniu;

		switch (meniu) {
		case 1:
			//operatii de baza
			do {
				system("cls");
				cout << "1. Inserare\n";
				cout << "2. Traversare inordine\n";
				cout << "3. Traversare preordine\n";
				cout << "4. Traversare postordine\n";
				cout << "5. Cautare\n";
				cout << "6. Distrugere\n";
				cout << "7. Determinara adancime maxima\n";
				cout << "8. Nodurile aflate pe un nivel dat\n";
				cout << "9. Verificare egalitate structurala a doi arbori de cautare\n";
				cout << "10. Inapoi\n";
				cout << "Introduceti optiunea:";
				cin >> submeniu;

				switch (submeniu) {
				case 1:
					//inserare
					cout << "Introduceti informatia noua:";
					cin >> info_nou;
					ROOT = inserare_ABC(ROOT, info_nou);
					break;

				case 2:
					//inordine
					inordine(ROOT);
					system("pause");
					break;

				case 3:
					//preordine
					preordine(ROOT);
					system("pause");
					break;

				case 4:
					//postordine
					postordine(ROOT);
					system("pause");
					break;

				case 5:
					//cautare
					cout << "Introduceti cheia cautata:";
					cin >> key;
					adr = cautare_ABC(ROOT, key);
					
					if (adr != NULL)
						cout << "Element gasit\n";
					else 
						cout << "Eroare - cheie inexistenta\n";
				
					system("pause");
					break;

				case 6:
					//distrugere
					ROOT = distrugere_ABC(ROOT);
					cout << "Distrus\n";
					system("pause");
					break;

				case 7:
					//adancime maxima
					adancime = adancime_max(ROOT);
					cout << "Adancime arbore:" << adancime << endl;
					system("pause");
					break;

				case 8:
					//noduri aflate pe un nivel
					cout << "Introduceti nivel dorit:";
					cin >> nivel;
					noduri_nivel(ROOT, 1, nivel);
					system("pause");
					break;

				case 9:
					//egalitate 2 arbori
					break;

				case 10:
					//inapoi
					break;
				}
			} while (submeniu!=10);
			break;

		case 2:
			//op extinse
			do {
				system("cls");
				cout << "1. Inserare automata\n";
				cout << "2. ex2\n";
				cout << "3. Inapoi\n";
				cout << "Introduceti optiunea: ";
				cin >> submeniu;

				switch (submeniu) {
				case 1:
					//generare
					srand(time(NULL));
					cout << "Introduceti nr de numere:";
					cin >> n;
					for (int i = 0; i < n; i++) {
						nr = rand()%100;
						ROOT=inserare_ABC(ROOT, nr);
					}
					break;

				case 2:
					//ex2
					break;

				case 3:
					//inapoi
					break;

				}
			} while (submeniu != 3);
			break;
		}
	} while (meniu != 3);

	return 0;
}