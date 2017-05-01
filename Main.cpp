#include "SDL\include\SDL.h"
#pragma comment( lib, "SDL/lib/x86/SDL2.lib" )
#pragma comment(lib, "SDL/lib/x86/SDL2main.lib")
#include "Application.h"
#include "Globals.h"

Application* App;

int main(int argc, char* argv[]) {
	// Creacio
	int in_Game = true;
	App = new Application;
	if (App->Init() == false)
		in_Game = false;
	// Update
	while (in_Game == true) {
		bool update_return = App->Update();
		if (update_return == false)
			in_Game = false;
	}
	// Finish
	if (App->Finish() == false)
		print("Error al tancar");
	delete App;
	printf_s("Joc Tancat\n");
	system("pause");
	return 0;
}