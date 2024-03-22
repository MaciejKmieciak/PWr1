#include <iostream>

using namespace std;

void merge_sort_od_dolu(int* A, int* B, int rozmiar);
void polacz_fragmenty(int* A, int* B, int index_poczatek_a, int index_poczatek_b, int index_koniec_b);

int main()
{
    int ile;
    cin >> ile;

    int *tab_wejscie = new int[ile], *tab_posortowana = new int[ile];

    for (int i = 0; i < ile; ++i)
        cin >> tab_wejscie[i];

    merge_sort_od_dolu(tab_wejscie, tab_posortowana, ile);

    for (int i = 0; i < ile; ++i)
        cout << tab_posortowana[i] << " ";

    return 0;
}

void merge_sort_od_dolu(int* A, int* B, int rozmiar) {

    // Bierzemy coraz wieksze podzbiory tablicy, tzn. najpierw singletony, potem dwojki, czworki itd. 
    // Na koniec kazdej iteracji mamy tablice, ktorej coraz szersze fragmenty sa wewnetrznie posortowane. 
    for (int szerokosc_fragmentow = 1; szerokosc_fragmentow < rozmiar; szerokosc_fragmentow *= 2) {

        // Dla kazdego fragmentu wykonujemy operacje laczenia z sortowaniem.
        // Dzieki funkcjom min() mamy pewnosc, ze nigdy nie wyjdziemy poza granice tablicy,
        // jesli jej rozmiar nie jest potega dwojki
        for (int i = 0; i < rozmiar; i += 2 * szerokosc_fragmentow) {
            polacz_fragmenty(A, B, i, min(i + szerokosc_fragmentow, rozmiar), min(i + 2 * szerokosc_fragmentow, rozmiar));
        }

        // Teraz w tablicy B fragmenty danej szerokosci wewnetrznie posortowane
        // Tablica B staje sie nowa tablica A dla nastepnej iteracji 
        // (poprzedniej tablicy A dalej nie potrzebujemy)
        for (int i = 0; i < rozmiar; ++i) {
            A[i] = B[i];
        }

        // Podwajamy szerokosc fragmentow...
    }
}

void polacz_fragmenty(int* A, int* B, int index_poczatek_a, int index_poczatek_b, int index_koniec_b) {
    // Indeksem i bedziemy przesuwac sie po lewym fragmencie
    // Indeksem j bedziemy przesuwac sie po prawym fragmencie
    int i = index_poczatek_a, j = index_poczatek_b;

    // Kolejne indeksy k odpowiadaja kolejnym miejscom nowego, posortowanego fragmentu tablicy B
    for (int k = index_poczatek_a; k < index_koniec_b; ++k) {

        // Jesli z indeksem i nie wyszlismy poza granice lewego fragmentu
        // oraz jesli wartosc w lewym fragmencie na miejscu i jest <= warotsci w prawym fragmencie na miejscu j
        // (lub jesli prawy fragment sie skonczyl), 
        // to na miejscu k w tablicy B umieszczamy wartosc z lewego fragmentu
        // oraz przesuwamy indeks i o jeden w prawo
        if (i < index_poczatek_b && (j >= index_koniec_b || A[i] <= A[j])) {
            B[k] = A[i];
            ++i;
        }

        // W przeciwnym wypadku, czyli jesli
        // prawy fragment sie nie skonczyl oraz [lewy fragment sie skonczyl lub
        // wartosc w prawym fragmencie na miejscu j > wartosci w lewym frag. na miejscu i],
        // to na miejscu k w tablicy B umieszczamy wartosc z prawego fragmentu
        // oraz przesuwamy indeks j o jeden w prawo
        else {
            B[k] = A[j];
            ++j;
        }
    }
}