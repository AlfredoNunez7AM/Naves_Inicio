#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include <SDL.h>
#include <SDL_image.h>

CGame::CGame(){
	estado = ESTADO_INICIANDO; //ACT2:Mal, Aqui debes de iniciar tu estado, revisa el diagrama para saber cual es el estado inicial
atexit(SDL_Quit);
}

void CGame::Iniciando()
{
	if (SDL_Init( SDL_INIT_VIDEO )){
		printf("Error %s ", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	screen = SDL_SetVideoMode( 640, 480, 24, SDL_SWSURFACE );	if (screen == NULL){
		printf("Error %s ", SDL_GetError());
		exit(EXIT_FAILURE);
	}
SDL_WM_SetCaption( "Mi primer Juego", NULL );
}
// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
	SDL_Quit();
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
          
	while (salirJuego == false){
            
		//Maquina de estados
		switch(estado){///ACT2: Mal,, te faltaron 2 estados mas.
			case Estado::ESTADO_INICIANDO:
				Iniciando();
				{
				nave =IMG_LoadJPG_RW(SDL_RWFromFile("../Data/cuadro.jpg","rb"));
				SDL_Rect fuente;
				fuente.x = 90;
				fuente.y = 152;
				fuente.w = 242;
				fuente.h = 75;
				SDL_Rect destino;
				destino.x = 100;
				destino.y = 100;
				destino.w = 100;
				destino.h =  fuente.h;
				SDL_BlitSurface(nave, &fuente, screen, &destino);
				}
				estado = Estado::ESTADO_MENU;
			break;
			case Estado::ESTADO_MENU:
				break;
			case Estado::ESTADO_JUGANDO:
			break;
			case Estado::ESTADO_FINALIZANDO:
				break;
			case Estado::ESTADO_TERMINANDO: 
				salirJuego = true;
			break;
		};
		//Este codigo estara provicionalmente aqui.
       SDL_Flip(screen);
    }
	return true;
}
