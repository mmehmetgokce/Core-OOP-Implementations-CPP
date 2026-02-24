#ifndef CIHAZ_H
#define CIHAZ_H

#include <string>

class Cihaz {
private:
    std::string tip; // cihazin turu
    bool durum; // cihaz acik mi kapali mi

public:
    Cihaz(std::string tip, bool durum); // cihazin hem tipini hem de durumunu belirtir
    void acKapat(); // cihazin durumunu tersine cevirir, aciksa kapatir kapaliysa acar
    std::string bilgi(std::string veri) const; // parametreye gore ya cihazin durumunu ya da tipini dondurur
};

#endif