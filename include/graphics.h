#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <glfw/glfw3.h>
#include <windows.h>
#include <iostream>
#include <vector>

/* To use key inputs */
#include <keyHandler.h>

#define TITLE                       "Game"
#define SCR_WIDTH                   640 
#define SCR_HEIGHT                  480
#define ORIGINAL_ASPECT_RATIO       (4.0f / 3.0f)

void pixel(int x, int y, int r, int g, int b);

void drawCircle(int x, int y, int radius, int r, int g, int b);
void drawLine(int x1, int y1, int x2, int y2, int r, int g, int b);

void frameRate(int frames);

GLFWwindow* displayMode(int modeScreen);
void fullScreen(KeyHandler key, GLFWwindow* &window);
void changeDisplayMode(GLFWwindow* &window, int modeScreen);
void cleanScreen();
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

#endif