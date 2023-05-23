/*
 * Ficha.h
 *
 *  Created on: 23 may 2023
 *      Author: David
 */

#ifndef FICHA_H_
#define FICHA_H_
typedef enum TipoFicha{soldado,mina,barco,avionRadar};


class Ficha{

private:

	TipoFicha tipoFicha;

public:

	Ficha(TipoFicha tipoFicha);

	TipoFicha getTipoFicha();

	void setTipoFicha();

};



#endif /* FICHA_H_ */
