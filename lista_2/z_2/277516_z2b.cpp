#include <iostream>

using namespace std;

int arr[1001];

bool is_in_arr(int* term, int range_start, int range_end) {

    // cout << "New function call, got " << *term << " " << range_start << " " << range_end << endl;

    if (range_end - range_start <= 0) {
        if (arr[range_end] == *term) return true;
        return false;
    }

    int middle_arg = range_start + ((range_end - range_start) / 2);

    int middle_value = arr[middle_arg];

    // cout << "Middle arg: " << middle_arg << ", middle value: " << middle_value << endl << endl;

    if (middle_value == *term) return true;
    if (middle_value > *term) return is_in_arr(term, range_start, middle_arg - 1);
    if (middle_value < *term) return is_in_arr(term, middle_arg + 1, range_end);

}

int main()
{

    for (int i = 0; i <= 1000; ++i) {
        cin >> arr[i];
    }

    int* term = &arr[1000];

    if (is_in_arr(term, 0, 999)) cout << "TAK";
    else cout << "NIE";

    return 0;
}