#ifndef __Application_H__
#define __Application_H__
#include "Globals.h"
#define NUM_MODULES 7

class Module;
class ModuleWindow;
class ModuleInput;
class ModuleRender;
class ModuleBlocs;
class blocBasic;
class ModuleBackground;
class ModulePlayer;

class Application {
public:
	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleInput* input;
	ModuleRender* render;
	ModuleBlocs* blocs;
	blocBasic* basicBloc;
	ModuleBackground* background;
	ModulePlayer* player;
public:
	Application();
	~Application();

	bool Init();
	bool Update();
	bool Finish();

};

extern Application* App;
#endif
