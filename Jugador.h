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
#include"Ficha.h"
class Jugador{

private:

	Lista<Carta*>* cartas;
	int numeroSoldadosDisponibles;
	std::string simbolo;
	Lista<Ficha*>* FichasDisponibles;

public:

	Jugador(int solodadoDisponibles, std::string simbolo);

	Lista<Carta*>* getCartas();

	std::string getSimbolo();

	int getSoldadosDisponibles();

	Lista<Ficha*>* getFichasDisponibles();


};




#endif /* JUGADOR_H_ */
