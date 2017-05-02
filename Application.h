#ifndef __Application_H__
#define __Application_H__
#include "Globals.h"
#define NUM_MODULES 4

class Module;
class ModuleWindow;
class ModuleInput;
class ModuleRender;
class ModuleBlocs;

class Application {
public:
	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleInput* input;
	ModuleRender* render;
	ModuleBlocs* blocs;
public:
	Application();
	~Application();

	bool Init();
	bool Update();
	bool Finish();

};

extern Application* App;
#endif
