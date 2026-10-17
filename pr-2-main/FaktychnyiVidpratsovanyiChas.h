#pragma once
#include <string>
using namespace std;

class FaktychnyiVidpratsovanyiChas {
private:
    string pratsivnyk;
    string period;
    double kilkistHodyn;

public:
    FaktychnyiVidpratsovanyiChas();
    FaktychnyiVidpratsovanyiChas(string pratsivnyk, string period, double kilkistHodyn);

    void rozrahuvatyFaktychnyiChas();
    void pokazatyFaktychnyiChas();
    string toString();
};

FaktychnyiVidpratsovanyiChas::FaktychnyiVidpratsovanyiChas() {
    pratsivnyk = "";
    period = "";
    kilkistHodyn = 0;
}

FaktychnyiVidpratsovanyiChas::FaktychnyiVidpratsovanyiChas(
    string pratsivnyk, string period, double kilkistHodyn) {
    this->pratsivnyk = pratsivnyk;
    this->period = period;
    this->kilkistHodyn = kilkistHodyn;
}

void FaktychnyiVidpratsovanyiChas::rozrahuvatyFaktychnyiChas() {
}

void FaktychnyiVidpratsovanyiChas::pokazatyFaktychnyiChas() {
}

string FaktychnyiVidpratsovanyiChas::toString() {
    return "Pratsivnyk: " + pratsivnyk +
           ", period: " + period +
           ", faktychno vidpratsovano: " +
           to_string(kilkistHodyn) + " hod.";
}
