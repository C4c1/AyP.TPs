/*
 * Jugador.cpp
 *
 *  Created on: 22 may 2023
 *      Author: David
 */
using namespace std;
#include"Jugador.h"

Jugador::Jugador(int solodadoDisponibles, string simbolo){
	this->cartas = new Lista<Carta*>();
	this->simbolo = simbolo;
	this->numeroSoldadosDisponibles = solodadoDisponibles;
	this->FichasDisponibles = new Lista<Ficha*>();
}

Lista<Carta*>* Jugador::getCartas(){
	return this->cartas;
}

string Jugador::getSimbolo(){
	return this->simbolo;
}

int Jugador::getSoldadosDisponibles(){
	return this->numeroSoldadosDisponibles;
}

Lista<Ficha*>* Jugador::getFichasDisponibles(){
	return this->FichasDisponibles;
}
