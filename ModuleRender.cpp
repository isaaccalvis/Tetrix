#include "Application.h"
#include "Globals.h"
#include "ModuleRender.h"
#include "SDL/include/SDL.h"
#include "ModuleWindow.h"

#include "SDL/include/SDL.h"
#include "SDL_image\include\SDL_image.h"
#pragma comment( lib, "SDL_image/libx86/SDL2_image.lib" )

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

	return true;
}
bool ModuleRender::Finish() {
	SDL_DestroyRenderer(renderer);
	// NETEJA DE TEXTURES
	for (unsigned short i = 0; i < MAX_TEXTURES; i++) {
		if (textures[i] != nullptr)
			SDL_DestroyTexture(textures[i]);
	}
	return true;
}
bool ModuleRender::Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section, float speed){
	bool ret = true;
	SDL_Rect rectIntern;
	rectIntern.x = x;
	rectIntern.y = y;

	if (section != NULL) {
		rectIntern.w = section->w;
		rectIntern.h = section->h;
	}
	else
		SDL_QueryTexture(texture, NULL, NULL, &rectIntern.w, &rectIntern.h);

	if (SDL_RenderCopy(App->render->renderer, texture, section, &rectIntern) != 0)
		ret = false;
	return ret;
}

void ModuleRender::CleanRender() {
	SDL_RenderClear(renderer);
}

SDL_Texture* ModuleRender::newTexture(const char* direccio) {
	SDL_Surface* surface = IMG_Load(direccio);
	SDL_Texture* texture = NULL;
	texture = SDL_CreateTextureFromSurface(App->render->renderer, surface);
	textures[last_texture++] = texture;
	SDL_FreeSurface(surface);
	return texture;
}