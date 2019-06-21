#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <time.h>
#include <Windows.h>

#define minim 10240
#define maxim 102400

using namespace std;

struct Imagine{
	int nrBytes=0;
	char* buffer=NULL;
	__int64 CheckSum=0;
	Imagine* succ=NULL;
};

struct Data {
	char nume[30];
	char prenume[30];
	int serie;
};

struct nodLSI {
	Data data;
	nodLSI* succ;
};

struct QueueD {
	nodLSI* LIST=NULL;
	nodLSI* END=0; 
};

struct QueueS {
	Data* data = NULL;
	int FRONT=0;
	int END=0;
	int MAX=0;
};

struct QueueImg {
	Imagine* FRONT = NULL;
	Imagine* END = NULL;
};

nodLSI* alocare_nod(Data info) {
	nodLSI* nod = new nodLSI;
	
	nod->data = info;
	nod->succ = NULL;

	return nod;
}

Imagine* alocare_imagine() {
	
	srand(time(NULL));
	Imagine* img = new Imagine();
	img->nrBytes = rand() % (maxim - minim + 1) + minim;

	img->buffer = new char[img->nrBytes];

	for (int i = 0; i < img->nrBytes; i++) {
		img->buffer[i] = rand() % 254;
	}

	for (int i = 0; i < img->nrBytes; i++) {
		img->CheckSum += img->buffer[i];
	}

	return img;
}

QueueS initializare_CS(QueueS coada) {
	if (coada.data != NULL)
		delete[] coada.data;

	cout << "Max=";
	cin >> coada.MAX;

	coada.data = new Data[coada.MAX];
	coada.FRONT = 0;
	coada.END = 0;

	return coada;
}

bool FullQueue(QueueS coada) {
	return (coada.END == coada.MAX);
}

bool EmptyQueue(QueueS coada) {
	return (coada.FRONT == coada.END);
}

bool EmptyQueue_CD(QueueD coada) {
	if (coada.LIST == NULL && coada.END == NULL)
		return true;
	else
		return false;
}

bool isEmptyQImg(QueueImg coadaImg) {
	return (coadaImg.FRONT == NULL && coadaImg.END == NULL);
}

QueueS enqueue_CS(QueueS coada, Data info) {
	if (FullQueue(coada))
		cout << "Coada plina\n";
	else {
		coada.data[coada.END] = info;
		coada.END++;
	}

	return coada;
}

QueueS dequeue_CS(QueueS coada, Data* elementScos) {
	if (EmptyQueue(coada))
		cout << "Coada goala\n";
	else {
		*elementScos = coada.data[coada.FRONT];
		for (int i = 0; i < coada.MAX; i++)
			coada.data[i] = coada.data[i + 1];
		coada.END--;
	}

	return coada;
}

QueueS clear_CS(QueueS coada) {
	Data elementScos;
	int i = 1;
	
	while (!EmptyQueue(coada)) {
		coada = dequeue_CS(coada, &elementScos);
		cout << i << " Nume:" << elementScos.nume << endl;
		cout << "Prenume:" << elementScos.prenume << endl;
		cout << "Serie buletin:" << elementScos.serie << endl;
		cout << endl;
		i++;
	}

	return coada;
}

QueueD enqueue_CD(QueueD coada, Data info) {
	if (coada.LIST == NULL) {
		nodLSI* nou = alocare_nod(info);

		if (nou == NULL)
			cout << "Eroare - Memorie insuficienta\n";
		else {
			coada.LIST = nou;
			nou->data = info;
			nou->succ = NULL;
		}
	}
	else {
		nodLSI* tmp = coada.LIST;
		while (tmp->succ) {
			tmp = tmp->succ;
		}

		nodLSI* ultim = tmp;
		nodLSI* nou = alocare_nod(info);
		ultim->succ = nou;
		nou->succ = NULL;
		nou->data = info;
		
	}

	return coada
;
}

QueueD dequeue_CD(QueueD coada, Data* elementScos) {
	if (EmptyQueue_CD(coada)) {
		cout << "Coada este goala\n";
		elementScos = NULL;
	}
	nodLSI* salv = coada.LIST;
	coada.LIST = coada.LIST->succ;
	*elementScos = salv->data;
	delete salv;
	
	return coada;
 }

QueueD clear_CD(QueueD coada) {
	Data elementScos;
	int i = 1;

	while (!EmptyQueue_CD(coada)) {
		coada = dequeue_CD(coada, &elementScos);
		cout << i << " Nume:" << elementScos.nume << endl;
		cout << "Prenume:" << elementScos.prenume << endl;
		cout << "Serie buletin:" << elementScos.serie << endl;
		cout << endl;
		i++;
	}

	return coada;
}

QueueD initializare_CD(QueueD coada) {
	Data elementScos;

	if (coada.LIST != NULL)
		dequeue_CD(coada, &elementScos);

	
	coada.END = NULL;
	coada.LIST = NULL;

	return coada;
}

QueueImg enqueue_img(QueueImg coadaImg) {
	if (isEmptyQImg(coadaImg)) {
		Imagine* img = alocare_imagine();
		coadaImg.FRONT = img;
		coadaImg.END = img;
	}
	else {
		Imagine* img = alocare_imagine();
		img->succ = coadaImg.END;
		coadaImg.END = img;
	}
	return coadaImg;
}

QueueImg dequeue_img(QueueImg coadaImg) {
	if (isEmptyQImg(coadaImg)) {
		cout << "Eroare - coada goala.\n";
		return coadaImg;
	}
	Imagine* tmp = coadaImg.END;
	Imagine* salv = coadaImg.FRONT;
	if (coadaImg.END == coadaImg.FRONT) {
		cout << "noBytes = " << salv->nrBytes << endl;
		cout << "checkSum = " << salv->CheckSum << endl;
		cout << endl;
		delete salv;
		coadaImg.END = NULL;
		coadaImg.FRONT = NULL;
		return coadaImg;
	}
	while (tmp->succ != coadaImg.FRONT) {
		tmp = tmp->succ;
	}
	cout << "noBytes = " << salv->nrBytes << endl;
	cout << "checkSum = " << salv->CheckSum << endl;
	coadaImg.FRONT = tmp;
	tmp->succ = NULL;
	delete salv;
	return coadaImg;
}

QueueImg clear_img(QueueImg coadaImg) {
	if (isEmptyQImg(coadaImg)) {
		cout << "Eroare - coada goala.\n";
	}
	while (!isEmptyQImg(coadaImg)) {
		coadaImg = dequeue_img(coadaImg);
	}
	return coadaImg;
}

int main() {
	int meniu, submeniu;
	QueueS coada;
	QueueD coadaD;
	QueueImg coadaImg;
	Data data;
	

	do {
		system("cls");					//INCEPUT MENIU PRINCIPAL
		cout << "1. Operatii de baza\n";
		cout << "2. Operatii extinse\n";
		cout << "3. Iesire\n";
		cout << "Introduceti optiunea:";
		cin >> meniu;

		switch (meniu) {
		case 1:

			do {
				system("cls");	 //INCEPUT MENIU OP BAZA
				cout << "1. Coada - implementare statica\n";
				cout << "2. Coada - implementare dinamica\n";
				cout << "3. Inapoi\n";
				cout << "Introduceti optiunea:";
				cin >> submeniu;

				switch (submeniu) {
				case 1:
					coada = initializare_CS(coada);
					do {
						system("cls");  //INCEPUT MENIU COADA STATICA
						cout << "1. Enqueue\n";
						cout << "2. Dequeue\n";
						cout << "3. Clear\n";
						cout << "4. Inapoi\n";
						cout << "Introduceti optiunea:";
						cin >> submeniu;

						switch (submeniu) {
						case 1:
							//enqueue
							cout << "Nume:";
							cin >> data.nume;

							cout << "Prenume:";
							cin >> data.prenume;

							cout << "Serie buletin:";
							cin >> data.serie;

							coada = enqueue_CS(coada, data);

							break;

						case 2:
							//dequeue
							coada = dequeue_CS(coada, &data);

							if (&data != NULL) {
								cout << "Nume:" << data.nume << endl;
								cout << "Prenume:" << data.prenume << endl;
								cout << "Serie buletin:" << data.serie << endl;
							}
							else {
								cout << "Elementul nu a fost scos\n";
							}

							system("pause");
							break;

						case 3:
							//clear
							coada = clear_CS(coada);

							system("pause");
							break;

						case 4:
							//inapoi
							break;
						}
					} while (submeniu != 4);  //SF MENIU COADA STATICA
					break;

				case 2:
					coadaD = initializare_CD(coadaD);
					do {
						system("cls");	//INCEPUT MENIU COADA DINAMICA
						cout << "1. Enqueue\n";
						cout << "2. Dequeue\n";
						cout << "3. Clear\n";
						cout << "4. Inapoi\n";
						cout << "Introduceti optiunea:";
						cin >> submeniu;

						switch (submeniu) {
						case 1:
							//enqueue
							cout << "Nume:";
							cin >> data.nume;

							cout << "Prenume:";
							cin >> data.prenume;

							cout << "Serie buletin:";
							cin >> data.serie;

							coadaD = enqueue_CD(coadaD, data);
							break;

						case 2:
							//dequeue
							coadaD = dequeue_CD(coadaD, &data);

							if (&data != NULL) {
								cout << "Nume:" << data.nume << endl;
								cout << "Prenume:" << data.prenume << endl;
								cout << "Serie buletin:" << data.serie << endl;
							}
							else {
								cout << "Elementul nu a fost scos\n";
							}

							system("pause");
							break;

						case 3:
							//clear
							coadaD = clear_CD(coadaD);
							system("pause");
							break;

						case 4:
							//inapoi
							break;
						}
					} while (submeniu != 4);  //SF MENIU COADA DINAMICA

				}
			} while (submeniu != 3);   //SF MENIU OP DE BAZA

			break;

		case 2:
			//operatii extinse
			coadaD = initializare_CD(coadaD);
			do {
				system("cls");
				cout << "1. Enqueue\n";
				cout << "2. Dequeue\n";
				cout << "3. Clear\n";
				cout << "4. Inapoi\n";
				cout << "Introduceti optiunea:";
				cin >> submeniu;

				switch (submeniu) {
				case 1:
					//enqueue
					coadaImg = enqueue_img(coadaImg);
					cout << "Inserat\n";
					system("pause");
					break;

				case 2:
					//dequeue
					coadaImg = dequeue_img(coadaImg);
					system("pause");
					break;

				case 3:
					//clear
					coadaImg = clear_img(coadaImg);
					system("pause");
					break;

				case 4:
					//inapoi;
					break;
				}
			} while (submeniu != 4);
			break;

		case 3:
			//iesire
			break;
		}
	} while (meniu != 3);	//SF MENIU PRINCIPAL

	return 0;
}