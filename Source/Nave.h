#ifndef _NAVE_H_
#define _NAVE_H_
#include "Sprite.h"

class Nave{
	Sprite * sprite;
	int x;
	int y;
	int w;
	int h;
	bool automovimiento;
	int pasos;
	int pasoActual;
	int pasoLimite;
public:
	void MoverArribaAbajo(int posicion);
	Nave(SDL_Surface * screen, char * rutaImagen, int x, int y);//Constructor
	void SetAutoMovimiento(bool automovimiento);
	void SetPasoLimite(int pasos);
	int ObtenerPasoActual();
	void IncrementarPasoActual();
	bool EstaColicionando(Nave * b);
	void Pintar();
	void MoverLados(int posicion);
	void Actualizar();
	int ObtenerY();
	int ObtenerX();
	int ObtenerW();
	int ObtenerH();
};
#endif