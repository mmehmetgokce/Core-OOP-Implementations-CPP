#include "Oda.h"

Oda::Oda(std::string tip) : tip(tip) {}

void Oda::cihazEkle(Cihaz cihaz) {
    cihazlar.push_back(cihaz); // vektore yeni eleman ekler
}

std::string Oda::bilgi() const {
    return "Oda tipi: " + tip; // odanin tipini dondurur
}

Cihaz Oda::getCihaz(int index) const { // belirtilen cihazi dondurur. 
    return cihazlar.at(index); 
}