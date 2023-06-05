/*
 * Tablero.cpp
 *
 *  Created on: 20 may 2023
 *      Author: David
 */
#include"Tablero.h"

Tablero::Tablero(int limiteX,int limiteY,int limiteZ){

	this->limiteX = limiteX;
	this->limiteY = limiteY;
	this->limiteZ = limiteZ;
	this->tablero = new Lista<Lista<Lista<Casillero*>*>*>();
	//this->crearTablero();
}

Lista<Lista<Lista<Casillero*>*>*>* Tablero::getTablero(){
	return this->tablero;
}

void Tablero::crearTablero(){
	for(int posicionZ = 0;posicionZ<this->limiteZ;posicionZ++){

		Lista<Lista<Casillero*>*>* nivelUno = new Lista<Lista<Casillero*>*>();

		for(int posicionY = 0;posicionY<this->limiteY;posicionY++){

			Lista<Casillero*>* nivelDos = new Lista<Casillero*>();

			for(int posicionX = 0;posicionX<this->limiteX;posicionX++){

				Casillero* nuevaCasilla = new Casillero(posicionX,posicionY,posicionZ);
				nivelDos->add(nuevaCasilla);

			}

			nivelUno->add(nivelDos);

		}

		this->tablero->add(nivelUno);

	}
}

int Tablero::getLimiteX(){
	return this->limiteX;
}

int Tablero::getLimiteY(){
	return this->limiteY;
}

int Tablero::getLimiteZ(){
	return this->limiteZ;
}

void Tablero::setLimiteX(int nuevoLimite){
	this->limiteX = nuevoLimite;
}

void Tablero::setLimiteY(int nuevoLimite){
	this->limiteY = nuevoLimite;
}

void Tablero::setLimiteZ(int nuevoLimite){
	this->limiteZ = nuevoLimite;
}
