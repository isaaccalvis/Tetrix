#include "Globals.h"
#include "Application.h"
#include "ModuleBlocs.h"
#include "ModuleInput.h"
#include "ModulePlayer.h"
#include "ModuleMenu.h"
#include "ModuleStructBlocs.h"
#include "SDL\include\SDL_timer.h"

bool ModuleBlocs::Init() {
	texturaBlocBlau = App->render->newTexture("Resources/Sprites/blocBlau_mitja.png");
	texturaBlocGroc = App->render->newTexture("Resources/Sprites/blocGroc_mitja.png");
	texturaBlocLila = App->render->newTexture("Resources/Sprites/blocLila_mitja.png");
	texturaBlocRosa = App->render->newTexture("Resources/Sprites/blocRosa_mitja.png");
	texturaBlocVerd = App->render->newTexture("Resources/Sprites/blocVerd_mitja.png");
	texturaBlocVermell = App->render->newTexture("Resources/Sprites/blocVermell_mitja.png");
	texturaBlocVermellClar = App->render->newTexture("Resources/Sprites/blocVermellClar_mitja.png");

	for (int i = 0; i < MAX_BLOCS; i++)
		blocs[i] = nullptr;
	nextStruct = formaStructBloc(App->getRamdomValue(7) + 1);
	return true;
}

bool ModuleBlocs::Update() {
	for (int i = 0; i < MAX_BLOCS; i++) {
		if (blocs[i] != nullptr)
			blocs[i]->pintarBloc();
	}

	// REFRESH STRUCTURES ( THE PLAYING ONE )
	if (structBlocActual == nullptr) {
		structBlocActual = new blocStruct(nextStruct, colorBlocs((int)nextStruct), 384, 0);
		nextStruct = formaStructBloc(App->getRamdomValue(7) + 1);
		structBlocSeguent = new blocStruct(nextStruct, colorBlocs((int)nextStruct), 95, 90);

	}
	else {
		for (int i = 0; i < 16; i++)
			if (App->blocs->structBlocActual->comprobarPosBloc(i * 32, 0))
				if (App->blocs->structBlocActual->retAngleColl(0) == true)
					gameOver();
		structBlocActual->normalFall();
	}
	return true;
}

bool ModuleBlocs::Finish() {
	for (int i = 0; i < MAX_BLOCS; i++) {
		if (App->blocs->blocs[i] != nullptr) {
			delete  App->blocs->blocs[i]; // vigila, que no estas fent viu = false, l'elimino directament
			App->blocs->blocs[i] = nullptr;
		}
	}
	App->blocs->structBlocActual = nullptr;
	App->blocs->structBlocSeguent = nullptr;

	App->render->Unload(texturaBlocBlau);
	App->render->Unload(texturaBlocGroc);
	App->render->Unload(texturaBlocLila);
	App->render->Unload(texturaBlocRosa);
	App->render->Unload(texturaBlocVerd);
	App->render->Unload(texturaBlocVermell);
	App->render->Unload(texturaBlocVermellClar);

	return true;
}

void ModuleBlocs::netejaBlocsMorts() {
	for (int i = 0; i < MAX_BLOCS; i++) {
		if (blocs[i] != nullptr && blocs[i]->estaViu() == false) {	// elimina blocs si esta mort
			delete blocs[i];
			blocs[i] = nullptr;
		}
	}
}

void ModuleBlocs::gameOver() {
	App->menu->Enable();
}