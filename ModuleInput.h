#ifndef __ModuleInpu_H__
#define __ModuleInpu_H__
#include "Module.h"

class ModuleInput : public Module {
public:
	ModuleInput();
	~ModuleInput();

	bool Init();
	bool Update();
	bool Finish();
};
#endif // !
