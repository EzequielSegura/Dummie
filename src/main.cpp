#include <GLFW/glfw3.h>
#include <game.h>

int main(void)
{
    GLFWwindow* window;

    /* Initialize glfw */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = displayMode(0);
    
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Manually call framebuffer_size_callback at the beginning to ensure initial adjustment
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    framebuffer_size_callback(window, width, height);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Configurate the matrix projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, SCR_WIDTH, SCR_HEIGHT, 0, -1, 1);

    /* Make the Game object and initialize*/
    Game game(window);
    game.start();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        cleanScreen();

        /* Game update */
        game.update();
        
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}