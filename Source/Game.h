
#include <SDL_image.h>

class CGame
{
public:
	bool Start();
	static CGame instanceGame;

	CGame();
	void Finalize();
	
	enum Estado{
		ESTADO_INICIANDO,
		ESTADO_MENU,
		ESTADO_JUGANDO,
		ESTADO_TERMINANDO,
		ESTADO_FINALIZANDO
	};


private:
	void Iniciando();
	SDL_Surface *screen;
	SDL_Surface *nave;
	Estado estado;

};