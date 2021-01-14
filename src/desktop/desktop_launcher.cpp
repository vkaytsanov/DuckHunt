
#include "../lib/include/configuration.h"
#include "../lib/include/application.h"
#include "../core/include/duckhunt.h"

int main(int argc, char* args[]) {
	auto* config = new Configuration("DuckHunt", 980, 600);

	auto* app = new Application(new DuckHunt(), config);

	delete app;
	return 0;
}