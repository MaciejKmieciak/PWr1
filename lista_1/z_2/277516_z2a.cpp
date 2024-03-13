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

int main()
{
    unsigned int n, moc = 0;

    cin >> n;

    for (int k = 1; k <= n; ++k) {
        if (NWD(k, n) == 1) ++moc;
    }

    cout << moc;
 
    return 0;
}

