/*
 * Casilla.h
 *
 *  Created on: 20 may 2023
 *      Author: David
 */

#ifndef CASILLERO_H_
#define CASILLERO_H_
#include"Coordenada.h"
#include"Ficha.h"
#define NULL 0
typedef enum TipoTerreno {tierra, agua, aire};

class Casillero{

private:

	Coordenada* coordenada;
	char simbolo;
	TipoTerreno terreno;
	Ficha* ficha;

public:

	Casillero(int posicionX,int posicionY,int posicionZ);

	Coordenada* getCoordenada();

	char getSimbolo();

	void setSimbolo(char nuevoSimbolo);

	void setTerrono(TipoTerreno nuevoTerreno);

};



#endif /* CASILLERO_H_ */
