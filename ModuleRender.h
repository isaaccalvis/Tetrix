#ifndef __ModuleRender_H__
#define __ModuleRender_H__
#include "Module.h"
#include "SDL\include\SDL_rect.h"

struct SDL_Renderer;
struct SDL_Texture;

class ModuleRender : public Module {
public:
	ModuleRender();
	~ModuleRender();
	bool Init();
	bool Update();
	bool Finish();
	bool Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section, float speed = 1.0f);
	bool CleanRender();
public:
	SDL_Renderer* renderer = nullptr;
	SDL_Rect camera;
};

#endif