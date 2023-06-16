/*
 * Casilla.cpp
 *
 *  Created on: 20 may 2023
 *      Author: David
 */

#include "Casillero.h"
using namespace std;

Casillero::Casillero(int posicionX,int posicionY,int posicionZ){

	this->coordenada = new Coordenada(posicionX, posicionY, posicionZ);
	this->terreno = tierra;
	this->simbolo = "*";
	this->ficha = NULL;
	this->estado = libre;
	this->numeroDeturnosBloqueado = 0;

}

Coordenada* Casillero::getCoordenada(){

	return this->coordenada;

}

string Casillero::getSimbolo(){

	return this->simbolo;

}

void Casillero::setSimbolo(string nuevoSimbolo){

	this->simbolo = nuevoSimbolo;

}

void Casillero::setTerrono(TipoTerreno nuevoTerreno){
	this->terreno = nuevoTerreno;
}

Estado Casillero::getEstado(){
	return this->estado;
}

void Casillero::setEstado(Estado estado){
	this->estado = estado;
}

TipoTerreno Casillero::getTipoTerreno(){
	return this->terreno;
}

void Casillero::setFicha(Ficha* ficha){
	this->ficha = ficha;
}

Ficha* Casillero::getFicha(){
	return this->ficha;
}

void Casillero::setTurnosBloqueado(int numeroTurnos){
	this->numeroDeturnosBloqueado = numeroTurnos;
}

int Casillero::getTurnosBloqueado(){
	return this->numeroDeturnosBloqueado;
}

Casillero::~Casillero(){
	delete this->coordenada;
}
