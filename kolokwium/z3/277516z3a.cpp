#include <iostream>
#include <math.h>

using namespace std;

class Wielomian {
public:
    int stopien;
    float* wspolczynniki;

    Wielomian(int s, float* tab) : stopien(s), wspolczynniki(tab) {};

    void wyswietl() {
        for (int i = 0; i <= stopien; ++i) {
            cout << wspolczynniki[i] << "x^" << i;
            if (i < stopien) cout << " + ";
        }
        cout << endl;
    }
    
    float operator () (float x) {
        float wynik = 0;
        for (int i = 0; i <= stopien; ++i) {
            wynik += wspolczynniki[i] * powf(x, i);
        }
        return wynik;
    }

    Wielomian operator + (const Wielomian &u) {
        int stopien_wyniku = max(this->stopien, u.stopien);

        float* wspolczynniki_wynikowe = new float[stopien_wyniku];

        int i = 0;

        while(i <= min(this->stopien, u.stopien)) {
            wspolczynniki_wynikowe[i] = this->wspolczynniki[i] + u.wspolczynniki[i];
            ++i;
        }

        while (i <= stopien_wyniku) {
            if (this->stopien > u.stopien) {
                wspolczynniki_wynikowe[i] = this->wspolczynniki[i];
            }

            else if (u.stopien > this->stopien) {
                wspolczynniki_wynikowe[i] = u.wspolczynniki[i];
            }

            ++i;
        }

        return Wielomian(stopien_wyniku, wspolczynniki_wynikowe);
    }

    Wielomian operator - (const Wielomian& u) {

        float* wspolczynniki_wynikowe = new float[u.stopien];

        for (int i = 0; i <= u.stopien;++i) {
            wspolczynniki_wynikowe[i] = -u.wspolczynniki[i];
        }

        Wielomian przeciwny = Wielomian(u.stopien, wspolczynniki_wynikowe);

        return *this + przeciwny;
    }

};

int main()
{
    int n;
    cin >> n;

    float* a = new float[n + 1];

    for (int i = 0; i < n + 1; ++i) {
        cin >> a[i];
    }

    int m;
    cin >> m;

    float* b = new float[m + 1];

    for (int i = 0; i < m + 1; ++i) {
        cin >> b[i];
    }

    float x;
    cin >> x;

    Wielomian A = Wielomian(n, a);
    Wielomian B = Wielomian(m, b);

    A.wyswietl();
    B.wyswietl();

    Wielomian Suma = A + B;
    Suma.wyswietl();

    Wielomian Roznica = A - B;
    Roznica.wyswietl();

    cout << A(x) << endl;

    return 0;
}