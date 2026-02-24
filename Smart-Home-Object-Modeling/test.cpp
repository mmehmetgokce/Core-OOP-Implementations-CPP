#include <iostream>
#include <string>

using namespace std;

#include "Ev.h"
#include "Oda.h"
#include "Cihaz.h"

int main() {

    Ev ev = Ev(Oda("Yatak"));
    cout << "Oda sayisi: " << ev.bilgi() << endl;
    cout << "Oda bilgisi: " << ev.getOda(0).bilgi() << endl;

    ev.odaEkle(Oda("Mutfak"));
    cout << "Oda sayisi: " << ev.bilgi() << endl;
    cout << "Oda bilgisi: " << ev.getOda(1).bilgi() << endl;

    ev.odaSil();
    cout << endl << "Oda Silindi. Oda sayisi: " << ev.bilgi() << endl << endl;

    ev.odaEkle(Oda("Banyo"));
    cout << "Oda sayisi: " << ev.bilgi() << endl;
    cout << "Oda bilgisi: " << ev.getOda(1).bilgi() << endl;

    ev.odaEkle(Oda("Oturma"));
    Oda oda = ev.getOda(2);
    oda.cihazEkle(Cihaz("TV", true));
    cout << "Oda sayisi: " << ev.bilgi() << endl;
    cout << "Oda bilgisi: " << ev.getOda(2).bilgi() << endl;
    cout << "Cihaz bilgisi " << oda.getCihaz(0).bilgi("tip") << " " << oda.getCihaz(0).bilgi("durum") << endl;
    oda.cihazEkle(Cihaz("isitici", true));
    cout << "Cihaz bilgisi " << oda.getCihaz(1).bilgi("tip") << " " << oda.getCihaz(0).bilgi("durum") << endl;
    Cihaz cihaz = oda.getCihaz(1);
    cihaz.acKapat();
    cout << "Cihaz bilgisi " << cihaz.bilgi("tip") << " " << cihaz.bilgi("durum") << endl;


    cout << endl << endl;
    return 0;
}