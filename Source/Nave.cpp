#include "Nave.h"
#include "Config.h"

Nave::Nave(SDL_Surface * screen, char * rutaImagen, int x, int y, int module)
{
	this->module = module;
	sprite = new Sprite(screen);
	sprite->cargarimagen(rutaImagen);
	w = sprite->WidthModule(this->module);
	h = sprite->HeightModule(this->module);
	this->x = x;
	this->y = y;
	automovimiento = false;
	pasoActual=0;
	pasoLimite=-1;
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
		MoverArribaAbajo(1);
	}
	if (pasoLimite>0)
	{
		//pasoActual++;
		if (pasoActual>=pasoLimite)
		pasoActual=0;
	}	
	}

void Nave::Pintar(){
	sprite->PintarModulo(this->module,x,y);
}

void Nave::Pintar(int modulo, int x, int y){
	sprite->PintarModulo(modulo, x, y);
}

void Nave::MoverLados(int posicion){
	x += posicion;
}

void Nave::MoverArribaAbajo(int posicion)
{
	y += posicion;
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

void Nave::SetPasoLimite(int pasos)
{
	this->pasoLimite = pasos;
}

int Nave::ObtenerPasoActual(){
	return pasoActual;
}

void Nave::IncrementarPasoActual()
{
	pasoActual++;
}

//bool Nave::EstaColicionando(Nave * b)
//{
//}