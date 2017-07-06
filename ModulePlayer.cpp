#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleBlocs.h"
#include "ModuleMenu.h"

bool ModulePlayer::Init() {
	puntuacio = 0;
	return true;
}
bool ModulePlayer::Update(){
	if (App->blocs->IsEnabled()) {
		if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_DOWN)
			App->blocs->structBlocActual->moureStruct(UP);
		if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
			App->blocs->structBlocActual->moureStruct(DOWN);
		if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_DOWN)
			App->blocs->structBlocActual->moureStruct(RIGHT);
		if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_DOWN)
			App->blocs->structBlocActual->moureStruct(LEFT);
		if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
			App->blocs->structBlocActual->rotarStruct();
		if (App->input->keyboard[SDL_SCANCODE_M] == KEY_STATE::KEY_DOWN || App->input->keyboard[SDL_SCANCODE_ESCAPE] == KEY_STATE::KEY_DOWN)
			App->menu->Enable();
	}
	else if (App->menu->IsEnabled()) {
		if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN) {
			switch (App->menu->posicioEnMenu) {
			case 0:
				print("Historia\n");
				break;
			case 1:
				App->menu->startGame();
				break;
			case 2:
				print("options\n");
				break;
			case 3:
				return false;
				break;
			}
		}
		if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_DOWN) {
			App->menu->posicioEnMenu--;
			if (App->menu->posicioEnMenu < 0)
				App->menu->posicioEnMenu = 3;
		}
		if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_DOWN) {
			App->menu->posicioEnMenu++;
			if (App->menu->posicioEnMenu > 3)
				App->menu->posicioEnMenu = 0;
		}
		if (App->input->keyboard[SDL_SCANCODE_ESCAPE] == KEY_STATE::KEY_DOWN)
			return false;
	}
	return true;
}
bool ModulePlayer::Finish() { return true; }