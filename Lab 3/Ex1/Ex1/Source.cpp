#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream>


using namespace std;

struct nodLSIpersoana {
	char nume[30];
	char prenume[30];
	int varsta;
	nodLSIpersoana* succ;
};

struct nodLSIcartier {
	char nume[30];
	nodLSIpersoana* LIST;
	nodLSIcartier* succ;
};

nodLSIpersoana* alocare_nod_LSI(char nume[30], char prenume[30], int varsta)
{
	nodLSIpersoana* nod = new nodLSIpersoana;
	strcpy(nod->nume, nume);
	strcpy(nod->prenume, prenume);
	nod->varsta = varsta;
	nod->succ = NULL;

	return nod;
}

nodLSIpersoana* inserare_inceput(nodLSIpersoana* LIST, char nume[30], char prenume[30], int varsta)
{
	if (LIST == NULL)
	{
		nodLSIpersoana* nou = alocare_nod_LSI(nume, prenume, varsta);
		if (nou == NULL)
		{
			cout << "Eroare - memorie insuficienta";
			
			return NULL;
		}
		else
		{
			LIST = nou;
			strcpy(nou->nume, nume);
			strcpy(nou->prenume, prenume);
			nou->varsta = varsta;
			nou->succ = NULL;
		}

	}
	else
	{
		nodLSIpersoana* nou = alocare_nod_LSI(nume, prenume, varsta);
		nou->succ = LIST;
		LIST = nou;
	}

	return LIST;
}

nodLSIpersoana* inserare_sfarsit(nodLSIpersoana* LIST, char nume[30], char prenume[30], int varsta)
{
	
	if (LIST == NULL)
	{
		nodLSIpersoana* nou = alocare_nod_LSI(nume, prenume, varsta);
		if (nou == NULL)
		{
			cout << "EROARE - memorie insuficienta\n";
			return NULL;
		}
		else
		{
			LIST = nou;
			strcpy(nou->nume, nume);
			strcpy(nou->prenume, prenume);
			nou->varsta = varsta;
			nou->succ = NULL;
		}
	}
	else
	{
		nodLSIpersoana* tmp = LIST;
		while (tmp->succ)
		{
			tmp = tmp->succ;
		}
		nodLSIpersoana* ultim = tmp;
		nodLSIpersoana* nou = alocare_nod_LSI(nume, prenume, varsta);
		ultim->succ = nou;
		nou->succ = NULL;
		strcpy(nou->nume, nume);
		strcpy(nou->prenume, prenume);
		nou->varsta = varsta;
	}

	return LIST;
}

nodLSIpersoana* inserare_cheie_dupa(nodLSIpersoana* LIST, char _nume[30], char _prenume[30], int _varsta, char cheie[30]) {
	if (LIST == NULL) {
		nodLSIpersoana* nou = alocare_nod_LSI(_nume, _prenume, _varsta);
		if (nou == NULL) {
			printf("Eroare memorie insuficienta.");
			return NULL;
		}
		else {
			LIST = nou;
			strcpy(nou->nume, _nume);
			strcpy(nou->prenume, _prenume);
			nou->varsta = _varsta;
			nou->succ = NULL;
		}
	}
	else {
		nodLSIpersoana* nou = alocare_nod_LSI(_nume, _prenume, _varsta);
		if (LIST -> succ == NULL) {	 
			inserare_sfarsit(LIST, _nume, _prenume, _varsta);
		}
		else {
			nodLSIpersoana* nou = alocare_nod_LSI(_nume, _prenume, _varsta);
			nodLSIpersoana* tmp = LIST;
			while ((strcmp(tmp->nume, cheie)) != 0 && (tmp != NULL)) {
				tmp = tmp->succ;
			}
			nodLSIpersoana* dupa = tmp;
			nou->succ = dupa->succ;
			dupa->succ = nou;
			strcpy(nou->nume, _nume);
			strcpy(nou->prenume, _prenume);
			nou->varsta = _varsta;
		}
	}
	return LIST;
}

nodLSIpersoana* inserare_cheie_inainte(nodLSIpersoana* LIST, char _nume[30], char _prenume[30], int _varsta, char cheie[30]) {
	if (LIST == NULL) {
		nodLSIpersoana* nou = alocare_nod_LSI(_nume, _prenume, _varsta);
		if (nou == NULL) {
			cout<<"Eroare memorie insuficienta.";
			return NULL;
		}
		else {
			LIST = nou;
			strcpy(nou->nume, _nume);
			strcpy(nou->prenume, _prenume);
			nou->varsta = _varsta;
			nou->succ = NULL;
		}
	}
	else {
		nodLSIpersoana* nou = alocare_nod_LSI(_nume, _prenume, _varsta);
		if (LIST -> succ == NULL) {
			inserare_inceput(LIST, _nume, _prenume, _varsta);
		}
		else {
			nodLSIpersoana* nou = alocare_nod_LSI(_nume, _prenume, _varsta);
			nodLSIpersoana* tmp = LIST;
			while ((strcmp((tmp->succ)->nume, cheie)) != 0 && (tmp != NULL)) {
				tmp = tmp->succ;
				
			}
			nodLSIpersoana* dupa = tmp;
			nou->succ = dupa->succ;
			dupa->succ = nou;
			strcpy(nou->nume, _nume);
			strcpy(nou->prenume, _prenume);
			nou->varsta = _varsta;
		}
	}
	return LIST;
}

nodLSIpersoana* stergere_inceput(nodLSIpersoana* LIST)
{
	if (LIST == NULL)
	{
		cout << "Eroare - lista este vida";
		return NULL;
	}
	nodLSIpersoana* salv = LIST;
	LIST = LIST->succ;
	delete salv;

	return LIST;
}

nodLSIpersoana* stergere_ultim(nodLSIpersoana* LIST)
{
	if (LIST == NULL)
	{
		cout << "EROARE - Lista este vida!\n";
		return NULL;
	}

	nodLSIpersoana* tmp = LIST;
	nodLSIpersoana* penultim = NULL;
	
	while (tmp->succ != NULL)
	{
		penultim = tmp;
		tmp = tmp->succ;
		//cout << "INTRA\n";
	}
	
	nodLSIpersoana* salv = penultim->succ;
	penultim->succ = NULL;
	
	delete salv;

	return LIST;
}

nodLSIpersoana* stergere_interior_cheie(nodLSIpersoana* LIST, char nume[30], char prenume[30])
{
	if (LIST == NULL)
	{
		cout << "EROARE - Lista este vida!\n";
		return NULL;
	}

	if (LIST->succ == NULL)
	{
		nodLSIpersoana* salv = LIST;
		LIST = NULL;
		delete salv;
		
		return NULL;
	}

	nodLSIpersoana* tmp=LIST;
	nodLSIpersoana* t = NULL;
	while ((tmp != NULL) && (strcmp(nume, tmp->nume) != 0) && (strcmp(prenume, tmp->prenume) != 0))
	{
		t = tmp;
		tmp = tmp->succ;
	}
	if (tmp == NULL)
	{
		cout << "Nu s-a gait nume, prenume\n";
	}
	else
	{
		nodLSIpersoana* salv = tmp;
		t->succ = salv->succ;
		delete salv;
	}
	return LIST;
}

nodLSIpersoana* cautare_nume(nodLSIpersoana* LIST, char cheie[30]) {
	nodLSIpersoana* tmp = LIST;

	while (tmp != NULL)
	{
		if (strcmp(cheie, tmp->nume) == 0)
			return tmp;
		else
			tmp = tmp->succ;
	}

	return NULL;
}

nodLSIpersoana* cautare_prenume(nodLSIpersoana* LIST, char cheie[30]) {
	nodLSIpersoana* tmp = LIST;
	while (tmp != NULL)
	{
		if (strcmp(cheie, tmp->prenume) == 0)
			return tmp;
		else
			tmp = tmp->succ;
	}

	return NULL;
}

nodLSIpersoana* cautare_varsta(nodLSIpersoana* LIST, int cheie) {
	nodLSIpersoana* tmp = LIST;
	
	while (tmp != NULL) {
		if (cheie == tmp->varsta)
			return tmp;
		else
			tmp = tmp->succ;
	}

	return NULL;
}

nodLSIpersoana* distrugere(nodLSIpersoana* LIST){
	while (LIST != NULL)
		LIST = stergere_inceput(LIST);

	return NULL;
}

void afisare(nodLSIpersoana* LIST)
{
	nodLSIpersoana* tmp = LIST;
	while (tmp!=NULL)
	{
		cout << "\nNume:" << tmp->nume;
		cout << "\nPrenume:" << tmp->prenume;
		cout << "\nVarsta:" << tmp->varsta << endl;
		tmp = tmp->succ;
	}
}

nodLSIcartier* alocare_nod_cartier_LSI(char nume[30], nodLSIpersoana* LIST)
{
	nodLSIcartier* nod = new nodLSIcartier;

	strcpy(nod->nume, nume);
	nod->LIST = NULL;
	nod->succ = NULL;

	return nod;
}

nodLSIcartier* inserare_inceput_cartier(nodLSIcartier* LISTC, char nume[30], nodLSIpersoana* LISTP)
{
	if (LISTC == NULL)
	{
		nodLSIcartier* nou = alocare_nod_cartier_LSI(nume, LISTP);
		if (nou == NULL)
		{
			cout << "Eroare - memorie insuficienta";

			return NULL;
		}
		else
		{
			LISTC = nou;
			strcpy(nou->nume, nume);
			nou->succ = NULL;
		}

	}
	else
	{
		nodLSIcartier* nou = alocare_nod_cartier_LSI(nume, LISTP);
		nou->succ = LISTC;
		LISTC = nou;
	}

	return LISTC;
}

nodLSIcartier* inserare_sfarsit_cartier(nodLSIcartier* LISTC, char nume[30], nodLSIpersoana* LISTP)
{
	if (LISTC == NULL)
	{
		nodLSIcartier* nou = alocare_nod_cartier_LSI(nume, LISTP);
		if (nou == NULL)
		{
			cout << "EROARE - memorie insuficienta\n";
			return NULL;
		}
		else
		{
			LISTC = nou;
			strcpy(nou->nume, nume);
			nou->succ = NULL;
		}
	}
	else
	{
		nodLSIcartier* tmp = LISTC;
		while (tmp->succ)
		{
			tmp = tmp->succ;
		}
		nodLSIcartier* ultim = tmp;
		nodLSIcartier* nou = alocare_nod_cartier_LSI(nume, LISTP);
		ultim->succ = nou;
		nou->succ = NULL;
		strcpy(nou->nume, nume);
	}

	return LISTC;
}

nodLSIcartier* stergere_inceput_cartier(nodLSIcartier* LISTC)
{
	if (LISTC == NULL)
	{
		cout << "Eroare - lista este vida";
		return NULL;
	}
	nodLSIcartier* salv = LISTC;
	LISTC = LISTC->succ;
	delete salv;

	return LISTC;
}

nodLSIcartier* stergere_sfarsit_cartier(nodLSIcartier* LISTC)
{
	if (LISTC == NULL)
	{
		cout << "EROARE - Lista este vida!\n";
		return NULL;
	}

	nodLSIcartier* tmp = LISTC;
	nodLSIcartier* penultim = NULL;

	while (tmp->succ != NULL)
	{
		penultim = tmp;
		tmp = tmp->succ;
	}

	nodLSIcartier* salv = penultim->succ;
	penultim->succ = NULL;

	delete salv;

	return LISTC;
}

nodLSIcartier* cautare_cartier(nodLSIcartier* LISTC, char cheie_cartier[30])
{
	nodLSIcartier* tmp = LISTC;

	while (tmp != NULL)
	{
		if (strcmp(cheie_cartier, tmp->nume) == 0)
			return tmp;
		else
			tmp = tmp->succ;
	}

	return NULL;
}

nodLSIcartier* actualizare_cartier(nodLSIcartier* LISTC, char cheie_cartier[30], char nume_nou[30])
{
	if (LISTC == NULL)
	{
		cout << "Eroare - Lista vida!";
	}
	else
	{
		nodLSIcartier* tmp = LISTC;
		while (tmp != NULL)
		{
			if (strcmp(cheie_cartier, tmp->nume) == 0)
			{
				strcpy(tmp->nume, nume_nou);
				break;
			}
		}
	}

	return LISTC;
}

void max_varsta(nodLSIcartier* LISTC, char cheie_cartier[30])
{
	nodLSIcartier* tmp = LISTC;
	char nume_max[30];
	
	while (tmp!=NULL)
	{
		if (strcmp(tmp->nume, cheie_cartier) == 0)
		{
			nodLSIpersoana* tmp2 = tmp->LIST;
			while (tmp2 != NULL)
			{
				int max = tmp2->varsta;
				
				if ((tmp2->varsta) > max)
				{
					max = tmp2->varsta;
					strcpy(nume_max, tmp2->nume);
				}
				tmp2 = tmp2->succ;
			}
		}
		tmp = tmp->succ;
	}

	printf("%s", nume_max);
}

void afisare_cartier(nodLSIcartier* LISTC)
{
	nodLSIcartier* tmp = LISTC;
	while (tmp != NULL)
	{
		cout << "\nNume:" << tmp->nume;
		tmp = tmp->succ;
	}
}

int main() {
	nodLSIpersoana* LIST = NULL;
	nodLSIcartier* LISTC = NULL;
	char nume[30];
	char prenume[30];
	char cheie[30];
	char cartier[30];
	char cheie_cartier[30];
	char nume_nou[30];
	int varsta;
	int opt, opt1, opt2, opt3, opt4, opt5, opt6;

	//INCEPUT MENIU PRINCIPAL
	do {
		system("cls");
		cout << "1. Adaugare.\n";
		cout << "2. Stergere.\n";
		cout << "3. Cautare.\n";
		cout << "4. Afisare.\n";
		cout << "5. Distrugere.\n";
		cout << "6. Operatii extinse\n";
		cout << "7. Iesire\n";
		cout << "Alegeti optiunea: ";
		cin >> opt;
		
		switch (opt) {
		case 7: 
			break; //IESIRE
		
		case 1:
			//INCEPUT MENIU ADAUGARE

			do {
				system("cls");
				cout << "Adaugare:\n";
				cout << "1. La inceput.\n";
				cout << "2. La sfarsit.\n";
				cout << "3. Inainte de un element (cheie).\n";
				cout << "4. Dupa un element (cheie).\n";
				cout << "5. Iesire.\n";
				cout << "Alegeti optiunea: ";
				cin>>opt1;
				switch (opt1) {
				
				case 1:
					//INSERARE INCEPUT
					
					cout << "Nume:";
					scanf("%s", nume);
					
					cout << "Prenume:";
					scanf("%s", prenume);

					cout << "Varsta:";
					cin >> varsta;

					LIST = inserare_inceput(LIST, nume, prenume, varsta);
					break;
				
				case 2:
					//INSERARE SFARSIT

					cout << "Nume:";
					scanf("%s", nume);

					cout << "Prenume:";
					scanf("%s", prenume);

					cout << "Varsta:";
					cin >> varsta;

					LIST = inserare_sfarsit(LIST, nume, prenume, varsta);
					break;
				
				case 3:
					//INSERARE INAINTE CHEIE

					cout << "Nume:";
					scanf("%s", nume);

					cout << "Prenume:";
					scanf("%s", prenume);

					cout << "Varsta:";
					cin >> varsta;

					cout << "Cheie:";
					scanf("%s", cheie);

					LIST = inserare_cheie_inainte(LIST, nume, prenume, varsta, cheie);
					break;
				
				case 4:
					//INSERARE DUPA CHEIE

					cout << "Nume:";
					scanf("%s", nume);

					cout << "Prenume:";
					scanf("%s", prenume);

					cout << "Varsta:";
					cin >> varsta;

					cout << "Cheie:";
					scanf("%s", cheie);

					LIST = inserare_cheie_dupa(LIST, nume, prenume, varsta, cheie);
					break;
				
				case 5:
					system("cls");
					break;
				}
			} while (opt1 != 5);  //SFARSIT MENIU ADAUGARE
			break;
		
		case 2:
			//INCEPUT MENIU STERGERE

			do {
				system("cls");
				cout << "Stergere:\n";
				cout << "1. Primul element.\n";
				cout << "2. Ultimul element.\n";
				cout << "3. Element identificat prin cheie.\n";
				cout << "4. Iesire.\n";
				cout << "Alegeti optiunea: ";
				cin>>opt2;
				
				switch (opt2) {
				
				case 1:
					//STERGERE INCEPUT

					LIST = stergere_inceput(LIST);
					cout << "Primul element a fost sters!\n";
					system("pause");
					break;
				
				case 2:
					//STERGERE SFARSIT

					LIST = stergere_ultim(LIST);
					cout << "Ultimul element a fost sters!\n";
					system("pause");
					break;
				
				case 3:
					//STERGERE INTERIOR

					char cheie1[30];
					cout << "Nume:";
					scanf("%s", cheie1);

					char cheie2[30];
					cout << "Prenume:";
					scanf("%s", cheie2);

					LIST = stergere_interior_cheie(LIST, cheie1, cheie2);
					cout << "Elementul a fost sters!\n";
					system("pause");
					break;
				
				case 4:
					//IESIRE
					
					system("cls");
					break;
				}
			} while (opt2 != 4); //SFARSIT MENIU STERGERE
			break;
		
		case 3:
			 //INCEPUT MENIU CAUTARE

			do {
				system("cls");
				cout << "Cautare:\n";
				cout << "1. Dupa nume:\n";
				cout << "2. Dupa prenume:\n";
				cout << "3. Dupa varsta.\n";
				cout << "4. Iesire.\n";
				cout << "Alegeti optiunea: ";
				cin>>opt3;
				
				switch (opt3) {
				
				case 1:
					//CAUTARE DUPA NUME

					nodLSIpersoana* adr;
					cout << "Introduceti numele cautat:";
					scanf("%s", &cheie);
					
					adr = cautare_nume(LIST, cheie);
					
					if (adr != NULL) {
						cout << "Elementul a fost gasit!\n";
						cout << "\nNume:" << adr->nume;
						cout << "\nPrenume:" << adr->prenume;
						cout << "\nVarsta:" << adr->varsta;
						cout << endl;
					}
					else
						cout << "Eroare - numele cautat nu exista!\n";
					
					system("pause");
					break;
				
				case 2:
					//CAUTARE DUPA PRENUME
					nodLSIpersoana* cautare;
					char cheie[30];
					
					cout << "Introduceti prenumele cautat:";
					scanf("%s", &cheie);

					cautare = cautare_nume(LIST, cheie);
					
					if (cautare != NULL)
					{
						cout << "Elementul a fost gasit!\n";
						cout << "\nNume:" << cautare->nume;
						cout << "\nPrenume:" << cautare->prenume;
						cout << "\nVarsta:" << cautare->varsta;
						cout << endl;
					}
					else
					{
						cout << "Eroare - prenumele cautat nu exista!\n";
					}
					
					system("pause");
					break;
				
				case 3:
					//CAUTARE DUPA VARSTA

					nodLSIpersoana* varsta;
					int key;

					cout << "Introduceti varsta cautata:";
					cin >> key;

					varsta = cautare_varsta(LIST, key);
					if (varsta != NULL)
					{
						cout << "Elementul a fost gasit!\n";
						cout << "\nNume:" << varsta->nume;
						cout << "\nPrenume:" << varsta->prenume;
						cout << "\nVarsta:" << varsta->varsta;
						cout << endl;
					}
					else
						cout << "Eroare - varsta cautata nu exista!\n";

					system("pause");
					break;

				case 4:
					//IESIRE
					system("cls");
					break;
				}

			} while (opt3 != 4); //SFARSIT MENIU CAUTARE
			break;
		
		case 4:
			//AFISARE

			if (LIST == NULL)
				cout << "Eroare - Lista vida!\n";
			else
				afisare(LIST);
			
			system("pause");
			system("cls");
			break;
		
		case 5:
			//DISTRUGERE

			LIST = distrugere(LIST);
			cout << "Lista a fost distrusa!\n";
			
			system("pause");
			system("cls");
			break;
		
		case 6:
			//INCEPUT MENIU OP EXTINSE

			do {
				system("cls");
				cout<<"Operatii extinse:\n";
				cout << "1. Adaugare.\n";
				cout << "2. Stergere.\n";
				cout << "3. Cautare.\n";
				cout << "4. Afisare.\n";
				cout << "5. Actualizare.\n";
				cout << "6. Varsta maxima din cartier\n";
				cout << "7. ! TODO !\n";
				cout << "8. Iesire.\n";
				cout << "Alegeti optiunea: ";
				cin >> opt4;
				switch (opt4) {
				
				case 8:
					//IESIRE

					break;
				
				case 1:
					do {
						//INCEPUT MENIU ADUGARE
						
						system("cls");
						printf("Adaugare:\n");
						printf("1. La inceput.\n");
						printf("2. La sfarsit.\n");
						printf("3. Iesire.\n");
						printf("Alegeti optiunea: ");
						scanf("%d", &opt5);
					
						switch (opt5) {
					
						case 1:
							//INSERARE INCEPUT

							printf("Introduceti nume cartier: ");
							scanf("%s", cartier);
							LISTC = inserare_inceput_cartier(LISTC, cartier, LIST);
							break;
						
						case 2:	
							//INSERARE SFARSIT

							printf("Introduceti nume cartier: ");
							scanf("%s", cartier);
							LISTC = inserare_sfarsit_cartier(LISTC, cartier, LIST);
							break;
						
						case 3:
							//IESIRE

							system("cls");
							break;
						}
					} while (opt5 != 3); //SFARSIT MENIU ADAUGARE
					break;
					case 2:
						//INCEPUT MENIU STERGERE

						do {

							system("cls");
							printf("Stergere:\n");
							printf("1. La inceput.\n");
							printf("2. La sfarsit.\n");
							printf("3. Iesire.\n");
							printf("Alegeti optiunea: \n");
							cin >> opt6;

							switch (opt6) {

							case 1:
								//STERGERE INCEPUT CARTIER

								cout << "Primul cartier a fost sters!\n";
								LISTC = stergere_inceput_cartier(LISTC);
								break;

							case 2:
								//STERGERE SFARSIT CARTIER

								cout << "Ultimul cartier a fost sters";
								LISTC = stergere_sfarsit_cartier(LISTC);
								break;

							case 3:
								//IESIRE
								
								system("cls");
								break;
							}
						} while (opt5 != 3); //SFARSIT MENIU STERGERE

						break;
					
					case 3:
						//CAUTARE

						system("cls");
						cout << "Introduceti numele cauat:";
						scanf("%s", cheie_cartier);

						nodLSIcartier* adr_cartier;
						adr_cartier = cautare_cartier(LISTC, cheie_cartier);
						if (adr_cartier == NULL)
						{
							cout << "Eroare - cartierul nu a fost gasit!\n";
						}
						else
						{
							cout << "Cartierul a fost gasit!\n";
							cout << "Nume: " << adr_cartier->nume;
							cout << endl;
						}
						system("pause");
						break;
					
					case 4:
						//AFISARE

						afisare_cartier(LISTC);
						cout << endl;
						system("pause");
						break;

					case 5:
						//ACTUALIZARE
						
						system("cls");
						
						cout << "Introduceti cartierul pe care doriti sa-l actualizati:";
						scanf("%s", cheie_cartier);

						cout << "Introduceti noul nume:";
						scanf("%s", nume_nou);

						LISTC = actualizare_cartier(LISTC, cheie_cartier, nume_nou);
						
						cout << "Numele cartierului '" << cheie_cartier << "' a fost actualizat!\n";
						cout << "Noul nume: " << nume_nou << endl;

						system("pause");
						break;

					case 6:
						//MAXIM VARSTA
						system("cls");

						cout << "Introduceti cartierul in care doriti sa cautati:";
						scanf("%s", cheie_cartier);

						cout << "Persoana cu varsta maxima este:\n";
						cout << "Nume:"; 
						max_varsta(LISTC, cheie_cartier);

						system("pause");
						break;

				
					}
				} while (opt4 != 8); //SFARSIT MENIU OP EXTINSE
			}
		} while (opt != 6);	  //SFARSIT MENIU PRINCIPAL
	
	return 0;
}