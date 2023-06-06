/*
 * Casilla.h
 *
 *  Created on: 20 may 2023
 *      Author: David
 */

#ifndef CASILLERO_H_
#define CASILLERO_H_
#include<string>
#include"Coordenada.h"
#include"Ficha.h"
#define NULL 0

enum TipoTerreno {tierra,agua,aire};
enum Estado {libre,ocupado,bloqueado};

class Casillero{

private:

	Coordenada* coordenada;
	std::string simbolo;
	TipoTerreno terreno;
	Ficha* ficha;
	Estado estado;
	int numeroDeturnosBloqueado;

public:

	Casillero(int posicionX,int posicionY,int posicionZ);

	Coordenada* getCoordenada();

	std::string getSimbolo();

	void setSimbolo(std::string nuevoSimbolo);

	void setTerrono(TipoTerreno nuevoTerreno);

	Estado getEstado();

	void setEstado(Estado estado);

	TipoTerreno getTipoTerreno();

	void setFicha(Ficha* ficha);

	Ficha* getFicha();

};



#endif /* CASILLERO_H_ */
