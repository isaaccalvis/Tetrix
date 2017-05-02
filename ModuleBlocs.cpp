#include "Globals.h"
#include "Application.h"
#include "ModuleBlocs.h"

ModuleBlocs::ModuleBlocs() {}
ModuleBlocs::~ModuleBlocs(){}

bool ModuleBlocs::Init() {
	texturaBlocBlau = App->render->newTexture("Resources/Sprites/bloc0.png");

	return true;
}

bool ModuleBlocs::Update() {

	return true;
}

bool ModuleBlocs::Finish() {

	return true;
}

bool ModuleBlocs::CreateBlocEstructure() {

	return true;
}

void blocBasic::pintarBlocs() {
	//App->render->Blit(texturaBlocBlau, x, y, { 0,0,16,16 });
}