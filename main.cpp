/*
 * main.cpp
 *
 *  Created on: 21 may 2023
 *      Author: David
 */
#include"BatallaDigital.h"
#include<string>
#include"Carta.h"
#include"Pila.h"
using namespace std;
int main(){

	BatallaDigital* batallaDigital = new BatallaDigital(6,4,7,2,2);
	batallaDigital->mostrarTablero();

	return 0;
}


