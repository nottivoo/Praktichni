#pragma once
#include <string>
using namespace std;

class Pratsivnyk {
private:
    string pib;
    string posada;
    string pidrozdil;
    int tabelnyiNomer;

public:
    Pratsivnyk();
    Pratsivnyk(string pib, string posada, string pidrozdil, int tabelnyiNomer);

    void dodatyPratsivnyka();
    void pokazatyPratsivnyka();
    string toString();
};

Pratsivnyk::Pratsivnyk() {
    pib = "";
    posada = "";
    pidrozdil = "";
    tabelnyiNomer = 0;
}

Pratsivnyk::Pratsivnyk(string pib, string posada, string pidrozdil, int tabelnyiNomer) {
    this->pib = pib;
    this->posada = posada;
    this->pidrozdil = pidrozdil;
    this->tabelnyiNomer = tabelnyiNomer;
}

void Pratsivnyk::dodatyPratsivnyka() {
}

void Pratsivnyk::pokazatyPratsivnyka() {
}

string Pratsivnyk::toString() {
    return "PIB: " + pib + ", posada: " + posada +
           ", pidrozdil: " + pidrozdil +
           ", tabelnyi nomer: " + to_string(tabelnyiNomer);
}
