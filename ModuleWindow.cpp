#include "Globals.h"
#include "Application.h"
#include "ModuleWindow.h"
#include "SDL/include/SDL.h"

ModuleWindow::ModuleWindow() : Module() {}

ModuleWindow::~ModuleWindow() {}

bool ModuleWindow::Init() {
	bool ret = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		ret = false;
	else {
		Uint32 flags = SDL_WINDOW_SHOWN;
		window = SDL_CreateWindow("Window1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, flags);

		if (window == NULL)
			ret = false;
		else
			screen_surface = SDL_GetWindowSurface(window);
	}

	return ret;
}

bool ModuleWindow::Finish() {
	bool ret = true;
	if (window != NULL)
		SDL_DestroyWindow(window);
	SDL_Quit();
	return ret;
}