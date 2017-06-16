#ifndef __Application_H__
#define __Application_H__
#include "Globals.h"
#define NUM_MODULES 5

class Module;
class ModuleWindow;
class ModuleInput;
class ModuleRender;
class ModuleBlocs;
class ModuleBackground;

class Application {
public:
	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleInput* input;
	ModuleRender* render;
	ModuleBlocs* blocs;
	ModuleBackground* background;
public:
	Application();
	~Application();

	bool Init();
	bool Update();
	bool Finish();

};

extern Application* App;
#endif
