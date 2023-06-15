/*
 * Ficha.h
 *
 *  Created on: 23 may 2023
 *      Author: David
 */

#ifndef FICHA_H_
#define FICHA_H_
#include<string>
#include"Coordenada.h"
enum TipoFicha{soldado,mina,barco,avionRadar};
#define NULL 0;

class Ficha{

private:

	TipoFicha tipoFicha;
	std::string simbolo;
	Coordenada* coordenadas;
	std::string nombreJugador;

public:

    /* Pre: Requiere ingresar un dato TipoFicha valido(soldado,mina,barco o avionRadar) y otro string que sera el nombre del jugador.
     * Pos: Crea una instancia ficha con valores inicializados segun lo ingresado.
     */
	Ficha(TipoFicha tipoFicha,std::string nombre);

    /* Pre: -- No requiere condiciones especificas
     * Pos: Devuelve el tipo de ficha que representa.
     */
	TipoFicha getTipoFicha();

    /* Pre: -- No requiere condiciones especificas
     * Pos: Devuelve el string que representa el simbolo de la ficha.
     */
	std::string getSimbolo();

    /* Pre: -- No requiere condiciones especificas
     * Pos: Devuelve el puntero a Coordenada que representa la posicion de la ficha en el tablero.
     */
	Coordenada* getCoordenada();

    /* Pre: Requiere ingresar un puntero a Coordenada valido (no null y dentro de los limites del tablero)
     * Pos: Cambia la coordenada de la ficha por la nueva ingresada.
     */
	void setCoordenada(Coordenada* nuevaCoordenada);

    /* Pre: -- No requiere condiciones especificas
     * Pos: Devuelve el string que representa el nombre del jugador duenio de la ficha.
     */
	std::string getNombreJugador();

	~Ficha();

};



#endif /* FICHA_H_ */
