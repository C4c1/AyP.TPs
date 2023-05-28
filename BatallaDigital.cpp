/*
 * BatallaDigital.cpp
 *
 *  Created on: 21 may 2023
 *      Author: David
 */
#include"BatallaDigital.h"
using namespace std;

BatallaDigital::BatallaDigital(int limiteX,int limiteY,int limiteZ,int cantidadJugadores,int cantidadSoldados){

	this->tablero = new Tablero(limiteX,limiteY,limiteZ);
	this->cantidadJugadores = cantidadJugadores;
	this->cantidadSoldados = cantidadSoldados;
	this->jugadores = new Lista<Jugador*>();

	//this->mazoDeCartas = new Pila<Carta*>();
	//this->crearMazoDeCartas();

}

void BatallaDigital::mostrarTablero(){

	this->tablero->getTablero()->reiniciarCursor();
	int numeroCapa  = 1;
	while(this->tablero->getTablero()->avanzarCursor()){

		cout<<"Capa"<<numeroCapa<<endl;
		cout<<endl;
		this->tablero->getTablero()->getCursor()->reiniciarCursor();

		while(this->tablero->getTablero()->getCursor()->avanzarCursor()){

			this->tablero->getTablero()->getCursor()->getCursor()->reiniciarCursor();

			while(this->tablero->getTablero()->getCursor()->getCursor()->avanzarCursor()){

				char simbolo = this->tablero->getTablero()->getCursor()->getCursor()->getCursor()->getSimbolo();

				cout<<" "<<simbolo;

			}
			cout<<endl;
		}
		numeroCapa++;
		cout<<endl;
	}

}

Tablero* BatallaDigital::getTablero(){
	return this->tablero;
}

void BatallaDigital::cargarMapa(){
	Lista<Lista<Lista<Casillero*>*>*>* tablero = this->tablero->getTablero();

	tablero->reiniciarCursor();
	while(tablero->avanzarCursor()){

		Lista<Lista<Casillero*>*>* nivelUno = tablero->getCursor();
		nivelUno->reiniciarCursor();
		while(nivelUno->avanzarCursor()){

			Lista<Casillero*>* nivelDos = nivelUno->getCursor();
			nivelDos->reiniciarCursor();
			while(nivelDos->avanzarCursor()){

				Casillero* casilla = nivelDos->getCursor();
				if(casilla->getCoordenada()->getPosicionZ() < 5){
					if(casilla->getCoordenada()->getPosicionY() < (this->tablero->getLimiteY()/2)){
						casilla->setSimbolo('A');
						casilla->setTerrono(agua);
					}else{
						casilla->setSimbolo('T');
						casilla->setTerrono(tierra);
					}
				}
			}
		}

	}
}

void BatallaDigital::agregarJugador(){



}
/*
void BatallaDigital::crearMazoDeCartas(){
	int contadorCartas = 0;
	do{

		Carta* cartaAtaqueQuimico = new Carta(CartaAtaqueQuimico);
		contadorCartas++;
		this->mazoDeCartas->apilar(cartaAtaqueQuimico);
		Carta* cartaBarco = new Carta(cartaDeBarco);
		contadorCartas++;
		this->mazoDeCartas->apilar(cartaBarco);
		Carta* cartaAvion = new Carta(cartaDeAvionRadar);
		contadorCartas++;
		this->mazoDeCartas->apilar(cartaAvion);

	}while(contadorCartas < 20);

}

Pila<Carta*>* BatallaDigital::getMazoDeCartas(){
	return this->mazoDeCartas;
}
*/


