#include <iostream>

using namespace std;

int main() {
	int ile_zapalek, nr_rundy = 0, ile_zabrano;

	bool semafor = false, czy_pomylka;

	cout << "Gra w zapalki z komputerem" << endl;
	cout << "Podaj liczbe zapalek: ";
	cin >> ile_zapalek;

	cout << endl;

	while (ile_zapalek > 0) {

		++nr_rundy;

		semafor = !semafor;

		cout << "Runda " << nr_rundy << "! Pozostalo zapalek: " << ile_zapalek << endl;

		if (semafor) do { // Ruch gracza
			czy_pomylka = false;

			cout << "To ruch gracza. Ile zapalek zabrac (1, 2 lub 3): ";
			cin >> ile_zabrano;

			if (ile_zabrano < 1) {
				cout << "Blad! Liczba zabranych zapalek musi byc dodatnia. " << endl;
				czy_pomylka = true;
			}

			else if (ile_zabrano > 3) {
				cout << "Blad! Nie wolno zabrac wiecej niz 3 zapalki. " << endl;
				czy_pomylka = true;
			}

			else if (ile_zabrano > ile_zapalek) {
				cout << "Blad! Nie wolno zabrac wiecej zapalek niz pozostalo. " << endl;
				czy_pomylka = true;
			}

		} while (czy_pomylka);

		else { // Ruch komputera
			cout << "To ruch komputera. Komputer zabiera zapalek: ";

			/*
			* Opis strategii
			*
			* Kiedy pozostala 1 zapalka, komputer PRZEGRYWA
			* Kiedy pozostaly 2 zapalki, komputer zabiera jedna i WYGRYWA
			* Kiedy pozostaly 3 zapalki, komputer zabiera dwie i WYGRYWA
			* Kiedy pozostaly 4 zapalki, komputer zabiera trzy i WYGRYWA
			*
			* Kiedy pozostalo 5 zapalek, komputer redukuje do liczby 2 / 3 / 4, wiec PRZEGRYWA
			* Kiedy pozostalo 6 zapalek, komputer zabiera jedna i WYGRYWA
			* Kiedy pozostalo 7 zapalek, komputer zabiera dwie i WYGRYWA
			* Kiedy pozostalo 8 zapalek, komputer zabiera trzy i WYGRYWA
			*
			* itd...
			*
			* Zwyciestwo zapewnia liczba zapalek mod 4 rowna 2, 3, lub 0
			* Nalezy wtedy odpowiednio :
			* brac jedna zapalke gdy reszta rowna 2
			* brac dwie zapalki gdy reszta rowna 3
			* brac trzy zapalki gdy reszta rowna 0
			*
			* Gdy reszta rowna 1 jestesmy na przegranej pozycji
			* Mozna wtedy zabrac jedna zapalke,
			* co daje najwieksza szanse na pomylke niewtajemniczonego przeciwnika
			*/

			switch (ile_zapalek % 4)
			{
			case 0:
				ile_zabrano = 3;
				break;
			case 3:
				ile_zabrano = 2;
				break;
			default:
				ile_zabrano = 1;
				break;
			}

			cout << ile_zabrano << endl;
		}

		

		ile_zapalek -= ile_zabrano;

		cout << endl;
	}

	cout << "Koniec gry! Wszystkie zapalki zostaly zabrane. " << endl;

	if (semafor) {
		cout << "Wygrywa komputer. " << endl;
	}
	else {
		cout << "Wygrywa gracz. " << endl;
	}

	return 0;
}
