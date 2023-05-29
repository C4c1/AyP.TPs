/*
 * Jugador.cpp
 *
 *  Created on: 22 may 2023
 *      Author: David
 */

#include"Jugador.h"

Jugador::Jugador(int solodadoDisponibles, char simbolo){
	this->cartas = new Lista<Carta*>();
	this->simbolo = simbolo;
	this->solodadoDisponibles = solodadoDisponibles;
}

Lista<Carta*>* Jugador::getCartas(){
	return this->cartas;
}

char Jugador::getSimbolo(){
	return this->simbolo;
}

int Jugador::getSoldadosDisponibles(){
	return this->solodadoDisponibles;
}
