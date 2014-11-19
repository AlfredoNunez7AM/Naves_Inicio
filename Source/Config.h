#ifndef _CONFIG_H_
#define _CONFIG_H_

#define WIDTH_SCREEN 540
#define HEIGHT_SCREEN 480

#define BORDE_IZQUIERDO 1<<0
#define BORDE_SUPERIOR  1<<1
#define BORDE_DERECHO   1<<2
#define BORDE_INFERIOR  1<<3

#define FPS_LIMIT 30.0f
#define FPS_DELAY 1000.0f / FPS_LIMIT

/***SPRITES***/
#define MODULO_MINAVE_NAVE 0
#define MODULO_MENU_FONDO 1
#define MODULO_ENEMIGO_NAVE 2
#define MODULO_TEXTO_TITULO 3
#define MODULO_TEXTO_NOMBRE 4
#define MODULO_TEXTO_MENU_OPCION1 5
#define MODULO_TEXTO_MENU_OPCION2 6
#define MODULO_TEXTO_MENU_OPCION1_SELECCIONADO 7
#define MODULO_TEXTO_MENU_OPCION2_SELECCIONADO 8

#endif