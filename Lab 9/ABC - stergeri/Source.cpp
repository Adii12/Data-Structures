#include <iostream>
#include <time.h>

using namespace std;

struct nodABC {
	int info = 0;
	nodABC* fiu_st = NULL;
	nodABC* fiu_dr = NULL;
};

void traversare(nodABC* ROOT) {
	if (ROOT != NULL) {
		traversare(ROOT->fiu_st);
		traversare(ROOT->fiu_dr);
	}
}

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

nodABC* caz1(nodABC* ROOT, nodABC* tmp, nodABC* tata) {
	if (tmp == ROOT) {
		cout << "S-a sters nodul "<<tmp->info<<endl;
		delete tmp;
		ROOT = NULL;
	}
	else {
		if (tata == tmp->fiu_st)
			tata->fiu_st = NULL;
		else if(tata == tmp->fiu_dr)
			tata->fiu_dr = NULL;
		cout << "S-a sters nodul" << tmp->info << endl;
		delete tmp;
	}

	return ROOT;
}

nodABC* caz2(nodABC* ROOT, nodABC* tmp, nodABC* tata) {
	if (tmp == ROOT) {
		if (tmp->fiu_st != NULL)
			ROOT = tmp->fiu_st;
		else
			ROOT = tmp->fiu_dr;
		cout << "S-a sters nodul " << tmp->info << endl;
		delete tmp;
	}
	else {
		if (tata->fiu_st == tmp && tmp->fiu_st != NULL)//SS
			tata->fiu_st = tmp->fiu_st;
		else if (tata->fiu_st == tmp && tmp->fiu_dr != NULL)//SD
			tata->fiu_st = tmp->fiu_dr;
		else if (tata->fiu_dr == tmp && tmp->fiu_st != NULL)//DS
			tata->fiu_dr = tmp->fiu_st;
		else if (tata->fiu_dr == tmp && tmp->fiu_dr != NULL)//DD
			tata->fiu_dr = tmp->fiu_dr;
	}

	return ROOT;
}

nodABC* caz3(nodABC* ROOT, nodABC* tmp, nodABC* tata) {
	nodABC* max = tmp->fiu_st;
	nodABC* tata_max = tmp;

	while (max->fiu_dr != NULL) {
		tata_max = max;
		max = max->fiu_dr;
	}

	if (max->fiu_st == NULL)
		ROOT = caz1(ROOT, max, tata_max);
	else
		ROOT = caz2(ROOT, max, tata_max);
	return ROOT;
}

nodABC* stergere_ABC(nodABC* ROOT, int key) {
	if (ROOT == NULL) {
		cout << "Eroare - arbore gol." << endl;
		system("pause");
		return ROOT;
	}
	nodABC* tmp = ROOT;
	nodABC* tata = NULL;
	while ((tmp != NULL) && (tmp->info != key)) {
		tata = tmp;
		if (key > tmp->info) {
			tmp = tmp->fiu_dr;
		}
		else {
			tmp = tmp->fiu_st;
		}
	}
	if (tmp == NULL) {
		cout << "Eroare - elementul nu a fost gasit." << endl;
		system("pause");
		return ROOT;
	}
	else {
		if (tmp->fiu_dr == NULL && tmp->fiu_st == NULL) {
			ROOT = caz1(ROOT, tmp, tata);
		}
		else if (tmp->fiu_dr == NULL || tmp->fiu_st == NULL) {
			ROOT = caz2(ROOT, tmp, tata);
		}
		else if (tmp->fiu_dr != NULL && tmp->fiu_st != NULL) {
			ROOT = caz3(ROOT, tmp, tata);
		}
	}
}

nodABC* stergere_frunze(nodABC* ROOT) {
	nodABC* tmp = ROOT;
	int chei[50];
	int i = 0;
	
	if (tmp != NULL) {
		stergere_frunze(tmp->fiu_st);
		if (tmp->fiu_st == NULL && tmp->fiu_dr == NULL) {
			chei[i] = tmp->info;
			i++;
		}
		stergere_frunze(tmp->fiu_dr);
	}
	
	

	for (int contor = 0; contor < i; contor++) {
		ROOT = stergere_ABC(ROOT, chei[contor]);
	}
	//system("pause");
	return ROOT;
}

nodABC* stergere_nivel(nodABC * ROOT, int nivel, int nivel_dorit) {
	nodABC* tmp = ROOT;
	if (ROOT == NULL) {
	}
	else {
		if (nivel == nivel_dorit - 1) {
			if (tmp->fiu_dr != NULL) {
				ROOT = stergere_ABC(ROOT, tmp->fiu_dr->info);
			}
			if (tmp->fiu_st != NULL) {
				ROOT = stergere_ABC(ROOT, tmp->fiu_st->info);
			}
		}
		else {
			stergere_nivel(tmp->fiu_st, nivel + 1, nivel_dorit);
			stergere_nivel(tmp->fiu_dr, nivel + 1, nivel_dorit);
		}
	}
	return ROOT;
}

void inordine(nodABC * ROOT) {
	if (ROOT != NULL) {
		inordine(ROOT->fiu_st);
		cout << "Info:" << ROOT->info << endl;
		inordine(ROOT->fiu_dr);
	}
}


int main() {
	int meniu, submeniu, nivel;
	int info_nou, info_sters;
	nodABC* ROOT = NULL;
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
				cout << "3. Stergere\n";
				cout << "4. Actualizare\n";
				cout << "5. Distrugere\n";
				cout << "6. Stergerea frunzelor curente\n";
				cout << "7. Stergerea nodurilor de la un nivel dat\n";
				cout << "8. Inapoi\n";
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
					//stergere
					cout << "Introduceti info sters:";
					cin >> info_sters;
					ROOT = stergere_ABC(ROOT, info_sters);
					system("pause");
					break;

				case 4:
					//actualizare
					break;

				case 5:
					//distrugere
					ROOT = distrugere_ABC(ROOT);
					cout << "Distrus\n";
					system("pause");
					break;

				case 6:
					//stergerea frunzelor curente
					ROOT = stergere_frunze(ROOT);
					system("pause");
					break;

				case 7:
					//stergere noduri pe nivel
					cout << "Introduceti nivelul:";
					cin >> nivel;
					ROOT = stergere_nivel(ROOT, 1, nivel);
					break;

				case 8:
					//inapoi
					break;
				}
			} while (submeniu != 8);
			break;

		case 2:
			//op extinse
			do {
				system("cls");
				cout << "1. Inserare automata\n";
				cout << "2. Evaluare expresii\n";
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
						nr = rand() % 100;
						ROOT = inserare_ABC(ROOT, nr);
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