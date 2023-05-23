/*
 * Carta.cpp
 *
 *  Created on: 22 may 2023
 *      Author: David
 */

#include"Carta.h"

Carta::Carta(Tipo tipo){
	this->tipos = tipo;
}

Tipo Carta::getTipoCarta(){
	return this->tipos;
}

void Carta::setTipoCarta(Tipo nuevoTipo){
	this->tipos = nuevoTipo;
}

