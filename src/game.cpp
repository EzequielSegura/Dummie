#include <game.h>

// Map whit perlin noise 
// Resolution 640x480

int tileSize = 10;

Color colorAzul = Color(0, 0, 255);
Color colorVerde = Color(0, 255, 0);

Image perlinNoise;
const int matrixSize = SCR_WIDTH * SCR_HEIGHT;
int imageMatrix[matrixSize] = {0};

void drawnTile(int x, int y, Color color){
    for (int i = 0; i < tileSize; i++)
    {
        for (int j = 0; j < tileSize; j++)
        {
            pixel(i + (x*tileSize), j + (y*tileSize), color.r, color.g, color.b);
        }   
    }
}

void Game::start(){
    perlinNoise.loadImage("games/MapWithPerlinNoise/PerlinNoise.png");
    perlinNoise.LoadPixels(imageMatrix);
}

void Game::update(){
    for (int i = 0; i < SCR_WIDTH/tileSize; i++)
    {
        for (int j = 0; j < SCR_HEIGHT/tileSize; j++)
        {
            if (imageMatrix[j * SCR_WIDTH + i] > 100){
                int r, g, b;
                int color = imageMatrix[j * SCR_WIDTH + i];
                perlinNoise.HexToRGB(color, r, g, b);
                pixel(i, j, r, g, b);
                //drawnTile(i, j, colorAzul);
            }else{
                drawnTile(i, j, colorVerde);
            }
        }
    }   
}
