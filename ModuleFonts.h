#ifndef __ModuleFonts_H__
#define __ModuleFonts_H__

#define MAX_FRASES 20
#define MAX_CHARS_PER_FRASE 100

#include "Module.h"

struct lletra {
public:
	int x, y, imgX = -1, frasePare;
};

struct sFrase {
public:
	int x, y, totalLletres;
	char name[10];
	char frase[MAX_CHARS_PER_FRASE];
	lletra* lletres[MAX_CHARS_PER_FRASE];
};

class ModuleFonts : public Module {
public:
	ModuleFonts(){}
	~ModuleFonts() {}
	bool Init();
	bool Update();
	void addFrase(int x, int y, char frase[MAX_CHARS_PER_FRASE], char name[10] = 0);
	void deleteFrase(char frase[MAX_CHARS_PER_FRASE]);
	char* transformNumIntoChar(int x);
private:
	int letterH, letterW, totalChars;
	char* base;
public:
	sFrase* frases[MAX_FRASES];
	// La textura textura_fonts la inicialitzo al module render perk aqui no em deixa ...
};

#endif