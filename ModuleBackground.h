#ifndef __ModuleBackground_H__
#define __ModuleBackground_H__
#include "Module.h"

class ModuleBackground : public Module{
public:
	ModuleBackground(){}
	~ModuleBackground(){}

	bool Init();
	bool Update();
	bool Finish();
private:
	SDL_Texture* texturaFons = nullptr;
	SDL_Rect tamanyPantalla;
};
#endif
