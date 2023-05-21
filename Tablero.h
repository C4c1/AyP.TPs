/*
 * Tablero.h
 *
 *  Created on: 20 may 2023
 *      Author: David
 */

#ifndef TABLERO_H_
#define TABLERO_H_

#include"Lista.h"
#include"Casilla.h"

class Tablero{

private:

	Lista<Lista<Lista<Casilla*>*>*>* tablero;
	int limiteX;
	int limiteY;
	int limiteZ;

public:

	Tablero(int limiteX,int limiteY,int limiteZ);

	Lista<Lista<Lista<Casilla*>*>*>* getTablero();

	void crearTablero();

};


#endif /* TABLERO_H_ */
