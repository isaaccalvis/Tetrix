#include "Application.h"
#include "ModuleBasicBloc.h"
#include "ModuleBlocs.h"

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

void blocBasic::moureBloc(int x, int y, posMov pos) {
	if (this->x + 32< 768 && pos == RIGHT)
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
			if (App->blocs->blocs[i] != nullptr) {
				if ((App->blocs->blocs[i]->x - 32 == this->x && App->blocs->blocs[i]->y == this->y) || this->x + 32 >= 768)
					App->blocs->structBlocActual->angleCollDet(RIGHT, true);
				else if (App->blocs->structBlocActual->retAngleColl(1) == false)
					App->blocs->structBlocActual->angleCollDet(RIGHT, false);
				if ((App->blocs->blocs[i]->x + 32 == this->x && App->blocs->blocs[i]->y == this->y) || this->x <= 256)
					App->blocs->structBlocActual->angleCollDet(LEFT, true);
				else if (App->blocs->structBlocActual->retAngleColl(2) == false)
					App->blocs->structBlocActual->angleCollDet(LEFT, false);
				if ((App->blocs->blocs[i]->y - 32 == this->y && App->blocs->blocs[i]->x == this->x) || this->y + 32 >= 704)
					App->blocs->structBlocActual->angleCollDet(DOWN, true);
				else if (App->blocs->structBlocActual->retAngleColl(0) == false)
					App->blocs->structBlocActual->angleCollDet(DOWN, false);
			}
		}
	}
}