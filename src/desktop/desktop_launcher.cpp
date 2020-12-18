#define SDL_MAIN_HANDLED
#include "../utils/include/configuration.h"
#include "../utils/include/application.h"
#include "../core/include/duckhunt.h"


int main(int argc, char* args[]) {
    SDL_SetMainReady();
	Configuration* config = new Configuration("DuckHunt", 980, 640);

	Application(new DuckHunt(), config);
	return 0;
}