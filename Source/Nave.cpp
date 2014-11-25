#include "Nave.h"

Nave::Nave(SDL_Surface * screen, char * rutaImagen, int x, int y, int module)
{
	nave = new Objeto(screen, rutaImagen, x, y, module);
}

void Nave::Pintar()
{
	nave->Pintar();
}

void Nave::moverAbajo(){
	nave->MoverArribaAbajo(20);
}
void Nave::moverArriba(){
	nave->MoverArribaAbajo(-20);
}
void Nave::moverDerecha(){
	nave->MoverLados(20);
}
void Nave::moverIzquierda(){
	nave->MoverLados(-20);
}

Objeto * Nave::GetNaveObjeto()
{
	return nave;
}