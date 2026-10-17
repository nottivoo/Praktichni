#pragma once
#include <string>
using namespace std;

class Likarnyanyi {
private:
    string dataPochatku;
    string dataZavershennya;
    string prychyna;

public:
    Likarnyanyi();
    Likarnyanyi(string dataPochatku, string dataZavershennya, string prychyna);

    void oformytyLikarnyanyi();
    void pokazatyLikarnyanyi();
    string toString();
};

Likarnyanyi::Likarnyanyi() {
    dataPochatku = "";
    dataZavershennya = "";
    prychyna = "";
}

Likarnyanyi::Likarnyanyi(string dataPochatku, string dataZavershennya, string prychyna) {
    this->dataPochatku = dataPochatku;
    this->dataZavershennya = dataZavershennya;
    this->prychyna = prychyna;
}

void Likarnyanyi::oformytyLikarnyanyi() {
}

void Likarnyanyi::pokazatyLikarnyanyi() {
}

string Likarnyanyi::toString() {
    return "Pochatok: " + dataPochatku +
           ", zavershennya: " + dataZavershennya +
           ", prychyna: " + prychyna;
}
