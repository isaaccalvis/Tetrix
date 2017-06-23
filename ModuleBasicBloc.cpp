#include "Application.h"
#include "ModuleBasicBloc.h"
#include "ModuleBlocs.h"

blocBasic::blocBasic(colorBlocs newColor, int Nx, int Ny) {
	color = newColor;
	x = Nx;
	y = Ny;
	viu = true;
}

void blocBasic::pintarBloc() {
	switch (color) {
	case blau:
		if (App->blocs->texturaBlocBlau != nullptr)
			App->render->Blit(App->blocs->texturaBlocBlau, x, y, &App->blocs->rectBlocPerTextura);
		break;
	case groc:
		if (App->blocs->texturaBlocGroc != nullptr)
			App->render->Blit(App->blocs->texturaBlocGroc, x, y, &App->blocs->rectBlocPerTextura);
		break;
	case lila:
		if (App->blocs->texturaBlocLila != nullptr)
			App->render->Blit(App->blocs->texturaBlocLila, x, y, &App->blocs->rectBlocPerTextura);
		break;
	case rosa:
		if (App->blocs->texturaBlocRosa != nullptr)
			App->render->Blit(App->blocs->texturaBlocRosa, x, y, &App->blocs->rectBlocPerTextura);
		break;
	case verd:
		if (App->blocs->texturaBlocVerd != nullptr)
			App->render->Blit(App->blocs->texturaBlocVerd, x, y, &App->blocs->rectBlocPerTextura);
		break;
	case vermell:
		if (App->blocs->texturaBlocVermell != nullptr)
			App->render->Blit(App->blocs->texturaBlocVermell, x, y, &App->blocs->rectBlocPerTextura);
		break;
	}
}

void blocBasic::deleteBloc() {
	viu = false;
	App->blocs->netejaBlocsMorts();
}
void blocBasic::moureBloc(int x, int y, posMov pos) {
	if (this->x + BLOC_SIZE < 768 && pos == RIGHT)
		this->x += x;

	if (this->x > 256 && pos == LEFT)
		this->x += x;

	if (this->y + y < 704 && pos == DOWN)
		this->y += y;

	if (this->y > 0 && pos == UP)
		this->y += y;

	// CORRECTOR
	if (this->y < 0)
		this->y = 1;
	if (this->y > 704)
		this->y = 704;
	if (this->x < 256)
		this->x = 255;
	if (this->x > 768)
		this->x = 769;
}

void blocBasic::comprobarBorder() {
	for (int i = 0; i < MAX_BLOCS; i++) {
		if (App->blocs->structBlocActual->copiaLlocDelsBlocsStruct[0] != i && App->blocs->structBlocActual->copiaLlocDelsBlocsStruct[1] != i && App->blocs->structBlocActual->copiaLlocDelsBlocsStruct[2] != i && App->blocs->structBlocActual->copiaLlocDelsBlocsStruct[3] != i) {
			if (this->x + BLOC_SIZE >= 768)
				App->blocs->structBlocActual->angleCollDet(RIGHT, true);
			else if (App->blocs->structBlocActual->retAngleColl(1) == false)
				App->blocs->structBlocActual->angleCollDet(RIGHT, false);
			if (this->x <= 256)
				App->blocs->structBlocActual->angleCollDet(LEFT, true);
			else if (App->blocs->structBlocActual->retAngleColl(2) == false)
				App->blocs->structBlocActual->angleCollDet(LEFT, false);
			if (this->y + BLOC_SIZE >= 704)
				App->blocs->structBlocActual->angleCollDet(DOWN, true);
			else if (App->blocs->structBlocActual->retAngleColl(0) == false)
				App->blocs->structBlocActual->angleCollDet(DOWN, false);
			if (App->blocs->blocs[i] != nullptr) {
				if ((App->blocs->blocs[i]->x - BLOC_SIZE == this->x && App->blocs->blocs[i]->y == this->y))
					App->blocs->structBlocActual->angleCollDet(RIGHT, true);
				else if (App->blocs->structBlocActual->retAngleColl(1) == false)
					App->blocs->structBlocActual->angleCollDet(RIGHT, false);
				if ((App->blocs->blocs[i]->x + BLOC_SIZE == this->x && App->blocs->blocs[i]->y == this->y))
					App->blocs->structBlocActual->angleCollDet(LEFT, true);
				else if (App->blocs->structBlocActual->retAngleColl(2) == false)
					App->blocs->structBlocActual->angleCollDet(LEFT, false);
				if ((App->blocs->blocs[i]->y - BLOC_SIZE == this->y && App->blocs->blocs[i]->x == this->x))
					App->blocs->structBlocActual->angleCollDet(DOWN, true);
				else if (App->blocs->structBlocActual->retAngleColl(0) == false)
					App->blocs->structBlocActual->angleCollDet(DOWN, false);
			}
		}
	}
}

bool blocBasic::detectarPreColl(posMov pos, int multipliDistancia) {
	switch (pos) {
	case UP:
		if ((this->y - (BLOC_SIZE * multipliDistancia)) < 0)
			return true;
		for (int i = 0; i < MAX_BLOCS; i++) {
			if (App->blocs->structBlocActual->copiaLlocDelsBlocsStruct[0] != i && App->blocs->structBlocActual->copiaLlocDelsBlocsStruct[1] != i && App->blocs->structBlocActual->copiaLlocDelsBlocsStruct[2] != i && App->blocs->structBlocActual->copiaLlocDelsBlocsStruct[3] != i) {
				if (App->blocs->blocs[i] != nullptr)
					if (App->blocs->blocs[i]->y + (BLOC_SIZE * multipliDistancia) == this->y && App->blocs->blocs[i]->x == this->x)
						return true;
			}
		}
		break;
	case DOWN:
		if ((this->y + (BLOC_SIZE * multipliDistancia)) >= 704)
			return true;
		for (int i = 0; i < MAX_BLOCS; i++) {
			if (App->blocs->structBlocActual->copiaLlocDelsBlocsStruct[0] != i && App->blocs->structBlocActual->copiaLlocDelsBlocsStruct[1] != i && App->blocs->structBlocActual->copiaLlocDelsBlocsStruct[2] != i && App->blocs->structBlocActual->copiaLlocDelsBlocsStruct[3] != i) {
				if (App->blocs->blocs[i] != nullptr)
					if (App->blocs->blocs[i]->y - (BLOC_SIZE * multipliDistancia) == this->y && App->blocs->blocs[i]->x == this->x)
						return true;
			}
		}
		break;
	case RIGHT:
		if ((this->x + (BLOC_SIZE * multipliDistancia)) >= 768)
			return true;
		for (int i = 0; i < MAX_BLOCS; i++) {
			if (App->blocs->structBlocActual->copiaLlocDelsBlocsStruct[0] != i && App->blocs->structBlocActual->copiaLlocDelsBlocsStruct[1] != i && App->blocs->structBlocActual->copiaLlocDelsBlocsStruct[2] != i && App->blocs->structBlocActual->copiaLlocDelsBlocsStruct[3] != i) {
				if (App->blocs->blocs[i] != nullptr)
					if (App->blocs->blocs[i]->x - (BLOC_SIZE * multipliDistancia) == this->x && App->blocs->blocs[i]->y == this->y)
						return true;
			}
		}
		break;
	case LEFT:
		if ((this->x - (BLOC_SIZE * multipliDistancia)) < 256)
			return true;
		for (int i = 0; i < MAX_BLOCS; i++) {
			if (App->blocs->structBlocActual->copiaLlocDelsBlocsStruct[0] != i && App->blocs->structBlocActual->copiaLlocDelsBlocsStruct[1] != i && App->blocs->structBlocActual->copiaLlocDelsBlocsStruct[2] != i && App->blocs->structBlocActual->copiaLlocDelsBlocsStruct[3] != i) {
				if (App->blocs->blocs[i] != nullptr)
					if (App->blocs->blocs[i]->x + (BLOC_SIZE * multipliDistancia) == this->x && App->blocs->blocs[i]->y == this->y)
						return true;
			}
		}
		break;
	}
	return false;
}