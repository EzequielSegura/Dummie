#include <game.h>

// Resolution 160x120

/* Game Config */
unsigned int fps = 50;

/* Player */
void player(KeyHandler key);
double playerX = 79;
double playerY = 59;
double minSpeed = 0.2;
double speed   = minSpeed;
int playerAngle = 0;
double rotateSpeed = 2.5;

/* Scene  */
const int matrixSize = SCR_WIDTH * SCR_HEIGHT;
int sceneMatrix[matrixSize] = {0};

/* Render Image */
Image pruebaImg;
Image fondoImg;
 /* RayCast */
void rayCast();
void drawColumn(int column, int height, int color);
void calculateDistanceToWall(double rayXDir, double rayYDir, double rayAngle);

double maxDistanceToWall = 100.0;        // Define la máxima distancia al muro que se considerará
double distanceToWall = 0;              // Distancia al muro
int color = 0;                          // Color de la columna  
const double FOV = 60.0;                // Campo de vision
const int NUM_RAYS = 160;               // Numero de rayos
const double DEG_TO_RAD = 0.0174533;    // Conversion a radianes

void Game::start(){
    pruebaImg.loadImage("games/raycast/res/img/prueba1.png");
    pruebaImg.LoadPixels(sceneMatrix);

    fondoImg.loadImage("games/raycast/res/img/fondoPrueba1.png");
}

void Game::update(){
    fondoImg.showImage(0,0);

    rayCast();

    player(key);
    fullScreen(key, window);
    
    /* Control the framerate */
    frameRate(fps);
    
}

void normalizeAngle() {
    if (playerAngle >= 360) {
        playerAngle -= 360;
    } else if (playerAngle < 0) {
        playerAngle += 360;
    }
}

void rotatePlayer(int rotation) {
    playerAngle += rotation;
    normalizeAngle();
}

void player(KeyHandler key){
    // Render

    // Mover
    if (key.keyPress(KEY_UP))   {
    playerX += speed * (cos(playerAngle * DEG_TO_RAD));
    playerY += speed * (sin(playerAngle * DEG_TO_RAD));
    }
    if (key.keyPress(KEY_DOWN)) {
    playerX -= speed * (cos(playerAngle * DEG_TO_RAD));
    playerY -= speed * (sin(playerAngle * DEG_TO_RAD));
    }

    // Rotar la camara
    if (key.keyPress(KEY_RIGHT)){rotatePlayer(rotateSpeed);}
    if (key.keyPress(KEY_LEFT)) {rotatePlayer(-rotateSpeed);} 

    // Correr
    if (key.keyPress(KEY_LEFT_SHIFT)){speed = minSpeed * 1.5;}
    else {speed = minSpeed;}
}

void rayCast() {
    for (int i = 0; i < NUM_RAYS; ++i) {
        double rayAngle = playerAngle - (FOV / 2) + (i * (FOV / NUM_RAYS));
        double rayXDir = cos(rayAngle * DEG_TO_RAD);
        double rayYDir = sin(rayAngle * DEG_TO_RAD);

        // Código para calcular la distancia al muro y el color
        calculateDistanceToWall(rayXDir, rayYDir, rayAngle);

        // Calcula la altura de la pared en pantalla en función de la distancia al muro
        int wallHeight = static_cast<int>(SCR_HEIGHT / distanceToWall);

        // Dibuja la columna correspondiente con la altura de la pared
        drawColumn(i, wallHeight, color);
    }
}

void drawColumn(int column, int height, int color) {
    // Itera sobre la altura de la pantalla y dibuja la columna en la posición 'column' con 'height' píxeles
    for (int y = 0; y < SCR_HEIGHT; ++y) {
        if (y < (SCR_HEIGHT - height) / 2 || y >= (SCR_HEIGHT + height) / 2) {
        } else {
            // Dibuja la pared
            if (distanceToWall<=maxDistanceToWall){
                int r, g, b;
                pruebaImg.HexToRGB(color, r, g, b);
                pixel(column, y, r, g, b);
            }
        }
    }   
}

void calculateDistanceToWall(double rayXDir, double rayYDir, double rayAngle){
    double posX = playerX;
    double posY = playerY;
    double stepSize = 0.01; 
    distanceToWall = 0;

    double angle = fmod(rayAngle, 360.0);
    if (angle < 0) {
        angle += 360.0;
    }

    double angleRad = angle * DEG_TO_RAD;
    rayXDir = cos(angleRad);
    rayYDir = sin(angleRad);

    while (distanceToWall < maxDistanceToWall) {
        posX += rayXDir * stepSize;
        posY += rayYDir * stepSize;

        int mapX = static_cast<int>(posX);
        int mapY = static_cast<int>(posY);

        if (mapX >= 0 && mapX < SCR_WIDTH && mapY >= 0 && mapY < SCR_HEIGHT) {
            if (sceneMatrix[mapY * SCR_WIDTH + mapX] != 0) {
                color = sceneMatrix[mapY * SCR_WIDTH + mapX];
                distanceToWall = sqrt((posX - playerX) * (posX - playerX) + (posY - playerY) * (posY - playerY));
                break;
            }
        }
        distanceToWall += stepSize;
    }
}

