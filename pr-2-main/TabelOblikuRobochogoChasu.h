#pragma once
#include <string>
using namespace std;

class TabelOblikuRobochogoChasu {
private:
    string misyats;
    string pratsivnyk;
    double vidpratsovaniHodyny;
    int neiavky;

public:
    TabelOblikuRobochogoChasu();
    TabelOblikuRobochogoChasu(string misyats, string pratsivnyk, double vidpratsovaniHodyny, int neiavky);

    void dodatyZapys();
    void pokazatyTabel();
    string toString();
};

TabelOblikuRobochogoChasu::TabelOblikuRobochogoChasu() {
    misyats = "";
    pratsivnyk = "";
    vidpratsovaniHodyny = 0;
    neiavky = 0;
}

TabelOblikuRobochogoChasu::TabelOblikuRobochogoChasu(
    string misyats, string pratsivnyk, double vidpratsovaniHodyny, int neiavky) {
    this->misyats = misyats;
    this->pratsivnyk = pratsivnyk;
    this->vidpratsovaniHodyny = vidpratsovaniHodyny;
    this->neiavky = neiavky;
}

void TabelOblikuRobochogoChasu::dodatyZapys() {
}

void TabelOblikuRobochogoChasu::pokazatyTabel() {
}

string TabelOblikuRobochogoChasu::toString() {
    return "Misyats: " + misyats + ", pratsivnyk: " + pratsivnyk +
           ", vidpratsovani hodyny: " + to_string(vidpratsovaniHodyny) +
           ", neiavky: " + to_string(neiavky);
}
