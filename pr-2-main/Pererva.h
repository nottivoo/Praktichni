#pragma once
#include <string>
using namespace std;

class Pererva {
private:
    string chasPochatku;
    string chasZavershennya;
    double tryvalist;

public:
    Pererva();
    Pererva(string chasPochatku, string chasZavershennya, double tryvalist);

    void rozrahuvatyTryvalist();
    void pokazatyPerervu();
    string toString();
};

Pererva::Pererva() {
    chasPochatku = "";
    chasZavershennya = "";
    tryvalist = 0;
}

Pererva::Pererva(string chasPochatku, string chasZavershennya, double tryvalist) {
    this->chasPochatku = chasPochatku;
    this->chasZavershennya = chasZavershennya;
    this->tryvalist = tryvalist;
}

void Pererva::rozrahuvatyTryvalist() {
}

void Pererva::pokazatyPerervu() {
}

string Pererva::toString() {
    return "Pochatok: " + chasPochatku +
           ", zavershennya: " + chasZavershennya +
           ", tryvalist: " + to_string(tryvalist) + " hod.";
}
