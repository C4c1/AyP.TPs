
#include "Soldado.h"

Soldado::Soldado() {
    this->estaVivo = true;
}

void Soldado::matarSoldado() {
    this->estaVivo = false;
}