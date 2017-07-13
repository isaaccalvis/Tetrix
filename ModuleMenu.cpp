#include "Application.h"
#include "Globals.h"
#include "ModuleMenu.h"
#include "ModuleBackground.h"
#include "ModuleBlocs.h"
#include "ModuleBasicBloc.h"

bool ModuleMenu::Init() {
	App->background->Disable();
	App->blocs->Disable();
	sprite_fonsMenu = App->render->newTexture("Resources/Sprites/BackGrounds/fonsMenu.png");
	sprite_Play = App->render->newTexture("Resources/Sprites/MenuButtons/startButtonYes.png");
	sprite_PlayNo = App->render->newTexture("Resources/Sprites/MenuButtons/startButtonNo.png");
	sprite_Arcade = App->render->newTexture("Resources/Sprites/MenuButtons/arcadeButtonYes.png");
	sprite_ArcadeNo = App->render->newTexture("Resources/Sprites/MenuButtons/arcadeButtonNo.png");
	sprite_Configuration = App->render->newTexture("Resources/Sprites/MenuButtons/optionsButtonYes.png");
	sprite_ConfigurationNo = App->render->newTexture("Resources/Sprites/MenuButtons/optionsButtonNo.png");
	sprite_Exit = App->render->newTexture("Resources/Sprites/MenuButtons/exitButtonYes.png");
	sprite_ExitNo = App->render->newTexture("Resources/Sprites/MenuButtons/exitButtonNo.png");
	sprite_SelectorSprite = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocExtres/iconoSelectorBloc.png");
	sprite_MostraBlocs = App->render->newTexture("Resources/Sprites/SpriteBlocs/blocExtres/mostraBlocs.png");
	App->render->newSmallAnimation(sprite_fonsMenu, 0, 0, &rectTamanyPantalla, 100, 3);
	posicioEnMenu = 0;
	return true;
}

bool ModuleMenu::Update() {
	switch (posicioEnMenu) {
	case 0:
		App->render->Blit(sprite_Play, SCREEN_WIDTH / 2 - 128, 150, &rectTamanyIconesMenu);
		App->render->Blit(sprite_ArcadeNo, SCREEN_WIDTH / 2 - 128, 250, &rectTamanyIconesMenu);
		App->render->Blit(sprite_ConfigurationNo, SCREEN_WIDTH / 2 - 128, 350, &rectTamanyIconesMenu);
		App->render->Blit(sprite_ExitNo, SCREEN_WIDTH / 2 - 128, 450, &rectTamanyIconesMenu);
		break;
	case 1:
		App->render->Blit(sprite_PlayNo, SCREEN_WIDTH / 2 - 128, 150, &rectTamanyIconesMenu);
		App->render->Blit(sprite_Arcade, SCREEN_WIDTH / 2 - 128, 250, &rectTamanyIconesMenu);
		App->render->Blit(sprite_ConfigurationNo, SCREEN_WIDTH / 2 - 128, 350, &rectTamanyIconesMenu);
		App->render->Blit(sprite_ExitNo, SCREEN_WIDTH / 2 - 128, 450, &rectTamanyIconesMenu);
		break;
	case 2:
		App->render->Blit(sprite_PlayNo, SCREEN_WIDTH / 2 - 128, 150, &rectTamanyIconesMenu);
		App->render->Blit(sprite_ArcadeNo, SCREEN_WIDTH / 2 - 128, 250, &rectTamanyIconesMenu);
		App->render->Blit(sprite_Configuration, SCREEN_WIDTH / 2 - 128, 350, &rectTamanyIconesMenu);
		App->render->Blit(sprite_ExitNo, SCREEN_WIDTH / 2 - 128, 450, &rectTamanyIconesMenu);
		break;
	case 3:
		App->render->Blit(sprite_PlayNo, SCREEN_WIDTH / 2 - 128, 150, &rectTamanyIconesMenu);
		App->render->Blit(sprite_ArcadeNo, SCREEN_WIDTH / 2 - 128, 250, &rectTamanyIconesMenu);
		App->render->Blit(sprite_ConfigurationNo, SCREEN_WIDTH / 2 - 128, 350, &rectTamanyIconesMenu);
		App->render->Blit(sprite_Exit, SCREEN_WIDTH / 2 - 128, 450, &rectTamanyIconesMenu);
		break;
	case 4:	// Aqui es en mode Options
		App->render->Blit(sprite_PlayNo, SCREEN_WIDTH / 2 - 128, 150, &rectTamanyIconesMenu);
		App->render->Blit(sprite_ArcadeNo, SCREEN_WIDTH / 2 - 128, 250, &rectTamanyIconesMenu);
		App->render->Blit(sprite_ConfigurationNo, SCREEN_WIDTH / 2 - 128, 350, &rectTamanyIconesMenu);
		App->render->Blit(sprite_ExitNo, SCREEN_WIDTH / 2 - 128, 450, &rectTamanyIconesMenu);
		App->render->Blit(sprite_MostraBlocs, (SCREEN_WIDTH / 3) + 25, 555, &rectTamanyMostraBlocs);
		App->render->Blit(sprite_SelectorSprite, (SCREEN_WIDTH / 3) + 20 + posicioSelectorBlocsOptions * 40 + posicioSelectorBlocsOptions * 2, 550, &rectTamanySelectorIcones);
		break;
	}
	return true;
}

bool ModuleMenu::Finish() {
	App->render->Unload(sprite_fonsMenu);
	App->render->Unload(sprite_Play);
	App->render->Unload(sprite_PlayNo);
	App->render->Unload(sprite_Configuration);
	App->render->Unload(sprite_ConfigurationNo);
	App->render->Unload(sprite_Exit);
	App->render->Unload(sprite_ExitNo);

	App->background->Enable();
	App->blocs->Enable();
	return true;
}

void ModuleMenu::startGame() {
	App->render->deleteSmallAnimation(sprite_fonsMenu);
	Disable();
}