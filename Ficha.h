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
	std::string nombreJugador;

public:

	Ficha(TipoFicha tipoFicha,std::string nombre);

	TipoFicha getTipoFicha();

	std::string getSimbolo();

	Coordenada* getCoordenada();

	void setCoordenada(Coordenada* nuevaCoordenada);

	std::string getNombreJugador();

};



#endif /* FICHA_H_ */
