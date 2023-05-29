/*
 * BatallaDigital.h
 *
 *  Created on: 21 may 2023
 *      Author: David
 */

#ifndef BATALLADIGITAL_H_
#define BATALLADIGITAL_H_
#include"Tablero.h"
#include"Carta.h"
#include"Pila.h"
#include"Jugador.h"
#include<iostream>

class BatallaDigital{

private:

	Tablero* tablero;
	int cantidadJugadores;
	int cantidadSoldados;
	Lista<Jugador*>* jugadores;
	//Pila<Carta*>* mazoDeCartas;

public:

	BatallaDigital(int limiteX,int limiteY,int limiteZ,int cantidadJugadores,int cantidadSoldados);

	int getCantidadJugadores();

	int getCantidadSoldados();

	void mostrarTablero();

	void agregarJugador(char simbolo);

	Tablero* getTablero();

	void cargarMapa();

	bool colocarFicha(Ficha* ficha,int posicionX, int posicionY, int posicionZ);

	//void crearMazoDeCartas();

	//Pila<Carta*>* getMazoDeCartas();

};



#endif /* BATALLADIGITAL_H_ */
