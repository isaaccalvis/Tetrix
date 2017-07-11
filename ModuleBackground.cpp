#include "Application.h"
#include "ModuleRender.h"
#include "ModuleBackground.h"
#include "ModuleFonts.h"

bool ModuleBackground::Init() {
	texturaFons = App->render->newTexture("Resources/Sprites/fonsPantalla.png");
	App->fonts->deleteFrase("puntuacio");
	App->fonts->addFrase(15, 500, "puntuacio");
	tamanyPantalla = { 0,0,768,720 };
	return true;
}

bool ModuleBackground::Update() {
	App->render->Blit(texturaFons, 0, 0, &tamanyPantalla);
	return true;
}

bool ModuleBackground::Finish() {
	App->render->Unload(texturaFons);
	return true;
}