#include "application.h"

#define RAYGUI_IMPLEMENTATION

int main() {
	application = new Application;
	application->Initialize();
	application->Loop();
	delete application;
	return 0;
}