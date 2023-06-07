/*
 * Carta.h
 *
 *  Created on: 22 may 2023
 *      Author: David
 */

#ifndef CARTA_H_
#define CARTA_H_
#include<string>

enum TipoCarta {CartaAtaqueQuimico, cartaDeBarco, cartaDeAvionRadar};

class Carta{

private:

	TipoCarta tipos;

public:

	Carta(TipoCarta tipo);

	TipoCarta getTipoCarta();

	void setTipoCarta(TipoCarta nuevoTipo);

};


#endif /* CARTA_H_ */
