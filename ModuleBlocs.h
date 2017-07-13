#ifndef __ModuleBlocks_h__
#define __ModuleBlocks_h__

#include "Application.h"
#include "Globals.h"
#include "Module.h"
#include "ModuleStructBlocs.h"
#include "ModuleRender.h"

enum TipusBlocEstetic {
	BASIC,
	CASTELLAR,
	CUADRAT,
	PUR,
	TRESOR
};

class ModuleBlocs : public Module {
public:
	ModuleBlocs(){}
	~ModuleBlocs(){}

	bool Init();
	bool Update();
	bool Finish();
	void netejaBlocsMorts();
	void gameOver();
public:
	SDL_Texture* texturaBlocBlau = nullptr;
	SDL_Texture* texturaBlocGroc = nullptr;
	SDL_Texture* texturaBlocLila = nullptr;
	SDL_Texture* texturaBlocRosa = nullptr;
	SDL_Texture* texturaBlocVerd = nullptr;
	SDL_Texture* texturaBlocVermell = nullptr;
	SDL_Texture* texturaBlocVermellClar = nullptr;

	SDL_Rect rectBlocPerTextura = { 0,0,BLOC_SIZE,BLOC_SIZE };
	blocBasic* blocs[MAX_BLOCS];
	blocStruct* structBlocActual = nullptr;
	blocStruct* structBlocSeguent = nullptr;
	formaStructBloc nextStruct;
	TipusBlocEstetic tipusBlocEsteticActual = BASIC;
};
#endif