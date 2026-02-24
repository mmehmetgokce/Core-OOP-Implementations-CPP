#ifndef EV_H
#define EV_H

#include <vector>
#include "Oda.h"

class Ev {
private:
    std::vector<Oda> odalar; // evdeki odalarin listesini tutar

public:
    Ev(Oda oda); // ilk oda olusur
    void odaEkle(Oda oda); // yeni bir odayi odalar vektorune ekler
    int bilgi() const; // evdeki oda sayisini dondurur
    Oda getOda(int index) const; // belirtilen odayi dondurur
    void odaSil(); // son odayi siler
};

#endif