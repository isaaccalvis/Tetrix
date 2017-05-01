#include "ModuleWindow.h"
#include "Application.h"
#include "Globals.h"
#include "SDL\include\SDL.h"
#include <stdio.h>
ModuleWindow::ModuleWindow(){}
ModuleWindow::~ModuleWindow(){}

bool ModuleWindow::Init() {
	bool ret = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		print("SDL_WINDOW FAIL TO INIT\n");
		ret = false;
	}
	else {
		int width = SCREEN_WIDTH;
		int height = SCREEN_HEIGHT;
		Uint32 flags = SDL_WINDOW_SHOWN;

		window = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);
		if (window == NULL) {
			print("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			ret = false;
		}
		else
			screen_surface = SDL_GetWindowSurface(window);
	}
	return ret;
}

bool ModuleWindow::Finihs() {
	bool ret = true;
	if (window != NULL)
		SDL_DestroyWindow(window);
	SDL_Quit();
	return ret;
}