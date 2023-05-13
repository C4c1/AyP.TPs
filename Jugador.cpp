//
// Created by Usuario on 13/05/2023.
//

#include "Jugador.h"


Jugador::Jugador() {
    this->cantMinas = 0;
    this->cantSoldados = 0;
    this->cantCartas = 6;
}

Jugador::Jugador(int numSoldados, int numMinas) {
    this->cantMinas = numMinas;
    this->cantSoldados = numSoldados;
    this->cantCartas = 6;
}

void::Jugador::inicializarSoldados(){
}

Jugador::~Jugador() {
}
