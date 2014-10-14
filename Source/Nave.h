#ifndef _NAVE_H_
#define _NAVE_H_
#include "Sprite.h"

class Nave{
	Sprite * sprite;
	int x;
	int y;
public:
	void Mover(int posicion);
	Nave(SDL_Surface * screen, char * rutaImagen);//Constructor
	void Pintar();
};
#endif