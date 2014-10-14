#include "Nave.h"
#include "Config.h"

Nave::Nave(SDL_Surface * screen, char * rutaImagen)
{
	sprite = new Sprite(screen);
	sprite->cargarimagen(rutaImagen);
	x = (WIDTH_SCREEN/2)-(sprite->WidthModule(0)/2);
	y = (HEIGHT_SCREEN-80)-(sprite->HeightModule(0));
}

void Nave::Pintar(){
	sprite->PintarModulo(0,x,y);
}

void Nave::MoverLados(int posicion){
	y += posicion;
}

void Nave::MoverArribaAbajo(int posicion)
{
	x += posicion;
}
