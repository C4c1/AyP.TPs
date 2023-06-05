/*
 * Ficha.h
 *
 *  Created on: 23 may 2023
 *      Author: David
 */

#ifndef FICHA_H_
#define FICHA_H_
#include"Coordenada.h"
enum TipoFicha{soldado,mina,barco,avionRadar};
#define NULL 0;

class Ficha{

private:

	TipoFicha tipoFicha;
	char simbolo;
	Coordenada* coordenadas;

public:

	Ficha(TipoFicha tipoFicha);

	TipoFicha getTipoFicha();

	char getSimbolo();

};



#endif /* FICHA_H_ */
