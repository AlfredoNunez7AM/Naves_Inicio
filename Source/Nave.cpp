#include "Nave.h"
#include "Config.h"

Nave::Nave(SDL_Surface * screen, char * rutaImagen, int x, int y)
{
	sprite = new Sprite(screen);
	sprite->cargarimagen(rutaImagen);
	//x = (WIDTH_SCREEN/2)-(sprite->WidthModule(0)/2);//Ancho
	//y = (HEIGHT_SCREEN-80)-(sprite->HeightModule(0));//Alto
	this->x = x;
	this->y = y;
	automovimiento = false;

}
void Nave::SetAutoMovimiento(bool automovimiento)
{
	this->automovimiento = automovimiento;
}

void Nave::Actualizar()
{
	if (automovimiento)
	{
		MoverLados(1);
		/*MoverArribaAbajo(1);*/
	}
	
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
