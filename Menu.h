#ifndef MENU_H_
#define MENU_H_
#include"BatallaDigital.h"
#include"Carta.h"
#include<string>
#include<iostream>
#include<cstdlib>
enum EstadoDelJUego {enJuego,finalizado,empate,existeGanador};

class Menu{
private:

	BatallaDigital* juego;
	EstadoDelJUego estado;
	bool saltarTurno;

public:

    /* Pre: -- No requiere de condiciones especificas
     * Pos: Crea una instancia de tipo de dato Menu inicializando sus atributos.
     */
	Menu();

    /* Pre: -- No requiere de condiciones especificas
     * Pos:  Inicializa el dato BatallaDigital con nuevos atributos y procede a iniciar el juego.
     */
	void iniciarJuego();

    /* Pre: -- No requiere de condiciones especificas
     * Pos: Interactua con el usuario y define la cantidad de jugadores agregandolos al juego.
     */
	void ingresarJugadores();

    /* Pre: Requiere ingresar un puntero a Tablero y uno a Lista de jugadores valido para el juego
     * (jugadores mayor a cero y tablero con limites mayor a cero)
     * Pos: Añade soldados de los jugadores ingresados al tablero
     */
	void aniadirSoldadosEnTablero(Tablero* tablero, Lista<Jugador*>* jugadores);

    /* Pre: Requiere ingresar un dos numeros que representen valores minimo y maximo, y un string que sera el mensaje que se muestre
     * Pos: Devuelve el numero que se pida segun el texto ingresado. En caso de no estar entre el minimo y el maximo, se pedira
     * ingresar otro numero hasta que sea valido.
     */
	int validarPosicion(int valorMinimo, int valorMaximo,std::string texto);

    /* Pre: Requiere ingresar dos string, uno que representa un simbolo y otro el que se utilizara para comparar el ultimo.
     * Pos: Devuelve la coordenada asignada, si la coordenada no es valida se seguira preguntando a usuario hasta
     * conseguir una coordenada valida para el simbolo ingresado.
     */
	Coordenada* validarCasilla(std::string simboloAComparar,std::string simbolo);

    /* Pre: Requiere ingresar un puntero a jugador no nulo
     * Pos: Devuelve un puntero a ficha valida que sera la seleccionada por el jugador luego de imprimirse en pantalla los datos
     * sobre sus fichas disponibles.
     */
	Ficha* seleccionarFicha(Jugador* jugador);

    /* Pre: -- No requiere de condiciones especificas
     * Pos: Realiza el procedimiento que comienza el juego.
     */
	void iniciarPartida();

    /* Pre: Requiere un puntero a jugador valido (no null)
     * Pos: Realiza el procesamiento de su turno en totalidad (elegir una ficha disponible y moverla de posicion).
     */
	void jugarTurno(Jugador* jugador);

    /* Pre: Requiere un puntero a ficha valido (no null y de tipo soldado)
     * Pos: Devuelve el casillero que se seleccionó para mover la ficha ingresada.
     */
	Casillero* seleccionarDireccionAMoverSoldado(Ficha* ficha);

    /* Pre: Requiere un puntero a ficha valido y un puntero a casillero valido (ambos no null)
     * Pos: Devuelve true si la ficha que hay en ese casillero pertenece al mismo jugador de la ficha ingresada
     */
	bool tieneFichaDeMisomoJUgador(Ficha* ficha, Casillero* aRevisar);

    /* Pre:
     * Pos:
     */
	void agregarDireccionVlidaDeMovimiento(Ficha* ficha, Lista<Casillero*>* casilleros, int posicionX,int posicionY,int posicionZ);

    /* Pre:
     * Pos:
     */
	void aniadirMinaEnTablero(Jugador* jugador);

    /* Pre: -- No requiere de condiciones especificas
     * Pos: Devuelve el estado del juego, siendo ganador si los demas jugadores no tienen soldados disponibles.
     * En otro caso devolvera empate o enJuego
     */
	EstadoDelJUego revisarEstadoDeJuego();

    /* Pre: -- No requiere condiciones especificas
     * Pos: Devuelve enJuego o Empate dependiendo de los soldados disponibles de los jugadores.
     */
	EstadoDelJUego revisarEmpate();

    /* Pre: -- No requiere condiciones especificas
     * Pos:
     */
	EstadoDelJUego revisarGanador();

    /* Pre: Requiere un puntero a ficha valido (no null)
     * Pos: Devuelve un puntero a lista de casilleros disponibles para ser
     */
	Lista<Casillero*>* generarListaDeCasilleroDisponibles(Ficha* ficha);

    /* Pre: Requiere 4 numeros, uno que sera el evaluado, dos que sirven de limites y la opcion debe ser un
     * valor entre 1 y 2.
     * Pos: Devuelve un numero valido segun la opcion elegida.(Lo que varia la opcion es la forma de evaluar,
     * siendo 1: mayor que el minimo, y 2: menor que el maximo.
     */
	int validarNumero(int numero, int minimo, int maximo, int opcion);

    /* Pre: Requiere ingresar un puntero a jugador valido (no null)
     * Pos: Selecciona una carta para ser jugada que corresponde al jugador ingresado.
     */
	void SeleccionarCartaAJugar(Jugador* jugador);

    /* Pre: Requiere ingresar un puntero a jugador valido (no null)
     * Pos: Se realiza el ataque con barcos disparando todos los que posea el jugador ingresado.
     */
	void disparaConBarcosDisponibles(Jugador* jugador);

    /* Pre: Requiere un puntero a jugador valido (no nulo) y dato TipoFicha
     * Pos: Devuelve una lista con las fichas del tipo ingresado que correspondan al jugador ingresado.
     */
	Lista<Ficha*>* buscarFichas(Jugador* jugador, TipoFicha tipo);

	void SeleccionarAvionRadarKamikaze(Jugador* jugador);

	void ingresarEpicentroAtaqueQuimico(Jugador* jugador);

	/*
	void verListaDeMinasDetectadas(Jugador* jugador){

		jugador->getPosicionDeMinasDetectadasPorRadar()->reiniciarCursor();

		while(jugador->getPosicionDeMinasDetectadasPorRadar()->avanzarCursor()){
			std::string posicion = jugador->getPosicionDeMinasDetectadasPorRadar()->getCursor()->verCoordenada();
			std::cout<<"MIna: "<<posicion<<std::endl;

		}

	}
	*/

	void ingresarTamanioDeTablero();

	void ingreseCantidadDeSoldados();

	~Menu();

};




#endif /* MENU_H_ */
