/*
 * Jugador.h
 *
 *  Created on: 22 may 2023
 *      Author: David
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_
#include"Carta.h"
#include"Lista.h"
#include"Ficha.h"
#include<string>

class Jugador{

private:

	Lista<Carta*>* cartas;
	int numeroSoldadosDisponibles;
	std::string simbolo;
	Lista<Ficha*>* FichasDisponibles;
	Lista<Coordenada*>* posicionDeMinasDetectadasPorRadar;

public:

    /* Pre: Requiere ingresar un entero y un string que representan los soldados disponibles y el simbolo del jugador.
     * Pos: Crea una instancia jugador con atributos inicializados segun lo ingresado.
     */
	Jugador(int solodadoDisponibles, std::string simbolo);

    /* Pre: -- No requiere condiciones especificas
     * Pos: Devuelve el puntero a listas del jugador
     */
	Lista<Carta*>* getCartas();

    /* Pre: -- No requiere condiciones especificas
     * Pos: Devuelve el string que representa el simbolo del jugador
     */
	std::string getSimbolo();

    /* Pre: --No requiere condiciones especificas.
     * Pos: Devuelve el numero de soldados disponibles del jugador
     */
	int getSoldadosDisponibles();

    /* Pre: -- No requiere condiciones especificas
     * Pos: Devuelve la lista a fichas del jugador.
     */
	Lista<Ficha*>* getFichasDisponibles();

	Lista<Coordenada*>* getPosicionDeMinasDetectadasPorRadar();

	~Jugador();

};




#endif /* JUGADOR_H_ */
