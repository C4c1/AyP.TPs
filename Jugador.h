/*
 * Jugador.h
 *
 *  Created on: 22 may 2023
 *      Author: David
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_

class Jugador{

private:

	Lista<Carta*>* Cartas;
	int solodadoDisponibles;


public:

	Jugador(int solodadoDisponibles);

	Lista<Carta*>* getCartas();

};




#endif /* JUGADOR_H_ */
