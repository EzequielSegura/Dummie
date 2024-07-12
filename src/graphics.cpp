#include <graphics.h>

/* Screen mode */
void fullScreen(KeyHandler key, GLFWwindow* &window);
bool isFullScreen = false;
int  screenChanged = 5;

/* Pixels */
int pixelSize = 0;

// Put a pixel with RGB value
void pixel(int x, int y, int r, int g, int b){
    // Set pixel color
    glColor3ub(r,g,b); 

    // Pixel size
    glPointSize(pixelSize);

    // Drawn the pixel in the coordinate
    glBegin(GL_POINTS);
    glVertex2d(x, y);
    glEnd();
}

// Drawn a circle with RGB value
void drawCircle(int x, int y, int radius, int r, int g, int b) {
    int p0 = 1 - radius;
    int x_val = 0;
    int y_val = radius;

    while (x_val <= y_val) {
        pixel(x + x_val, y + y_val, r, g, b);
        pixel(x - x_val, y + y_val, r, g, b);
        pixel(x + x_val, y - y_val, r, g, b);
        pixel(x - x_val, y - y_val, r, g, b);
        pixel(x + y_val, y + x_val, r, g, b);
        pixel(x - y_val, y + x_val, r, g, b);
        pixel(x + y_val, y - x_val, r, g, b);
        pixel(x - y_val, y - x_val, r, g, b);

        if (p0 < 0) {
            p0 += 2 * x_val + 3;
        } else {
            p0 += 2 * (x_val - y_val) + 5;
            y_val--;
        }
        x_val++;
    }
}

// Drawn a line with RGB value
void drawLine(int x1, int y1, int x2, int y2, int r, int g, int b) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;

    while (x1 != x2 || y1 != y2) {
        pixel(x1, y1, r, g, b);
        
        int err2 = 2 * err;
        
        if (err2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        
        if (err2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
    pixel(x2, y2, r, g, b);
}

// Set a frame rate
void frameRate(int frames){
    int fps = 1000/frames;
    Sleep(fps);
}

// Set the display mode
GLFWwindow* displayMode(int modeScreen){
    GLFWwindow* window;
    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    if (modeScreen == 0) {
        window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, TITLE, NULL, NULL);
    } else if (modeScreen == 1) {
        window = glfwCreateWindow(mode->width, mode->height, TITLE, glfwGetPrimaryMonitor(), NULL);
    } else if (modeScreen == 2) {
        window = glfwCreateWindow(mode->width, mode->height, TITLE, NULL, NULL);
    }else {
        window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, TITLE, NULL, NULL);
    }
    return window;
}

 // Change the screen mode with a key input
void fullScreen(KeyHandler key, GLFWwindow* &window){
    if(key.keyPress(KEY_LEFT_ALT) && key.keyPress(KEY_ENTER) && screenChanged >= 10){
        if(!isFullScreen){
            changeDisplayMode(window, 1);
            isFullScreen = !isFullScreen;
            screenChanged = 0;
        }else{
            changeDisplayMode(window, 0);
            isFullScreen = !isFullScreen;
            screenChanged = 0;
        }
    }
    // Set a delay to change the display mode
    screenChanged++;
    if(screenChanged>10){
        screenChanged = 10;
    }
}

// Change the display mode
void changeDisplayMode(GLFWwindow* &window, int modeScreen) {
    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

    if (modeScreen == 0) {
        glfwSetWindowMonitor(window, NULL, (mode->width/2)-(SCR_WIDTH/2), (mode->height/2)-(SCR_HEIGHT/2), SCR_WIDTH, SCR_HEIGHT, GLFW_DONT_CARE);
    } else if (modeScreen == 1) {
        glfwSetWindowMonitor(window, glfwGetPrimaryMonitor(), 0, 0, mode->width, mode->height, mode->refreshRate);
    } else if (modeScreen == 2) {
        glfwSetWindowMonitor(window, NULL, 0, 30, mode->width, mode->height, GLFW_DONT_CARE);
    } else {
        glfwSetWindowMonitor(window, NULL, (mode->width/2)-(SCR_WIDTH/2), (mode->height/2)-(SCR_HEIGHT/2), SCR_WIDTH, SCR_HEIGHT, GLFW_DONT_CARE);
    }
}

// Clear the display
void cleanScreen(){
    glClear(GL_COLOR_BUFFER_BIT);
}

//  Change the viewport when the window change
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // Calculate the current aspect ratio
    float currentAspectRatio = static_cast<float>(width) / static_cast<float>(height);
    int newWidth, newHeight, xOffset, yOffset;

    if (currentAspectRatio > ORIGINAL_ASPECT_RATIO) {
        // The window is wider than the original aspect ratio
        newHeight = height;
        newWidth = static_cast<int>(height * ORIGINAL_ASPECT_RATIO + 0.5f);
        xOffset = (width - newWidth) / 2;
        yOffset = 0;
    } else {
        // The window is taller or has the same aspect as the original
        newWidth = width;
        newHeight = static_cast<int>(width / ORIGINAL_ASPECT_RATIO + 0.5f);
        xOffset = 0;
        yOffset = (height - newHeight) / 2;
    }
    // Set the area of the window where the scene is rendered
    glViewport(xOffset, yOffset, newWidth, newHeight);

    // Calculate the pixel size
    if (ORIGINAL_ASPECT_RATIO > 1){pixelSize = (newWidth/SCR_WIDTH)+1;}
    if (ORIGINAL_ASPECT_RATIO < 1){pixelSize = (newHeight/SCR_HEIGHT)+1;}
}