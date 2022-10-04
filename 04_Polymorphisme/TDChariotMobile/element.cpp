#include "element.h"

Element::Element(const int _vitesse):
    numero(0),
    vitesse(_vitesse) {

}

Element::~Element() {

}

int Element::getNumero() const {
     return numero;
}

void Element::setNumero(const int _numero) {

}
