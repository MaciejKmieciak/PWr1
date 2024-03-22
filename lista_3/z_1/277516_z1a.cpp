#include <iostream>

using namespace std;

int main() {
	int ile_zapalek, nr_rundy = 0, ile_zabrano;

	string gracz_a, gracz_b;

	bool semafor = false, czy_pomylka;

	cout << "Gra w zapalki" << endl;
	cout << "Podaj liczbe zapalek: ";
	cin >> ile_zapalek;

	cout << "Podaj nazwe pierwszego gracza: ";
	cin >> gracz_a;

	cout << "Podaj nazwe drugiego gracza: ";
	cin >> gracz_b;

	cout << endl;

	while (ile_zapalek > 0) {

		++nr_rundy;

		semafor = !semafor;

		cout << "Runda " << nr_rundy << "! Pozostalo zapalek: " << ile_zapalek << endl;

		do {
			czy_pomylka = false;

			cout << "To ruch gracza ";

			if (semafor) {
				cout << gracz_a;
			}
			else {
				cout << gracz_b;
			}

			cout << ". Ile zapalek zabrac (1, 2 lub 3): ";
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

		ile_zapalek -= ile_zabrano;

		cout << endl;
	}

	cout << "Koniec gry! Wszystkie zapalki zostaly zabrane. " << endl;

	if (semafor) {
		cout << "Wygrywa gracz " << gracz_b << ", a przegrywa gracz " << gracz_a << endl;
	}
	else {
		cout << "Wygrywa gracz " << gracz_a << ", a przegrywa gracz " << gracz_b << endl;
	}

	return 0;
}
