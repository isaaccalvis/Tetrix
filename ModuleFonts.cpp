#include <string>
#include "Application.h"
#include "Globals.h"
#include "ModuleFonts.h"
#include "ModuleRender.h"

bool ModuleFonts::Init() {
	App->render->textura_fonts = App->render->newTexture("Resources/Sprites/tetrix_Font.png");
	letterW = 8;
	letterH = 8;
	base = "abcdefghijklmnopqrstuvwxyz123456789- *";
	totalChars = 0;
	while (base[totalChars] != '\0') {
		totalChars++;
	}
	return true;
}

bool ModuleFonts::Update() {
	for (int i = 0; i < MAX_FRASES; i++) {
		if (frases[i] != nullptr) {
			int posXactual = frases[i]->x;
			SDL_Rect rectBase = { 0,0,letterW,letterH };
			for (int v = 0; v < frases[i]->totalLletres; v++) {
				rectBase.x = frases[i]->lletres[v]->imgX;
				App->render->Blit(App->render->textura_fonts, posXactual, frases[i]->y, &rectBase);
				posXactual += letterW;
			}
		}
	}
	return true;
}

void ModuleFonts::addFrase(int x, int y, char frase[MAX_CHARS_PER_FRASE], char name[10]){
	int newX = x, newY = y;		
	for (int i = 0; i < MAX_FRASES; i++) {
		if (frases[i] == nullptr) {
			frases[i] = new sFrase;
			if (name != 0)
				for (int q = 0; q < 10; q++)
					frases[i]->name[q] = name[q];
			for (int z = 0; z < MAX_CHARS_PER_FRASE; z++)
				frases[i]->lletres[z] = nullptr;
			for (int q = 0; q < MAX_CHARS_PER_FRASE; q++) {
				if (frase[q] == '\0') {
					frases[i]->frase[q] = '\0';
					q = MAX_CHARS_PER_FRASE;
				}
				else
					frases[i]->frase[q] = frase[q];
			}
			frases[i]->x = x;
			frases[i]->y = y;
			frases[i]->totalLletres = 0;
			for (int v = 0; v < MAX_CHARS_PER_FRASE; v++) {
				if (frase[v] != '\0') {
					frases[i]->totalLletres++;
					frases[i]->lletres[v] = new lletra;
					frases[i]->lletres[v]->frasePare = i;
					frases[i]->lletres[v]->x = x;
					x += letterW;
					frases[i]->lletres[v]->y = y;
					int thisX = 0;
					for (int p = 0; p < totalChars; p++) {
						if (frase[v] == base[p]) {
							p = totalChars;
							frases[i]->lletres[v]->imgX = thisX;
						}
						else {
							thisX += letterW;
						}
					}
				}
				else {
					v = MAX_CHARS_PER_FRASE;
				}
			}
			i = MAX_FRASES;
		}
	}
}

void ModuleFonts::deleteFrase(char frase[MAX_CHARS_PER_FRASE]) {
	for (int i = 0; i < MAX_FRASES; i++)
		if (frases[i] != nullptr) {
			bool sonIguals = true;
			for (int v = 0; frase[v] != '\0'; v++) {
				if (frases[i]->frase[v] != frase[v])
					sonIguals = false;
			}
			if (sonIguals == false) {
				sonIguals = true;
				for (int q = 0; q < 10; q++)
					if (frases[i]->name[q] != frase[q])
						sonIguals = false;
			}
			if (sonIguals == true) {
				for (int v = 0; v < MAX_CHARS_PER_FRASE; v++)
					if (frases[i]->lletres[v] != nullptr) {
						delete frases[i]->lletres[v];
						frases[i]->lletres[v] = nullptr;
					}
				delete frases[i];
				frases[i] = nullptr;
			}
		}
}

char* ModuleFonts::transformNumIntoChar(int x) {
	std::string s = std::to_string(x);
	char const *pchar = s.c_str();
	print("%s", (char*)pchar);
	return (char*)pchar;
}