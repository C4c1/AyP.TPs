/*
 * Carta.h
 *
 *  Created on: 22 may 2023
 *      Author: David
 */

#ifndef CARTA_H_
#define CARTA_H_
#include<string>

typedef enum Tipo {CartaAtaqueQuimico, cartaDeBarco, cartaDeAvionRadar};

class Carta{

private:

	Tipo tipos;

public:

	Carta(Tipo tipo);

	Tipo getTipoCarta();

	void setTipoCarta(Tipo nuevoTipo);

};


#endif /* CARTA_H_ */
