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

	void aniadirSoldadosEnTablero(Tablero* tablero, Lista<Jugador*>* jugadores);

	int validarPosicion(int valorMinimo, int valorMaximo,std::string texto);

	Coordenada* validarCasilla(std::string simboloAComparar,std::string simbolo);

	Ficha* seleccionarFicha(Jugador* jugador);

	void iniciarPartida();

	void jugarTurno(Jugador* jugador);

	Casillero* seleccionarDireccionAMoverSoldado(Ficha* ficha);

	bool tieneFichaDeMisomoJUgador(Ficha* ficha, Casillero* aRevisar);

	void agregarDireccionVlidaDeMovimiento(Ficha* ficha, Lista<Casillero*>* casilleros, int posicionX,int posicionY,int posicionZ);

};




#endif /* MENU_H_ */
