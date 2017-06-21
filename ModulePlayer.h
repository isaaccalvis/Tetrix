#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"

class ModulePlayer : public Module{
public:
	ModulePlayer(){}
	~ModulePlayer() {}

	bool Init();
	bool Update();
	bool Finish();
private:

};

#endif