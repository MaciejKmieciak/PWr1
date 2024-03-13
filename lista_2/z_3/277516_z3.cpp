#include <iostream>

using namespace std;

int main(int argc, char* argv[]) 
{
    int size_a = 0, size_b = 0;

    while (argv[1][size_a] != NULL) ++size_a;
    while (argv[2][size_b] != NULL) ++size_b;

    if (size_a != size_b) {
        cout << "NIE";
        return 0;
    }

    for (int i = 0; i < size_a; ++i) {
        char my_char = argv[1][i];
        bool flag = false;
        for (int j = 0; j < size_a; ++j) {
            if (argv[2][j] == my_char) flag = true;
        }
        if (!flag) {
            cout << "NIE";
            return 0;
        }
    }

    cout << "TAK";
    return 0;
}