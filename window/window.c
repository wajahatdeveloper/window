// window.c : Defines the functions for the static library.

#include "window.h"

#include <SDL.h>
#include <SDL_opengl.h>
#include <gl/GLU.h>
#include <stdio.h>
#include <string.h>
#include "sds/sds.h"

SDL_Window* gWindow;
SDL_GLContext* gContext;

windowX = WINDOWPOS_UNDEFINED;
windowY = WINDOWPOS_UNDEFINED;
windowWidth = 800;
windowHeight = 600;
windowOpenGL = true;
windowFullscreen = true;

SDL_Event e;

b32 window_init()
{

	// Initialize SDL Video Subsystem
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("window module could not initialize! Error: %s\n", SDL_GetError());
		return false;
	}

	// Window Flags
	int windowFlags = 0;
	if (windowOpenGL) { windowFlags = windowFlags | SDL_WINDOW_OPENGL; }
	if (windowFullscreen) {windowFlags = windowFlags | SDL_WINDOW_FULLSCREEN;}
	windowFlags = windowFlags | SDL_WINDOW_SHOWN;

	sds sdsWindowTitle = sdsnew(windowTitle);

	// Create Window
	gWindow = SDL_CreateWindow(sdsWindowTitle, WINDOWPOS_UNDEFINED, WINDOWPOS_UNDEFINED,
		windowWidth, windowHeight, windowFlags);

	if (gWindow == NULL)
	{
		printf("window module unable to create window! Error: %s\n", SDL_GetError());
		return false;
	}

	if (windowOpenGL)
	{
		// Create Context
		gContext = SDL_GL_CreateContext(gWindow);

		if (gContext == NULL)
		{
			printf("window module OpenGL context could not be created! Error: %s\n", SDL_GetError());
			return false;
		}
	}

	return true;
	
}

void window_close()
{
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	SDL_Quit();
}

b32 window_should_close()
{
	return windowShouldClose;
}

void window_hanlde_events()
{
	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
		{
			windowShouldClose = true;
		}
	}
}

void swapGLBuffers()
{
	SDL_GL_SwapWindow(gWindow);
}
