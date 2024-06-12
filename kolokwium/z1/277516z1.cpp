#include <iostream>

using namespace std;

bool is_prime(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 3; i + 2 <= n; i+=2) {
        if (is_prime(i) && is_prime(i + 2)) {
            cout << "(" << i << ", " << i + 2 << ")" << endl;
            i += 2; // Czyli razem +4
        }
    }

    return 0;
}