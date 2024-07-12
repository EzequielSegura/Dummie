#ifndef GAME_H
#define GAME_H
/* Basic includes */
#include <iostream>

/* Load game elements */
#include <keyHandler.h>
#include <graphics.h>
#include <collider.h>
#include <color.h>
#include <image.h>

class Game
{
private:
    GLFWwindow *window;
    KeyHandler key;

public:
    Game(GLFWwindow *win) : window(win), key(win) {}
    void start();
    void update();
};
#endif