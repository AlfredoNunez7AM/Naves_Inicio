#ifndef _SPRITE_H_
#define _SPRITE_H_
#include <SDL.h>

class Sprite{
	SDL_Surface * imagen;
	SDL_Surface * screen;
public:
	Sprite(SDL_Surface * screen);
	~Sprite();
	void cargarimagen (char * nombre);
	void PintarModulo(int nombre, int x, int y, int w, int h);
	void PintarModulo(int nombre, int x, int y);
};


#endif