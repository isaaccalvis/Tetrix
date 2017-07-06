#include <stdlib.h>
#include <time.h>
#include "Application.h"
#include "Module.h"
#include "ModuleWindow.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleBlocs.h"
#include "ModuleBasicBloc.h"
#include "ModuleBackground.h"
#include "ModulePlayer.h"
#include "ModuleMenu.h"

Application::Application() {
	int i = 0;
	modules[i++] = window = new ModuleWindow();
	modules[i++] = input = new ModuleInput();
	modules[i++] = render = new ModuleRender();
	modules[i++] = background = new ModuleBackground();
	modules[i++] = blocs = new ModuleBlocs();
	modules[i++] = menu = new ModuleMenu();
	modules[i++] = basicBloc = new blocBasic();
	modules[i++] = player = new ModulePlayer();

}

Application::~Application() {
	for (int i = NUM_MODULES - 1; i >= 0; --i)
		delete modules[i];
}

bool Application::Init() {
	bool ret = true;
	srand(time(NULL));
	for (int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->Init();
	return ret;
}

bool Application::Update() {
	bool ret = true;
	for (int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Update() : ret;
	for (int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PostUpdate() : ret;
	return ret;
}

bool Application::Finish() {
	bool ret = true;

	for (int i = NUM_MODULES - 1; i >= 0 && ret == true; --i)
		ret = modules[i]->Finish();

	return ret;
}

int Application::getRamdomValue(int maxNum) {
	return rand() % maxNum; 
}

void Application::blocUpdate(int time) {
	current_time_update_bloc = SDL_GetTicks() + time;
}

void Application::disblocUpdate() {
	current_time_update_bloc = 0;
}