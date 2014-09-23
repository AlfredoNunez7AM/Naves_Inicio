
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
	Estado estado;
};