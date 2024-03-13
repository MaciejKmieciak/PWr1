#include <iostream>

using namespace std;

int main()
{
    int arr[1001];

    for (int i = 0; i <= 100; ++i) {
        cin >> arr[i];
    }

    int* term = &arr[1000];
    int* i_ptr = &arr[0];

    for (int i = 0; i <= 999; ++i) {
        if (*i_ptr == *term) {
            cout << "TAK";
            return 0;
        }
        ++i_ptr;
    }

    cout << "NIE";
    return 0;
}