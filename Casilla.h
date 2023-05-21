/*
 * Casilla.h
 *
 *  Created on: 20 may 2023
 *      Author: David
 */

#ifndef CASILLA_H_
#define CASILLA_H_
#include"Coordenada.h"


class Casilla{

private:

	Coordenada* coordenada;
	char simbolo;

public:

	Casilla(int posicionX,int posicionY,int posicionZ);

	Coordenada* getCoordenada();

	char getSimbolo();

	void setSimbolo(char nuevoSimbolo);

};



#endif /* CASILLA_H_ */
