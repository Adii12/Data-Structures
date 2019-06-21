#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>

using namespace std;

struct nodABC {
	int info;
	nodABC* fiu_st;
	nodABC* fiu_dr;
};

nodABC* alocarenod_ABC(int info_nou) {
	nodABC* nod = new nodABC;
	nod->info = info_nou;
	nod->fiu_st = NULL;
	nod->fiu_dr = NULL;

	return nod;
}

nodABC* inserare_ABC(nodABC* ROOT, int info_nou){
	if (ROOT == NULL)
		ROOT = alocarenod_ABC(info_nou);
	else {
		nodABC* tmp = ROOT;
		nodABC* tata = NULL;

		while (tmp != NULL) {
			tata = tmp;
			if (tmp->info < info_nou)
				tmp = tmp->fiu_dr;
			else if (tmp->info > info_nou)
				tmp = tmp->fiu_st;
			else {
				cout << "Cheie dubla\n";
				return ROOT;
			}

		}//sf while

		nodABC* nou = alocarenod_ABC(info_nou);
		if (tata->info < info_nou)
			tata->fiu_dr = nou;
		else
			tata->fiu_st = nou;
		
	}//sf else

	return ROOT;
} 

nodABC* caz1(nodABC* ROOT, nodABC* tmp, nodABC* tata) {
	if (tmp == ROOT) {
		//un singur nod in arbore
		cout << "S-a sters nodul " << tmp->info << endl;
		delete tmp;
		ROOT = NULL;
	}
	else {
		//se sterge o frunza
		if (tmp == tata->fiu_st)
			tata->fiu_st = NULL;
		else
			tata->fiu_dr = NULL;
		cout << "S-a sters nodul " << tmp->info << endl;
		delete tmp;
	}

	return ROOT;
}

nodABC* caz2(nodABC* ROOT, nodABC* tmp, nodABC* tata) {
	if (tmp == ROOT)
	{
		if (tmp->fiu_st != NULL)
			ROOT = tmp->fiu_st;
		else
			ROOT = tmp->fiu_dr;
		cout << "S-a sters nodul " << tmp->info << endl;
		delete tmp;
	}
	else {
		//SS, SD, DS, DD
		//tmp si tatal lui tmp se cheama tata
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

void preordine(nodABC* nod) {
	if (nod != NULL) {
		cout << nod->info;
		preordine(nod->fiu_st);
		preordine(nod->fiu_dr);
	}
}

void inordine(nodABC* nod) {
	if (nod != NULL) {
		inordine(nod->fiu_st);
		cout << nod->info;
		inordine(nod->fiu_dr);
	}
}

void postordine(nodABC* nod) {
	if (nod != NULL) {
		postordine(nod->fiu_st);
		postordine(nod->fiu_dr);
		cout << nod->info;
	}
}

nodABC* stergere_ABC(nodABC* ROOT, int info_sters) {
	if (ROOT == NULL)
		cout << "Arbore vid\n";
	else {
		nodABC* tmp = ROOT;
		nodABC* tata = NULL;

		while (tmp != NULL && tmp->info != info_sters) {
			tata = tmp;
			if (tmp->info < info_sters)
				tmp = tmp->fiu_dr;
			else
				tmp = tmp->fiu_st;
		}
		if (tmp == NULL) {
			cout << "Info sters nu a fost gasit\n";
			return ROOT;
		}
		else {
			if (tmp->fiu_st == NULL && tmp->fiu_dr == NULL)
				ROOT = caz1(ROOT, tmp, tata);
			else if ((tmp->fiu_st != NULL && tmp->fiu_dr == NULL) || (tmp->fiu_st == NULL && tmp->fiu_dr != NULL))
				ROOT = caz2(ROOT, tmp, tata);
			else
				ROOT = caz3(ROOT, tmp, tata);
		}
	}
	return ROOT;
}

nodABC* eliberare_ABC(nodABC* nod) {
	if (nod != NULL) {
		eliberare_ABC(nod->fiu_st);
		eliberare_ABC(nod->fiu_dr);
		delete nod;
	}

	nod = NULL;
	return nod;
}

int main() {
	int meniu;
	int info;
	nodABC* ROOT = NULL;

	do {
		cout << "Introduceti o varianta de la 0-7\n";
		cout << "0. Iesire din program\n";
		cout << "1. Initializare Arbore\n";
		cout << "2. Inserare\n";
		cout << "3. Stergere\n";
		cout << "4. Traversare in ordine\n";
		cout << "5. Traversare pre ordine\n";
		cout << "6. Traversare post ordine\n";
		cout << "7. Eliberare\n";
		cin >> meniu;
		
		switch (meniu) {
		case 0: break;
		case 1: {
			//initializare
			ROOT=eliberare_ABC(ROOT);
			ROOT = NULL;
			break;
		}
		case 2: {
			cout << "Introduceti info nou:";
			cin >> info;
			ROOT = inserare_ABC(ROOT, info);
			break;
		}
		case 3: {
			//stergere
			int info_sters;
			cout << "Dati nodul sters:";
			cin >> info_sters;
			ROOT = stergere_ABC(ROOT, info_sters);
			break;
		}
		case 4: {
			 //traversare in ordine
			cout << "Traversare inordine:";
			inordine(ROOT);
			system("pause");
			break;
		}
		case 5: {
			//traversare in preordine
			cout << "Traversare in preordine:";
			preordine(ROOT);
			system("pause");
			break;
		}
		case 6: {
			//traversare in postordine
			cout << "Traversare in postordine:";
			postordine(ROOT);
			system("pause");
			break;
		}
		case 7: {
			//eliberare
			ROOT = eliberare_ABC(ROOT);
			break;
		}
		default: {
			cout << "Varianta gresita.\n Introduceti o valoare de la 0-7\n";
		}
		}
	} while (meniu != 0);
	
	_getch();
	return 0;
}