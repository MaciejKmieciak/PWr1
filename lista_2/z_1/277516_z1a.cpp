#include <iostream>

using namespace std;

int fib_iter(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    int a = 0, b = 1, bufor;
    for (int i = 2; i <= n; ++i) {
        bufor = b;
        b = a + b;
        a = bufor;
    }
    return b;
    
}

int main()
{
    int n;
    
    cin >> n;

    cout << fib_iter(n);

    return 0;
}