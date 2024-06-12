#include <iostream>

using namespace std;

class Konto {
protected:
    string imie;
    string nazwisko;
    float stan_konta;
public:
    Konto(string i, string n) : imie(i), nazwisko(n), stan_konta(0.0) {};

    void wplata(float kwota_wplaty) {
        stan_konta += kwota_wplaty;
    }

    void wyplata(float kwota_wyplaty) {
        stan_konta -= kwota_wyplaty;
    }

    void sprawdz_stan() {
        cout << stan_konta << endl;
    }
};

class Premium : public Konto {
    int bonus;

public:
    Premium(string i, string n) : Konto(i, n), bonus(0) {};

    void wplata(float kwota_wplaty) {
        Konto::wplata(kwota_wplaty);
        ++bonus;
    }

    void wyplata(float kwota_wyplaty) {
        Konto::wyplata(kwota_wyplaty);
        ++bonus;
    }

    void sprawdz_stan() {
        cout << "Szanowny " << imie << " " << nazwisko << ", Twoj balans to " << stan_konta << " i bonus to " << bonus << endl;
    }
};

class Sub_premium : public Konto {
public:
    Sub_premium(string i, string n) : Konto(i, n) {};

    void sprawdz_stan() {
        cout << "Czesc, " << imie << " " << nazwisko << ", Twoj balans to " << stan_konta << endl;
    }
};

int main()
{
    string s1, s2;
    float w1, w2, w3;
    cin >> s1 >> s2 >> w1 >> w2 >> w3;

    Sub_premium* sub = new Sub_premium(s1, s2);

    Premium* premium = new Premium(s1, s2);

    sub->wplata(w1);
    sub->wplata(w2);
    sub->wyplata(w3);

    premium->wplata(w1);
    premium->wplata(w2);
    premium->wyplata(w3);

    sub->sprawdz_stan();

    premium->sprawdz_stan();

    return 0;
}