#include <iostream>
#include<stdlib.h>
#include<locale.h>
#include<time.h>
using namespace std;
void autor(void) {
	printf("\n");
	for (int i = 1; i <= 120; i++) cout << "*";
	cout << "Autor programu: Simon Dudek\n\n";
	for (int i = 1; i <= 120; i++) cout << "*";
}
void los(int x, int tab[10][10], int pocz, int kon, int kontroler) {
	srand(kontroler);
	if (pocz == 0) {
		kon++;
		for (int i = 0, j = 0; i < x && j < x; i++) {
			tab[j][i] = (pocz + rand() % kon);
			if (i == x - 1) {
				i = -1;
				j++;
			}
		}
	}
	else {
		if (pocz > 0) {
			kon -= pocz - 1;
			for (int i = 0, j = 0; i < x && j < x; i++) {
				tab[j][i] = (pocz + rand() % kon);
				if (i == x - 1) {
					i = -1;
					j++;
				}
			}
		}
		else {
			kon += (pocz * (-1)) + 1;
			for (int i = 0, j = 0; i < x && j < x; i++) {
				tab[j][i] = (pocz + rand() % kon);
				if (i == x - 1) {
					i = -1;
					j++;
				}
			}
		}
	}
}
void wyswietl(int x, int tab[10][10]) {
	for (int i = 0, j = 0; i < x && j < x; i++) {
		if (tab[j][i] >= 0 && tab[j][i] < 10)
		{
			cout << " " << tab[j][i] << " ";
			if (i == x - 1) {
				cout << endl;
				i = -1;
				j++;
			}
		}
		else {
			cout << tab[j][i] << " ";
			if (i == x - 1) {
				cout << endl;
				i = -1;
				j++;
			}
		}
	}
}
void trans(int x, int tab[10][10], int wyn[10][10]) {
	for (int i = 0, j = 0; i < x && j < x; i++) {
		wyn[i][j] = tab[j][i];
		if (i == x - 1) {
			i = -1;
			j++;
		}
	}
}
void trans(int x, int tab[10][10]) {
	int wyn[10][10];
	for (int i = 0, j = 0; i < x && j < x; i++) {
		wyn[i][j] = tab[j][i];
		if (i == x - 1) {
			i = -1;
			j++;
		}
	}
	for (int i = 0, j = 0; i < x && j < x; i++) {
		tab[j][i] = wyn[j][i];
		if (i == x - 1) {
			i = -1;
			j++;
		}
	}
}
void mnoz(int x, int tab[10][10], int y) {
	for (int i = 0, j = 0; i < x && j < x; i++) {
		tab[j][i] *= y;
		if (i == x - 1) {
			i = -1;
			j++;
		}
	}
}
void mnoz(int x, int tab[10][10], int czyn[10][10], int wyn[10][10]) {
	int y;
	int z = 0;
	for (int i = 0, j = 0; i < x && j < x; i++) {
		y = 0;
		for (int a = 0;a < x ;a++) {
			y += (tab[j][a] * czyn[a][z]);
		}
		z++;
		if (z == x) {
			z = 0;
		}
		wyn[j][i] = y;
		if (i == x - 1) {
			i = -1;
			j++;
		}
	}
}
int main()
{
	int wym, beg, end, mac1[10][10], mac2[10][10], iloczyn[10][10], control, czyn;
	time_t t;
	control = time(&t);
	setlocale(LC_ALL, "");
	autor();
	cout << "\nMaksymalny rozmiar macierzy to 10x10. ";
	cout << "Podaj wymiar macierzy: ";
	cin >> wym;
	while (wym > 10 || wym < 0)
	{
		cout << "Błędny rozmiar! Proszę ponowownie podać wymiar macierzy: ";
		cin >> wym;
	}
	cout << "Podaj zakres losowanych liczb.\n";
	cout << "Początek: ";
	cin >> beg;
	cout << "Koniec: ";
	cin >> end;
	while (beg >= end) {
		cout << "Błędne wpisanie zakresu! Aby zdefiniować liczba pocątkowa musi być mniejsza niż liczba końcowa!\n";
		cout << "Początek: ";
		cin >> beg;
		cout << "Koniec: ";
		cin >> end;
	}
	cout << endl;
	los(wym, mac1, beg, end, control);
	cout << "\n\n\nPierwsza macierz: \n\n";
	wyswietl(wym, mac1);
	trans(wym, mac1, mac2);
	trans(wym, mac1);
	cout << "\n\n\nMacierz po transponowaniu pierwszego sposobu: \n\n";
	wyswietl(wym, mac2);
	cout << "\n\n\nMacierz po transponowaniu drugiego sposobu: \n\n";
	wyswietl(wym, mac1);
	cout << "\n\n\nPodaj liczbę przez jaką chcesz pomnożyć macierz: ";
	cin >> czyn;
	los(wym, mac1, beg, end, control);
	mnoz(wym, mac1, czyn);
	cout << "\nPierwsza macierz po pomnożeniu przez "<<czyn<<" :\n\n";
	wyswietl(wym, mac1);
	los(wym, mac1, beg, end, control);
	cout << "\n\n\nPierwsza macierz:\n\n";
	wyswietl(wym, mac1);
	control = time(&t);
	los(wym, mac2, beg, end, control);
	cout << "\n\n\nDruga macierz:\n\n";
	wyswietl(wym, mac2);
	mnoz(wym, mac1, mac2, iloczyn);
	cout << "\n\n\nPierwsza macierz po pomnożeniu przez drugą macierz:\n\n";
	wyswietl(wym, iloczyn);
	cout << endl;
	system("pause");
	return 0;
}