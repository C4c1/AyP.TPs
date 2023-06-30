#include"Coordenada.h"

Coordenada::Coordenada(int posicionX,int posicionY,int posicionZ){

	this->posicionX = posicionX;
	this->posicionY = posicionY;
	this->posicionZ = posicionZ;

}


int Coordenada::getPosicionX(){

	return this->posicionX;

}

void Coordenada::setPosicionX(int nuevaPosicionX){

	this->posicionX = nuevaPosicionX;

}

int Coordenada::getPosicionY(){

	return this->posicionY;

}

void Coordenada::setPosicionY(int nuevaPosicionY){

	this->posicionY = nuevaPosicionY;

}

int Coordenada::getPosicionZ(){

	return this->posicionZ;

}

void Coordenada::setPosicionZ(int nuevaPosicionZ){

	this->posicionZ = nuevaPosicionZ;

}

std::string Coordenada::verCoordenada(){

	std::stringstream ss1;
	std::stringstream ss2;
	std::stringstream ss3;
	std::string x,y,z;

	ss1<<this->posicionX;
	ss1>>x;

	ss2<<this->posicionY;
	ss2>>y;

	ss3<<this->posicionZ;
	ss3>>z;

	std::string texto = "(" + x + "," + y + "," + z + ")";
	return texto;
}

bool Coordenada::compararCoordenadas(Coordenada* aComparar){

	if(this->posicionX == aComparar->getPosicionX() && this->posicionY == aComparar->getPosicionY() && this->posicionZ == aComparar->getPosicionZ()){
		return true;
	}else{
		return false;
	}

}
/*
Coordenada::~Coordenada(){

}
*/
