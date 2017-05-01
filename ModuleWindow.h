#ifndef __ModuleWindow_H__
#define __ModuleWindow_H__
#include "Module.h"

struct SDL_Window;
struct SDL_Surface;

class ModuleWindow : public Module {
public:
	ModuleWindow();
	~ModuleWindow();
	bool Init();
	bool Finihs();
public:
	SDL_Window* window = nullptr;
	SDL_Surface* screen_surface = nullptr;
};
#endif // !__ModuleWindow_H__
