/*
 * Coordenada.cpp
 *
 *  Created on: 20 may 2023
 *      Author: David
 */

#include"Coordenada.h"

Coordenada::Coordenada(int posicionX,int posicionY,int posicionZ){

	this->posicionX = posicionX;
	this->posicionY = posicionY;
	this->posicionZ = posicionZ;

}


int Coordenada::getPosicionX(){

	return this->posicionX;

}

void Coordenada::setPosicionX(int nuevaPosicionX){

	this->posicionX = nuevaPosicionX;

}

int Coordenada::getPosicionY(){

	return this->posicionY;

}

void Coordenada::setPosicionY(int nuevaPosicionY){

	this->posicionY = nuevaPosicionY;

}

int Coordenada::getPosicionZ(){

	return this->posicionZ;

}

void Coordenada::setPosicionZ(int nuevaPosicionZ){

	this->posicionZ = nuevaPosicionZ;

}


