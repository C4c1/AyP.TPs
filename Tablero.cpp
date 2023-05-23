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
	this->crearTablero();


}

Lista<Lista<Lista<Casillero*>*>*>* Tablero::getTablero(){
	return this->tablero;
}

void Tablero::crearTablero(){
	for(int i = 0;i<this->limiteZ;i++){

		Lista<Lista<Casillero*>*>* nivelUno = new Lista<Lista<Casillero*>*>();

		for(int j = 0;j<this->limiteY;j++){

			Lista<Casillero*>* nivelDos = new Lista<Casillero*>();

			for(int k = 0;k<this->limiteX;k++){

				Casillero* nuevaCasilla = new Casillero(i,j,k);
				nivelDos->add(nuevaCasilla);

			}

			nivelUno->add(nivelDos);

		}

		this->tablero->add(nivelUno);

	}
}


