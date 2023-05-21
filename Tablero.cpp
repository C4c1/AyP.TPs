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
	this->tablero = new Lista<Lista<Lista<Casilla*>*>*>();
	this->crearTablero();


}

Lista<Lista<Lista<Casilla*>*>*>* Tablero::getTablero(){
	return this->tablero;
}

void Tablero::crearTablero(){
	for(int i = 0;i<=this->limiteX;i++){

		Lista<Lista<Casilla*>*>* nivelUno = new Lista<Lista<Casilla*>*>();

		for(int j = 0;j<=this->limiteY;j++){

			Lista<Casilla*>* nivelDos = new Lista<Casilla*>();

			for(int k = 0;k<=this->limiteZ;k++){

				Casilla* nuevaCasilla = new Casilla(i,j,k);
				nivelDos->add(nuevaCasilla);

			}

			nivelUno->add(nivelDos);

		}

		this->tablero->add(nivelUno);

	}
}


