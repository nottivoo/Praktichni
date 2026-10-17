#pragma once
#include <string>
using namespace std;

class NadurochnaRobota {
private:
    string data;
    double kilkistHodyn;
    string pratsivnyk;

public:
    NadurochnaRobota();
    NadurochnaRobota(string data, double kilkistHodyn, string pratsivnyk);

    void dodatyNadurochnuRobotu();
    void pokazatyNadurochnuRobotu();
    string toString();
};

NadurochnaRobota::NadurochnaRobota() {
    data = "";
    kilkistHodyn = 0;
    pratsivnyk = "";
}

NadurochnaRobota::NadurochnaRobota(string data, double kilkistHodyn, string pratsivnyk) {
    this->data = data;
    this->kilkistHodyn = kilkistHodyn;
    this->pratsivnyk = pratsivnyk;
}

void NadurochnaRobota::dodatyNadurochnuRobotu() {
}

void NadurochnaRobota::pokazatyNadurochnuRobotu() {
}

string NadurochnaRobota::toString() {
    return "Data: " + data + ", kilkist hodyn: " +
           to_string(kilkistHodyn) + ", pratsivnyk: " + pratsivnyk;
}
