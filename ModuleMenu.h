#ifndef __ModuleMenu_H__
#define __ModuleMenu_H__
#include "Module.h"
#include "SDL_image\include\SDL_image.h"

class ModuleMenu : public Module {
public:

	ModuleMenu(){}
	~ModuleMenu(){}

	bool Init();
	bool Update();
	bool Finish();

	void startGame();
public:
	SDL_Texture* sprite_fonsMenu = nullptr;
	SDL_Texture* sprite_Play = nullptr;
	SDL_Texture* sprite_PlayNo = nullptr;
	SDL_Texture* sprite_Arcade = nullptr;
	SDL_Texture* sprite_ArcadeNo = nullptr;
	SDL_Texture* sprite_Exit = nullptr;
	SDL_Texture* sprite_ExitNo = nullptr;
	SDL_Texture* sprite_Configuration = nullptr;
	SDL_Texture* sprite_ConfigurationNo = nullptr;
	SDL_Texture* sprite_SelectorSprite = nullptr;
	SDL_Texture* sprite_MostraBlocs = nullptr;
	SDL_Rect rectTamanyPantalla = { 0,0,768,720 };
	SDL_Rect rectTamanyIconesMenu = { 0,0,256,64 };
	SDL_Rect rectTamanySelectorIcones = { 0,0,40,40 };
	SDL_Rect rectTamanyMostraBlocs = { 0,0,200,32 };
	int posicioEnMenu = 0;
	int posicioSelectorBlocsOptions = 0;
};

#endif