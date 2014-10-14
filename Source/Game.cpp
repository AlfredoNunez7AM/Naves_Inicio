#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Config.h"
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
	screen = SDL_SetVideoMode( WIDTH_SCREEN, HEIGHT_SCREEN, 24, SDL_SWSURFACE );
	if (screen == NULL){
		printf("Error %s ", SDL_GetError());
		exit(EXIT_FAILURE);
	}
SDL_WM_SetCaption( "Mi primer Juego", NULL );
atexit(SDL_Quit);
nave = new Nave(screen,"../Data/MiNave.bmp");
//nave = new Sprite(screen);
//nave->cargarimagen("../Data/MiNave.bmp");



}
// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
	delete(nave);
	SDL_FreeSurface(screen);
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
				/*{
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
				}*/
				estado = Estado::ESTADO_MENU;
			break;
			case Estado::ESTADO_MENU:
				SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
				/*nave->PintarModulo(0,0,0,64,64);*/
				//nave->PintarModulo(0,100,100);
				keys =SDL_GetKeyState(NULL);
				if(keys[SDLK_DOWN])
				{
					nave->Pintar();
					/*nave->Pintar(0,100,100);
					nave->Pintar(0,100,165);
					nave->Pintar(0,100,230);
					nave->Pintar(0,100,295);
					nave->Pintar(0,100,360);
					nave->Pintar(0,165,133);
					nave->Pintar(0,165,198);
					nave->Pintar(0,165,263);
					nave->Pintar(0,165,328);*/
				}
				break;
			case Estado::ESTADO_JUGANDO:
			break;
			case Estado::ESTADO_FINALIZANDO:
				break;
			case Estado::ESTADO_TERMINANDO: 
				salirJuego = true;
			break;
		};

		while(SDL_PollEvent(&event))//Aqui sdl creara una lista de eventos ocurridos
		{
			if(event.type == SDL_QUIT) {salirJuego = true;} //si se detecta una salida del sdl o.....
			if(event.type == SDL_KEYDOWN) { }
		}
		//Este codigo estara provicionalmente aqui.
       SDL_Flip(screen);

    }
	return true;
}
