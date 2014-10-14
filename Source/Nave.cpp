#include "Nave.h"
#include "Config.h"

Nave::Nave(SDL_Surface * screen, char * rutaImagen)
{
	sprite = new Sprite(screen);
	sprite->cargarimagen(rutaImagen);
	x = (WIDTH_SCREEN/2)-(sprite->WidthImage()/2);
	y = (HEIGHT_SCREEN-80)-(sprite->HeightImage());
}

void Nave::Pintar(){
	sprite->PintarModulo(0,x,y);
}