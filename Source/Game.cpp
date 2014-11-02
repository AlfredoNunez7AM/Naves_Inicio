#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Config.h"
#include <SDL.h>
#include <SDL_image.h>

CGame::CGame(){
	estado = ESTADO_INICIANDO;
	condicion = ESTADO_TERMINANDO;//ACT2:Mal, Aqui debes de iniciar tu estado, revisa el diagrama para saber cual es el estado inicial
atexit(SDL_Quit);

}

void CGame::Iniciando()
{
	if (SDL_Init( SDL_INIT_VIDEO )){
		printf("Error %s ", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	screen = SDL_SetVideoMode( WIDTH_SCREEN, HEIGHT_SCREEN, 24, SDL_HWSURFACE );
	if (screen == NULL){
		printf("Error %s ", SDL_GetError());
		exit(EXIT_FAILURE);
	}
SDL_WM_SetCaption( "Mi primer Juego", NULL );
atexit(SDL_Quit);
//x = (WIDTH_SCREEN/2)-(sprite->WidthModule(0)/2);//Ancho
//	y = (HEIGHT_SCREEN-80)-(sprite->HeightModule(0));//Alto
nave = new Nave(screen,"../Data/MiNave.bmp",(WIDTH_SCREEN/2)/*-(sprite->WidthModule(0)/2)*/, (HEIGHT_SCREEN-80)/*-(sprite->HeightModule(0))*/);
enemigo = new Nave(screen, "../Data/enemigo.bmp", 0,0);
for (int i = 0; i < 5; i++)
{
	enemigoArreglo[i] = new Nave(screen, "../Data/enemigo.bmp",i*50,0);
	enemigoArreglo[i]->SetAutoMovimiento(false);
	enemigoArreglo[i]->SetPasoLimite(4);
}
enemigo->SetAutoMovimiento(false);
enemigo->SetPasoLimite(4);
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
				printf("\n1. ESTADO_INICIANDO");
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
				//enemigo->Actualizar();
				//SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
				//*nave->PintarModulo(0,0,0,64,64);*/
				////nave->PintarModulo(0,100,100);
				//keys =SDL_GetKeyState(NULL);
				//if(keys[SDLK_UP])
				//{
				//	nave->MoverArribaAbajo(-1);
				//}
				//if(keys[SDLK_DOWN])
				//{
				//	nave->MoverArribaAbajo(1);
				//}
				//if(keys[SDLK_LEFT])
				//{
				//	nave->MoverLados(-1);
				//}
				//if(keys[SDLK_RIGHT])
				//{
				//	nave->MoverLados(1);
				//}
				//nave->Pintar();
				//enemigo->Pintar();
				if (condicion == Estado::ESTADO_MENU)
				{
					estado = Estado::ESTADO_FINALIZANDO;
					printf("\n2. ESTADO_MENU");
					condicion = ESTADO_TERMINANDO;
					
				}
				else
				{
					printf("\n2. ESTADO_MENU");
					estado = Estado::ESTADO_JUGANDO;
				}
				
				
				
				break;
			case Estado::ESTADO_JUGANDO:
				for (int i = 0; i < 5; i++)
				{
					enemigoArreglo[i]->Actualizar();
				}
				enemigo->Actualizar();
				MoverEnemigo();
				SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
				/*nave->PintarModulo(0,0,0,64,64);
				nave->PintarModulo(0,100,100);*/
				keys =SDL_GetKeyState(NULL);
				if(keys[SDLK_UP])
				{
					if (!LimitePantalla(nave, BORDE_SUPERIOR))
					nave->MoverArribaAbajo(-1);
				}
				if(keys[SDLK_DOWN])
				{
					if (!LimitePantalla(nave, BORDE_INFERIOR))
					nave->MoverArribaAbajo(1);
				}

				if(keys[SDLK_LEFT])
				{
					if (!LimitePantalla(nave, BORDE_IZQUIERDO))
					nave->MoverLados(-1);
				}
				if(keys[SDLK_RIGHT])
				{
					if (!LimitePantalla(nave, BORDE_DERECHO))
					nave->MoverLados(1);
				}
				if(keys[SDLK_F10])
				{estado = Estado::ESTADO_TERMINANDO;
				
				printf("\n3. ESTADO_JUGANDO");
				}
				nave->Pintar();
				enemigo->Pintar();
				for (int i = 0; i < 5; i++)
				{
					enemigoArreglo[i]->Pintar();
				}
				
			break;
			case Estado::ESTADO_FINALIZANDO:
				printf("\n5. ESTADO_FINALIZANDO");
				estado = Estado::ESTADO_ESPERANDO;
				salirJuego = false;
				break;
			case Estado::ESTADO_TERMINANDO: 
				printf("\n4. ESTADO_TERMINANDO");
				estado = Estado::ESTADO_MENU;
				condicion = Estado::ESTADO_MENU;
			break;

			case Estado::ESTADO_ESPERANDO:

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

bool CGame::LimitePantalla(Nave*objeto, int bandera)
{
	if(bandera & BORDE_IZQUIERDO)
	if(objeto->ObtenerX() <= 0)
		return true;
	if (bandera & BORDE_SUPERIOR)
	if (objeto->ObtenerY() <=0)
		return true;

	if (bandera & BORDE_DERECHO)
	if (objeto->ObtenerX() >=(WIDTH_SCREEN - objeto->ObtenerW()))
		return true;
	if (bandera & BORDE_INFERIOR)
	if (objeto->ObtenerY() >=HEIGHT_SCREEN - objeto->ObtenerH())
		return true;
	return false;

}//Termina LimitePantalla

void CGame::MoverEnemigo(){

	if(enemigo->ObtenerPasoActual()==0)
	if (!LimitePantalla(enemigo, BORDE_DERECHO))
	enemigo->MoverLados(1);//Derecha
	else{
		enemigo->IncrementarPasoActual();
	}//fin else derecho

	if (enemigo->ObtenerPasoActual()==1)
		if(!LimitePantalla(enemigo, BORDE_INFERIOR))
			enemigo->MoverArribaAbajo(1);//Abajo
		else{
		enemigo->IncrementarPasoActual();
	}//Fn else inferior

	if(enemigo->ObtenerPasoActual()==2)
		if (!LimitePantalla(enemigo, BORDE_IZQUIERDO))
			enemigo->MoverLados(-1);//Izquierda
	else{
				enemigo->IncrementarPasoActual();
			}//fin else izquierda

		if (enemigo->ObtenerPasoActual()==3)
			if (!LimitePantalla(enemigo, BORDE_SUPERIOR))
				enemigo->MoverArribaAbajo(-1);//Arriba
			else{
				enemigo->IncrementarPasoActual();
			}//fin else arriba

	//if(enemigo->ObtenerPasoActual()==3)
	//	if (!LimitePantalla(enemigo, BORDE_INFERIOR))
	//		enemigo->MoverArribaAbajo(1);//Abajo

			for (int i = 0; i < 5; i++)
			{
				if(enemigoArreglo[i]->ObtenerPasoActual()==0)
	if (!LimitePantalla(enemigoArreglo[i], BORDE_DERECHO))
	enemigoArreglo[i]->MoverLados(1);//Derecha
	else{
		enemigoArreglo[i]->IncrementarPasoActual();
	}//fin else derecho

	if (enemigoArreglo[i]->ObtenerPasoActual()==1)
		if(!LimitePantalla(enemigoArreglo[i], BORDE_INFERIOR))
			enemigoArreglo[i]->MoverArribaAbajo(1);//Abajo
		else{
		enemigoArreglo[i]->IncrementarPasoActual();
	}//Fn else inferior

	if(enemigoArreglo[i]->ObtenerPasoActual()==2)
		if (!LimitePantalla(enemigoArreglo[i], BORDE_IZQUIERDO))
			enemigoArreglo[i]->MoverLados(-1);//Izquierda
	else{
				enemigoArreglo[i]->IncrementarPasoActual();
			}//fin else izquierda

		if (enemigoArreglo[i]->ObtenerPasoActual()==3)
			if (!LimitePantalla(enemigoArreglo[i], BORDE_SUPERIOR))
				enemigoArreglo[i]->MoverArribaAbajo(-1);//Arriba
			else{
				enemigoArreglo[i]->IncrementarPasoActual();
			}//fin else arriba

	//if(enemigo->ObtenerPasoActual()==3)
	//	if (!LimitePantalla(enemigo, BORDE_INFERIOR))
	//		enemigo->MoverArribaAbajo(1);//Abajo
			}
			

}//Termina MoverEnemigo

