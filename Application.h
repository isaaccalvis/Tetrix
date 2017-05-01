#ifndef __Application_H__
#define __Application_H__
#include "Globals.h"
#define NUM_MODULES 2

class Module;
class ModuleWindow;
class ModuleInput;

class Application {
public:
	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleInput* input;
public:
	Application();
	~Application();

	bool Init();
	bool Update();
	bool Finish();

};

extern Application* App;
#endif // !__Application_H__
