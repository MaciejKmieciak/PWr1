#include <iostream>

using namespace std;

// Algorytm Euklidesa (iteracyjnie)
unsigned int NWD(unsigned int a, unsigned int b) {
    unsigned int q, r;

    while (b > 0) {
        q = a / b;
        r = a % b;

        a = b;
        b = r;
    }

    return a;
}

unsigned int fi(unsigned int n) {
    unsigned int moc = 0;

    for (int k = 1; k <= n; ++k) {
        if (NWD(k, n) == 1) ++moc;
    }

    return moc;
}

unsigned int F(unsigned int n) {
    unsigned int suma = 0;

    for (unsigned int d = 1; d <= n; ++d) {
        if (n % d == 0) suma += fi(d);
    }

    return suma;
}

int main()
{
    unsigned int n;

    cin >> n;

    cout << F(n);

    return 0;
}