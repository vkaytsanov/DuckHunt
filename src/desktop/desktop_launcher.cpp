#include "../utils/include/configuration.h"
#include "../utils/include/application.h"
#include "../duckhunt.h"


int main(int argc, char* args[]) {
	Configuration* config = new Configuration("DuckHunt", 980, 640);

	Application(new DuckHunt(), config);
	return 0;
}