#include <iostream>

using namespace std;

unsigned int f(unsigned int n) {
    if (n % 2 == 0) return n / 2;
    else return 3 * n + 1;
}

int main()
{
    int n, licznik = 1;
    cin >> n;

    cout << n;

    while (n != 1) {
        n = f(n);
        cout << " " << n;
        ++licznik;
    }

    cout << ", " << licznik;

    return 0;
}