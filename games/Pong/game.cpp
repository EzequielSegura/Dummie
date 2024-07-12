#include <game.h>

// Resolution 640x480

void player(KeyHandler key);
void enemy();
void ball();
void backGround();

Image textImg;
int puntajePlayer = 0;
int puntajeEnemy = 0;

int xPlayer = 20;
int yPlayer = 160;
Collider colliderPlayer(xPlayer, yPlayer, 20, 150);

int xEnemy = 600;
int yEnemy = 160;
Collider colliderEnemy(xEnemy, yEnemy, 20, 150);

int speed = 8;

int xBall = 315;
int yBall = 235;
int speedX = 8;
int speedY = speedX;
Collider colliderBall(xBall, yBall, 10, 10);

bool pause = false;
int delayPause = 0;

void Game::start(){
    textImg.setFont("games/pong/font/Perfect-DOS-VGA-437.png");
}

void Game::update(){

    backGround();

    if (!pause){
        player(key);
        enemy();
        ball();
        textImg.setTextSize(40,80);
        textImg.setTextPadding(40);
        textImg.text(std::to_string(puntajePlayer), 200, 20);
        textImg.text(std::to_string(puntajeEnemy), 410, 20);
    }else{
        textImg.setTextSize(80,160);
        textImg.setTextPadding(80);
        textImg.text("pause", 120, 150);
    }
    
    if (key.keyPress(KEY_ESCAPE) && delayPause == 0) {pause = !pause; delayPause = 5;}
    if (delayPause > 0 ) delayPause--;

    fullScreen(key, window);
    frameRate(60);
}

void player(KeyHandler key){
    colliderPlayer.setPosition(xPlayer, yPlayer);

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 150; j++)
        {
            pixel(i+xPlayer, j+yPlayer, 255,255,255);
        }
    }

    //colliderPlayer.drawCollider();
        
    if (key.keyPress(KEY_DOWN))yPlayer+=speed;
    if (key.keyPress(KEY_UP))yPlayer-=speed;

    if (yPlayer<0)yPlayer=1;
    if (yPlayer>330)yPlayer=329;
}

void enemy(){
    colliderEnemy.setPosition(xEnemy, yEnemy);

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 150; j++)
        {
            pixel(i+xEnemy, j+yEnemy, 255,255,255);
        }
    }

    //colliderEnemy.drawCollider();

    if(xBall>=320 && speedX>0){    
        if (yBall>yEnemy)yEnemy+=speed;
        if (yBall<yEnemy)yEnemy-=speed;
    }

    if (yEnemy<0)yEnemy=1;
    if (yEnemy>330)yEnemy=329;
}

void ball(){
    colliderBall.setPosition(xBall-4, yBall-4);
    
    if (colliderBall.checkCollision(colliderPlayer) || colliderBall.checkCollision(colliderEnemy))
    {
        speedX*=-1;
    }
    
    //colliderBall.drawCollider();

    xBall += speedX;
    yBall += speedY;

    if (xBall<=0 || xBall>=630){
        speedX*=-1;
        if (xBall<=0) puntajeEnemy++;
        else if (xBall>=630) puntajePlayer++;
    }
    if (yBall<=0 || yBall>=470){speedY*=-1;}

    drawCircle(xBall, yBall, 4, 255,255,255);
}

void backGround(){
    for (int k = 0; k < 500; k+=40)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                pixel(i+317, j+k, 255,255,255);
            }
        }
    } 
    for (int i = 1; i <= SCR_HEIGHT; i++)pixel(1,   i, 255,255,255);
    for (int i = 1; i <= SCR_HEIGHT; i++)pixel(639, i, 255,255,255);
}