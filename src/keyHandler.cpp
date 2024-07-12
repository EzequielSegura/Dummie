#include <keyHandler.h>

bool KeyHandler::keyPress(int key) {
    if (glfwGetKey(window, key) == GLFW_PRESS) return true;
    else return false;
}

bool KeyHandler::keyUp(int key) {
    if (glfwGetKey(window, key) == GLFW_RELEASE) return true;
    else return false;
}