#include <iostream>

using namespace std;

struct nodLDI {
	int info;
	nodLDI* succ;
	nodLDI* pred;
};

struct CAPETE {
	nodLDI* FRONT;
	nodLDI* END;
};

nodLDI* alocare_nod_LDI(int info_nou)
{
	nodLDI* nod = new nodLDI;
	nod->info = info_nou;
	nod->succ = NULL;
	nod->pred = NULL;

	return nod;
}

CAPETE inserare_inceput_LDI(CAPETE capete, int info_nou)
{
	if (capete.FRONT == capete.END && capete.FRONT == NULL) {
		nodLDI* nou = alocare_nod_LDI(info_nou);
		capete.FRONT = nou;
		capete.END = nou;
	}
	else {
		nodLDI* nou = alocare_nod_LDI(info_nou);
		nou->succ = capete.FRONT;
		capete.FRONT->pred = nou;
		capete.FRONT = nou;
	}

	return capete;
}

CAPETE inserare_sfarsit_LDI(CAPETE capete, int info_nou)
{

	if (capete.FRONT == capete.END && capete.FRONT == NULL) {
		nodLDI* nou = alocare_nod_LDI(info_nou);
		capete.FRONT = nou;
		capete.END = nou;
	}
	else
	{
		nodLDI* nou = alocare_nod_LDI(info_nou);
		capete.END->succ = nou;
		nou->succ = NULL;
		nou->pred = capete.END;
		capete.END = nou;
		nou->info = info_nou;
	}

	return capete;
}

CAPETE inserare_interior_LDI(CAPETE capete, int info_dupa, int info_nou)
{
	if (capete.FRONT == capete.END && capete.FRONT == NULL)
		cout << "Info dupa nu exista. Lista este vida.\n";
	else if (capete.FRONT->succ == NULL)
		capete = inserare_sfarsit_LDI(capete, info_nou);
	else
	{
		nodLDI* nou = alocare_nod_LDI(info_nou);
		nodLDI* tmp = capete.FRONT;
		while (tmp != NULL && tmp->info != info_dupa)
		{
			tmp = tmp->succ;
		}
		if (tmp == NULL)
			cout << "Info dupa nu se regaseste in lista\n";
		else
		{
			nodLDI* dupa = tmp;
			nou->succ = dupa->succ;
			nou->pred = dupa;
			dupa->succ->pred = nou;
			dupa->succ = nou;
		}

	}

	return capete;
}

CAPETE stergere_inceput_LDI(CAPETE capete)
{
	if (capete.FRONT == capete.END && capete.FRONT == NULL)
	{
		cout << "Eroare - lista vida";
		
	}
	else if (capete.FRONT->succ == NULL)
	{
		nodLDI* salv;
		salv = capete.FRONT;
		capete.FRONT = NULL;

		delete salv;

	}
	else
	{
		nodLDI* salv = NULL;

		salv = capete.FRONT;
		capete.FRONT = capete.FRONT->succ;
		capete.FRONT->pred = NULL;

		delete salv;

	}

	return capete;
}

CAPETE stergere_sfarsit_LDI(CAPETE capete)
{
	if (capete.FRONT == capete.END && capete.FRONT == NULL)
		cout << "Eroare - lista vida";
	else if (capete.FRONT->succ == NULL)
	{
		nodLDI* salv;
		salv = capete.FRONT;
		capete.FRONT = NULL;

		delete salv;

	}
	else
	{
		nodLDI* salv;

		salv = capete.END;
		capete.END = capete.END->pred;
		capete.END->succ = NULL;

		delete salv;

	}

	return capete;
}

nodLDI* cautare_LDI(CAPETE capete, int cheie)
{
	nodLDI* tmp = capete.FRONT;

	if (capete.FRONT == capete.END && capete.FRONT == NULL)
		cout << "Eroare - lista vida!";
	else
	{

		while (tmp != NULL)
		{
			if (tmp->info == cheie)
				return tmp;
			tmp = tmp->succ;
		}

	}
	
	return NULL;
}

CAPETE stergere_interior_LDI(CAPETE capete, int info_dupa) {
	if (capete.FRONT == capete.END && capete.FRONT == NULL)
		cout << "Eroare - Lista vida\n";

	else if (capete.FRONT->succ == NULL)
		capete = stergere_sfarsit_LDI(capete);

	else
	{
		nodLDI* dupa = cautare_LDI(capete, info_dupa);
		if (dupa == NULL)
			cout << "Nu se sterge nimic din lista\n";
		else
		{
			if (dupa->succ == NULL)
				cout << "Nu exista element dupa nodul_dupa\n";
			else if (dupa->succ->succ == NULL)
				capete = stergere_sfarsit_LDI(capete);
			else
			{
				nodLDI* salv = dupa->succ;
				dupa->succ = salv->succ;
				salv->succ->pred = dupa;
			}

		}
	}

	return capete;
}

CAPETE actualizare_LDI(CAPETE capete, int cheie, int info_nou) {
	
	if (capete.FRONT == capete.END && capete.FRONT == NULL)
		cout << "Eroare - lista vida!";
	else {
		nodLDI* gasit = cautare_LDI(capete, cheie);
		gasit->info = info_nou;
	}

	return capete;
}

CAPETE distrugere_LDI(CAPETE capete)
{
	while (capete.FRONT != NULL)
		capete = stergere_inceput_LDI(capete);

	return capete;
}

void afisare_StDr_LDI(CAPETE capete)
{
	if (capete.FRONT == capete.END && capete.FRONT == NULL)
		cout << "Eroare - lista vida!";
	else
	{
		nodLDI* tmp = capete.FRONT;
		while (tmp != NULL)
		{
			cout << endl;
			cout << tmp->info << endl;
			tmp = tmp->succ;
		}
	}
}

void afisare_DrSt_LDI(CAPETE capete) {

	if (capete.FRONT == capete.END && capete.FRONT == NULL)
		cout << "Eroare - lista vida!";
	else{
		nodLDI* tmp = capete.END;
		while (tmp != NULL)
		{
			cout << endl;
			cout << tmp->info <<endl;
			tmp = tmp->pred;
		}
	}
}

// Operatii extinse


CAPETE stergere(CAPETE capete, nodLDI* sters) {
	
	if (sters->succ == NULL)
		capete = stergere_sfarsit_LDI(capete);
	else if (sters->pred == NULL)
		capete = stergere_inceput_LDI(capete);
	else {
		nodLDI* salv = sters;
		sters->pred->succ = sters->succ;
		sters->succ->pred = sters->pred;
		delete salv;
	}
	

	return capete;
}

CAPETE eliminare_repet(CAPETE capete) {
	nodLDI* prim = capete.FRONT;
	nodLDI* doi;
	
	while (prim != NULL) {
		doi = capete.FRONT;
		while (doi != NULL) {
			if (prim->info == doi->info && doi!=prim) {
				nodLDI* salv = doi;
				doi = doi->succ;
				capete=stergere(capete, salv);
			}
			else
				doi = doi->succ;
		}
		prim = prim->succ;
	}

	return capete;
}

CAPETE adaugare_divizor(CAPETE capete, int info_nou) {
	
	nodLDI* tmp = capete.FRONT;
	nodLDI* salv;
	
	while (tmp != NULL) {
		if (info_nou%tmp->info == 0) {
			if (tmp->succ == NULL) {
				capete = inserare_sfarsit_LDI(capete, info_nou);
				break;
			}
			else {
				salv = tmp;
				tmp = tmp->succ;
				capete = inserare_interior_LDI(capete, salv->info, info_nou);
			}
		}
		else {
			tmp = tmp->succ;
		}
	}
	return capete;
}

CAPETE ordonare_crescator(CAPETE capete) {
	nodLDI* prim = capete.FRONT;
	nodLDI* doi = prim->succ;
	nodLDI* aux;
	nodLDI* aux2;
	nodLDI* salv;
	while (prim->succ != NULL) {
		doi = prim->succ;
		while (doi != NULL) {
			if (prim->info > doi->info) {
				aux = prim;
				aux2 = doi;
				
				capete = inserare_interior_LDI(capete, aux->info, doi->info);
				capete = inserare_interior_LDI(capete, aux2->info, prim->info);
				salv = prim;
				prim = prim->succ;
				
				capete = stergere(capete, salv);
				
				salv = doi;
				doi = doi->succ;
				
				capete = stergere(capete, salv);
			}
			else {
				doi = doi->succ;
			}
		}
		prim = prim->succ;
	}
	return capete;
}

CAPETE ordonare_descrescator(CAPETE capete) {
	nodLDI* prim = capete.FRONT;
	nodLDI* doi = prim->succ;
	nodLDI* aux;
	nodLDI* aux2;
	nodLDI* salv;
	
	while (prim->succ != NULL) {
		doi = prim->succ;
		while (doi != NULL) {
			if (prim->info < doi->info) {
				aux = prim;
				aux2 = doi;

				capete = inserare_interior_LDI(capete, aux->info, doi->info);
				capete = inserare_interior_LDI(capete, aux2->info, prim->info);
				salv = prim;
				prim = prim->succ;

				capete = stergere(capete, salv);

				salv = doi;
				doi = doi->succ;

				capete = stergere(capete, salv);
			}
			else {
				doi = doi->succ;
			}
		}
		prim = prim->succ;
	}
	return capete;
}

int main()
{
	CAPETE capete;
	capete.FRONT = NULL;
	capete.END = NULL;

	int info_nou, info_dupa;
	int opt, opt1, opt2, opt3, opt4, opt5;

	do {
		//INCEPUT MENIU PRINCIPAL
		system("cls");
		cout << "Meniu principal\n";
		cout << "\n1. Adaugare\n";
		cout << "2. Stergere\n";
		cout << "3. Cautare\n";
		cout << "4. Afisare\n";
		cout << "5. Actualizare\n";
		cout << "6. Distrugere\n";
		cout << "7. Operatii extinse\n";
		cout << "8. Iesire\n";
		cout << "Introduceti optiunea:";
		cin >> opt;

		switch (opt)
		{
		case 1:
			//INCEPUT MENIU ADAUGARE
			do {
				system("cls");
				cout << "Meniu adaugare\n";
				cout << "\n1. La inceput\n";
				cout << "2. La sfarsit\n";
				cout << "3. Dupa un element\n";
				cout << "4. Inapoi\n";
				cout << "Introduceti optiunea:";
				cin >> opt1;

				switch (opt1) {
				case 1:

					cout << "Introduceti noua valoare:";
					cin >> info_nou;

					capete = inserare_inceput_LDI(capete, info_nou);
					break;

				case 2:
					cout << "Introduceti noua valoare:";
					cin >> info_nou;

					capete = inserare_sfarsit_LDI(capete, info_nou);
					break;

				case 3:

					cout << "Introduceti noua valoare:";
					cin >> info_nou;
					cout << "Introduceti valoarea elementului dupa care doriti sa inserati:";
					cin >> info_dupa;

					capete = inserare_interior_LDI(capete, info_dupa, info_nou);
					break;

				case 4:
					system("cls");
					break;

				default:
					cout << "Optiunea introdusa nu exista!\n";
					system("pause");
					break;

				} //SFARSIT MENIU ADAUGARE
			} while (opt1 != 4);
			break;

		case 2:
			do { //INCEPUT MENIU STERGERE
				system("cls");
				cout << "Meniu stergere\n";
				cout << "\n1. Stergere la inceput\n";
				cout << "2. Stergere la sfarsit\n";
				cout << "3. Stergere interior\n";
				cout << "4. Inapoi\n";
				cout << "Introduceti optiunea:";
				cin >> opt2;

				switch (opt2) {
				case 1:
					capete = stergere_inceput_LDI(capete);
					cout << "Primul element a fost sters\n";
					system("pause");
					break;

				case 2:
					capete = stergere_sfarsit_LDI(capete);
					cout << "Ultimul element a fost sters\n";
					system("pause");
					break;

				case 3:
					cout << "Introduceti valoarea elementului dupa care doriti sa stergeti:";
					cin >> info_dupa;

					capete = stergere_interior_LDI(capete, info_dupa);
					cout << "Elementul a fost sters!\n";

					system("pause");
					break;

				case 4:
					system("cls");
					break;

				default:
					cout << "Optiunea introdusa nu exista!\n";
					system("pause");
					break;
				}
			} while (opt2 != 4);   //SFARSIT MENIU STERGERE
			break;

		case 3:
			do {	//INCEPUT MENIU CAUTARE
				system("cls");
				cout << "Meniu cautare\n";
				cout << "\n1. Dupa valoare\n";
				cout << "2. Inapoi\n";
				cout << "Introduceti optiunea:";
				cin >> opt3;

				switch (opt3)
				{
				case 1:
					int info_caut;
					cout << "Introduceti informatia cautata:";
					cin >> info_caut;

					nodLDI* nodgasit;
					nodgasit = cautare_LDI(capete, info_caut);

					if (nodgasit != NULL)
						cout << "Informatia cautata exista in LDI!\n";
					else
						cout << "Informatia cautata nu exista in LDI\n";

					system("pause");
					break;

				case 2:
					system("cls");
					break;

				default:
					cout << "Optiunea introdusa nu exista!\n";
					system("pause");
					break;
				}
			} while (opt3 != 2); //SFARSIT CAUTARE
			break;

		case 4:
			do {	 //INCEPUT MENIU AFISARE
				system("cls");
				cout << "Meniu afisare\n";
				cout << "\n1. Inceput-sfarsit\n";
				cout << "2. Sfarsit-inceput\n";
				cout << "3. Inapoi\n";
				cout << "Introduceti optiunea dorita:";
				cin >> opt4;

				switch (opt4)
				{
				case 1:
					afisare_StDr_LDI(capete);

					system("pause");
					break;

				case 2:
					afisare_DrSt_LDI(capete);

					system("pause");
					break;

				case 3:
					system("cls");
					break;

				default:
					cout << "Optiunea introdusa nu exista!\n";
					system("pause");
					break;
				}
			} while (opt4 != 3); //SFARSIT MENIU AFISARE
			break;

		case 5:	 //actualizare
			cout << "Introduceti valoarea cautata:";
			int info_caut;
			cin >> info_caut;
			cout << "Introduceti noua valoare:";
			cin >> info_nou;

			capete = actualizare_LDI(capete, info_caut, info_nou);
			cout << "Elementul a fost actualizat!";
			system("pause");
			break;

		case 6: //distrugere
			capete = distrugere_LDI(capete);

			cout << "Lista a fost distrusa\n";
			system("pause");
			break;

		case 7:
			do { //INCEPUT MENIU OPERATII EXTINSE
				system("cls");
				cout << "Meniu operatii extinse\n";
				cout << "\n1. Eliminarea elementelor care se repeta\n";
				cout << "2. Adaugarea unui element dupa fiecare divizor al sau\n";
				cout << "3. Ordonarea listei crescator\n";
				cout << "4. Ordonarea listei descrescator\n";
				cout << "5. Inapoi\n";
				cout << "Introduceti optiunea:";
				cin >> opt5;

				switch (opt5) {

				case 1:
					capete = eliminare_repet(capete);
					cout << "Elementele care se repeta au fost eliminate\n";
					system("pause");
					break;

				case 2:
					cout << "Introduceti info:";
					cin >> info_nou;
					capete = adaugare_divizor(capete, info_nou);

					cout << "Nr a fost adaugat dupa divizori\n";
					system("pause");
					break;

				case 3:
					capete = ordonare_crescator(capete);
					cout << "Lista a fost ordonata crescator\n";
					system("pause");
					break;

				case 4:
					capete = ordonare_descrescator(capete);
					cout << "Lista a fost ordonata descrescator\n";
					system("pause");
					break;

				case 5:
					system("cls");
					break;

				default:
					cout << "Optiunea introdusa nu exista!\n";
					system("pause");
					break;
				}
			} while (opt5 != 5);//SFARSIT MENIU OP EXTINSE
			break;

		case 8:
			break;

		default:
			cout << "Optiunea introdusa nu exista!\n";
			system("pause");
			break;

		}
	} while (opt != 8); //SFARSIT MENIU PRINCIPAL

	
	return 0;
}