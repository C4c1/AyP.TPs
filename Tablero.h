#ifndef TABLERO_H_
#define TABLERO_H_

#include "Casillero.h"
#include"Lista.h"
#include "EasyBMP_Font.h"
#include "EasyBMP.h"

#include<string>
using namespace std;
class Tablero{

private:

	Lista<Lista<Lista<Casillero*>*>*>* tablero;
	int limiteX;
	int limiteY;
	int limiteZ;

public:

    /* Pre: Requiere 3 numeros mayores a cero que representan los limites en X, Y y Z que seran el tamaño del tablero
     * Pos: Crea una instancia del tipo de dato Tablero con sus atributos inicializados.
     */
	Tablero(int limiteX,int limiteY,int limiteZ);

    /* Pre: -- No requiere condiciones especificas
     * Pos: Devuelve el puntero a Lista que guarda el tablero con estructura de puntero a lista de lista a casilleros.
     */
	Lista<Lista<Lista<Casillero*>*>*>* getTablero();

    /* Pre: -- No requiere condiciones especificas
     * Pos: Inicializa el tablero con estructura de punteros de listas basandose en los limites definidos al instanciarse
     * el tipo de dato tablero.
     */
	void crearTablero();

    /* Pre: -- No requiere condiciones especificas
     * Pos: Devuelve el limite X
     */
	int getLimiteX();

    /* Pre: -- No requiere condiciones especificas
     * Pos: Devuelve el limite Y
     */
	int getLimiteY();

    /* Pre: -- No requiere condiciones especificas
     * Pos: Devuelve el limite Z
     */
	int getLimiteZ();

    /* Pre: Requiere ingresar un numero mayor a cero que sera el limite en X
     * Pos: Cambia el atributo limiteX al nuevo ingresado.
     */
	void setLimiteX(int nuevoLimite);

    /* Pre: Requiere ingresar un numero mayor a cero que sera el limite en Y
     * Pos: Cambia el atributo limiteY al nuevo ingresado.
     */
	void setLimiteY(int nuevoLimite);

    /* Pre: Requiere ingresar un numero mayor a cero que sera el limite en Z
     * Pos: Cambia el atributo limiteZ al nuevo ingresado.
     */
	void setLimiteZ(int nuevoLimite);

	void imprimirTablero();

	void imprimirTablero(string numeroJugador);

	~Tablero();
};


#endif /* TABLERO_H_ */
