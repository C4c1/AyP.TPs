/*
 * Casilla.h
 *
 *  Created on: 20 may 2023
 *      Author: David
 */

#ifndef CASILLERO_H_
#define CASILLERO_H_
#include"Coordenada.h"


class Casillero{

private:

	Coordenada* coordenada;
	char simbolo;

public:

	Casillero(int posicionX,int posicionY,int posicionZ);

	Coordenada* getCoordenada();

	char getSimbolo();

	void setSimbolo(char nuevoSimbolo);

};



#endif /* CASILLERO_H_ */
