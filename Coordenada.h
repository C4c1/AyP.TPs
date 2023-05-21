/*
 * Coordenada.h
 *
 *  Created on: 20 may 2023
 *      Author: David
 */

#ifndef COORDENADA_H_
#define COORDENADA_H_

class Coordenada{

private:

	int posicionX;
	int posicionY;
	int posicionZ;

public:

	Coordenada(int posicionX,int posicionY,int posicionZ);

	int getPosicionX();

	void setPosicionX(int nuevaPosicionX);

	int getPosicionY();

	void setPosicionY(int nuevaPosicionY);

	int getPosicionZ();

	void setPosicionZ(int nuevaPosicionZ);

};

#endif /* COORDENADA_H_ */
