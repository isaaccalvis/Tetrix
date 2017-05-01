#include "Application.h"
#include"Globals.h"
#include "ModuleRender.h"
#include "SDL/include/SDL.h"
#include "ModuleWindow.h"

ModuleRender::ModuleRender() {
	camera.x = 0;
	camera.y = 0;
	camera.w = SCREEN_WIDTH;
	camera.h = SCREEN_HEIGHT;
}
ModuleRender::~ModuleRender() {}

bool ModuleRender::Init() {
	bool ret = true;
	Uint32 flags = 0;
	flags |= SDL_RENDERER_PRESENTVSYNC;

	renderer = SDL_CreateRenderer(App->window->window, -1, flags);
	if (renderer == NULL) {
		print("SDL_Render can't load");
		ret = false;
	}

	return ret;
}

bool ModuleRender::Update() {


}