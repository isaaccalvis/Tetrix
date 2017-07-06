#ifndef __ModuleRender_H__
#define __ModuleRender_H__
#include "Module.h"
#include "SDL\include\SDL_rect.h"

#define MAX_TEXTURES 50
#define MAX_SMALL_ANIMATION 10

struct SDL_Renderer;
struct SDL_Texture;

class smallAnimation {
public:
	smallAnimation(SDL_Texture* textura, int x, int y, SDL_Rect* rect, int timePerAnim, int numImages);
	~smallAnimation() {}
	void animationUpdate();
	SDL_Texture* textura;
	SDL_Rect rect;
	int x, y, time = 0, timePerAnim, numImages, actualImage;
};

class ModuleRender : public Module {
public:
	ModuleRender();
	~ModuleRender();
	bool Init();
	bool Update();
	bool PostUpdate();
	bool Finish();
	bool Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section);
	void CleanRender();
	void newSmallAnimation(SDL_Texture* textura, int x, int y, SDL_Rect* rect, int timePerAnim, int numImages);
	void deleteSmallAnimation(SDL_Texture* textura);
	SDL_Texture* newTexture(const char* direccio);
	void Unload(SDL_Texture* texture);
public:
	SDL_Renderer* renderer = nullptr;
	SDL_Rect camera;
	SDL_Texture* textures[MAX_TEXTURES];
	unsigned short last_texture = 0;
private:
	smallAnimation* smallAnim[MAX_SMALL_ANIMATION];
};
#endif