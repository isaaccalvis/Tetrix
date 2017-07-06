#ifndef __ModuleStructBlocs_H__
#define __ModuleStructBlocs_H__

#include "Application.h"
#include "Globals.h"
#include "Module.h"
#include "ModuleBasicBloc.h"

class blocStruct{
private:
	int llocDelsBlocsStruct[MAX_BLOCS_STRUCT];
	formaStructBloc formaStruct;
	bool angleColl[3] = { false,false,false }; // 0->down, 1->right, 2->left
	int current_time;
public:
	int copiaLlocDelsBlocsStruct[MAX_BLOCS_STRUCT];
	blocStruct() {}
	blocStruct(formaStructBloc forma, colorBlocs color, int x, int y);
	~blocStruct() {}
	bool moventse = true;
	void moureStruct(posMov posMov);
	void comprobarXoc();
	void copiarLlocDelsBlocsStruct();
	void angleCollDet(posMov posColl, bool det);
	bool retAngleColl(int num) { return angleColl[num]; }
	void normalFall();
	void rotarStruct();
	bool comprobarPosBloc(int x, int y);
	void eliminarLinies();
	void eliminatBlocs();
};
#endif