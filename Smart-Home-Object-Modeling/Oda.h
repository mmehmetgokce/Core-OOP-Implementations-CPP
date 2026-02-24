#ifndef ODA_H
#define ODA_H

#include <string>
#include <vector>
#include "Cihaz.h"

class Oda {
private:
    std::string tip; // odanin turunu tutar
    std::vector<Cihaz> cihazlar; // odadaki cihazlarin listesini tutan bir vektor

public:
    Oda(std::string tip); // odanin tipini baslatir
    void cihazEkle(Cihaz cihaz); // bir cihazi odanin cihazlar listesine ekler
    std::string bilgi() const; // odanin tipini dondurur
    Cihaz getCihaz(int index) const; // belirtilen cihazi dondurur
};

#endif