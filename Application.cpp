#include "Application.h"
#include "Module.h"
#include "ModuleWindow.h"
#include "ModuleInput.h"

Application::Application() {
	int i = 0;
	modules[i++] = window = new ModuleWindow();
	modules[i++] = window = new ModuleInput();
}

Application::~Application() {
	for (int i = NUM_MODULES - 1; i >= 0; --i)
		delete modules[i];
}

bool Application::Init() {
	bool ret = true;

	for (int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->Init();

	return ret;
}

bool Application::Update() {
	bool ret = true;
	for (int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Update() : ret;
	return ret;
}

bool Application::Finish() {
	bool ret = true;

	for (int i = NUM_MODULES - 1; i >= 0 && ret == true; --i)
		ret = modules[i]->Finish();

	return ret;
}