/*
 * Ficha.cpp
 *
 *  Created on: 23 may 2023
 *      Author: David
 */
using namespace std;
#include"Ficha.h"

Ficha::Ficha(TipoFicha tipoFicha, string nombre){
	this->tipoFicha = tipoFicha;
	this->coordenadas = NULL;
	this->nombreJugador = nombre;
	if(this->tipoFicha == soldado){
		this->simbolo = "S";
	}else if(this->tipoFicha == barco){
		this->simbolo = "B";
	}else if(this->tipoFicha == mina){
		this->simbolo = "M";
	}else if(this->tipoFicha == avionRadar){
		this->simbolo = "+";
	}
}

TipoFicha Ficha::getTipoFicha(){
	return this->tipoFicha;
}

string Ficha::getSimbolo(){
	return this->simbolo;
}

Coordenada* Ficha::getCoordenada(){
	return this->coordenadas;
}

void Ficha::setCoordenada(Coordenada* nuevaCoordenada){
	this->coordenadas = nuevaCoordenada;
}

string Ficha::getNombreJugador(){
	return this->nombreJugador;
}

