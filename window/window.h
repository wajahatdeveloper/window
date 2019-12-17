#pragma once

#include "Common.h"

#define WINDOWPOS_UNDEFINED  (0x1FFF0000u|(0))

int windowX;
int windowY;
int windowWidth;
int windowHeight;
const char * windowTitle;
b32 windowOpenGL;
b32 windowFullscreen;
b32 windowShouldClose;

b32 window_init();
void window_close();
b32 window_should_close();
void window_hanlde_events();

void swapGLBuffers();