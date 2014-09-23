#include <stdio.h>
#include <stdlib.h>
#include "Game.h"

CGame::CGame(){
	estado ; //ACT2:Mal, Aqui debes de iniciar tu estado, revisa el diagrama para saber cual es el estado inicial
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
          
	while (salirJuego == false){
            
		//Maquina de estados
		switch(estado){///ACT2: Mal,, te faltaron 2 estados mas.
			case Estado::ESTADO_INICIANDO: 
			break;
			case Estado::ESTADO_JUGANDO:
			break;
			case Estado::ESTADO_TERMINANDO: 
				salirJuego = true;
			break;
		};
    }
	return true;
}
