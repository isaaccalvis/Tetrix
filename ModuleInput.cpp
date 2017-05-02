#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "SDL/include/SDL.h"

ModuleInput::ModuleInput() : Module() {
	for (uint i = 0; i < MAX_KEYS; ++i)
		keyboard[i] = KEY_IDLE;
}

ModuleInput::~ModuleInput() {}

bool ModuleInput::Init() {
	bool ret = true;
	SDL_Init(0);

	if (SDL_InitSubSystem(SDL_INIT_EVENTS) < 0) {
		ret = false;
	}

	return ret;
}

bool ModuleInput::Update() {
	SDL_PumpEvents();
	const Uint8* keys = SDL_GetKeyboardState(NULL);

	for (int i = 0; i < MAX_KEYS; ++i) {
		if (keys[i] == 1) {
			if (keyboard[i] == KEY_IDLE)
				keyboard[i] = KEY_DOWN;
			else
				keyboard[i] = KEY_REPEAT;
		}
		else {
			if (keyboard[i] == KEY_REPEAT || keyboard[i] == KEY_DOWN)
				keyboard[i] = KEY_UP;
			else
				keyboard[i] = KEY_IDLE;
		}
	}
	if (keyboard[SDL_SCANCODE_ESCAPE]) {
		return false;
	}
	return true;
}

bool ModuleInput::CleanUp() {
	SDL_QuitSubSystem(SDL_INIT_EVENTS);
	return true;
}