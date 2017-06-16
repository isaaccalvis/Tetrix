#include "Application.h"
#include "ModuleRender.h"
#include "ModuleBackground.h"

bool ModuleBackground::Init() {
	texturaFons = App->render->newTexture("Resources/Sprites/fonsPantalla.png");
	tamanyPantalla = { 0,0,768,720 };
	return true;
}

bool ModuleBackground::Update() {
	App->render->Blit(texturaFons, 0, 0, &tamanyPantalla);
	return true;
}

bool ModuleBackground::Finish() {
	return true;
}