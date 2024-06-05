#include <iostream>

using namespace std;

class Zwierz {
protected:
    string imie;
    string rasa;
public:
    virtual string sound() = 0;
};

class Kot : public Zwierz {
public:
    virtual string sound() {
        return "Meow!";
    }

    friend ostream& operator << (ostream& output, Kot &k) {
        output << k.imie << ", " << k.rasa << ", " << k.sound();
        return output;
    }

    friend istream& operator >> (istream& input, Kot& k) {
        input >> k.imie >> k.rasa;
        return input;
    }
};

class Pies : public Zwierz {
public:
    virtual string sound() {
        return "Whoof!";
    }

    friend ostream& operator << (ostream& output, Pies& p) {
        output << p.imie << ", " << p.rasa << ", " << p.sound();
        return output;
    }

    friend istream& operator >> (istream& input, Pies& p) {
        input >> p.imie >> p.rasa;
        return input;
    }
};

int main()
{
    Kot k1;
    Pies p1;

    cin >> k1;
    cin >> p1;

    cout << k1 << endl;
    cout << p1 << endl;

    return 0;
}