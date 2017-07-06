#include "Application.h"
#include "Globals.h"
#include "ModuleRender.h"
#include "SDL/include/SDL_timer.h"
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
	for (int i = 0; i < MAX_SMALL_ANIMATION; i++)
		smallAnim[i] = nullptr;

	return ret;
}

bool ModuleRender::Update() {
	SDL_RenderClear(renderer);
	for (int i = 0; i < MAX_SMALL_ANIMATION; i++)
		if (smallAnim[i] != nullptr)
			smallAnim[i]->animationUpdate();
	return true;
}

bool ModuleRender::PostUpdate() {
	SDL_RenderPresent(renderer);
	return true;
}

bool ModuleRender::Finish() {
	for (unsigned short i = 0; i < MAX_SMALL_ANIMATION; i++) {
		if (smallAnim[i] != nullptr)
			delete smallAnim[i];
	}
	for (unsigned short i = 0; i < MAX_TEXTURES; i++) {
		if (textures[i] != nullptr)
			SDL_DestroyTexture(textures[i]);
	}
	SDL_DestroyRenderer(renderer);
	return true;
}

bool ModuleRender::Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section){
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
	if (SDL_RenderCopy(renderer, texture, section, &rectIntern) != 0)
		ret = false;
	return ret;
}

void ModuleRender::CleanRender() {
	SDL_RenderClear(renderer);
}

SDL_Texture* ModuleRender::newTexture(const char* direccio) {
	SDL_Surface* surface;
	surface = IMG_Load(direccio);
	SDL_Texture* texture = NULL;
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (textures != nullptr)
		textures[last_texture++] = texture;
	SDL_FreeSurface(surface);
	return texture;
}

void ModuleRender::Unload(SDL_Texture* texture) {
	for (int i = 0; i < MAX_TEXTURES; ++i){
		if (texture == textures[i] && textures[i] != nullptr) {
			SDL_DestroyTexture(textures[i]);
			textures[i] = nullptr;
			break;
		}
	}
}

void ModuleRender::newSmallAnimation(SDL_Texture* textura, int x, int y, SDL_Rect* rect, int timePerAnim, int numImages) {
	for (int i = 0; i < MAX_SMALL_ANIMATION; i++) {
		if (smallAnim[i] == nullptr) {
			smallAnim[i] = new smallAnimation(textura, x, y, rect, timePerAnim, numImages);
			break;
		}
	}
}

void ModuleRender::deleteSmallAnimation(SDL_Texture* textura) {
	for (int i = 0; i < MAX_SMALL_ANIMATION; i++) {
		if (smallAnim[i] != nullptr)
			if (smallAnim[i]->textura == textura) {
				delete smallAnim[i];
				smallAnim[i] = nullptr;
			}
	}
}

smallAnimation::smallAnimation(SDL_Texture* textura, int x, int y, SDL_Rect* rect, int timePerAnim, int numImages) {
	this->textura = textura;
	this->rect = *rect;
	this->x = x;
	this->y = y;
	this->timePerAnim = timePerAnim;
	this->numImages = numImages;
	this->actualImage = numImages;
	time = 0;
}

void smallAnimation::animationUpdate() {
		if (SDL_GetTicks() > time) {
			time = SDL_GetTicks() + timePerAnim;
			actualImage--;
			if (actualImage <= 0) {
				rect.x -= rect.w * numImages;
				actualImage = numImages;
			}
			rect.x += rect.w;
		}
		App->render->Blit(textura, x, y, &rect);
}