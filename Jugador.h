//
// Created by Usuario on 13/05/2023.
//

#ifndef TP2_JUGADOR_H
#define TP2_JUGADOR_H


#include "Casillero.h"
#include "Soldado.h"

class Jugador {

private:

public:
    int cantSoldados;
    int cantMinas;
    int cantCartas;

    Soldado *soldados;
    //Armamento *armamento;
    //Carta cartas

Jugador();
Jugador(int numSoldados, int numMinas);

void inicializarSoldados();

~Jugador();

};


#endif //TP2_JUGADOR_H
