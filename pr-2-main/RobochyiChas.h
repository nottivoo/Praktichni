#pragma once
#include <string>
using namespace std;

class RobochyiChas {
private:
    string data;
    string chasPochatku;
    string chasZavershennya;
    double tryvalist;

public:
    RobochyiChas();
    RobochyiChas(string data, string chasPochatku, string chasZavershennya, double tryvalist);

    void rozrahuvatyChas();
    void pokazatyRobochyiChas();
    string toString();
};

RobochyiChas::RobochyiChas() {
    data = "";
    chasPochatku = "";
    chasZavershennya = "";
    tryvalist = 0;
}

RobochyiChas::RobochyiChas(string data, string chasPochatku, string chasZavershennya, double tryvalist) {
    this->data = data;
    this->chasPochatku = chasPochatku;
    this->chasZavershennya = chasZavershennya;
    this->tryvalist = tryvalist;
}

void RobochyiChas::rozrahuvatyChas() {
}

void RobochyiChas::pokazatyRobochyiChas() {
}

string RobochyiChas::toString() {
    return "Data: " + data + ", pochatok: " + chasPochatku +
           ", zavershennya: " + chasZavershennya +
           ", tryvalist: " + to_string(tryvalist) + " hod.";
}
