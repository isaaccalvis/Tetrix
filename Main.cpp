#include "Application.h"
#include "Globals.h"

#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL/lib/x86/SDL2.lib" )
#pragma comment( lib, "SDL/lib/x86/SDL2main.lib" )

enum main_states {
	MAIN_CREATION,
	MAIN_START,
	MAIN_UPDATE,
	MAIN_FINISH,
	MAIN_EXIT
};

Application* App = nullptr;

int main(int argc, char* argv[]) {
	main_states state = MAIN_CREATION;
	while (state != MAIN_EXIT) {
		switch (state) {
		case MAIN_CREATION:
			App = new Application();
			state = MAIN_START;
			break;

		case MAIN_START:
			if (App->Init() == false)
				state = MAIN_EXIT;
			else
				state = MAIN_UPDATE;
			break;

		case MAIN_UPDATE: {
			int update_return = App->Update();
			if (update_return == false)
				state = MAIN_FINISH;
		}break;
		case MAIN_FINISH:
			if (App->Finish() == true)
				return 0;
			state = MAIN_EXIT;
			break;
		}
	}
	delete App;
	return 0;
}