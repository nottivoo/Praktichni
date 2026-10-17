#pragma once
#include <string>
using namespace std;

class Robotodavets {
private:
    string nazva;
    string adresa;
    string pidrozdily;

public:
    Robotodavets();
    Robotodavets(string nazva, string adresa, string pidrozdily);

    void dodatyPidrozdil();
    void pokazatyInformatsiyu();
    string toString();
};

Robotodavets::Robotodavets() {
    nazva = "";
    adresa = "";
    pidrozdily = "";
}

Robotodavets::Robotodavets(string nazva, string adresa, string pidrozdily) {
    this->nazva = nazva;
    this->adresa = adresa;
    this->pidrozdily = pidrozdily;
}

void Robotodavets::dodatyPidrozdil() {
}

void Robotodavets::pokazatyInformatsiyu() {
}

string Robotodavets::toString() {
    return "Nazva: " + nazva + ", adresa: " + adresa +
           ", pidrozdily: " + pidrozdily;
}
