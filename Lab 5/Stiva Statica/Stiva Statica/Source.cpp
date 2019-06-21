#include <iostream>

using namespace std;

struct Data1 {
	int cod = 0;
	int cantitate = 0;
};

struct Data2 {
	int cod = 0;
	int pret = 0;
};

struct Data3 {
	int cod = 0;
	int cantitate = 0;
	int pret = 0;
};

struct StackS {
	Data1* data = NULL;
	int TOP;
	int MAX;
};

struct StackS2 {
	Data2* data = NULL;
	int TOP;
	int MAX;
};

struct StackS3 {
	Data3* data = NULL;
	int TOP;
	int MAX;
};	

bool emptyStack(StackS stiva) {
	return (stiva.TOP == 0);
}

bool fullStack(StackS stiva) {
	return (stiva.TOP == stiva.MAX);
}

bool fullStack2(StackS2 stiva) {
	return (stiva.TOP == stiva.MAX);
}

bool fullStack3(StackS3 stiva) {
	return(stiva.TOP == stiva.MAX);
}

bool emptyStack2(StackS2 stiva) {
	return (stiva.TOP == 0);
}

bool emptyStack3(StackS3 stiva) {
	return (stiva.TOP == 0);
}

StackS popSS(StackS stiva, Data1* elementScos) {
	if (emptyStack(stiva)) {
		cout << "Lista este goala\n";
		elementScos = NULL;
	}
	else {
		*elementScos = stiva.data[stiva.TOP - 1];
		stiva.TOP--;
	}

	return stiva;
}

StackS2 popSS2(StackS2 stiva, Data2* elementScos) {
	if (emptyStack2(stiva)) {
		cout << "Lista este goala\n";
		elementScos = NULL;
	}
	else {
		*elementScos = stiva.data[stiva.TOP - 1];
		stiva.TOP--;
	}

	return stiva;
}

StackS pushSS(StackS stiva, Data1 info_nou) {
	if (fullStack(stiva)) {
		cout << "Lista este plina\n";
	}
	else {
		stiva.data[stiva.TOP] = info_nou;
		stiva.TOP++;
	}
	return stiva;
}

StackS2 pushSS2(StackS2 stiva, Data2 info_nou) {
	if (fullStack2(stiva)) {
		cout << "Lista este plina\n";
	}
	else {
		stiva.data[stiva.TOP] = info_nou;
		stiva.TOP++;
	}
	return stiva;
}

StackS initializareSS(StackS stiva) {
	if (stiva.data != NULL) {
		delete[] stiva.data;
	}
	cout << "Introduceti max pentru stiva 1: ";
	cin >> stiva.MAX;
	stiva.data = new Data1[stiva.MAX];
	stiva.TOP = 0;
	return stiva;
} 

StackS2 initializareSS2(StackS2 stiva) {
	if (stiva.data != NULL) {
		delete[] stiva.data;
	}
	cout << "Introduceti max pentru stiva 2: ";
	cin >> stiva.MAX;
	stiva.data = new Data2[stiva.MAX];
	stiva.TOP = 0;
	return stiva;
}

StackS3 initializareSS3(StackS3 stiva, int max) {
	stiva.MAX = max;
	stiva.TOP = 0;
	stiva.data = new Data3[stiva.MAX];
	return stiva;
}

StackS initializarebestSS(StackS stiva, int max) {

	stiva.data = new Data1[max + 1];
	stiva.TOP = 0;
	return stiva;
}

StackS clearSS(StackS stiva) {
	Data1 elementscos;
	int i = 1;
	while (!emptyStack(stiva)) {
		stiva = popSS(stiva, &elementscos);
		cout << i << ".cod: " << elementscos.cod << endl;
		cout << i << ".cantitate: " << elementscos.cantitate << endl;
		cout << endl;
		i++;
	}
	return stiva;
}

StackS2 clearSS2(StackS2 stiva) {
	Data2 elementscos;
	int i = 1;
	while (!emptyStack2(stiva)) {
		stiva = popSS2(stiva, &elementscos);
		cout << i << ".cod: " << elementscos.cod << endl;
		cout << i << ".pret: " << elementscos.pret << endl;
		cout << endl;
		i++;
	}
	return stiva;
}

StackS3 pushSS3(StackS3 stiva, Data3 info_nou) {
	if (fullStack3(stiva)) {
		cout << "Stack Overflow\n";
	}
	else {
		stiva.data[stiva.TOP] = info_nou;
		stiva.TOP++;
	}

	return stiva;
}

StackS3 popSS3(StackS3 stiva, Data3 *elementScos) {
	if (emptyStack3(stiva)) {
		cout << "Stack Underflow\n";
		elementScos = NULL;
	}
	else {
		*elementScos = stiva.data[stiva.TOP - 1];
		stiva.TOP--;
	}
	
	return stiva;
}

StackS3 clearSS3(StackS3 stiva)
{
	Data3 elementscos;
	int i = 1;
	while (!emptyStack3(stiva)) {
		stiva = popSS3(stiva, &elementscos);
		cout << i << ".cod: " << elementscos.cod << endl;
		cout << i << ".cantitate: " << elementscos.cantitate << endl;
		cout << i << ".pret: " << elementscos.pret << endl;
		cout << endl;
		i++;
	}
	
	return stiva;
}

StackS pushEx(StackS stiva, Data1 info_nou) {
	if (fullStack(stiva)) {
		StackS stiva2;
		stiva2 = initializarebestSS(stiva2, stiva.MAX);
		for (int i = 0; i < stiva.MAX; i++) {
			stiva2.data[i] = stiva.data[i];
		}
		stiva2.TOP = stiva.TOP;
		stiva2.data[stiva2.TOP] = info_nou;
		stiva2.TOP++;
		
		delete[] stiva.data;
		return stiva2;
	}
	else {
		stiva.data[stiva.TOP] = info_nou;
		stiva.TOP++;
	}

	return stiva;
}

int main() {
	
	int meniu, submeniu, sm2;
	StackS stiva;
	StackS2 stiva2;
	StackS3 stiva3;
	Data1 data1;
	Data2 data2;
	Data3 data3;
	
	do {	//MENIU PRINCIPAL
		system("cls");
		cout << "1. Operatii de baza\n";
		cout << "2. Operatii extinse\n";
		cout << "3. Iesire\n";
		cout << "Introduceti optiunea:";
		cin >> meniu;
		
		switch (meniu) {
		case 1:	   //MENIU OPERATII DE BAZA
			do {
				system("cls");
				cout << "1. Stiva statica uzuala\n";
				cout << "2. Stiva statica extensibila\n";
				cout << "3. Inapoi\n";
				cout << "Introduceti optiunea:";
				cin >> submeniu;
				
				switch (submeniu) {
				case 1:		 //MENIU STIVA UZUALA
					stiva = initializareSS(stiva);
					
					do {
						system("cls");
						cout << "1. Push\n";
						cout << "2. Pop\n";
						cout << "3. Clear\n";
						cout << "4.Iesire\n";
						cout << "Introduceti optiunea:";
						cin >> sm2;
						switch (sm2) {
						
						case 1:
							//push1
							cout << "Cod: ";
							cin >> data1.cod;
							cout << "Cantitate: ";
							cin >> data1.cantitate;
							stiva = pushSS(stiva, data1);
							break;
						
						case 2:
							//pop1
							stiva = popSS(stiva, &data1);
							if (&data1 != NULL) {
								cout << "cod: " << data1.cod << endl;
								cout << "cantitate: " << data1.cantitate << endl;
							}
							else {
								cout << "Elementul nu a fost scos.";
							}
							system("pause");
							break;
						
						case 3:
							//clear1
							stiva = clearSS(stiva);
							system("pause");
							break;
						
						case 4:
							break;
						}
					} while (sm2 != 4);
					break;
				
				case 2:	 //MENIU STIVA EXTENSIBILA
					stiva = initializareSS(stiva);
					do {
						system("cls");
						cout << "1. Push\n";
						cout << "2. Pop\n";
						cout << "3. Clear + afisare\n";
						cout << "4. Inapoi\n";
						cout << "Introduceti optiunea:";
						cin >> sm2;

						switch (sm2) {
						case 1:
							cout << "Cod: ";
							cin >> data1.cod;
							cout << "Cantitate: ";
							cin >> data1.cantitate;
							stiva = pushEx(stiva, data1);
							break;

						case 2:
							stiva = popSS(stiva, &data1);
							if (&data1 != NULL) {
								cout << "cod: " << data1.cod << endl;
								cout << "cantitate: " << data1.cantitate << endl;
							}
							else {
								cout << "Elementul nu a fost scos.";
							}
							system("pause");
							break;

						case 3:
							//clear
							stiva = clearSS(stiva);
							system("pause");
							break;

						case 4:
							system("cls");
							break;
						}
					} while (sm2 != 4);
					break;
				
				case 3:
					break;
				}
			} while (submeniu != 3);
			break;
		
		case 2:	 //OPERATII EXTINSE
			do {
				system("cls");
				cout << "1. Stiva statica uzuala\n";
				cout << "2. Stiva statica extensibila\n";
				cout << "3. Inapoi\n";
				cout << "Introduceti optiunea:";
				cin >> submeniu;
				
				switch (submeniu) {
				case 1:		//STIVA UZUALA - OP EXTINSE
					stiva = initializareSS(stiva);
					stiva2 = initializareSS2(stiva2);
					
					do {
						system("cls");
						cout << "1. Push1\n";
						cout << "2. Push2\n";
						cout << "3. Pop1\n";
						cout << "4. Pop2\n";
						cout << "5. Clear1\n";
						cout << "6. Clear2\n";
						cout << "7. Generare stiva 3\n";
						cout << "8. Pop3\n";
						cout << "9. Clear3\n";
						cout << "10.Inapoi\n";
						cout << "Introduceti optiunea:";
						cin >> sm2;
				
						switch (sm2) {
						case 1:
							//push1
							cout << "Cod: ";
							cin >> data1.cod;
							cout << "Cantitate: ";
							cin >> data1.cantitate;
							stiva = pushSS(stiva, data1);
							break;
						
						case 2:
							//push2
							cout << "Cod: ";
							cin >> data2.cod;
							cout << "Pret: ";
							cin >> data2.pret;
							stiva2 = pushSS2(stiva2, data2);
							break;
						
						case 3:
							//pop1
							stiva = popSS(stiva, &data1);
							if (&data1 != NULL) {
								cout << "cod: " << data1.cod << endl;
								cout << "cantitate: " << data1.cantitate << endl;
							}
							else {
								cout << "Elementul nu a fost scos.";
							}
							system("pause");
							break;
						
						case 4:
							//pop2
							stiva2 = popSS2(stiva2, &data2);
							if (&data2 != NULL) {
								cout << "cod: " << data2.cod << endl;
								cout << "cantitate: " << data2.pret << endl;
							}
							else {
								cout << "Elementul nu a fost scos.";
							}
							system("pause");
							break;
						
						case 5:
							//clear1
							stiva = clearSS(stiva);
							system("pause");
							break;
						
						case 6:
							//clear2
							stiva2 = clearSS2(stiva2);
							system("pause");
							break;
						
						case 7:
							//Generare stiva 3
							if (stiva.MAX > stiva2.MAX) {
								stiva3 = initializareSS3(stiva3, stiva.MAX);
								
								while (!emptyStack(stiva)) {
									stiva = popSS(stiva, &data1);
									stiva2 = popSS2(stiva2, &data2);
									
									if (data1.cod == data2.cod && data2.cod!=NULL) {
										data3.cod = data2.cod;
										data3.cantitate = data1.cantitate;
										data3.pret = data2.pret;
										stiva3 = pushSS3(stiva3, data3);
										cout << "Introdus\n";
									}
									else {
										data3.cod = -1;
										data3.cantitate = -1;
										data3.pret = -1;
										stiva3 = pushSS3(stiva3, data3);
										cout << "Introdus\n";
									}

								}
							}
							else {
								stiva3 = initializareSS3(stiva3, stiva2.MAX);
								
								while (!emptyStack(stiva)) {
									stiva = popSS(stiva, &data1);
									stiva2 = popSS2(stiva2, &data2);
									if (data1.cod == data2.cod && data1.cod!=NULL) {
										data3.cod = data2.cod;
										data3.cantitate = data1.cantitate;
										data3.pret = data2.pret;
										stiva3 = pushSS3(stiva3, data3);
										cout << "Introdus\n";
									}
									else {
										data3.cod = -1;
										data3.cantitate = -1;
										data3.pret = -1;
										stiva3 = pushSS3(stiva3, data3);
										cout << "Introdus\n";
									}
								}
							}
							cout << "Stiva 3 genarata\n";
							system("pause");
							break;
						
						case 8:
							stiva3 = popSS3(stiva3, &data3);
							if (&data3 != NULL) {
								cout << "Cod:" << data3.cod << endl;
								cout << "Cantitate:" << data3.cantitate << endl;
								cout << "Pret:" << data3.pret << endl;
								system("pause");
							}
							else {
								cout << "Nu s-a extras nimic\n";
								system("pause");
							}
								
							break;
						
						case 9:
							stiva3 = clearSS3(stiva3);
							system("pause");
							break;
						
						case 10:
							break;
						}
					} while (sm2 != 10);
					break;
				
				case 2: //STIVA EXTENSIBILA  - OP EXTINSE
					do {
						system("cls");
						cout << "1. Push1\n";
						cout << "2. Push2\n";
						cout << "3. Pop1\n";
						cout << "4. Pop2\n";
						cout << "5. Clear1\n";
						cout << "6. Clear2\n";
						cout << "7. Generare stiva 3\n";
						cout << "8. Pop3\n";
						cout << "9. Clear3\n";
						cout << "10.Inapoi\n";
						cout << "Introduceti optiunea:";
						cin >> sm2;

						switch (sm2) {

						case 1:
							//push1
							break;
						
						case 2:
							//push2
							break;

						case 3:
							//pop1
							break;

						case 4:
							//pop2
							break;

						case 5:
							//clear1
							break;

						case 6:
							//clear2
							break;

						case 7:
							//Generare stiva 3
							break;

						case 8:
							//pop3
							break;

						case 9:
							//clear3
							break;

						case 10:
							system("cls");
							break;
						}
					} while (sm2 != 10);
					break;

				case 3:
					break;
				}
			} while (submeniu != 3);
			break;
		}
	} while (meniu != 3);
	
	return 0;
}