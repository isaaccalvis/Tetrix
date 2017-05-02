#ifndef __ModuleBlocks_h__
#define __ModuleBlocks_h__

#include "Application.h"
#include "Globals.h"
#include "Module.h"
#include "ModuleRender.h"

#include "SDL/include/SDL.h"
#include "SDL_image\include\SDL_image.h"
#pragma comment( lib, "SDL_image/libx86/SDL2_image.lib" )

#define MAX_BLOCS_STRUCT 4

enum colorBlocs {
	NONE_COLOR = 0,
	blau,
	groc,
	lila,
	rosa,
	verd,
	vermell,
};

enum formaStructBloc {
	NONE_STRUCT = 0,
	recta,
	eleR,
	eleL,
	creu,
	escalaR,
	escalaL,
	cuadrat,
	te,
};

class blocBasic {
private:
	bool viu = true;
	colorBlocs color = NONE_COLOR;
public:
	blocBasic(colorBlocs newColor, int Nx, int Ny) {
		color = newColor;
		x = Nx;
		y = Ny;
	}
	blocBasic(){}
	int x, y;
	bool estaViu() {
		return viu;
	}
	void changeColor(colorBlocs newColor) {
		color = newColor;
	}
	void pintarBlocs();
};

class blocStruct {
private:
	blocBasic* blocs[MAX_BLOCS_STRUCT];
public:
	blocStruct(formaStructBloc formaStruct, colorBlocs newColor) {
		switch (formaStruct) {
		case NONE_STRUCT:
			break;
		case recta:
			blocs[0] = new blocBasic(newColor, 0, 0);
			blocs[1] = new blocBasic(newColor, 10, 10);
			break;
		}
	}
	~blocStruct() {
		delete[] blocs; // posible generador de memori leaks
	}
	bool moventse = true;

};
class ModuleBlocs : public Module {
public:
	ModuleBlocs();
	~ModuleBlocs();

	bool Init();
	bool Update();
	bool Finish();
	bool CreateBlocEstructure();

public:
	SDL_Texture* texturaBlocBlau = nullptr;

};
#endif
