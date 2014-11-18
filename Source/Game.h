#pragma once
#include <SDL_image.h>
#include "Nave.h"



class CGame
{
public:
	bool Start();
	static CGame instanceGame;

	CGame();
	void Finalize();
	
	enum Estado{
		ESTADO_INICIANDO,
		ESTADO_MENU,
		ESTADO_JUGANDO,
		ESTADO_TERMINANDO,
		ESTADO_FINALIZANDO,
		ESTADO_ESPERANDO
	};


private:
	void Iniciando();
	void MoverEnemigo();
	bool LimitePantalla(Nave * objeto, int bandera);
	unsigned int x;

	Uint8 *keys;//Esta variable nos servira para ver si determinadas teclas estan o no pulsadas
	SDL_Event event;//La variable event de tipo evento de SDL nos servira para motorizar
	SDL_Surface *screen, *image;

	Nave *nave;
	Nave *enemigoArreglo[5];

	Estado estado;
	Estado condicion;

	int tick;
	int tiempoFrameInicial;
	int tiempoFrameFinal;

	Nave *menu;//Fondo del menu
	Nave *textos;//Textos del juego
	Nave *fondo;//Fondo del juego

};