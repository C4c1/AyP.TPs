/*
 * Ficha.cpp
 *
 *  Created on: 23 may 2023
 *      Author: David
 */
#include"Ficha.h"

Ficha::Ficha(TipoFicha tipoFicha){
	this->tipoFicha = tipoFicha;
	this->coordenadas = NULL;
	if(this->tipoFicha == soldado){
		this->simbolo = 'S';
	}else if(this->tipoFicha == barco){
		this->simbolo = 'B';
	}else if(this->tipoFicha == mina){
		this->simbolo = 'M';
	}else if(this->tipoFicha == avionRadar){
		this->simbolo = '+';
	}
}

TipoFicha Ficha::getTipoFicha(){
	return this->tipoFicha;
}

char Ficha::getSimbolo(){
	return this->simbolo;
}


