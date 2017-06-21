#include "Globals.h"
#include "Application.h"
#include "ModuleBlocs.h"
#include "ModuleInput.h"

bool ModuleBlocs::Init() {
	texturaBlocBlau = App->render->newTexture("Resources/Sprites/blocBlau_mitja.png");
	texturaBlocGroc = App->render->newTexture("Resources/Sprites/blocGroc_mitja.png");
	texturaBlocLila = App->render->newTexture("Resources/Sprites/blocLila_mitja.png");
	texturaBlocRosa = App->render->newTexture("Resources/Sprites/blocRosa_mitja.png");
	texturaBlocVerd = App->render->newTexture("Resources/Sprites/blocVerd_mitja.png");
	texturaBlocVermell = App->render->newTexture("Resources/Sprites/blocVermell_mitja.png");

	for (int i = 0; i < MAX_BLOCS; i++)
		blocs[i] = nullptr;
	return true;
}

bool ModuleBlocs::Update() {
	for (int i = 0; i < MAX_BLOCS; i++) {
		if (blocs[i] != nullptr && blocs[i]->estaViu() == false) {	// elimina blocs si esta mort
			delete blocs[i];
			blocs[i] = nullptr;
		}
		else if (blocs[i] != nullptr)	// pinta blocs
			blocs[i]->pintarBloc();
	}
	if (structBlocActual == nullptr) {
		blocStruct(recta, blau, 320, 160);
		structBlocActual = new blocStruct(recta, blau, 288, 0);
	}
	else {
		structBlocActual->comprobarXoc();
	}
	return true;
}

bool ModuleBlocs::Finish() {
	return true;
}

blocStruct::blocStruct(formaStructBloc forma, colorBlocs color, int x, int y) {
	switch (forma) {
	case NONE_STRUCT:
		break;
	case recta:
		int cont = 0;
		while (cont < MAX_BLOCS_STRUCT) {
			for (int i = 0; i < MAX_BLOCS; i++) {
				if (cont < 4) { // tamany de la recta
					if (App->blocs->blocs[i] == nullptr) {
						App->blocs->blocs[i] = new blocBasic(color, x + 0, y + (cont * 32));
						llocDelsBlocsStruct[cont] = i;
						cont++;
					}
				}
			}
		}
		break;
	}
	for (int i = 0; i < 4; i++)
		angleColl[i] = false;
}

void blocStruct::moureStruct(posMov posMov) {
	switch (posMov) {
	case NONE:
		break;
	case UP:
		for (int i = 0; i < MAX_BLOCS_STRUCT; i++) {
			App->blocs->blocs[llocDelsBlocsStruct[i]]->moureBloc(0, -32, UP);
		}
		break;
	case DOWN:
		if (angleColl[0] == false)
			for (int i = 0; i < MAX_BLOCS_STRUCT; i++) {
				App->blocs->blocs[llocDelsBlocsStruct[i]]->moureBloc(0, 32, DOWN);
			}
		break;
	case RIGHT:
		if (angleColl[1] == false)
			for (int i = 0; i < MAX_BLOCS_STRUCT; i++) {
				App->blocs->blocs[llocDelsBlocsStruct[i]]->moureBloc(32, 0, RIGHT);
			}
		break;
	case LEFT:
		if (angleColl[2] == false)
			for (int i = 0; i < MAX_BLOCS_STRUCT; i++) {
				App->blocs->blocs[llocDelsBlocsStruct[i]]->moureBloc(-32, 0, LEFT);
			}
		break;
	}
}

void blocStruct::comprobarXoc() {
	for (int i = 0; i < MAX_BLOCS_STRUCT; i++)
		App->blocs->blocs[i]->comprobarBorder();
}

void blocStruct::copiarLlocDelsBlocsStruct() {
	for (int i = 0; i < MAX_BLOCS_STRUCT; i++)
		copiaLlocDelsBlocsStruct[i] = llocDelsBlocsStruct[i];
}

void blocStruct::angleCollDet(posMov posColl, bool det) {
	switch (posColl) {
	case DOWN:
		angleColl[0] = det;
		break;
	case RIGHT:
		angleColl[1] = det;
		break;
	case LEFT:
		angleColl[2] = det;
		break;
	}
}