#include "Nave.h"
#include "Config.h"

Nave::Nave(SDL_Surface * screen, char * rutaImagen, int x, int y)
{
	sprite = new Sprite(screen);
	sprite->cargarimagen(rutaImagen);
	w = sprite->WidthModule(0);
	h = sprite->HeightModule(0);
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


int Nave::ObtenerX(){
	return x;
}

int Nave::ObtenerY(){
	return y;

}

int Nave::ObtenerW()
{
	return w;
}

int Nave::ObtenerH()
{
	return h;
}