#include <iostream>
#include "Pratsivnyk.h"
#include "Robotodavets.h"
#include "RobochyiDen.h"
#include "RobochyiChas.h"
#include "Pererva.h"
#include "TabelOblikuRobochogoChasu.h"
#include "Vidsutnist.h"
#include "Vidpustka.h"
#include "Likarnyanyi.h"
#include "NadurochnaRobota.h"
#include "HrafikRoboty.h"
#include "FaktychnyiVidpratsovanyiChas.h"

using namespace std;

int main() {
    Pratsivnyk pratsivnyk(
        "Антоненко Юрій",
        "Програміст",
        "ІТ",
        101
    );

    Robotodavets robotodavets(
        "Навчальне підприємство",
        "м. Одеса",
        "ІТ, адміністрація"
    );

    RobochyiDen robochyiDen(
        "06.10.2026",
        "09:00",
        "18:00",
        8.0
    );

    RobochyiChas robochyiChas(
        "06.10.2026",
        "09:00",
        "18:00",
        8.0
    );

    Pererva pererva(
        "13:00",
        "14:00",
        1.0
    );

    TabelOblikuRobochogoChasu tabel(
        "Жовтень 2026",
        "Антоненко Юрій",
        160.0,
        0
    );

    Vidsutnist vidsutnist(
        "10.10.2026",
        "Особисті обставини",
        8.0
    );

    Vidpustka vidpustka(
        "Щорічна",
        "20.10.2026",
        "24.10.2026"
    );

    Likarnyanyi likarnyanyi(
        "02.11.2026",
        "05.11.2026",
        "Тимчасова непрацездатність"
    );

    NadurochnaRobota nadurochna(
        "06.10.2026",
        2.0,
        "Антоненко Юрій"
    );

    HrafikRoboty hrafik(
        "Пн-Пт",
        "09:00",
        "18:00",
        "13:00-14:00"
    );

    FaktychnyiVidpratsovanyiChas faktychnyiChas(
        "Антоненко Юрій",
        "Жовтень 2026",
        160.0
    );

    cout << "=== OBLIK ROBOCHOHO CHASU ===" << endl << endl;

    cout << "1. Pratsivnyk:" << endl;
    cout << pratsivnyk.toString() << endl << endl;

    cout << "2. Robotodavets / pidpryiemstvo:" << endl;
    cout << robotodavets.toString() << endl << endl;

    cout << "3. Robochyi den:" << endl;
    cout << robochyiDen.toString() << endl << endl;

    cout << "4. Robochyi chas:" << endl;
    cout << robochyiChas.toString() << endl << endl;

    cout << "5. Pererva:" << endl;
    cout << pererva.toString() << endl << endl;

    cout << "6. Tabel obliku robochoho chasu:" << endl;
    cout << tabel.toString() << endl << endl;

    cout << "7. Vidsutnist:" << endl;
    cout << vidsutnist.toString() << endl << endl;

    cout << "8. Vidpustka:" << endl;
    cout << vidpustka.toString() << endl << endl;

    cout << "9. Likarnyanyi:" << endl;
    cout << likarnyanyi.toString() << endl << endl;

    cout << "10. Nadurochna robota:" << endl;
    cout << nadurochna.toString() << endl << endl;

    cout << "11. Hrafik roboty:" << endl;
    cout << hrafik.toString() << endl << endl;

    cout << "12. Faktychno vidpratsovanyi chas:" << endl;
    cout << faktychnyiChas.toString() << endl;

    return 0;
}
