#include "Cihaz.h"

Cihaz::Cihaz(std::string tip, bool durum) : tip(tip), durum(durum) {} // cihazin tipini ve durumunu ilk degerleri ile baslatir

void Cihaz::acKapat() {
    durum = !durum; // durumu tersine cevirir.
}

std::string Cihaz::bilgi(std::string veri) const {
    if (veri == "tip") {
        return tip; // tipini dondurur
    }
    else if (veri == "durum") {
        return durum ? "Acik" : "Kapali"; // durumunu dondurur, acik/kapali
    }
    return "Gecersiz veri";
}