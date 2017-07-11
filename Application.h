#ifndef __Application_H__
#define __Application_H__
#include "Globals.h"
#define NUM_MODULES 9

class Module;
class ModuleWindow;
class ModuleInput;
class ModuleRender;
class ModuleBlocs;
class blocBasic;
class ModuleBackground;
class ModulePlayer;
class ModuleMenu;
class ModuleFonts;

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
	ModuleMenu* menu;
	ModuleFonts* fonts;

	int current_time_update_bloc = 0;
public:
	Application();
	~Application();

	bool Init();
	bool Update();
	bool Finish();

	int getRamdomValue(int maxNum);
	void blocUpdate(int time); // if time == 0, es permanent fins a que el desbloquis
	void disblocUpdate();	// aixo sha de fer que no ho he acabat ( ni començat casi )
};

extern Application* App;
#endif
