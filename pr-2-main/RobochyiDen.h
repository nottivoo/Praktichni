#pragma once
#include <string>
using namespace std;

class RobochyiDen {
private:
    string data;
    string chasPochatku;
    string chasZavershennya;
    double tryvalist;

public:
    RobochyiDen();
    RobochyiDen(string data, string chasPochatku, string chasZavershennya, double tryvalist);

    void rozrahuvatyTryvalist();
    void pokazatyDen();
    string toString();
};

RobochyiDen::RobochyiDen() {
    data = "";
    chasPochatku = "";
    chasZavershennya = "";
    tryvalist = 0;
}

RobochyiDen::RobochyiDen(string data, string chasPochatku, string chasZavershennya, double tryvalist) {
    this->data = data;
    this->chasPochatku = chasPochatku;
    this->chasZavershennya = chasZavershennya;
    this->tryvalist = tryvalist;
}

void RobochyiDen::rozrahuvatyTryvalist() {
}

void RobochyiDen::pokazatyDen() {
}

string RobochyiDen::toString() {
    return "Data: " + data + ", pochatok: " + chasPochatku +
           ", zavershennya: " + chasZavershennya +
           ", tryvalist: " + to_string(tryvalist) + " hod.";
}
