#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleBlocs.h"

bool ModulePlayer::Init() { return true; }
bool ModulePlayer::Update(){
	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
		App->blocs->structBlocActual->moureStruct(UP);
	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
		App->blocs->structBlocActual->moureStruct(DOWN);
	if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
		App->blocs->structBlocActual->moureStruct(RIGHT);
	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
		App->blocs->structBlocActual->moureStruct(LEFT);
	return true;
}
bool ModulePlayer::Finish() { return true; }