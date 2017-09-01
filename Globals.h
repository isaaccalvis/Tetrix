#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#include <stdio.h>
#define print printf

typedef unsigned int uint;

#define SCREEN_WIDTH 768	// 512 ( pantalla ) + 256 (zona de puntuacio etc ... )
#define SCREEN_HEIGHT 720

#define MAX_BLOCS_STRUCT 4
#define MAX_BLOCS 352

#define BLOC_SIZE 32

enum colorBlocs {
	NONE_COLOR = 0,
	blau,
	groc,
	lila,
	rosa,
	verd,
	vermell,
	vermellClar,
	colorExtraBloc_Sol,
	colorExtraBloc_Dinamita,
	colorExtraBloc_Taladru
};

enum formaStructBloc {
	NONE_STRUCT = 0,
	recta,
	eleR,
	eleL,
	escalaR,
	escalaL,
	cuadrat,
	te,
	extraBloc_Sol,
	extraBloc_Dinamita,
	extraBloc_Taladru
};

enum posMov {
	NONE = 0,
	UP,
	DOWN,
	RIGHT,
	LEFT
};
#endif