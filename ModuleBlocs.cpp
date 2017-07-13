#include "Globals.h"
#include "Application.h"
#include "ModuleBlocs.h"
#include "ModuleInput.h"
#include "ModulePlayer.h"
#include "ModuleMenu.h"
#include "ModuleStructBlocs.h"
#include "SDL\include\SDL_timer.h"

bool ModuleBlocs::Init() {
	switch (tipusBlocEsteticActual) {
	case BASIC:
		texturaBlocBlau = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocBlau_basic.png");
		texturaBlocGroc = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocGroc_basic.png");
		texturaBlocLila = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocLila_basic.png");
		texturaBlocRosa = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocRosa_basic.png");
		texturaBlocVerd = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocVerd_basic.png");
		texturaBlocVermell = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocVermell_basic.png");
		texturaBlocVermellClar = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocVermellClar_basic.png");
		break;
	case CASTELLAR:
		texturaBlocBlau = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocBlau_Castellar.png");
		texturaBlocGroc = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocGroc_Castellar.png");
		texturaBlocLila = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocLila_Castellar.png");
		texturaBlocRosa = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocRosa_Castellar.png");
		texturaBlocVerd = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocVerd_Castellar.png");
		texturaBlocVermell = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocVermell_Castellar.png");
		texturaBlocVermellClar = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocVermellClar_Castellar.png");
		break;
	case CUADRAT:
		texturaBlocBlau = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocBlau_cuadrat.png");
		texturaBlocGroc = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocGroc_cuadrat.png");
		texturaBlocLila = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocLila_cuadrat.png");
		texturaBlocRosa = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocRosa_cuadrat.png");
		texturaBlocVerd = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocVerd_cuadrat.png");
		texturaBlocVermell = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocVermell_cuadrat.png");
		texturaBlocVermellClar = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocVermellClar_cuadrat.png");
		break;
	case PUR:
		texturaBlocBlau = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocBlau_Pur.png");
		texturaBlocGroc = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocGroc_Pur.png");
		texturaBlocLila = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocLila_Pur.png");
		texturaBlocRosa = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocRosa_Pur.png");
		texturaBlocVerd = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocVerd_Pur.png");
		texturaBlocVermell = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocVermell_Pur.png");
		texturaBlocVermellClar = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocVermellClar_Pur.png");
		break;
	case TRESOR:
		texturaBlocBlau = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocBlau_Tresor.png");
		texturaBlocGroc = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocGroc_Tresor.png");
		texturaBlocLila = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocLila_Tresor.png");
		texturaBlocRosa = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocRosa_Tresor.png");
		texturaBlocVerd = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocVerd_Tresor.png");
		texturaBlocVermell = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocVermell_Tresor.png");
		texturaBlocVermellClar = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocVermellClar_Tresor.png");
		break;
	}
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