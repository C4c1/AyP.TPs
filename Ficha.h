/*
 * Ficha.h
 *
 *  Created on: 23 may 2023
 *      Author: David
 */

#ifndef FICHA_H_
#define FICHA_H_
#include<string>
#include"Coordenada.h"
enum TipoFicha{soldado,mina,barco,avionRadar};
#define NULL 0;

class Ficha{

private:

	TipoFicha tipoFicha;
	std::string simbolo;
	Coordenada* coordenadas;

public:

	Ficha(TipoFicha tipoFicha);

	TipoFicha getTipoFicha();

	std::string getSimbolo();

	Coordenada* getCoordenada();

	void setCoordenada(Coordenada* nuevaCoordenada);

};



#endif /* FICHA_H_ */
