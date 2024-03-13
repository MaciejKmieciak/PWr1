#include <iostream>

using namespace std;

int* arr;

int fib_rec(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 1;

    if (arr[n - 2] == 0) arr[n - 2] = fib_rec(n - 2);
    if (arr[n - 1] == 0) arr[n - 1] = fib_rec(n - 1);

    return arr[n - 2] + arr[n - 1];
}

int main()
{
    int n;

    cin >> n;

    arr = new int[n];

    for (int i = 0; i < n; ++i) {
        arr[i] = 0;
    }

    cout << fib_rec(n) << endl;

    return 0;
}