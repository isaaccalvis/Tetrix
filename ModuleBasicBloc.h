#ifndef __ModuleBasicBlocs_H__
#define __ModuleBasicBlocs_H__

#include "Module.h"
#include "ModuleBlocs.h"

class blocBasic : public Module {
private:
	bool viu;
	colorBlocs color = NONE_COLOR;
public:
	blocBasic(colorBlocs newColor, int Nx, int Ny);
	blocBasic() {}
	~blocBasic() {}
	int x, y;

	bool estaViu() { return viu; }
	void deleteBloc();
	void changeColor(colorBlocs newColor) { color = newColor; }
	void pintarBloc();
	void moureBloc(int x, int y, posMov pos);
	void comprobarBorder();
	bool detectarPreColl(posMov pos, int multipliDistancia);
};

#endif