/*
 * Menu.h
 *
 *  Created on: 28 may 2023
 *      Author: David
 */

#ifndef MENU_H_
#define MENU_H_
#include"BatallaDigital.h"
#include<string>
#include<iostream>

class Menu{
private:

	BatallaDigital* juego;

public:

	Menu();

	void iniciarJuego();

	void ingresarJugadores();

	BatallaDigital* getJuego(){
		return this->juego;
	}

	bool validarCaracterJugador(char caracter);

	void aniadirSoldadosEnTablero(Tablero* tablero, Lista<Jugador*>* jugadores);

};




#endif /* MENU_H_ */
