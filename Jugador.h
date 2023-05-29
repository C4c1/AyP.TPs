/*
 * Jugador.h
 *
 *  Created on: 22 may 2023
 *      Author: David
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_
#include"Carta.h"
#include"Lista.h"
class Jugador{

private:

	Lista<Carta*>* cartas;
	int solodadoDisponibles;
	char simbolo;

public:

	Jugador(int solodadoDisponibles, char simbolo);

	Lista<Carta*>* getCartas();

	char getSimbolo();

	int getSoldadosDisponibles();

};




#endif /* JUGADOR_H_ */
