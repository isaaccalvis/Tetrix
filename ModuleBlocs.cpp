#include "Globals.h"
#include "Application.h"
#include "ModuleBlocs.h"

ModuleBlocs::ModuleBlocs(){}
ModuleBlocs::~ModuleBlocs(){}

bool ModuleBlocs::Init() {
	texturaBlocBlau = App->render->newTexture("Resources/Sprites/blocBlau_mitja.png");
	for (int i = 0; i < MAX_BLOCS; i++)
		blocs[i] = nullptr;
	CreateBlocSimple();
	return true;
}

bool ModuleBlocs::Update() {
	for (int i = 0; i < MAX_BLOCS; i++) {
		if (blocs[i] != nullptr)
			blocs[i]->pintarBlocs();
	}
	return true;
}

bool ModuleBlocs::Finish() {

	return true;
}

bool ModuleBlocs::CreateBlocSimple(){
	for (int i = 0; i < MAX_BLOCS; i++) {
		if (blocs[i] == nullptr) {
			blocs[i] = new blocBasic(blau, 0, 0);
			i = MAX_BLOCS;
		}
	}
	return true;
}

bool ModuleBlocs::CreateBlocEstructure() {

	return true;
}

void blocBasic::pintarBlocs() {
	if (App->blocs->texturaBlocBlau != nullptr)
		App->render->Blit(App->blocs->texturaBlocBlau, x, y, &App->blocs->rectBlocPerTextura);
}