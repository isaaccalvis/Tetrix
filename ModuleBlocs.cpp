#include "Globals.h"
#include "Application.h"
#include "ModuleBlocs.h"
#include "ModuleInput.h"
#include "SDL\include\SDL_timer.h"

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

	// PRINT & CLEAN/DELETE BLOCS
	for (int i = 0; i < MAX_BLOCS; i++) {
		if (blocs[i] != nullptr && blocs[i]->estaViu() == false) {	// elimina blocs si esta mort
			delete blocs[i];
			blocs[i] = nullptr;
		}
		else if (blocs[i] != nullptr)	// pinta blocs
			blocs[i]->pintarBloc();
	}

	// REFRESH STRUCTURES ( THE PLAYING ONE )
	if (structBlocActual == nullptr) {
		structBlocActual = new blocStruct(te, blau, 288, 0);

		blocStruct(recta, blau, 320, 192);
		blocStruct(te, lila, 448, 192);
		blocStruct(eleL, groc, 384, 192);
	}
	else {
		structBlocActual->comprobarXoc();
		structBlocActual->normalFall();
	}
	return true;
}

bool ModuleBlocs::Finish() {
	return true;
}

blocStruct::blocStruct(formaStructBloc forma, colorBlocs color, int x, int y) {
	int cont = 0;
	switch (forma) {
	case NONE_STRUCT:
		break;
	case recta:
		for (int i = 0; i < MAX_BLOCS; i++) {
			if (cont < 4) { // tamany de la recta
				if (App->blocs->blocs[i] == nullptr) {
					App->blocs->blocs[i] = new blocBasic(color, x + 0, y + (cont * 32));
					llocDelsBlocsStruct[cont] = i;
					cont++;
				}
			}
			else
				i = MAX_BLOCS;
		}
		break;
	case eleR:
		for (int i = 0; i < MAX_BLOCS; i++) {
			if (cont < 3) {
				if (App->blocs->blocs[i] == nullptr) {
					App->blocs->blocs[i] = new blocBasic(color, x + 0, y + (cont * 32));
					llocDelsBlocsStruct[cont] = i;
					cont++;
				}
			}
			else if (cont == 3) {
				if (App->blocs->blocs[i] == nullptr) {
					App->blocs->blocs[i] = new blocBasic(color, x + 32, y + (2 * 32));
					llocDelsBlocsStruct[cont] = i;
					cont++;
				}
			}
			else
				i = MAX_BLOCS;
		}
		break;
	case eleL:
		for (int i = 0; i < MAX_BLOCS; i++) {
			if (cont < 3) {
				if (App->blocs->blocs[i] == nullptr) {
					App->blocs->blocs[i] = new blocBasic(color, x + 0, y + (cont * 32));
					llocDelsBlocsStruct[cont] = i;
					cont++;
				}
			}
			else if (cont == 3) {
				if (App->blocs->blocs[i] == nullptr) {
					App->blocs->blocs[i] = new blocBasic(color, x - 32, y + (2 * 32));
					llocDelsBlocsStruct[cont] = i;
					cont++;
				}
			}
			else
				i = MAX_BLOCS;
		}
		break;
	case escalaL:
		for (int i = 0; i < MAX_BLOCS; i++) {
			if (App->blocs->blocs[i] == nullptr) {
				llocDelsBlocsStruct[cont] = i;
				if (cont == 0)
					App->blocs->blocs[i] = new blocBasic(color, x + 32, y);
				else if (cont == 1)
					App->blocs->blocs[i] = new blocBasic(color, x, y);
				else if (cont == 2)
					App->blocs->blocs[i] = new blocBasic(color, x, y + (1 * 32));
				else if (cont == 3)
					App->blocs->blocs[i] = new blocBasic(color, x - 32, y + (1 * 32));
				cont++;
				if (cont == 4)
					i = MAX_BLOCS;
			}
		}
		break;
	case escalaR:
		for (int i = 0; i < MAX_BLOCS; i++) {
			if (App->blocs->blocs[i] == nullptr) {
				llocDelsBlocsStruct[cont] = i;
				if (cont == 0)
					App->blocs->blocs[i] = new blocBasic(color, x - 32, y);
				else if (cont == 1)
					App->blocs->blocs[i] = new blocBasic(color, x, y);
				else if (cont == 2)
					App->blocs->blocs[i] = new blocBasic(color, x, y + (1 * 32));
				else if (cont == 3)
					App->blocs->blocs[i] = new blocBasic(color, x + 32, y + (1 * 32));
				cont++;
				if (cont == 4)
					i = MAX_BLOCS;
			}
		}
		break;
	case cuadrat:
		for (int i = 0; i < MAX_BLOCS; i++) {
			if (App->blocs->blocs[i] == nullptr) {
				llocDelsBlocsStruct[cont] = i;
				if (cont == 0)
					App->blocs->blocs[i] = new blocBasic(color, x + 32, y);
				else if (cont == 1)
					App->blocs->blocs[i] = new blocBasic(color, x, y);
				else if (cont == 2)
					App->blocs->blocs[i] = new blocBasic(color, x, y + (1 * 32));
				else if (cont == 3)
					App->blocs->blocs[i] = new blocBasic(color, x + 32, y + (1 * 32));
				cont++;
				if (cont == 4)
					i = MAX_BLOCS;
			}
		}
		break;
	case te:
		for (int i = 0; i < MAX_BLOCS; i++) {
			if (App->blocs->blocs[i] == nullptr) {
				llocDelsBlocsStruct[cont] = i;
				if (cont == 0)
					App->blocs->blocs[i] = new blocBasic(color, x + 32, y);
				else if (cont == 1)
					App->blocs->blocs[i] = new blocBasic(color, x, y);
				else if (cont == 2)
					App->blocs->blocs[i] = new blocBasic(color, x - 32, y );
				else if (cont == 3)
					App->blocs->blocs[i] = new blocBasic(color, x, y + (1 * 32));
				cont++;
				if (cont == 4)
					i = MAX_BLOCS;
			}
		}
		break;
	}
	for (int i = 0; i < 3; i++)
		angleColl[i] = false;
	current_time = 0;
}

void blocStruct::moureStruct(posMov posMov) {
	if (App->blocs->structBlocActual != nullptr) {
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
}

void blocStruct::comprobarXoc() {
	if (App->blocs->structBlocActual != nullptr) {
		copiarLlocDelsBlocsStruct();
		for (int i = 0; i < 3; i++)
			angleColl[i] = false;
		for (int i = 0; i < MAX_BLOCS_STRUCT; i++)
			App->blocs->blocs[llocDelsBlocsStruct[i]]->comprobarBorder();
	}
}

void blocStruct::copiarLlocDelsBlocsStruct() {
	if (App->blocs->structBlocActual != nullptr) {
		for (int i = 0; i < MAX_BLOCS_STRUCT; i++)
			copiaLlocDelsBlocsStruct[i] = llocDelsBlocsStruct[i];
	}
}

void blocStruct::angleCollDet(posMov posColl, bool det) {
	if (App->blocs->structBlocActual != nullptr) {
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
}

void blocStruct::normalFall() {
	if (App->blocs->structBlocActual != nullptr) {
		if (current_time < SDL_GetTicks()) {
			current_time = SDL_GetTicks() + 1000;
			moureStruct(DOWN);
			if (angleColl[0] == true)
				App->blocs->structBlocActual = nullptr;
		}
	}
}