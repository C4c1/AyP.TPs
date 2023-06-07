/*
 * Carta.cpp
 *
 *  Created on: 22 may 2023
 *      Author: David
 */

#include"Carta.h"

Carta::Carta(TipoCarta tipo){
	this->tipos = tipo;
}

TipoCarta Carta::getTipoCarta(){
	return this->tipos;
}

void Carta::setTipoCarta(TipoCarta nuevoTipo){
	this->tipos = nuevoTipo;
}

