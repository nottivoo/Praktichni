#pragma once
#include <string>
using namespace std;

class Vidpustka {
private:
    string vyd;
    string dataPochatku;
    string dataZavershennya;

public:
    Vidpustka();
    Vidpustka(string vyd, string dataPochatku, string dataZavershennya);

    void oformytyVidpustku();
    void pokazatyVidpustku();
    string toString();
};

Vidpustka::Vidpustka() {
    vyd = "";
    dataPochatku = "";
    dataZavershennya = "";
}

Vidpustka::Vidpustka(string vyd, string dataPochatku, string dataZavershennya) {
    this->vyd = vyd;
    this->dataPochatku = dataPochatku;
    this->dataZavershennya = dataZavershennya;
}

void Vidpustka::oformytyVidpustku() {
}

void Vidpustka::pokazatyVidpustku() {
}

string Vidpustka::toString() {
    return "Vyd: " + vyd + ", pochatok: " + dataPochatku +
           ", zavershennya: " + dataZavershennya;
}
