#ifndef __ModuleBlocks_h__
#define __ModuleBlocks_h__

#include "Application.h"
#include "Globals.h"
#include "Module.h"
#include "ModuleRender.h"
#include "ModuleBasicBloc.h"

class blocStruct {
private:
	int llocDelsBlocsStruct[MAX_BLOCS_STRUCT];
	formaStructBloc formaStruct;
	bool angleColl[3] = { false,false,false }; // 0->down, 1->right, 2->left
public:
	int copiaLlocDelsBlocsStruct[MAX_BLOCS_STRUCT];
	blocStruct() { print("Sha creat un blocStruct sense valors"); }
	blocStruct(formaStructBloc forma, colorBlocs color, int x, int y);
	~blocStruct(){}
	bool moventse = true;
	void moureStruct(posMov posMov);
	void comprobarXoc();
	void copiarLlocDelsBlocsStruct();
	void angleCollDet(posMov posColl, bool det);
};

class ModuleBlocs : public Module {
public:
	ModuleBlocs(){}
	~ModuleBlocs(){}

	bool Init();
	bool Update();
	bool Finish();

public:
	SDL_Texture* texturaBlocBlau = nullptr;
	SDL_Texture* texturaBlocGroc = nullptr;
	SDL_Texture* texturaBlocLila = nullptr;
	SDL_Texture* texturaBlocRosa = nullptr;
	SDL_Texture* texturaBlocVerd = nullptr;
	SDL_Texture* texturaBlocVermell = nullptr;

	SDL_Rect rectBlocPerTextura = { 0,0,32,32 }; // 32 es l'alçada i amplada dels blocs
	blocBasic* blocs[MAX_BLOCS];
	blocStruct* structBlocActual = nullptr;
};
#endif