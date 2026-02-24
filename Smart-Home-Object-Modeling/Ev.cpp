#include "Ev.h"

Ev::Ev(Oda oda) { // bir ev yaratildiginda ilk odayi baslatir ve odalar vektorune ekler
    odalar.push_back(oda); 
}

void Ev::odaEkle(Oda oda) { // yeni bir oda vektore eklenir
    odalar.push_back(oda); 
}

int Ev::bilgi() const { // evde kac oda oldugunu dondurur
    return odalar.size();
}

Oda Ev::getOda(int index) const { // belirtilen odayi dondurur
    return odalar.at(index);
}

void Ev::odaSil() {
    if (!odalar.empty()) {
        odalar.pop_back(); // son odayi siler
    }
}