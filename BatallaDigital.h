#ifndef BATALLADIGITAL_H_
#define BATALLADIGITAL_H_
#include"Tablero.h"
#include"Carta.h"
#include"Jugador.h"
#include<string>
#include<iostream>
#include<sstream>
#include<cstdlib>
using namespace std;

class BatallaDigital{

private:

	Tablero* tablero;
	Lista<Jugador*>* jugadores;
    int cantidadSoldados;

public:

    /* Pre: -- No requiere condiciones especificas
     * Pos: Constructor de batalla digital que inicializa sus atributos (tablero y lista) con valores predeterminados
     */
	BatallaDigital();

    /* Pre: Se necesitan 5 valores mayores a cero que seran las especificaciones del tamaño del tablero,
     * la cantidad de jugadores y la cantidad de soldados que tendrá cada uno.
     * Pos: Constructor de BatallaDigital que inicializa tablero y jugadores con los atributos que determine el usuario.
     */
	BatallaDigital(int limiteX,int limiteY,int limiteZ,int cantidadJugadores,int cantidadSoldados);

    /* Pre: -- No requiere condiciones especificas
     * Pos: Devuelve el numero de jugadores que participan en la partida.
     */
	int getCantidadJugadores();

    /* Pre:  --No requiere condiciones especificas
     * Pos: (probablemente haya que sacar esta funcion)
     */
	int getCantidadSoldados();

    /* Pre: -- No requiere condiciones especificas
     * Pos:  Muestra por pantalla el tablero de juego.
     */
	void mostrarTablero();

    /* Pre: Requiere pasar un nombre que identifica al jugador del turno en juego
     * Pos:  Muestra por pantalla el tablero del jugador de turno
     */
	void mostrarTableroParaJugador(Jugador* jugador,std::string nombre);

    /* Pre: Requiere ingresar un numero entero que representa la cantidad de jugadores en juego.
     * Pos: Agrega los jugadores que seran parte del juego.
     */
	void agregarJugadores(int cantidad);

    /* Pre: -- No requiere condiciones especificas
     * Pos: Devuelve el dato puntero a Tablero
     */
	Tablero* getTablero();

    /* Pre: -- No requiere condiciones especificas
     * Pos:  Inicializa el mapa cargando identificando cada casillero con el tipo de terreno que representa
     */
	void cargarMapa();

    /* Pre: Requiere ingresar un puntero a ficha y a una coordenada validos ()
     * Pos: Devuelve true si logra colocar una ficha en un casillero vacio.
     */
	bool colocarFicha(Ficha* ficha, Coordenada* coordenada);

    /* Pre: Requiere ingresar un numero mayor a cero que represente la cantidad de soldados que tendra cada jugador
     * Pos: Inicializa las fichas de soldados de cada jugador.
     */
	void aniadirSoldadosAJugador(int cantidad);

    /* Pre: -- No requiere condiciones especificas
     * Pos: Devuelve el puntero a Lista que guarda los jugadores de la partida.
     */
	Lista<Jugador*>* getJugadores();

    /* Pre: -- No requiere condiciones especificas.
     * Pos: muestra por pantalla el tablero de forma ordenada y con numeracion de las coordenadas.
     */
	/*
	void mostrarTableroConCoordenadas(){

		this->tablero->getTablero()->reiniciarCursor();
		int numeroCapa  = 1;
		while(this->tablero->getTablero()->avanzarCursor()){

			cout<<"Capa"<<numeroCapa<<endl;
			cout<<endl;
			this->tablero->getTablero()->getCursor()->reiniciarCursor();

			while(this->tablero->getTablero()->getCursor()->avanzarCursor()){

				this->tablero->getTablero()->getCursor()->getCursor()->reiniciarCursor();

				while(this->tablero->getTablero()->getCursor()->getCursor()->avanzarCursor()){
					Casillero* casillero = this->tablero->getTablero()->getCursor()->getCursor()->getCursor();
					if(casillero->getFicha() != NULL){

						string simbolo = casillero->getFicha()->getSimbolo();
						cout<<"("<<casillero->getCoordenada()->getPosicionX()<<","<<casillero->getCoordenada()->getPosicionY()<<","<<casillero->getCoordenada()->getPosicionZ()<<")  ";

					}else{

						string simbolo = this->tablero->getTablero()->getCursor()->getCursor()->getCursor()->getSimbolo();
						cout<<"("<<casillero->getCoordenada()->getPosicionX()<<","<<casillero->getCoordenada()->getPosicionY()<<","<<casillero->getCoordenada()->getPosicionZ()<<")  ";
					}

				}
				cout<<endl;
			}
			numeroCapa++;
			cout<<endl;
		}

	}
	*/

	/*
	void mostrarTableroTurnosBloqueados(){

		this->tablero->getTablero()->reiniciarCursor();
		int numeroCapa  = 1;
		while(this->tablero->getTablero()->avanzarCursor()){

			cout<<"Capa"<<numeroCapa<<endl;
			cout<<endl;
			this->tablero->getTablero()->getCursor()->reiniciarCursor();

			while(this->tablero->getTablero()->getCursor()->avanzarCursor()){

				this->tablero->getTablero()->getCursor()->getCursor()->reiniciarCursor();

				while(this->tablero->getTablero()->getCursor()->getCursor()->avanzarCursor()){
					Casillero* casillero = this->tablero->getTablero()->getCursor()->getCursor()->getCursor();

					int turno = casillero->getTurnosBloqueado();
					cout<<"("<<turno<<")  ";

				}
				cout<<endl;
			}
			numeroCapa++;
			cout<<endl;
		}

	}
	*/


    /* Pre: -- No requiere condiciones especificas
     * Pos: muestra por pantalla los casilleros con su respectivo estado (sea ocupado, libre o bloqueado)
     */
	/*
	void mostrarTablerocasilleroBloqueados(){

		this->tablero->getTablero()->reiniciarCursor();
		int numeroCapa  = 1;
		while(this->tablero->getTablero()->avanzarCursor()){

			cout<<"Capa"<<numeroCapa<<endl;
			cout<<endl;
			this->tablero->getTablero()->getCursor()->reiniciarCursor();

			while(this->tablero->getTablero()->getCursor()->avanzarCursor()){

				this->tablero->getTablero()->getCursor()->getCursor()->reiniciarCursor();

				while(this->tablero->getTablero()->getCursor()->getCursor()->avanzarCursor()){
					Casillero* casillero = this->tablero->getTablero()->getCursor()->getCursor()->getCursor();
					if(casillero->getEstado() == ocupado){


						cout<<" OCUPADO ";

					}else if(casillero->getEstado() == libre){

						cout<<" LIBRE   ";

					}else  if(casillero->getEstado() == bloqueado){

						cout<<" BLOCK   ";
					}

				}
				cout<<endl;
			}
			numeroCapa++;
			cout<<endl;
		}

	}
	*/

    /* Pre: Requiere ingresar un puntero a un dato coordenada.
     * Pos: Devuelve el puntero al casillero que se encuentra en esa coordenada si es que es una coordenada valida.
     */
	Casillero* buscarCasillero(Coordenada* Coordenada);

    /* Pre: Requiere ingresar tres numeros mayores a cero que esten dentro de los limites del tamaño del tablero
     * (representan las coordenadas del casillero).
     * Pos: Devuelve un puntero al casillero que se encuentre en esa posicion.
     */
	Casillero* buscarCasillero(int posicionX,int posicionY,int posicionZ);

    /* Pre: Requiere ingresar dos punteros a casilleros y un puntero a ficha. Representan la ficha a cambiar de lugar,
     * el casillero donde se encuentra y el casillero a donde se quiere transportar la ficha.
     * Pos: Devuelve un booleano que será true una vez haya sido realizado el cambio.
     */
	bool moverFicha(Casillero* actual, Casillero* destino, Ficha* aMover);

    /* Pre: Requiere un string que representa el nombre del jugador. Debe ser un nombre valido (uno existente en la partida)
     * Pos: Devuelve la lista de fichas que le pertenecen al jugador del nombre ingresado.
     */
	Lista<Ficha*>* buscarDuenioDeFicha(std::string nombre);

    /* Pre: Requiere dos punteros, uno a un dato Coordenada y otro a una lista de fichas.
     * Pos: borra la ficha que presenta esa posicion en la lista.
     */
	void removerFichaDeLista(Coordenada* posicion,Lista<Ficha*>* lista);

    /* Pre: Requiere ingresar un puntero a un jugador valido (no null)
     * Pos: Devuelve true si tiene soldados disponibles.
     */
	bool tieneSoldados(Jugador* jugador);

    /* Pre:Requiere ingresar dos punteros, uno a un dato jugador y otro a una posicion
     * Pos: Devuelve true si se logra cologar la mina del jugador correspondiente en la posicion indicada
     */
	bool colocarMina(Jugador* jugador,int x,int y,int z);

    /* Pre: -- No requiere condiciones especificas
     * Pos: Devuelve el puntero al jugador cuyos soldados siguen vivos a diferencia del resto. Devuelve un puntero a null
     * si hay mas jugadores con soldados vivos.
     */
	Jugador* buscarGanador();

    /* Pre: Requiere ingresar un puntero a un jugador que representa el del turno en juego.
     * Pos: No devulve nada, el jugador ingresado recibe una carta al azar de los tipos disponibles.
     */
	void tomarCarta(Jugador* jugador);

    /* Pre: Requiere ingrear dos punteros, uno a carta y otro a jugador.
     * Pos: Realiza el ataque de la carta devolviendo true y borrando la carta al finalizar el procedimiento.
     */
	bool jugarCarta(Carta* carta,Jugador* jugador);

    /* Pre: Requiere ingresar un puntero a casillero.
     * Pos: Realiza el ataque con barcos inhabilitando el casillero si es que habia una mina, o liberando
     * el espacio en otro caso de ficha.
     */
	void dispararConBarcoA(Casillero* casillero);

	void detectarMinasConAvionRadar(Jugador* jugador, Coordenada* posicionDelAvionRadar);

	void detectarMinasCOnAvionRadarAlIncioDeTurno(Jugador* jugador);

	int validarNumero(int numero, int minimo, int maximo, int opcion);

	bool estaEnLaListaDeMinasDetectadas(Jugador* jugador,Coordenada* aBuscar);

	void eliminarMinasDetectadas(Jugador* jugador,  Coordenada* posicionDelAvionRadar);

	void usarAntiaereo(int numeroDeJugador);

	bool usarKamikaze(Ficha* kamikaze , Jugador* jugadorActual, int jugadorEnemigo);

	bool usarAtaqueQuimico(int x, int y, int z);

	int validarRangoAtaqueQuimico(int numero, int minimo, int maximo, int opcion);

	void revisarCasilleroBloqueados();

	bool todasLasFichasBloqueadasDe(Jugador* jugador);

	void setCantidadSoldados(int cantidad);

	~BatallaDigital();


};



#endif /* BATALLADIGITAL_H_ */
