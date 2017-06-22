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
	//	structBlocActual = new blocStruct(formaStructBloc(App->getRamdomValue(7)+1), colorBlocs(App->getRamdomValue(6) + 1), 288, 0);
		structBlocActual = new blocStruct(formaStructBloc(3), colorBlocs(App->getRamdomValue(6) + 1), 288, 0);

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
		formaStruct = forma;
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
		formaStruct = forma;
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
		formaStruct = forma;
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
	case escalaR:
		formaStruct = forma;
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
	case escalaL:
		formaStruct = forma;
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
		formaStruct = forma;
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
		formaStruct = forma;
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
					App->blocs->blocs[i] = new blocBasic(color, x, y + 32);
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

void blocStruct::rotarStruct() {
	if (App->blocs->structBlocActual != nullptr)
		switch (App->blocs->structBlocActual->formaStruct) {
		case recta:
			if ((App->blocs->blocs[llocDelsBlocsStruct[0]]->y + 96) == App->blocs->blocs[llocDelsBlocsStruct[3]]->y) {
				if (App->blocs->blocs[llocDelsBlocsStruct[2]]->detectarPreColl(LEFT, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[2]]->detectarPreColl(RIGHT, 2) == false && App->blocs->blocs[llocDelsBlocsStruct[2]]->detectarPreColl(RIGHT, 1) == false) {
					App->blocs->blocs[llocDelsBlocsStruct[3]]->x -= 32;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->y -= 32;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->x += 64;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->y += 64;
					App->blocs->blocs[llocDelsBlocsStruct[1]]->x += 32;
					App->blocs->blocs[llocDelsBlocsStruct[1]]->y += 32;
				}
			}
			else if ((App->blocs->blocs[llocDelsBlocsStruct[0]]->x - 96) == App->blocs->blocs[llocDelsBlocsStruct[3]]->x) {
				if (App->blocs->blocs[llocDelsBlocsStruct[2]]->detectarPreColl(DOWN, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[2]]->detectarPreColl(UP, 2) == false && App->blocs->blocs[llocDelsBlocsStruct[2]]->detectarPreColl(UP, 1) == false) {
					App->blocs->blocs[llocDelsBlocsStruct[1]]->x -= 32;
					App->blocs->blocs[llocDelsBlocsStruct[1]]->y -= 32;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->x += 32;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->y += 32;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->x -= 64;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->y -= 64;
				}
			}
			break;
		case eleR:
			if ((App->blocs->blocs[llocDelsBlocsStruct[1]]->y - 32) == (App->blocs->blocs[llocDelsBlocsStruct[0]]->y)) {
				if (App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(LEFT, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(RIGHT, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[2]]->detectarPreColl(LEFT, 1) == false) {
					App->blocs->blocs[llocDelsBlocsStruct[2]]->x -= 32;
					App->blocs->blocs[llocDelsBlocsStruct[2]]->y -= 32;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->x -= 64;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->y -= 0;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->x += 32;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->y += 32;
				}
			}
			else if ((App->blocs->blocs[llocDelsBlocsStruct[1]]->x - 32) == (App->blocs->blocs[llocDelsBlocsStruct[2]]->x)) {
				if (App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(UP, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[2]]->detectarPreColl(UP, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(DOWN, 1) == false) {
					App->blocs->blocs[llocDelsBlocsStruct[2]]->x += 32;
					App->blocs->blocs[llocDelsBlocsStruct[2]]->y -= 32;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->x += 0;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->y -= 64;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->x -= 32;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->y += 32;
				}
			}
			else if ((App->blocs->blocs[llocDelsBlocsStruct[1]]->y + 32) == (App->blocs->blocs[llocDelsBlocsStruct[0]]->y)) {
				if (App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(LEFT, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(RIGHT, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[3]]->detectarPreColl(RIGHT, 2) == false) {
					App->blocs->blocs[llocDelsBlocsStruct[2]]->x += 32;
					App->blocs->blocs[llocDelsBlocsStruct[2]]->y += 32;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->x += 64;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->y += 0;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->x -= 32;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->y -= 32;
				}
			}
			else if ((App->blocs->blocs[llocDelsBlocsStruct[1]]->x + 32) == (App->blocs->blocs[llocDelsBlocsStruct[2]]->x)) {
				if (App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(UP, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(DOWN, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[2]]->detectarPreColl(DOWN, 1) == false) {
					App->blocs->blocs[llocDelsBlocsStruct[2]]->x -= 32;
					App->blocs->blocs[llocDelsBlocsStruct[2]]->y += 32;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->x -= 0;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->y += 64;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->x += 32;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->y -= 32;
				}
			}
			break;
		case eleL:
			if ((App->blocs->blocs[llocDelsBlocsStruct[1]]->y - 32) == (App->blocs->blocs[llocDelsBlocsStruct[0]]->y)) {
				if (App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(LEFT, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(RIGHT, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[0]]->detectarPreColl(LEFT, 1) == false) {
					App->blocs->blocs[llocDelsBlocsStruct[2]]->x -= 32;
					App->blocs->blocs[llocDelsBlocsStruct[2]]->y -= 32;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->x -= 0;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->y -= 64;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->x += 32;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->y += 32;
				}
			}
			else if ((App->blocs->blocs[llocDelsBlocsStruct[1]]->x - 32) == (App->blocs->blocs[llocDelsBlocsStruct[2]]->x)) {
				if (App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(UP, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(DOWN, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[3]]->detectarPreColl(RIGHT, 2) == false) {
					App->blocs->blocs[llocDelsBlocsStruct[2]]->x += 32;
					App->blocs->blocs[llocDelsBlocsStruct[2]]->y -= 32;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->x += 64;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->y -= 0;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->x -= 32;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->y += 32;
				}
			}
			else if ((App->blocs->blocs[llocDelsBlocsStruct[1]]->y + 32) == (App->blocs->blocs[llocDelsBlocsStruct[0]]->y)) {
				if (App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(LEFT, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(RIGHT, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[0]]->detectarPreColl(RIGHT, 1) == false) {
					App->blocs->blocs[llocDelsBlocsStruct[2]]->x += 32;
					App->blocs->blocs[llocDelsBlocsStruct[2]]->y += 32;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->x += 0;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->y += 64;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->x -= 32;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->y -= 32;
				}
			}
			else if ((App->blocs->blocs[llocDelsBlocsStruct[1]]->x + 32) == (App->blocs->blocs[llocDelsBlocsStruct[2]]->x)) {
				if (App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(UP, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(DOWN, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[0]]->detectarPreColl(DOWN, 1) == false) {
					App->blocs->blocs[llocDelsBlocsStruct[2]]->x -= 32;
					App->blocs->blocs[llocDelsBlocsStruct[2]]->y += 32;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->x -= 64;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->y += 0;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->x += 32;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->y -= 32;
				}
			}
			break;
		case escalaR:
			if (App->blocs->blocs[llocDelsBlocsStruct[2]]->y - 32 == App->blocs->blocs[llocDelsBlocsStruct[1]]->y) {
				if (App->blocs->blocs[llocDelsBlocsStruct[3]]->detectarPreColl(UP, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[2]]->detectarPreColl(DOWN, 1) == false) {
					App->blocs->blocs[llocDelsBlocsStruct[1]]->x -= 32;
					App->blocs->blocs[llocDelsBlocsStruct[1]]->y += 32;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->x -= 64;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->y += 0;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->x += 32;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->y += 32;
				}
			}
			else if (App->blocs->blocs[llocDelsBlocsStruct[2]]->y + 32 == App->blocs->blocs[llocDelsBlocsStruct[3]]->y) {
				if (App->blocs->blocs[llocDelsBlocsStruct[2]]->detectarPreColl(UP, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[0]]->detectarPreColl(RIGHT, 2) == false) {
					App->blocs->blocs[llocDelsBlocsStruct[1]]->x += 32;
					App->blocs->blocs[llocDelsBlocsStruct[1]]->y -= 32;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->x += 64;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->y += 0;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->x -= 32;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->y -= 32;
				}
			}
			break;
		case escalaL:
			if (App->blocs->blocs[llocDelsBlocsStruct[2]]->y - 32 == App->blocs->blocs[llocDelsBlocsStruct[1]]->y) {
				if (App->blocs->blocs[llocDelsBlocsStruct[3]]->detectarPreColl(UP, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[2]]->detectarPreColl(DOWN, 1) == false) {
					App->blocs->blocs[llocDelsBlocsStruct[1]]->x += 32;
					App->blocs->blocs[llocDelsBlocsStruct[1]]->y += 32;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->x += 64;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->y += 0;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->x -= 32;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->y += 32;
				}
			}
			else if (App->blocs->blocs[llocDelsBlocsStruct[2]]->y + 32 == App->blocs->blocs[llocDelsBlocsStruct[3]]->y) {
				if (App->blocs->blocs[llocDelsBlocsStruct[2]]->detectarPreColl(UP, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[0]]->detectarPreColl(RIGHT, 2) == false) {
					App->blocs->blocs[llocDelsBlocsStruct[1]]->x -= 32;
					App->blocs->blocs[llocDelsBlocsStruct[1]]->y -= 32;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->x -= 64;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->y += 0;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->x += 32;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->y -= 32;
				}
			}
			break;
		case cuadrat:

			break;
		case te:
			if ((App->blocs->blocs[llocDelsBlocsStruct[1]]->x - 32) == (App->blocs->blocs[llocDelsBlocsStruct[2]]->x)) {
				if (App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(UP, 1) == false) {
					App->blocs->blocs[llocDelsBlocsStruct[2]]->x += 32;
					App->blocs->blocs[llocDelsBlocsStruct[2]]->y -= 32;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->x -= 32;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->y -= 32;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->x -= 32;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->y += 32;
				}
			}
			else if ((App->blocs->blocs[llocDelsBlocsStruct[1]]->x - 32) == (App->blocs->blocs[llocDelsBlocsStruct[3]]->x)) {
				if (App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(RIGHT, 1) == false) {
					App->blocs->blocs[llocDelsBlocsStruct[2]]->x += 32;
					App->blocs->blocs[llocDelsBlocsStruct[2]]->y += 32;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->x += 32;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->y -= 32;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->x -= 32;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->y -= 32;
				}
			}
			else if ((App->blocs->blocs[llocDelsBlocsStruct[1]]->x - 32) == (App->blocs->blocs[llocDelsBlocsStruct[0]]->x)) {
				if (App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(DOWN, 1) == false) {
					App->blocs->blocs[llocDelsBlocsStruct[2]]->x -= 32;
					App->blocs->blocs[llocDelsBlocsStruct[2]]->y += 32;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->x += 32;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->y += 32;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->x += 32;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->y -= 32;
				}
			}
			else if ((App->blocs->blocs[llocDelsBlocsStruct[1]]->y + 32) == (App->blocs->blocs[llocDelsBlocsStruct[2]]->y)) {
				if (App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(LEFT, 1) == false) {
					App->blocs->blocs[llocDelsBlocsStruct[2]]->x -= 32;
					App->blocs->blocs[llocDelsBlocsStruct[2]]->y -= 32;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->x -= 32;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->y += 32;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->x += 32;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->y += 32;
				}
			}
			break;
		}
}