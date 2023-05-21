/*
 * Casilla.cpp
 *
 *  Created on: 20 may 2023
 *      Author: David
 */

#include"Casilla.h"

Casilla::Casilla(int posicionX,int posicionY,int posicionZ){

	this->coordenada = new Coordenada(posicionX, posicionY, posicionZ);

	this->simbolo = '*';

}

Coordenada* Casilla::getCoordenada(){

	return this->coordenada;

}

char Casilla::getSimbolo(){

	return this->simbolo;

}

void Casilla::setSimbolo(char nuevoSimbolo){

	this->simbolo;

}

