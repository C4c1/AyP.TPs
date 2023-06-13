/*
 * Casilla.h
 *
 *  Created on: 20 may 2023
 *      Author: David
 */

#ifndef CASILLERO_H_
#define CASILLERO_H_
#include<string>
#include"Coordenada.h"
#include"Ficha.h"
#define NULL 0

enum TipoTerreno {tierra,agua,aire};
enum Estado {libre,ocupado,bloqueado};

class Casillero{

private:

	Coordenada* coordenada;
	std::string simbolo;
	TipoTerreno terreno;
	Ficha* ficha;
	Estado estado;
	int numeroDeturnosBloqueado;

public:

    /* Pre: Requiere ingresar tres numeros mayores o iguales a cero que representan la posicion en el tablero
     * Pos: Crea una instancia tablero inicializandose todos sus atributos.
     */
	Casillero(int posicionX,int posicionY,int posicionZ);

    /* Pre: -- No requiere condiciones especificas
     * Pos: Devuelve el puntero a coordenada del casillero.
     */
	Coordenada* getCoordenada();

    /* Pre: -- No requiere condiciones especificas
     * Pos: Devuelve el string que representa el simbolo del casillero.
     */
	std::string getSimbolo();

    /* Pre: Requiere ingresar un string que represente el nuevo simbolo del casillero
     * Pos: Cambia el simbolo del casillero
     */
	void setSimbolo(std::string nuevoSimbolo);

    /* Pre: Requiere ingresar un TipoTerreno valido (tierra,agua o aire).
     * Pos: Cambia el tipo de terreno que representa el casillero
     */
	void setTerrono(TipoTerreno nuevoTerreno);

    /* Pre: -- No requiere ingresar condiciones especificas
     * Pos: Devuelve el estado del terreno (puede ser ocupado, libre o bloqueado)
     */
	Estado getEstado();

    /* Pre: Requiere ingresar un estado valido (ocupado, libre o bloqueado)
     * Pos: Cambia el tipo de estado del casillero.
     */
	void setEstado(Estado estado);

    /* Pre: -- No requiere ingresar condiciones especificas
     * Pos: Devuelve el tipo de terreno que representa el casillero
     */
	TipoTerreno getTipoTerreno();

    /* Pre: Requiere ingresar un puntero a ficha valido (no null)
     * Pos: EL puntero a ficha del casillero pasa a apuntar a la direccion ingresada.
     */
	void setFicha(Ficha* ficha);

    /* Pre: -- No requiere condiciones especificas
     * Pos: Devuelve el puntero a Ficha del casillero.
     */
	Ficha* getFicha();

};



#endif /* CASILLERO_H_ */
