#pragma once
#include <string>
using namespace std;

class Vidsutnist {
private:
    string data;
    string prychyna;
    double tryvalist;

public:
    Vidsutnist();
    Vidsutnist(string data, string prychyna, double tryvalist);

    void zareiestruvatyVidsutnist();
    void pokazatyVidsutnist();
    string toString();
};

Vidsutnist::Vidsutnist() {
    data = "";
    prychyna = "";
    tryvalist = 0;
}

Vidsutnist::Vidsutnist(string data, string prychyna, double tryvalist) {
    this->data = data;
    this->prychyna = prychyna;
    this->tryvalist = tryvalist;
}

void Vidsutnist::zareiestruvatyVidsutnist() {
}

void Vidsutnist::pokazatyVidsutnist() {
}

string Vidsutnist::toString() {
    return "Data: " + data + ", prychyna: " + prychyna +
           ", tryvalist: " + to_string(tryvalist) + " hod.";
}
