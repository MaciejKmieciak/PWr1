#include <iostream>

using namespace std;

int main()
{
    unsigned int n;

    cin >> n;

    // Zauważmy, że zero końcowe w liczbie n! powstaje z każdej pary
    // 2 * 5, która występuje w rozkładzie n! na czynniki pierwsze

    // Ponadto, ilość liczb 2 w rozkładzie n! na czynniki pierwsze
    // jest zawsze >= ilość liczb 5 w rozkładzie n! na czynniki pierwsze
    // (biorąc rozkłady na czynniki pierwsze kolejnych liczb z przedziału [1; n]
    // potęgi dwójki występują w nich częściej niż potęgi piątki
    
    // Zatem
    // ilość zer końcowych n! =
    // ilość par 2 * 5 w rozkładzie n! na czynniki pierwsze =
    // ilość liczb 5 w rozkładzie n! na czynniki pierwsze = 
    // największe k_1 naturalne takie że k_1 * 5^1 <= n +
    // największe k_2 naturalne takie że k_2 * 5^2 <= n +
    // największe k_3 naturalne takie że k_3 * 5^3 <= n + ... =
    // podłoga(n/5^1) + podłoga(n/5^2) + podłoga(n/5^3) + ...

    // n! = ... * 5     * 6 * ... * 9 * 10     * ... * 15    * ... * 20    * ... * 25    * ... * 30    * ... * 50      * ... * 125     * ...
    // n! = ... * [5*1] * 6 * ... * 9 * [5*2]  * ... * [5*3] * ... * [5*4] * ... * [5*5] * ... * [5*6] * ... * [5*5*2] * ... * [5*5*5] * ...



    unsigned int ile_zer = 0;

    for (unsigned int i = 5; n / i >= 1; i *= 5) {
        ile_zer += n / i;
    }

    cout << ile_zer;

    return 0;
}