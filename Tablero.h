/*
 * Tablero.h
 *
 *  Created on: 20 may 2023
 *      Author: David
 */

#ifndef TABLERO_H_
#define TABLERO_H_

#include "Casillero.h"
#include"Lista.h"

class Tablero{

private:

	Lista<Lista<Lista<Casillero*>*>*>* tablero;
	int limiteX;
	int limiteY;
	int limiteZ;

public:

	Tablero(int limiteX,int limiteY,int limiteZ);

	Lista<Lista<Lista<Casillero*>*>*>* getTablero();

	void crearTablero();

	int getLimiteX();

	int getLimiteY();

	int getLimiteZ();

};


#endif /* TABLERO_H_ */
