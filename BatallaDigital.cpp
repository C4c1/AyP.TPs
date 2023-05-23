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

				cout<<simbolo;

			}
			cout<<endl;
		}
		numeroCapa++;
		cout<<endl;
	}

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


