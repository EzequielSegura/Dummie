#include <game.h>

// Resolution 320x240 

/* Game Config */
unsigned int fps = 60;

/* Level */
Image backGroundImg;
Image textImg;

/* Player */
int playerX = 110;
int playerY = 180;
double speed = 3;
bool slowMove = false;
Collider colliderPlayer(playerX, playerY, 10, 16);
Image playerImg;
void player(KeyHandler key);

/* Enemy */
int enemyX = 112;
int enemyY = 40;
Collider colliderEnemy(enemyX, enemyY, 9, 13);
Image enemyImg;
void enemy();

/* Score */
unsigned int hiScore = 0;
unsigned int score = 0;

/* Animations */
// Player
bool p_idleAnim = true;
bool p_leftAnim = false;
bool p_rightAnim = false;
int  p_animationNumber = 0;
int p_frameRateAnimation = 6;
int p_frameIndex = 0;
int p_framePosition = 0;

bool e_idleAnim = true;
int e_frameRateAnimation = 6;
int e_frameIndex = 0;
int e_framePosition = 0;

void animations();

void Game::start(){
    backGroundImg.loadImage("games/BulletHell/res/img/fondo.png");
    textImg.setFont("games/BulletHell/res/fonts/Perfect-DOS-VGA-437.png");
    playerImg.loadImage("games/BulletHell/res/img/characterTiles.png");
    enemyImg.loadImage("games/BulletHell/res/img/enemyTiles.png");
}

void Game::update(){
    /* Background */
    backGroundImg.showImage(20,20);

    /* Text */
    textImg.setTextSize(8,16);
    textImg.setTextPadding(9);
    textImg.text("hiscore "+std::to_string(hiScore), 205, 20);
    textImg.text("score   "+std::to_string(score), 205, 40);
    textImg.text("lives   "+std::to_string(3), 205, 60);
    textImg.text("power   "+std::to_string(100)+"%", 205, 80);

    /* Game objects */
    enemy();
    player(key);

    animations();

    /*  Game Control */
    fullScreen(key, window);
    frameRate(fps);
}

void player(KeyHandler key){
    playerImg.showPartialImageScaled(playerX,playerY,p_framePosition,p_animationNumber,32,48,16,24);
    if(slowMove){
        colliderPlayer.drawCollider(255,255,255);
    }

    /* Move */
    if (key.keyPress(KEY_UP)){playerY-=speed;}
    if (key.keyPress(KEY_DOWN)){playerY+=speed;}
    if (key.keyPress(KEY_LEFT)){
        p_idleAnim = false;
        p_rightAnim = false;
        p_leftAnim = true;
        playerX-=speed;
    }
    if (key.keyPress(KEY_RIGHT)){
        p_idleAnim = false;
        p_rightAnim = true;
        p_leftAnim = false;
        playerX+=speed;
    }
    if (!key.keyPress(KEY_RIGHT) && !(key.keyPress(KEY_LEFT)) || key.keyPress(KEY_RIGHT) && (key.keyPress(KEY_LEFT))){
        p_idleAnim = true;
        p_rightAnim = false;
        p_leftAnim = false;
    }

    /* Slow */
    if (key.keyPress(KEY_LEFT_SHIFT)){
        colliderPlayer.setSize(2,2);
        colliderPlayer.setPosition(playerX+6, playerY+14);
        slowMove = true;
        speed = 1;
        }
    else {
        colliderPlayer.setSize(10,16);
        colliderPlayer.setPosition(playerX+2, playerY+4);
        slowMove = false;
        speed = 3;
        }

    /* Limit */
    if(playerX<20)playerX = 20;
    if(playerX>187)playerX = 187;
    if(playerY<20)playerY = 20;
    if(playerY>196)playerY = 196;
}

void enemy(){
    enemyImg.showPartialImageScaled(enemyX, enemyY, e_framePosition, 0, 19, 27, 9, 13);
}

void animations(){
    /* Player */
    if (p_idleAnim){
        p_animationNumber = 0;
        if (p_frameIndex == p_frameRateAnimation)p_framePosition+=32;
        p_frameIndex++;
        if (p_frameIndex > p_frameRateAnimation)p_frameIndex = 0;
        if (p_framePosition>224){p_framePosition=0;}
    }else if (p_leftAnim){
        p_framePosition = 224;
        p_animationNumber = 48;
    }else if (p_rightAnim){
        p_framePosition = 224;
        p_animationNumber = 96;
    }

    /* enemy */
    if (e_frameIndex == e_frameRateAnimation)e_framePosition+=19;
    e_frameIndex++;
    if (e_frameIndex > e_frameRateAnimation)e_frameIndex = 0;
    if (e_framePosition>57){e_framePosition=0;}
}