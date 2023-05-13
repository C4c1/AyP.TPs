//
// Created by Usuario on 12/05/2023.
//

#ifndef TP2_BATALLADIGITAL_H
#define TP2_BATALLADIGITAL_H


// N jugadores
// M soldados/armamento (maximo, X.y (es decir,
// cantidad que sea igual a una cara completa del cubo tablero)
// TABLERO X.Y.Z (CUBO)

// En cada turno se saca una carta del mazo
// 6 tipos de cartas, puede determinarse un maximo, en cada turno se saca una carta y se puede usar como no
// se puede mover un soldado/armamento
// si el soldado choca con otro se mueren ambos
//del nivel 0 al 5 es tierra o agua, a partir de 5 es aire.

// los jugadores son todos contra todos,


#include <iostream>
#include "Jugador.h"

using namespace std;
const int MAX_JUGADORES = 4;

class BatallaDigital {

private:
    Jugador *jugadores;
    int numJugadores;

    void inicializarJugadores(int soldados, int minas);

public:

    BatallaDigital();
    BatallaDigital(int jugadores, int soldados, int minas);
    void DarInformacion();


    ~BatallaDigital();
};


#endif //TP2_BATALLADIGITAL_H
