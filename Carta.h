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

    /* Pre: Requiere ingresar el tipo de dato entre los disponibles que representara el ataque que realizara la carta
     * Pos: Crea una instancia de carta con su atributo inicializado
     */
	Carta(TipoCarta tipo);

    /* Pre: -- No requiere condiciones especificas
     * Pos: Devuelve el tipo de carta que identifica a la instancia
     */
	TipoCarta getTipoCarta();

    /* Pre: Requiere ingresar un tipo de dato entre los disponibles.
     * Pos: Cambia el tipo de la carta.
     */
	void setTipoCarta(TipoCarta nuevoTipo);

};


#endif /* CARTA_H_ */
