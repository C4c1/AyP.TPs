/*
 * Coordenada.h
 *
 *  Created on: 20 may 2023
 *      Author: David
 */

#ifndef COORDENADA_H_
#define COORDENADA_H_
#include<string>
#include<sstream>

class Coordenada{

private:

	int posicionX;
	int posicionY;
	int posicionZ;

public:

    /* Pre: Requiere 3 valores que sean numeros mayores o igual a cero que representen la posicion de la coordenada
     * Pos: Crea una instancia con sus atributos inicializados segun lo ingresado.
     */
	Coordenada(int posicionX,int posicionY,int posicionZ);

    /* Pre: -- No requiere de condiciones especificas
     * Pos: Devuelve el numero que representa la posicion en X
     */
	int getPosicionX();

    /* Pre: Requiere un numero mayor o igual a cero que sera la nueva posicion en X
     * Pos: Cambia la posicion en X por la ingresada.
     */
	void setPosicionX(int nuevaPosicionX);

    /* Pre: -- No requiere de condiciones especificas
     * Pos: Devuelve el numero que representa la posicion en Y
     */
	int getPosicionY();

    /* Pre: Requiere un numero mayor o igual a cero que sera la nueva posicion en Y
     * Pos: Cambia la posicion en Y por la ingresada.
     */
	void setPosicionY(int nuevaPosicionY);

    /* Pre: -- No requiere de condiciones especificas
     * Pos: Devuelve el numero que representa la posicion en Z
     */
	int getPosicionZ();

    /* Pre: Requiere un numero mayor o igual a cero que sera la nueva posicion en Z
     * Pos: Cambia la posicion en Z por la ingresada.
     */
	void setPosicionZ(int nuevaPosicionZ);

    /* Pre: -- No requiere condiciones especificas
     * Pos: Devuelve en string la coordenada en X, Y, Z y de forma ordenada.
     */
	std::string verCoordenada();

	bool compararCoordenadas(Coordenada* aComparar);

};

#endif /* COORDENADA_H_ */
