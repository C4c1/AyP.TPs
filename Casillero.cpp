/*
 * Casilla.cpp
 *
 *  Created on: 20 may 2023
 *      Author: David
 */

#include "Casillero.h"

Casillero::Casillero(int posicionX,int posicionY,int posicionZ){

	this->coordenada = new Coordenada(posicionX, posicionY, posicionZ);
	this->terreno = tierra;
	this->simbolo = '*';
	this->ficha = NULL;
	this->estado = libre;

}

Coordenada* Casillero::getCoordenada(){

	return this->coordenada;

}

char Casillero::getSimbolo(){

	return this->simbolo;

}

void Casillero::setSimbolo(char nuevoSimbolo){

	this->simbolo = nuevoSimbolo;

}

void Casillero::setTerrono(TipoTerreno nuevoTerreno){
	this->terreno = nuevoTerreno;
}
