#pragma once
#include <string>
using namespace std;

class HrafikRoboty {
private:
    string dniRoboty;
    string chasPochatku;
    string chasZavershennya;
    string perervy;

public:
    HrafikRoboty();
    HrafikRoboty(string dniRoboty, string chasPochatku, string chasZavershennya, string perervy);

    void vstanovytyHrafik();
    void pokazatyHrafik();
    string toString();
};

HrafikRoboty::HrafikRoboty() {
    dniRoboty = "";
    chasPochatku = "";
    chasZavershennya = "";
    perervy = "";
}

HrafikRoboty::HrafikRoboty(string dniRoboty, string chasPochatku, string chasZavershennya, string perervy) {
    this->dniRoboty = dniRoboty;
    this->chasPochatku = chasPochatku;
    this->chasZavershennya = chasZavershennya;
    this->perervy = perervy;
}

void HrafikRoboty::vstanovytyHrafik() {
}

void HrafikRoboty::pokazatyHrafik() {
}

string HrafikRoboty::toString() {
    return "Dni roboty: " + dniRoboty +
           ", pochatok: " + chasPochatku +
           ", zavershennya: " + chasZavershennya +
           ", perervy: " + perervy;
}
