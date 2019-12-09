#include "window/window.h"

int main()
{
	windowFullscreen = false;
	windowTitle = "new window";

	window_init();

	while (!window_should_close())
	{
		window_hanlde_events();
	}

	window_close();

	return 0;
}