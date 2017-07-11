#include "Application.h"
#include "ModuleBlocs.h"
#include "ModuleBasicBloc.h"
#include "ModuleStructBlocs.h"
#include "ModulePlayer.h"
#include "ModuleFonts.h"
#include "SDL\include\SDL_timer.h"

blocStruct::blocStruct(formaStructBloc forma, colorBlocs color, int x, int y) {
	int cont = 0;
	switch (forma) {
	case NONE_STRUCT:
		break;
	case recta:
		formaStruct = forma;
		for (int i = 0; i < MAX_BLOCS; i++) {
			if (cont < 4) {
				if (App->blocs->blocs[i] == nullptr) {
					App->blocs->blocs[i] = new blocBasic(color, x + 0, y + (cont * BLOC_SIZE));
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
					App->blocs->blocs[i] = new blocBasic(color, x + 0, y + (cont * BLOC_SIZE));
					llocDelsBlocsStruct[cont] = i;
					cont++;
				}
			}
			else if (cont == 3) {
				if (App->blocs->blocs[i] == nullptr) {
					App->blocs->blocs[i] = new blocBasic(color, x + BLOC_SIZE, y + (2 * BLOC_SIZE));
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
					App->blocs->blocs[i] = new blocBasic(color, x + 0, y + (cont * BLOC_SIZE));
					llocDelsBlocsStruct[cont] = i;
					cont++;
				}
			}
			else if (cont == 3) {
				if (App->blocs->blocs[i] == nullptr) {
					App->blocs->blocs[i] = new blocBasic(color, x - BLOC_SIZE, y + (2 * BLOC_SIZE));
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
					App->blocs->blocs[i] = new blocBasic(color, x + BLOC_SIZE, y);
				else if (cont == 1)
					App->blocs->blocs[i] = new blocBasic(color, x, y);
				else if (cont == 2)
					App->blocs->blocs[i] = new blocBasic(color, x, y + (1 * BLOC_SIZE));
				else if (cont == 3)
					App->blocs->blocs[i] = new blocBasic(color, x - BLOC_SIZE, y + (1 * BLOC_SIZE));
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
					App->blocs->blocs[i] = new blocBasic(color, x - BLOC_SIZE, y);
				else if (cont == 1)
					App->blocs->blocs[i] = new blocBasic(color, x, y);
				else if (cont == 2)
					App->blocs->blocs[i] = new blocBasic(color, x, y + (1 * BLOC_SIZE));
				else if (cont == 3)
					App->blocs->blocs[i] = new blocBasic(color, x + BLOC_SIZE, y + (1 * BLOC_SIZE));
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
					App->blocs->blocs[i] = new blocBasic(color, x + BLOC_SIZE, y);
				else if (cont == 1)
					App->blocs->blocs[i] = new blocBasic(color, x, y);
				else if (cont == 2)
					App->blocs->blocs[i] = new blocBasic(color, x, y + (1 * BLOC_SIZE));
				else if (cont == 3)
					App->blocs->blocs[i] = new blocBasic(color, x + BLOC_SIZE, y + (1 * BLOC_SIZE));
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
					App->blocs->blocs[i] = new blocBasic(color, x + BLOC_SIZE, y);
				else if (cont == 1)
					App->blocs->blocs[i] = new blocBasic(color, x, y);
				else if (cont == 2)
					App->blocs->blocs[i] = new blocBasic(color, x - BLOC_SIZE, y);
				else if (cont == 3)
					App->blocs->blocs[i] = new blocBasic(color, x, y + BLOC_SIZE);
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
	App->blocs->structBlocActual->comprobarXoc();
	if (App->blocs->structBlocActual != nullptr) {
		switch (posMov) {
		case NONE:
			break;
		case UP:
			for (int i = 0; i < MAX_BLOCS_STRUCT; i++) {
				App->blocs->blocs[llocDelsBlocsStruct[i]]->moureBloc(0, -BLOC_SIZE, UP);
			}
			break;
		case DOWN:
			if (angleColl[0] == false)
				for (int i = 0; i < MAX_BLOCS_STRUCT; i++) {
					App->blocs->blocs[llocDelsBlocsStruct[i]]->moureBloc(0, BLOC_SIZE, DOWN);
				}
			break;
		case RIGHT:
			if (angleColl[1] == false)
				for (int i = 0; i < MAX_BLOCS_STRUCT; i++) {
					App->blocs->blocs[llocDelsBlocsStruct[i]]->moureBloc(BLOC_SIZE, 0, RIGHT);
				}
			break;
		case LEFT:
			if (angleColl[2] == false)
				for (int i = 0; i < MAX_BLOCS_STRUCT; i++) {
					App->blocs->blocs[llocDelsBlocsStruct[i]]->moureBloc(-BLOC_SIZE, 0, LEFT);
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
			current_time = SDL_GetTicks() + 800;
			App->blocs->structBlocActual->comprobarXoc();
			moureStruct(DOWN);
			if (angleColl[0] == true) {
				App->blocs->structBlocActual = nullptr;
				App->blocs->structBlocSeguent->eliminatBlocs();
				App->blocs->structBlocSeguent = nullptr;
				eliminarLinies();
			}
		}
	}
}

void blocStruct::rotarStruct() {
	if (App->blocs->structBlocActual != nullptr)
		switch (App->blocs->structBlocActual->formaStruct) {
		case recta:
			if ((App->blocs->blocs[llocDelsBlocsStruct[0]]->y + 96) == App->blocs->blocs[llocDelsBlocsStruct[3]]->y) {
				if (App->blocs->blocs[llocDelsBlocsStruct[2]]->detectarPreColl(LEFT, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[2]]->detectarPreColl(RIGHT, 2) == false && App->blocs->blocs[llocDelsBlocsStruct[2]]->detectarPreColl(RIGHT, 1) == false) {
					App->blocs->blocs[llocDelsBlocsStruct[3]]->x -= BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->y -= BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->x += BLOC_SIZE * 2;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->y += BLOC_SIZE * 2;
					App->blocs->blocs[llocDelsBlocsStruct[1]]->x += BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[1]]->y += BLOC_SIZE;
				}
			}
			else if ((App->blocs->blocs[llocDelsBlocsStruct[0]]->x - 96) == App->blocs->blocs[llocDelsBlocsStruct[3]]->x) {
				if (App->blocs->blocs[llocDelsBlocsStruct[2]]->detectarPreColl(DOWN, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[2]]->detectarPreColl(UP, 2) == false && App->blocs->blocs[llocDelsBlocsStruct[2]]->detectarPreColl(UP, 1) == false) {
					App->blocs->blocs[llocDelsBlocsStruct[1]]->x -= BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[1]]->y -= BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->x += BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->y += BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->x -= BLOC_SIZE * 2;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->y -= BLOC_SIZE * 2;
				}
			}
			break;
		case eleR:
			if ((App->blocs->blocs[llocDelsBlocsStruct[1]]->y - BLOC_SIZE) == (App->blocs->blocs[llocDelsBlocsStruct[0]]->y)) {
				if (App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(LEFT, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(RIGHT, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[2]]->detectarPreColl(LEFT, 1) == false) {
					App->blocs->blocs[llocDelsBlocsStruct[2]]->x -= BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[2]]->y -= BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->x -= BLOC_SIZE * 2;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->y -= 0;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->x += BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->y += BLOC_SIZE;
				}
			}
			else if ((App->blocs->blocs[llocDelsBlocsStruct[1]]->x - BLOC_SIZE) == (App->blocs->blocs[llocDelsBlocsStruct[2]]->x)) {
				if (App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(UP, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[2]]->detectarPreColl(UP, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(DOWN, 1) == false) {
					App->blocs->blocs[llocDelsBlocsStruct[2]]->x += BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[2]]->y -= BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->x += 0;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->y -= BLOC_SIZE * 2;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->x -= BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->y += BLOC_SIZE;
				}
			}
			else if ((App->blocs->blocs[llocDelsBlocsStruct[1]]->y + BLOC_SIZE) == (App->blocs->blocs[llocDelsBlocsStruct[0]]->y)) {
				if (App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(LEFT, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(RIGHT, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[3]]->detectarPreColl(RIGHT, 2) == false) {
					App->blocs->blocs[llocDelsBlocsStruct[2]]->x += BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[2]]->y += BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->x += BLOC_SIZE * 2;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->y += 0;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->x -= BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->y -= BLOC_SIZE;
				}
			}
			else if ((App->blocs->blocs[llocDelsBlocsStruct[1]]->x + BLOC_SIZE) == (App->blocs->blocs[llocDelsBlocsStruct[2]]->x)) {
				if (App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(UP, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(DOWN, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[2]]->detectarPreColl(DOWN, 1) == false) {
					App->blocs->blocs[llocDelsBlocsStruct[2]]->x -= BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[2]]->y += BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->x -= 0;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->y += BLOC_SIZE * 2;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->x += BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->y -= BLOC_SIZE;
				}
			}
			break;
		case eleL:
			if ((App->blocs->blocs[llocDelsBlocsStruct[1]]->y - BLOC_SIZE) == (App->blocs->blocs[llocDelsBlocsStruct[0]]->y)) {
				if (App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(LEFT, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(RIGHT, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[0]]->detectarPreColl(LEFT, 1) == false) {
					App->blocs->blocs[llocDelsBlocsStruct[2]]->x -= BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[2]]->y -= BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->x -= 0;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->y -= BLOC_SIZE * 2;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->x += BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->y += BLOC_SIZE;
				}
			}
			else if ((App->blocs->blocs[llocDelsBlocsStruct[1]]->x - BLOC_SIZE) == (App->blocs->blocs[llocDelsBlocsStruct[2]]->x)) {
				if (App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(UP, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(DOWN, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[3]]->detectarPreColl(RIGHT, 2) == false) {
					App->blocs->blocs[llocDelsBlocsStruct[2]]->x += BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[2]]->y -= BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->x += BLOC_SIZE * 2;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->y -= 0;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->x -= BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->y += BLOC_SIZE;
				}
			}
			else if ((App->blocs->blocs[llocDelsBlocsStruct[1]]->y + BLOC_SIZE) == (App->blocs->blocs[llocDelsBlocsStruct[0]]->y)) {
				if (App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(LEFT, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(RIGHT, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[0]]->detectarPreColl(RIGHT, 1) == false) {
					App->blocs->blocs[llocDelsBlocsStruct[2]]->x += BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[2]]->y += BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->x += 0;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->y += BLOC_SIZE * 2;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->x -= BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->y -= BLOC_SIZE;
				}
			}
			else if ((App->blocs->blocs[llocDelsBlocsStruct[1]]->x + BLOC_SIZE) == (App->blocs->blocs[llocDelsBlocsStruct[2]]->x)) {
				if (App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(UP, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(DOWN, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[0]]->detectarPreColl(DOWN, 1) == false) {
					App->blocs->blocs[llocDelsBlocsStruct[2]]->x -= BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[2]]->y += BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->x -= BLOC_SIZE * 2;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->y += 0;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->x += BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->y -= BLOC_SIZE;
				}
			}
			break;
		case escalaR:
			if (App->blocs->blocs[llocDelsBlocsStruct[2]]->y - BLOC_SIZE == App->blocs->blocs[llocDelsBlocsStruct[1]]->y) {
				if (App->blocs->blocs[llocDelsBlocsStruct[3]]->detectarPreColl(UP, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[2]]->detectarPreColl(DOWN, 1) == false) {
					App->blocs->blocs[llocDelsBlocsStruct[1]]->x -= BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[1]]->y += BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->x -= BLOC_SIZE * 2;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->y += 0;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->x += BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->y += BLOC_SIZE;
				}
			}
			else if (App->blocs->blocs[llocDelsBlocsStruct[2]]->y + BLOC_SIZE == App->blocs->blocs[llocDelsBlocsStruct[3]]->y) {
				if (App->blocs->blocs[llocDelsBlocsStruct[2]]->detectarPreColl(UP, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[0]]->detectarPreColl(RIGHT, 2) == false) {
					App->blocs->blocs[llocDelsBlocsStruct[1]]->x += BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[1]]->y -= BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->x += BLOC_SIZE * 2;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->y += 0;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->x -= BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->y -= BLOC_SIZE;
				}
			}
			break;
		case escalaL:
			if (App->blocs->blocs[llocDelsBlocsStruct[2]]->y - BLOC_SIZE == App->blocs->blocs[llocDelsBlocsStruct[1]]->y) {
				if (App->blocs->blocs[llocDelsBlocsStruct[3]]->detectarPreColl(UP, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[2]]->detectarPreColl(DOWN, 1) == false) {
					App->blocs->blocs[llocDelsBlocsStruct[1]]->x += BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[1]]->y += BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->x += BLOC_SIZE * 2;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->y += 0;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->x -= BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->y += BLOC_SIZE;
				}
			}
			else if (App->blocs->blocs[llocDelsBlocsStruct[2]]->y + BLOC_SIZE == App->blocs->blocs[llocDelsBlocsStruct[3]]->y) {
				if (App->blocs->blocs[llocDelsBlocsStruct[2]]->detectarPreColl(UP, 1) == false && App->blocs->blocs[llocDelsBlocsStruct[0]]->detectarPreColl(RIGHT, 2) == false) {
					App->blocs->blocs[llocDelsBlocsStruct[1]]->x -= BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[1]]->y -= BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->x -= BLOC_SIZE * 2;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->y += 0;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->x += BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->y -= BLOC_SIZE;
				}
			}
			break;
		case cuadrat:

			break;
		case te:
			if ((App->blocs->blocs[llocDelsBlocsStruct[1]]->x - BLOC_SIZE) == (App->blocs->blocs[llocDelsBlocsStruct[2]]->x)) {
				if (App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(UP, 1) == false) {
					App->blocs->blocs[llocDelsBlocsStruct[2]]->x += BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[2]]->y -= BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->x -= BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->y -= BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->x -= BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->y += BLOC_SIZE;
				}
			}
			else if ((App->blocs->blocs[llocDelsBlocsStruct[1]]->x - BLOC_SIZE) == (App->blocs->blocs[llocDelsBlocsStruct[3]]->x)) {
				if (App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(RIGHT, 1) == false) {
					App->blocs->blocs[llocDelsBlocsStruct[2]]->x += BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[2]]->y += BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->x += BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->y -= BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->x -= BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->y -= BLOC_SIZE;
				}
			}
			else if ((App->blocs->blocs[llocDelsBlocsStruct[1]]->x - BLOC_SIZE) == (App->blocs->blocs[llocDelsBlocsStruct[0]]->x)) {
				if (App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(DOWN, 1) == false) {
					App->blocs->blocs[llocDelsBlocsStruct[2]]->x -= BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[2]]->y += BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->x += BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->y += BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->x += BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->y -= BLOC_SIZE;
				}
			}
			else if ((App->blocs->blocs[llocDelsBlocsStruct[1]]->y + BLOC_SIZE) == (App->blocs->blocs[llocDelsBlocsStruct[2]]->y)) {
				if (App->blocs->blocs[llocDelsBlocsStruct[1]]->detectarPreColl(LEFT, 1) == false) {
					App->blocs->blocs[llocDelsBlocsStruct[2]]->x -= BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[2]]->y -= BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->x -= BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[3]]->y += BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->x += BLOC_SIZE;
					App->blocs->blocs[llocDelsBlocsStruct[0]]->y += BLOC_SIZE;
				}
			}
			break;
		}
}

bool blocStruct::comprobarPosBloc(int x, int y) {
	for (int i = 0; i < MAX_BLOCS; i++) {
		if (App->blocs->blocs[i] != nullptr) {
			if (App->blocs->blocs[i]->y == y && App->blocs->blocs[i]->x == x)
				return true;
		}
	}
	return false;
}

void blocStruct::eliminarLinies() {
	for (int y = 22; y > 0; y--) { // 22 = nombre de files
		for (int x = 0; x < 16; x++) { // 16 = nombre de columnes
			if (comprobarPosBloc(x * BLOC_SIZE + 256, (y * BLOC_SIZE) - BLOC_SIZE) == false)
				x = 18;
			if (x == 15) {
				for (int delet = 0; delet < 16; delet++) {
					for (int x2 = 0; x2 < MAX_BLOCS; x2++) {
						if (App->blocs->blocs[x2] != nullptr)
							if (App->blocs->blocs[x2]->y == ((y * BLOC_SIZE) - BLOC_SIZE)) {
								App->blocs->blocs[x2]->deleteBloc();
								x2 = MAX_BLOCS;
							}
					}
				}
				for (int mov = 0; mov < MAX_BLOCS; mov++) {
					if (App->blocs->blocs[mov] != nullptr)
						if (App->blocs->blocs[mov]->y < y * BLOC_SIZE)
							App->blocs->blocs[mov]->moureBloc(0, 32, DOWN);
				}
				App->player->puntuacio += 100;
				App->fonts->deleteFrase("puntuacio");
				App->fonts->deleteFrase("2puntuacio");
				App->fonts->addFrase(15, 500,"puntuacio");
				App->fonts->addFrase(15, 550, App->fonts->transformNumIntoChar(App->player->puntuacio), "2puntuacio");
				y = 23; // Sha de reiniciar Y perk baixa la fila, i lha de re-comprobar
			}
		}
	}
}

void blocStruct::eliminatBlocs() {
	for (int i = 0; i < MAX_BLOCS_STRUCT; i++)
		if (App->blocs->blocs[llocDelsBlocsStruct[i]] != nullptr)
			App->blocs->blocs[llocDelsBlocsStruct[i]]->deleteBloc();
}