/*
 * BatallaDigital.h
 *
 *  Created on: 21 may 2023
 *      Author: David
 */

#ifndef BATALLADIGITAL_H_
#define BATALLADIGITAL_H_
#include "Tablero.h"
#include<iostream>

class BatallaDigital{

private:

	Tablero* tablero;

public:

	BatallaDigital(int limiteX,int limiteY,int limiteZ);

	void mostrarTablero();

};



#endif /* BATALLADIGITAL_H_ */
